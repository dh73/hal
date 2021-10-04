#include "gui/selection_details_widget/gate_details_widget/pin_tree_model.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/gate_library/gate_type.h"
#include "gui/gui_globals.h"
#include <QVector>
#include <QDebug>
#include "hal_core/utilities/enums.h"


namespace hal
{

    PinTreeModel::PinTreeModel(QObject *parent) : BaseTreeModel(parent)
    {
        setHeaderLabels(QList<QVariant>() << "Name" << "Direction" << "Type" << "Connected Net");

        //added to store a list of (multiple) net ids in a given treeitem (perhaps dont do this
        //at all, handle it in the view? (since the gate-id and pin name is accessable, the nets can be evaluated there
        qRegisterMetaType<QList<int>>();
    }

    PinTreeModel::~PinTreeModel()
    {
        delete mRootItem;

    }

    void PinTreeModel::clear()
    {
        BaseTreeModel::clear();
        mPinGroupingToTreeItem.clear();
        mGateId = -1;

    }

    void PinTreeModel::setGate(Gate *g)
    {
        clear();
        mGateId = g->get_id();

        beginResetModel();
        GateType* gateType = g->get_type();
        for(auto pin : gateType->get_pins())
        {
            TreeItem* pinItem = new TreeItem();
            //get all infos for that pin
            std::string grouping = gateType->get_pin_group(pin);
            QString pinDirection = QString::fromStdString(enum_to_string(gateType->get_pin_direction(pin)));
            QString pinType = QString::fromStdString(enum_to_string(gateType->get_pin_type(pin)));

            //evaluate netname (in case of inout multiple possible nets), method depends on pindirection (kind of ugly switch)
            QString netName = "";
            QList<int> netIDs;
            switch(gateType->get_pin_direction(pin))
            {
                case PinDirection::input:
                    if(g->get_fan_in_net(pin))
                    {
                        netName = QString::fromStdString(g->get_fan_in_net(pin)->get_name());
                        netIDs.append(g->get_fan_in_net(pin)->get_id());
                    }
                    break;
                    //netName = (g->get_fan_in_net(pin)) ? QString::fromStdString(g->get_fan_in_net(pin)->get_name()) : "" ; break;
                case PinDirection::output:
                    if(g->get_fan_out_net(pin))
                    {
                        netName = QString::fromStdString(g->get_fan_out_net(pin)->get_name());
                        netIDs.append(g->get_fan_out_net(pin)->get_id());
                    }
                    break;
                    //netName = (g->get_fan_out_net(pin)) ? QString::fromStdString(g->get_fan_out_net(pin)->get_name()) : "" ; break;
                case PinDirection::inout: //must take input and output net into account
                    if(g->get_fan_in_net(pin))
                    {
                        netName += QString::fromStdString(g->get_fan_in_net(pin)->get_name());
                        netIDs.append(g->get_fan_in_net(pin)->get_id());
                    }
                    if(g->get_fan_out_net(pin))
                    {
                        if(!netName.isEmpty()) netName += " / "; //add / when there is a input net to seperate it from the output net
                        netName += QString::fromStdString(g->get_fan_out_net(pin)->get_name());
                        netIDs.append(g->get_fan_out_net(pin)->get_id());
                    }
                    break;
                default: break; //none and internal, dont know how to handle internal (whatever an internal pin is)
            }

            pinItem->setData(QList<QVariant>() << QString::fromStdString(pin) << pinDirection << pinType << netName);
            pinItem->setAdditionalData(keyType, QVariant::fromValue(itemType::pin));
            pinItem->setAdditionalData(keyRepresentedNetsID, QVariant::fromValue(netIDs));
            if(!grouping.empty())
            {
                TreeItem* groupingsItem = mPinGroupingToTreeItem.value(grouping, nullptr); //since its a map, its okay
                if(!groupingsItem)
                {
                    //assume all items in the same grouping habe the same direction and type, so the grouping-item has also these types
                    groupingsItem = new TreeItem(QList<QVariant>() << QString::fromStdString(grouping) << pinDirection << pinType << "");
                    groupingsItem->setAdditionalData(keyType, QVariant::fromValue(itemType::grouping));
                    mRootItem->appendChild(groupingsItem);
                    mPinGroupingToTreeItem.insert(grouping, groupingsItem);
                }
                groupingsItem->appendChild(pinItem);

            }
            else
                mRootItem->appendChild(pinItem);

        }
        endResetModel();
    }

    int PinTreeModel::getCurrentGateID()
    {
        return mGateId;
    }

    QList<int> PinTreeModel::getNetIDsOfTreeItem(TreeItem *item)
    {
        return item->getAdditionalData(keyRepresentedNetsID).value<QList<int>>();
    }

    PinTreeModel::itemType PinTreeModel::getTypeOfItem(TreeItem *item)
    {
        return item->getAdditionalData(keyType).value<itemType>();
    }

    int PinTreeModel::getNumberOfDisplayedPins()
    {
        Gate* g = gNetlist->get_gate_by_id(mGateId);
        if(!g)
            return 0;

        return g->get_type()->get_pins().size();
    }
}
