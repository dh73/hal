#ifdef STANDALONE_PARSER
#include "saleae_parser.h"
#include "saleae_file.h"
#else
#include "netlist_simulator_controller/saleae_parser.h"
#include "netlist_simulator_controller/saleae_file.h"
#include "hal_core/netlist/net.h"
#endif
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cctype>
#include <iostream>

namespace hal
{
    uint64_t SaleaeParser::sTimeScaleFactor = 1000000000;

        SaleaeParser::SaleaeParser(const std::string& filename)
        : mSaleaeDirectory(filename)
    {;}

    std::string SaleaeParser::strim(std::string s)
    {
        if (s.empty()) return s;
        int p0 = 0;
        int p1 = s.length()-1;
        while (p0 <= p1 && isspace(s.at(p0))) p0++;
        while (p0 <= p1 && isspace(s.at(p1))) p1--;
        if (s.at(p0) == '"' && s.at(p1) == '"' && p1-p0 >= 2)
        {
            ++p0;
            --p1;
        }
        return s.substr(p0,p1-p0+1);
    }

    bool SaleaeParser::next_event()
    {
        auto it = mNextValueMap.begin();
        if (it == mNextValueMap.end()) return false;
        DataFileHandle wff = it->second;
        // std::cerr << "SaleaeParser::nextEvent v=" << std::dec << wff.value << " size=" << mNextValueMap.size() << std::endl;
        mNextValueMap.erase(it);
        wff.callback(wff.obj,it->first,wff.value);
        if (wff.file->good())
        {
            SaleaeDataTuple sdt = wff.file->nextValue(wff.value);
            wff.value = sdt.mValue;
            uint64_t nextT = sdt.mTime;
            mNextValueMap.insert(std::pair<uint64_t,DataFileHandle>(nextT,wff));
        }
        else
            delete wff.file;
        return true;
    }

    uint64_t SaleaeParser::get_max_time() const
    {
        return mSaleaeDirectory.get_max_time();
    }

    SaleaeDataBuffer SaleaeParser::get_waveform_by_net(const Net* net) const
    {
        std::string path = mSaleaeDirectory.get_datafile(net->get_name(),net->get_id());
        if (path.empty()) return SaleaeDataBuffer();
        SaleaeInputFile sif(path);
        if (!sif.good()) return SaleaeDataBuffer();
        return sif.get_data();
    }

    bool SaleaeParser::register_callback(const Net *net, std::function<void(void*,uint64_t, int)> callback, void *obj)
    {
        // std::cerr << "SaleaeParser::register_callback <" << net->get_name() << "> " << std::hex << (uintptr_t) obj << std::endl;
        std::string path = mSaleaeDirectory.get_datafile(net->get_name(),net->get_id());
        if (path.empty()) return false;
        SaleaeInputFile* datafile = new SaleaeInputFile(path);
        if (!datafile->good())
        {
            std::cerr << "Error loading SALEAE datafile <" << datafile->get_last_error() << ">" << std::endl;
            delete datafile;
            return false;
        }
        mNextValueMap.insert(std::pair<uint64_t,DataFileHandle>(0,{callback, datafile, datafile->startValue(), obj}));
        return true;
    }
}
