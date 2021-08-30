#include "gui/new_selection_details_widget/new_module_details_widget/module_info_table.h"

#include "hal_core/netlist/module.h"

#include "gui/new_selection_details_widget/py_code_provider.h"
#include "gui/gui_globals.h"

#include "gui/selection_details_widget/details_table_utilities.h"

#include <QDebug>
#include <QMenu>
#include <QApplication>
#include <QClipboard>

namespace hal
{
    ModuleInfoTable::ModuleInfoTable(QWidget* parent) : GeneralTableWidget(parent)
    {
        mNameEntryContextMenu = new QMenu();
        mNameEntryContextMenu->addAction("changeName", std::bind(&ModuleInfoTable::changeName, this));
        mNameEntryContextMenu->addAction("copyName", std::bind(&ModuleInfoTable::copyName, this));
        mNameEntryContextMenu->addAction("pyCopyName", std::bind(&ModuleInfoTable::pyCopyName, this));

        mIdEntryContextMenu = new QMenu();
        mIdEntryContextMenu->addAction("copyId", std::bind(&ModuleInfoTable::copyId, this));

        mTypeEntryContextMenu = new QMenu();
        mTypeEntryContextMenu->addAction("changeType", std::bind(&ModuleInfoTable::changeType, this));
        mTypeEntryContextMenu->addAction("copyType", std::bind(&ModuleInfoTable::copyType, this));
        mTypeEntryContextMenu->addAction("pyCopyType", std::bind(&ModuleInfoTable::pyCopyType, this));

        mModuleEntryContextMenu = new QMenu();
        mModuleEntryContextMenu->addAction("copyModule", std::bind(&ModuleInfoTable::copyModule, this));
        mModuleEntryContextMenu->addAction("pyCopyModule", std::bind(&ModuleInfoTable::pyCopyModule, this));

        mNumOfGatesContextMenu = new QMenu();
        mNumOfGatesContextMenu->addAction("copyNumOfGates", std::bind(&ModuleInfoTable::copyNumberOfGates, this));

        mNumOfSubmodulesContextMenu = new QMenu();
        mNumOfSubmodulesContextMenu->addAction("copyNumOfSubmodules", std::bind(&ModuleInfoTable::copyNumberOfSubmodules, this));

        mNumOfNetsContextMenu = new QMenu();
        mNumOfNetsContextMenu->addAction("copyNumOfNets", std::bind(&ModuleInfoTable::copyNumberOfNets, this));

        mModuleDoubleClickedAction = std::bind(&ModuleInfoTable::navModule, this);

        connect(gNetlistRelay, &NetlistRelay::moduleRemoved, this, &ModuleInfoTable::handleModuleRemoved);
        connect(gNetlistRelay, &NetlistRelay::moduleNameChanged, this, &ModuleInfoTable::handleModuleChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleParentChanged, this, &ModuleInfoTable::handleModuleChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleTypeChanged, this, &ModuleInfoTable::handleModuleChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleSubmoduleAdded, this, &ModuleInfoTable::handleSubmoduleChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleSubmoduleRemoved, this, &ModuleInfoTable::handleSubmoduleChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleGateAssigned, this, &ModuleInfoTable::handleGateChanged);
        connect(gNetlistRelay, &NetlistRelay::moduleGateRemoved, this, &ModuleInfoTable::handleGateChanged);
        connect(gNetlistRelay, &NetlistRelay::netSourceAdded, this, &ModuleInfoTable::handleNetChaned);
        connect(gNetlistRelay, &NetlistRelay::netSourceRemoved, this, &ModuleInfoTable::handleNetChaned);
        connect(gNetlistRelay, &NetlistRelay::netDestinationAdded, this, &ModuleInfoTable::handleNetChaned);
        connect(gNetlistRelay, &NetlistRelay::netDestinationRemoved, this, &ModuleInfoTable::handleNetChaned);
    }

    void ModuleInfoTable::setModule(hal::Module* module)
    {
        if(gNetlist->is_module_in_netlist(module))
        {
            mModule = module;

            setRow("Name", name(), mNameEntryContextMenu);
            setRow("Id", id(), mIdEntryContextMenu);
            setRow("Type", type(), mTypeEntryContextMenu);
            setRow("Parent Module", parentModule(), mModuleEntryContextMenu, mModuleDoubleClickedAction);
            setRow("No. of Gates", numberOfGates(), mNumOfGatesContextMenu);
            setRow("No. of Submodules", numberOfSubModules(), mNumOfSubmodulesContextMenu);
            setRow("No. of Nets", numberOfNets(), mNumOfNetsContextMenu);
            
            adjustSize();
        }
    }

    QString ModuleInfoTable::name() const
    {
        return QString::fromStdString(mModule->get_name());
    }

    QString ModuleInfoTable::id() const
    {
        return QString::number(mModule->get_id());
    }

    QString ModuleInfoTable::type() const
    {
        QString type = QString::fromStdString(mModule->get_type());

        if(type.isEmpty())
            type = "None";

        return type;
    }

    QString ModuleInfoTable::parentModule() const
    {
        QString parentModule = "None";

        Module* module = mModule->get_parent_module();

        if(module)
            parentModule = QString::fromStdString(module->get_name()) + "[Id:" + QString::number(module->get_id()) + "]";

        return parentModule;
    }

    QString ModuleInfoTable::numberOfGates() const
    {
        QString numOfGates = "";

        int numOfAllChilds = mModule->get_gates(nullptr, true).size();
        int numOfDirectChilds = mModule->get_gates(nullptr, false).size();
        int numOfChildsInModules = numOfAllChilds - numOfDirectChilds;

        numOfGates.append(QString::number(numOfAllChilds));

        if(numOfChildsInModules > 0)
            numOfGates.append(" (" + QString::number(numOfDirectChilds) + " direct members and " + QString::number(numOfChildsInModules) +" in submodules)");

        return numOfGates;
    }

    QString ModuleInfoTable::numberOfSubModules() const
    {
        return QString::number(mModule->get_submodules(nullptr, true).size());
    }

    QString ModuleInfoTable::numberOfNets() const
    {
        return QString::number(mModule->get_internal_nets().size());
    }

    void ModuleInfoTable::changeName()
    {
        qDebug() << "changeName()";
    }

    void ModuleInfoTable::copyName() const
    {
        copyToClipboard(name());
    }

    void ModuleInfoTable::pyCopyName() const
    {
        copyToClipboard(PyCodeProvider::pyCodeModuleName(mModule->get_id()));
    }

    void ModuleInfoTable::copyId() const
    {
        copyToClipboard(id());
    }

    void ModuleInfoTable::changeType() const
    {
        qDebug() << "changeType()";
    }

    void ModuleInfoTable::copyType() const
    {
        copyToClipboard(type());
    }

    void ModuleInfoTable::pyCopyType() const
    {
        copyToClipboard(PyCodeProvider::pyCodeModuleType(mModule->get_id()));
    }

    void ModuleInfoTable::copyModule() const
    {
        copyToClipboard(parentModule());
    }

    void ModuleInfoTable::pyCopyModule() const
    {
        copyToClipboard(PyCodeProvider::pyCodeModuleModule(mModule->get_id()));
    }

    void ModuleInfoTable::copyNumberOfGates() const
    {
        copyToClipboard(numberOfGates());
    }

    void ModuleInfoTable::copyNumberOfSubmodules() const
    {
        copyToClipboard(numberOfSubModules());
    }

    void ModuleInfoTable::copyNumberOfNets() const
    {
        copyToClipboard(numberOfNets());
    }

    void ModuleInfoTable::navModule()
    {
        Module* parentModule = mModule->get_parent_module();

        if(parentModule != nullptr)
        {
            u32 parentModuleId = parentModule->get_id();

            gSelectionRelay->clear();
            gSelectionRelay->addModule(parentModuleId);
            gSelectionRelay->relaySelectionChanged(this);
        }
    }

    void ModuleInfoTable::refresh()
    {
        setModule(mModule);
    }

    void ModuleInfoTable::handleModuleRemoved(Module* module)
    {
        if(mModule == module)
        {
            mModule = nullptr;

            const QString notification("Displayed module has been deleted.");

            setRow("Name", notification, nullptr);
            setRow("Id", notification, nullptr);
            setRow("Type", notification, nullptr);
            setRow("Parent Module", notification, nullptr, nullptr);
            setRow("No. of Gates", notification, nullptr);
            setRow("No. of Submodules", notification, nullptr);
            setRow("No. of Nets", notification, nullptr);

            adjustSize();
        }
    }

    void ModuleInfoTable::handleModuleChanged(Module* module)
    {
        if(mModule == module)
            refresh();
    }

    void ModuleInfoTable::handleSubmoduleChanged(Module* module, u32 affectedModuleId)
    {
        Q_UNUSED(affectedModuleId);

        if(mModule == module || mModule->contains_module(module))
            refresh();
    }

    void ModuleInfoTable::handleGateChanged(Module* module, u32 affectedGateId)
    {
        Q_UNUSED(affectedGateId);

        if(mModule == module || mModule->contains_module(module))
            refresh();
    }

    void ModuleInfoTable::handleNetChaned(Net* net, u32 affectedGateId)
    {
        Q_UNUSED(affectedGateId);

        std::vector<Net*> internalNets = mModule->get_internal_nets();

        if(std::find(std::begin(internalNets), std::end(internalNets), net) != std::end(internalNets))
            refresh();
    }
}
