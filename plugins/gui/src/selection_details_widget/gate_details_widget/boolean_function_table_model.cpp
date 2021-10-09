
#include <gui/include/gui/selection_details_widget/gate_details_widget/boolean_function_table_model.h>

#include "gui/selection_details_widget/gate_details_widget/lut_table_model.h"
#include "hal_core/utilities/log.h"

namespace hal {


    /* ========================================================
     * BooleanFunctionTableEntry - Superclass
     * ========================================================*/

    BooleanFunctionTableEntry::BooleanFunctionTableEntry(u32 gateId)
    {
        mGateId = gateId;
    }

    QString BooleanFunctionTableEntry::getEntryIdentifier() const
    {
        return mLeft;
    }

    QString BooleanFunctionTableEntry::getEntryValueString() const
    {
        return mRight;
    }

    u32 BooleanFunctionTableEntry::getGateId() const {
        return mGateId;
    }

    /* ========================================================
     * BooleanFunctionTableEntry - BooleanFunctionEntry
     * ========================================================*/

    BooleanFunctionEntry::BooleanFunctionEntry(u32 gateId, QString functionName, BooleanFunction bf)
    : BooleanFunctionTableEntry(gateId)
    {
        mLeft = functionName;
        mRight = QString::fromStdString(bf.to_string());
    }

    BooleanFunction BooleanFunctionEntry::getBooleanFunction() const
    {
        return mBF;
    }

    bool BooleanFunctionEntry::isCPBehavior() const
    {
        return false;
    }

    /* ========================================================
     * BooleanFunctionTableEntry - CPBehaviorEntry
     * ========================================================*/

    CPBehaviorEntry::CPBehaviorEntry(u32 gateId, std::pair<hal::AsyncSetResetBehavior, hal::AsyncSetResetBehavior> cPBehavior)
    : BooleanFunctionTableEntry(gateId)
    {
        mLeft = "set_clear_behavior";
        mRight = cPBehaviourToString(cPBehavior);
        mCPBehavior =cPBehavior;
    }

    std::pair<hal::AsyncSetResetBehavior, hal::AsyncSetResetBehavior> CPBehaviorEntry::getCPBehavior() const
    {
        return mCPBehavior;
    }

    bool CPBehaviorEntry::isCPBehavior() const
    {
        return true;
    }

    QString CPBehaviorEntry::cPBehaviourToString (std::pair<hal::AsyncSetResetBehavior, hal::AsyncSetResetBehavior> cPBehaviour)
    {
        static QMap<hal::AsyncSetResetBehavior, QString> cPBehaviourToString {
            {hal::AsyncSetResetBehavior::L, "L"},
            {hal::AsyncSetResetBehavior::H, "H"},
            {hal::AsyncSetResetBehavior::N, "N"},
            {hal::AsyncSetResetBehavior::T, "T"},
            {hal::AsyncSetResetBehavior::X, "X"},
            {hal::AsyncSetResetBehavior::undef, "Undefined"},
        };
        return QString(cPBehaviourToString[cPBehaviour.first] + ", " + cPBehaviourToString[cPBehaviour.second]);
    }

    /* ========================================================
     * BooleanFunctionTableModel
     * ========================================================*/

    BooleanFunctionTableModel::BooleanFunctionTableModel(QObject *parent) : QAbstractTableModel(parent)
    {
        mEntries.clear();
    }

    int BooleanFunctionTableModel::columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return 3;
    }

    int BooleanFunctionTableModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return mEntries.size();
    }

    QVariant BooleanFunctionTableModel::data(const QModelIndex &index, int role) const
    {
        int row = index.row();
        int col = index.column();

        if (role == Qt::DisplayRole){

            // Extract the information from the entry based on the column
            if(col == 0)
            {
                return (mEntries[row]->getEntryIdentifier());
            }
            else if(col == 1)
            {
                return mSeparator;
            }
            else
            {
                return (mEntries[row]->getEntryValueString());
            }
        }

        else if (role == Qt::TextAlignmentRole)
        {
            if(col == 0)
            {
                return QVariant(Qt::AlignTop | Qt::AlignLeft);
            }
            else if(col == 1)
            {
                return QVariant(Qt::AlignTop | Qt::AlignHCenter);
            }
            else
            {
                return QVariant(Qt::AlignTop | Qt::AlignLeft);
            }
            return Qt::AlignLeft;
        }

        return QVariant();
    }

    QVariant BooleanFunctionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        Q_UNUSED(section);
        Q_UNUSED(orientation);
        Q_UNUSED(role);
        return QVariant(); // No Header
    }

    bool BooleanFunctionTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        Q_UNUSED(index);
        Q_UNUSED(value);
        Q_UNUSED(role);
        return false;
    }

    QSharedPointer<BooleanFunctionTableEntry> BooleanFunctionTableModel::getEntryAtRow(int row) const
    {
        return mEntries[row];
    }

    void BooleanFunctionTableModel::setEntries(QVector<QSharedPointer<BooleanFunctionTableEntry>> entries){
        Q_EMIT layoutAboutToBeChanged();
        mEntries = entries;
        Q_EMIT layoutChanged();
    }

}// namespace hal
