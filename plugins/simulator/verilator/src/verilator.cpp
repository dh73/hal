
#include "hal_core/netlist/boolean_function.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/netlist.h"
#include "hal_core/netlist/netlist_utils.h"
#include "hal_core/utilities/log.h"
#include "hal_core/utilities/utils.h"

#include "verilog_writer/verilog_writer.h"

#include "netlist_simulator_controller/simulation_input.h"
#include "verilator/templates.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace hal {
namespace verilator {
    namespace converter {
        std::vector<std::string> get_vector_for_const_char(const char** txt)
        {
            std::vector<std::string> retval;
            const char* s = *txt;
            while (s) {
                retval.push_back(std::string(s));
                s++;
            }
            return retval;
        }
    }

    const int VerilatorEngine::s_command_lines = 3;

    bool VerilatorEngine::setSimulationInput(SimulationInput* simInput)
    {
        const std::vector<const Gate*> simulation_gates(simInput->get_gates().begin(), simInput->get_gates().end());
        m_partial_netlist = netlist_utils::get_partial_netlist(simulation_gates.at(0)->get_netlist(), simulation_gates);

        m_simulator_dir = "/tmp/hal/simulator/";

        std::filesystem::path provided_models = "/Users/eve/hal/plugins/real_world_reversing/simulation_models/";
        std::filesystem::path netlist_verilog = m_simulator_dir / std::string(m_partial_netlist->get_design_name() + ".v");

        // todo: delete folder if not empty
        if (std::filesystem::exists(m_simulator_dir)) {
            std::filesystem::remove_all(m_simulator_dir);
        }
        std::filesystem::create_directories(m_simulator_dir);

        std::vector<SimulationInput::Clock> clocks = simInput->get_clocks();

        // set inputs in testbench
        std::string testbench_cpp = get_testbench_cpp_template();
        std::stringstream simulation_data;

        log_info("verilator", "simulating {} net events", simInput->get_simulation_net_events().size());

        for (const auto& sim_event : simInput->get_simulation_net_events()) {
            u32 duration = sim_event.get_simulation_duration();
            for (const auto& [net, boolean_value] : sim_event) {
                log_info("verilator", "net: {}", net->get_name());
                simulation_data << "\tdut->" << net->get_name() << " = ";

                switch (boolean_value) {
                case BooleanFunction::Value::ONE:
                    simulation_data << "0x1";
                    break;

                case BooleanFunction::Value::ZERO:
                    simulation_data << "0x0";
                    break;

                default:
                    log_error("verilator", "cannot assign value '{}' to net '{}' at {}ps, only supporting 1 and 0, aborting...", BooleanFunction::to_string(boolean_value), net->get_name(), duration);
                    return false;
                    break;
                }
                simulation_data << ";" << std::endl;
            }
            simulation_data << "\tdut->eval();" << std::endl;
            simulation_data << "\tm_trace->dump(" << duration << ");" << std::endl;
            simulation_data << "\tsim_time += " << duration << ");" << std::endl;
            simulation_data << std::endl;
        }

        testbench_cpp = utils::replace(testbench_cpp, std::string("<insert_trace_here>"), simulation_data.str());
        testbench_cpp = utils::replace(testbench_cpp, std::string("<top_system>"), m_partial_netlist->get_design_name());

        log_info("verilator", "{}", testbench_cpp);
        log_info("verilator", "{}", simulation_data.str());

        std::ofstream testbench_cpp_file(m_simulator_dir / "testbench.cpp");
        testbench_cpp_file << testbench_cpp;
        testbench_cpp_file.close();

        if (!converter::convert_gate_library_to_verilog(m_partial_netlist.get(), m_simulator_dir, provided_models)) {
            log_error("verilator", "could not create gate definitions in verilog");
            return false;
        };
        //VerilogWriter::write(m_partial_netlist, netlist_verilog);

        return true; // everything ok
    }

    int VerilatorEngine::numberCommandLines() const
    {
        return s_command_lines;
    }

    std::vector<std::string> VerilatorEngine::commandLine(int lineIndex) const
    {
        // returns commands to be executed
        switch (lineIndex) {
        case 0: {
            const char* cl[] = { "verilator", "-I.", "-Wall", "-Wno-fatal", "--MMD", "-trace", "-y", "gate_definitions/",
                "--Mdir", "obj_dir", "--exe", "-cc", "-DSIM_VERILATOR", "--trace-depth", "1",
                "generic_tb.cpp", "counter.v", nullptr };
            return converter::get_vector_for_const_char(cl);
        } break;
        case 1: {
            const char* cl[] = { "make", "--no-print-directory", "-C", "obj_dir/", "-f", "Vcounter.mk", nullptr };
            return converter::get_vector_for_const_char(cl);
        } break;
        case 2: {
            const char* cl[] = { "make", "run", nullptr };
            return converter::get_vector_for_const_char(cl);
        } break;
        default:
            break;
        }

        return std::vector<std::string>();
    }

    VerilatorEngine::VerilatorEngine()
        : SimulationEngineScripted("verilator")
    {
        mRequireClockEvents = true;
    }

    bool VerilatorEngine::finalize()
    {
        m_result_filename = std::string(m_simulator_dir / "waveform.vcd");
        return true;
    }

} // namespace verilator
}
