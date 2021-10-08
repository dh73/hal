#include "netlist_simulator/simulation.h"

#include "hal_core/netlist/boolean_function.h"
#include "hal_core/netlist/net.h"

namespace hal
{
    BooleanFunction::Value Simulation::get_net_value(const Net* net, u64 time) const
    {
        BooleanFunction::Value result = BooleanFunction::Value::X;

        if (auto it = m_events.find(net); it != m_events.end())
        {
            for (const Event& e : it->second)
            {
                if (e.time > time)
                {
                    break;
                }
                result = e.new_value;
            }
        }
        return result;
    }

    void Simulation::add_event(const Event& event)
    {
        m_events[event.affected_net].push_back(event);
    }

    std::unordered_map<const Net*, std::vector<Event>> Simulation::get_events() const
    {
        return m_events;
    }
}    // namespace hal
