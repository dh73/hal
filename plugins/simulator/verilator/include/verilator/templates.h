#include "verilator/verilator.h"

#include <sstream>

namespace hal
{
    namespace verilator
    {

        // const std::string get_makefile_template()
        // {
        //     std::stringstream makefile_template;
        //     makefile_template << "all:\n"
        //                       << "\n"
        //                       << "VDIRFB  := obj_dir\n"
        //                       << "SUBMAKE := $(MAKE) --no-print-directory -C\n"
        //                       << "VERILATOR := verilator\n"
        //                       << "INCLUDE := -I.\n"
        //                       << "\n"
        //                       << "VFLAGS :=  -Wall -Wno-fatal --MMD -trace -y ./ -y gate_definitions --Mdir $(VDIRFB) --exe -cc -DSIM_VERILATOR --trace-depth 1\n"
        //                       << "\n"
        //                       << "\n"
        //                       << ".PHONY: all\n"
        //                       << "all: generic_tb\n"
        //                       << "\n"
        //                       << "veri_all: library verilate\n"
        //                       << "\n"
        //                       << "%: %.cpp\n"
        //                       << "	$(VERILATOR) $(INCLUDE) $(VFLAGS) $@.cpp <top_module>.v\n"
        //                       << "	$(SUBMAKE) $(VDIRFB)/ -f V<top_module>.mk\n"
        //                       << "	make run\n"
        //                       << "\n"
        //                       << "run:\n"
        //                       << "	$(VDIRFB)/V<top_module>\n"
        //                       << "\n"
        //                       << ".PHONY: verilate\n"
        //                       << "verilate: $(VDIRFB)/V<top_module>.h\n"
        //                       << "\n"
        //                       << "$(VDIRFB)/V<top_module>.h:\n"
        //                       << "	$(VERILATOR) $(VFLAGS) testbench.cpp <top_module>.v\n"
        //                       << "\n"
        //                       << ".PHONY: library\n"
        //                       << "library: $(VDIRFB)/V<top_module>.h\n"
        //                       << "	$(SUBMAKE) $(VDIRFB)/ -f V<top_module>.mk\n"
        //                       << "\n"
        //                       << ".PHONY: clean\n"
        //                       << "clean:\n"
        //                       << "	rm -rf $(VDIRFB)/\n"
        //                       << "\n"
        //                       << "DEPS := $(wildcard $(VDIRFB)/*.d)\n"
        //                       << "\n"
        //                       << "ifneq ($(DEPS),)\n"
        //                       << "include $(DEPS)\n"
        //                       << "endif" << std::endl;
        //     return makefile_template.str();
        // }
        // const std::string get_testbench_h_template()
        // {
        //     std::stringstream testbench_h_template;
        //     testbench_h_template << "#ifndef	TESTB_H\n"
        //                          << "#define	TESTB_H\n"
        //                          << "\n"
        //                          << "#include <stdio.h>\n"
        //                          << "#include <stdint.h>\n"
        //                          << "#include <verilated_vcd_c.h>\n"
        //                          << "#include \"tbclock.h\"\n"
        //                          << "#include <tbclock.h>\n"
        //                          << "\n"
        //                          << "template <class VA>	class TESTB {\n"
        //                          << "public:\n"
        //                          << "	VA	*m_core;\n"
        //                          << "	bool		m_changed;\n"
        //                          << "	VerilatedVcdC*	m_trace;\n"
        //                          << "	bool		m_done;\n"
        //                          << "	unsigned long	m_time_ps;\n"
        //                          << "    <CLOCK_DEFINES>\n"
        //                          << "\n"
        //                          << "	TESTB(void) {\n"
        //                          << "		m_core = new VA;\n"
        //                          << "		m_time_ps  = 0ul;\n"
        //                          << "		m_trace    = NULL;\n"
        //                          << "		m_done     = false;\n"
        //                          << "		Verilated::traceEverOn(true);\n"
        //                          << "        <CLOCKS_INITS>\n"
        //                          << "	}\n"
        //                          << "	virtual ~TESTB(void) {\n"
        //                          << "		if (m_trace) m_trace->close();\n"
        //                          << "		delete m_core;\n"
        //                          << "		m_core = NULL;\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "	virtual	void	opentrace(const char *vcdname) {\n"
        //                          << "		if (!m_trace) {\n"
        //                          << "			m_trace = new VerilatedVcdC;\n"
        //                          << "			m_core->trace(m_trace, 99);\n"
        //                          << "			m_trace->open(vcdname);\n"
        //                          << "		}\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "	void	trace(const char *vcdname) {\n"
        //                          << "		opentrace(vcdname);\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "	virtual	void	closetrace(void) {\n"
        //                          << "		if (m_trace) {\n"
        //                          << "			m_trace->close();\n"
        //                          << "			delete m_trace;\n"
        //                          << "			m_trace = NULL;\n"
        //                          << "		}\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "	virtual	void	eval(void) {\n"
        //                          << "		m_core->eval();\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "	virtual	void	tick(void) {\n"
        //                          << "        <MINTIME_CLOCKS>\n"
        //                          << "\n"
        //                          << "		assert(mintime > 1);\n"
        //                          << "\n"
        //                          << "		eval();\n"
        //                          << "		if (m_trace) m_trace->dump(m_time_ps+1);\n"
        //                          << "\n"
        //                          << "		<CLOCK_ADVANCES>\n"
        //                          << "\n"
        //                          << "		m_time_ps += mintime;\n"
        //                          << "\n"
        //                          << "		eval();\n"
        //                          << "		if (m_trace) {\n"
        //                          << "			m_trace->dump(m_time_ps+1);\n"
        //                          << "			m_trace->flush();\n"
        //                          << "		}\n"
        //                          << "\n"
        //                          << "        <CLOCK_FALLING_EDGE>\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "    <SIM_CLOCK_TICK>\n"
        //                          << "\n"
        //                          << "	virtual bool	done(void) {\n"
        //                          << "		if (m_done)\n"
        //                          << "			return true;\n"
        //                          << "\n"
        //                          << "		if (Verilated::gotFinish())\n"
        //                          << "			m_done = true;\n"
        //                          << "\n"
        //                          << "		return m_done;\n"
        //                          << "	}\n"
        //                          << "\n"
        //                          << "    virtual void wait_for_n_clocks(int ticks)\n"
        //                          << "    {\n"
        //                          << "        int counter = 0;\n"
        //                          << "\n"
        //                          << "        while (counter < ticks) {\n"
        //                          << "            tick();\n"
        //                          << "            counter++;\n"
        //                          << "        }\n"
        //                          << "    }\n"
        //                          << "\n"
        //                          << "	// virtual	void	reset(void) {\n"
        //                          << "	// 	m_core->i_reset = 1;\n"
        //                          << "	// 	tick();\n"
        //                          << "	// 	m_core->i_reset = 0;\n"
        //                          << "	// 	// printf(\"RESET\n\");\n"
        //                          << "	// }\n"
        //                          << "};\n"
        //                          << "\n"
        //                          << "#endif	// TESTB\n";
        //     return testbench_h_template.str();
        // }
        // const std::string get_testbench_clock_h_template()
        // {
        //     std::stringstream testbench_clock_h_template;
        //     testbench_clock_h_template << "#ifndef	TBCLOCK_H\n"
        //                                << "#define	TBCLOCK_H\n"
        //                                << "\n"
        //                                << "class	TBCLOCK	{\n"
        //                                << "	unsigned long	m_increment_ps, m_now_ps, m_last_edge_ps;\n"
        //                                << "\n"
        //                                << "public:\n"
        //                                << "	TBCLOCK(void) {\n"
        //                                << "		m_increment_ps = 10000; // 10 ns;\n"
        //                                << "\n"
        //                                << "		m_now_ps = m_increment_ps+1;\n"
        //                                << "		m_last_edge_ps = m_increment_ps;\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	TBCLOCK(unsigned long increment_ps) {\n"
        //                                << "		init(increment_ps);\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	void	init(unsigned long increment_ps) {\n"
        //                                << "		set_interval_ps(increment_ps);\n"
        //                                << "\n"
        //                                << "		// Start with the clock low, waiting on a positive edge\n"
        //                                << "		m_now_ps = m_increment_ps+1;\n"
        //                                << "		m_last_edge_ps = m_increment_ps;\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	unsigned long	time_to_tick(void) {\n"
        //                                << "		unsigned long	ul;\n"
        //                                << "		if (m_last_edge_ps > m_now_ps) {\n"
        //                                << "			// Should never happen\n"
        //                                << "			ul = m_last_edge_ps - m_now_ps;\n"
        //                                << "			ul /= m_increment_ps;\n"
        //                                << "			ul = m_now_ps + ul * m_increment_ps;\n"
        //                                << "		} else if (m_last_edge_ps == m_now_ps) {\n"
        //                                << "			ul = m_increment_ps;\n"
        //                                << "		} else if (m_last_edge_ps + m_increment_ps == m_now_ps) {\n"
        //                                << "			ul = m_increment_ps;\n"
        //                                << "		} else if (m_last_edge_ps + m_increment_ps > m_now_ps) {\n"
        //                                << "			ul = m_last_edge_ps + m_increment_ps - m_now_ps;\n"
        //                                << "		} else // if (m_last_edge + m_interval_ps > m_now) {\n"
        //                                << "			ul = (m_last_edge_ps + 2*m_increment_ps - m_now_ps);\n"
        //                                << "\n"
        //                                << "		return ul;\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	void	set_interval_ps(unsigned long interval_ps) {\n"
        //                                << "		// Divide the clocks interval by two, so we can have a\n"
        //                                << "		// period for raising the clock, and another for lowering\n"
        //                                << "		// the clock.\n"
        //                                << "		m_increment_ps = (interval_ps>>1)&-2l;\n"
        //                                << "		assert(m_increment_ps > 0);\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	int	advance(unsigned long itime)  {\n"
        //                                << "		int	clk = 0;\n"
        //                                << "		m_now_ps += itime;\n"
        //                                << "		if (m_now_ps >= m_last_edge_ps + 2*m_increment_ps) {\n"
        //                                << "			m_last_edge_ps += 2*m_increment_ps;\n"
        //                                << "			clk = 1;\n"
        //                                << "		} else if (m_now_ps >= m_last_edge_ps + m_increment_ps)\n"
        //                                << "			clk = 0;\n"
        //                                << "		else\n"
        //                                << "			clk = 1;\n"
        //                                << "		return clk;\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	bool	rising_edge(void) {\n"
        //                                << "		if (m_now_ps == m_last_edge_ps) {\n"
        //                                << "			return true;\n"
        //                                << "		} return false;\n"
        //                                << "	}\n"
        //                                << "\n"
        //                                << "	bool	falling_edge(void) {\n"
        //                                << "		if (m_now_ps == m_last_edge_ps + m_increment_ps) {\n"
        //                                << "			return true;\n"
        //                                << "		} return false;\n"
        //                                << "	}\n"
        //                                << "};\n"
        //                                << "#endif";
        //     return testbench_clock_h_template.str();
        // }
        const std::string get_testbench_cpp_template()
        {
            std::stringstream testbench_cpp_template;
            testbench_cpp_template << "#include <stdlib.h>\n"
                                   << "#include <iostream>\n"
                                   << "#include <verilated.h>\n"
                                   << "#include <verilated_vcd_c.h>\n"
                                   << "#include \"V<top_system>.h\"\n"
                                   << "#include \"testbench.h\"\n"
                                   << "\n"
                                   << "#define MAX_SIM_TIME 20\n"
                                   << "vluint64_t sim_time = 0;\n"
                                   << "\n"
                                   << "double sc_time_stamp(){\n"
                                   << "\treturn sim_time;\n"
                                   << "}\n"
                                   << "\n"
                                   << "int main(int argc, char** argv, char** env) {\n"
                                   << "    V<top_system> *dut = new V<top_system>;\n"
                                   << "\n"
                                   << "    Verilated::traceEverOn(true);\n"
                                   << "    VerilatedVcdC *m_trace = new VerilatedVcdC;\n"
                                   << "\n"
                                   << "\n"
                                   << "    dut->trace(m_trace, 1);\n"
                                   << "    m_trace->open(\"waveform.vcd\");\n"
                                   << "\n"
                                   << "<insert_trace_here>\n"
                                   << "\n"
                                   << "\tm_trace->dump(sim_time);\n"
                                   << "    m_trace->close();\n"
                                   << "    delete dut;\n"
                                   << "    exit(EXIT_SUCCESS);\n"
                                   << "}";
            return testbench_cpp_template.str();
        }
        const std::string get_partial_testbench_cpp_template()
        {
            std::stringstream partial_testbench_cpp_template;
            partial_testbench_cpp_template << "#include <stdlib.h>\n"
                                           << "#include <verilated.h>\n"
                                           << "#include <verilated_vcd_c.h>\n"
                                           << "#include \"V<top_system>.h\"\n"
                                           << "\n"
                                           << "void <part_xy>(V<top_system>* dut, VerilatedVcdC* m_trace, vluint64_t& sim_time) {\n"
                                           << "<insert_trace_here>\n"
                                           << "}";
            return partial_testbench_cpp_template.str();
        }

        const std::string get_testbench_h_template()
        {
            std::stringstream partial_testbench_h_template;
            partial_testbench_h_template << "#include <stdlib.h>\n"
                                         << "#include <verilated.h>\n"
                                         << "#include <verilated_vcd_c.h>\n"
                                         << "#include \"V<top_system>.h\"\n"
                                         << "\n"
                                         << "<insert_partial_testbench_here>\n";
            return partial_testbench_h_template.str();
        }

    }    // namespace verilator
}    // namespace hal