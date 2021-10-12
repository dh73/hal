#include "gui/selection_details_widget/gate_details_widget/boolean_function_table.h"
#include "gui/gui_globals.h"
#include "gui/python/py_code_provider.h"
#include <QHeaderView>
#include <QtWidgets/QMenu>
#include <QApplication>
#include <QClipboard>

namespace hal {
    BooleanFunctionTable::BooleanFunctionTable(QWidget *parent) : QTableView(parent),
    mBooleanFunctionTableModel(new BooleanFunctionTableModel(this))
    {
        this->setModel(mBooleanFunctionTableModel);
        this->setSelectionMode(QAbstractItemView::NoSelection);
        this->setFocusPolicy(Qt::NoFocus);
        this->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->verticalHeader()->setVisible(false);
        this->horizontalHeader()->setVisible(false);
        this->setShowGrid(false);
        setFrameStyle(QFrame::NoFrame);

        connect(this, &QTableView::customContextMenuRequested, this, &BooleanFunctionTable::handleContextMenuRequest);
    }

    BooleanFunctionTableModel* BooleanFunctionTable::getModel()
    {
        return mBooleanFunctionTableModel;
    }

    void BooleanFunctionTable::setEntries(QVector<QSharedPointer<BooleanFunctionTableEntry>> entries){
        mBooleanFunctionTableModel->setEntries(entries);
        adjustTableSizes();
        this->clearSelection();
        this->update();
    }

    void BooleanFunctionTable::resizeEvent(QResizeEvent *event)
    {
        QAbstractItemView::resizeEvent(event);
        adjustTableSizes();
    }

    void BooleanFunctionTable::handleContextMenuRequest(const QPoint &pos)
    {
        QModelIndex idx = indexAt(pos);
        if(!idx.isValid()){
            return;
        }

        QSharedPointer<BooleanFunctionTableEntry> entry = mBooleanFunctionTableModel->getEntryAtRow(idx.row());
        QMenu menu;
        QString menuText;
        QString pythonCode;

        /*====================================
                  Plaintext to Clipboard
          ====================================*/ 

        QString toClipboardText = entry->getEntryIdentifier() + " = " + entry->getEntryValueString();
        menu.addAction(
            "Copy boolean function to clipboard",
            [toClipboardText]()
            {
                QApplication::clipboard()->setText( toClipboardText );
            }
        );

        /*====================================
                Python to Clipboard 
          ====================================*/ 

        // Entry is a boolean function
        if(!entry->isCPBehavior())
        {
            menuText = "Extract boolean function as python code (copy to clipboard)";
            pythonCode = PyCodeProvider::pyCodeGateBooleanFunction(entry->getGateId(), entry->getEntryIdentifier());
        }
        // Entry is clear-preset behavior
        else
        {
            menuText = "Extract clear-preset behavior as python code (copy to clipboard)";
            pythonCode = PyCodeProvider::pyCodeGateAsyncSetResetBehavior(entry->getGateId());
        }
        menu.addAction(QIcon(":/icons/python"), menuText,
           [pythonCode]()
           {
               QApplication::clipboard()->setText( pythonCode );
           }
        );
        menu.move(dynamic_cast<QWidget*>(sender())->mapToGlobal(pos));
        menu.exec();
    }

    void BooleanFunctionTable::adjustTableSizes()
    {
        resizeColumnsToContents();
        this->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        this->setWordWrap(true);
        this->resizeRowsToContents();

        // Configure the widget height
        int h = 0;
        for (int i = 0; i < mBooleanFunctionTableModel->rowCount(); i++)
            h += rowHeight(i);

        setMaximumHeight(h);
        setMinimumHeight(h);
    }

} // namespace hal
