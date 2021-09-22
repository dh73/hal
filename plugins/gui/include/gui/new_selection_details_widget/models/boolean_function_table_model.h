//  MIT License
//
//  Copyright (c) 2019 Ruhr University Bochum, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2021 Max Planck Institute for Security and Privacy. All Rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#pragma once

#include <QAbstractTableModel>
#include <QVector>
#include <QString>
#include <QSharedPointer>
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/gate_library/gate_type.h"

#include "hal_core/defines.h"
#include "hal_core/utilities/log.h"


namespace hal {
    /**
     * @ingroup utility_widgets-selection_details
     *
     * @brief An entry in the boolean function table model.
     *
     * The boolean function table consists of boolean functions and clear-preset behaviors. Therefore the subclasses
     * BooleanFunctionEntry and CPBehaviorEntry are used. However both entry types have an entry left and right so that
     * the table looks like "left=right". These value can be accessed via getEntryIdentifier (left) and getEntryValueString (right).
     */
    class BooleanFunctionTableEntry
    {
    public:
        /**
         * Constructor.
         *
         * @param gateId - The id of the gate the boolean function/clear-preset behavior belongs to. If it belongs
         *                 to no gate, an invalid id can be passed (i.e. gateId=0).
         */
        BooleanFunctionTableEntry(u32 gateId);

        /**
         * Tells if the entry is a CPBehavior (true) or a boolean function (false)
         *
         * @returns true iff the BooleanFunctionTableEntry represents a CPBehavior
         */
        virtual bool isCPBehavior() const = 0;

        /**
         * Gets the left side of the equation.
         *
         * @return the entry identifier
         */
        QString getEntryIdentifier() const;

        /**
         * Gets the right side of the equation.
         *
         * @return the entry's value.
         */
        QString getEntryValueString() const;

        /**
         * Returns the gate id the represented entry is associated with. The gate id may be invalid.
         *
         * @returns the associated gate id.
         */
        u32 getGateId() const;

    protected:
        QString mLeft;
        QString mRight;
        u32 mGateId;
    };

    /**
     * @ingroup utility_widgets-selection_details
     *
     * @brief A BooleanFunctionTableEntry that represents a boolean function.
     */
    class BooleanFunctionEntry : public BooleanFunctionTableEntry
    {
    public:
        /**
         * Constructor.
         *
         * @param gateId - The id of the gate the boolean function belongs to
         * @param functionName - The name of the boolean function (e.g. "O")
         * @param bf - The boolean function
         */
        BooleanFunctionEntry(u32 gateId, QString functionName, BooleanFunction bf);

        /**
         * Get the stored boolean function (copy).
         *
         * @returns the boolean function of the entry.
         */
        BooleanFunction getBooleanFunction() const;

        virtual bool isCPBehavior() const;
    private:
        BooleanFunction mBF;
    };

    /**
     * @ingroup utility_widgets-selection_details
     *
     * @brief A BooleanFunctionTableEntry that represents a clear-preset behavior.
     */
    class CPBehaviorEntry : public BooleanFunctionTableEntry
    {

    public:
        /**
         * Constructor.
         *
         * @param gateId - The id of the gate the clear-preset behavior belongs to
         * @param cPBehavior - The clear set behavior
         */
        CPBehaviorEntry(u32 gateId, std::pair<GateType::ClearPresetBehavior, GateType::ClearPresetBehavior> cPBehavior);

        /**
         * Get the clear-preset behavior.
         *
         * @returns the clear-preset behavior
         */
        std::pair<GateType::ClearPresetBehavior, GateType::ClearPresetBehavior> getCPBehavior() const;

        virtual bool isCPBehavior() const;

    private:
        QString cPBehaviourToString (std::pair<GateType::ClearPresetBehavior, GateType::ClearPresetBehavior> cPBehaviour);
        std::pair<GateType::ClearPresetBehavior, GateType::ClearPresetBehavior> mCPBehavior;
    };

    /**
     * @ingroup utility_widgets-selection_details
     *
     * @brief A model that holds BooleanFunction%s and clear-preset behaviors.
     *
     * The model can be filled with a list of BooleanFunctionTableEntry%s. Each element is either BooleanFunction%s (using
     * BooleanFunctionEntry) or a clear-preset behavior (using CPBehaviorEntry).
     *
     * The table contains the identifier in the left column, a separator (i.e. "=") in the center column and the
     * BooleanFunction/clear-preset behavior in the right column.
     */
    class BooleanFunctionTableModel : public QAbstractTableModel
    {
    Q_OBJECT

    public:
        /**
         * Constructor.
         *
         * @param parent - The parent widget
         */
        BooleanFunctionTableModel(QObject* parent=nullptr);

        /**
         * Returns the amount of columns.
         *
         * @param parent - Then parent model index
         * @returns the amount of columns.
         */
        int columnCount(const QModelIndex &parent=QModelIndex()) const override;

        /**
         * Returns the amount of rows in the table.
         *
         * @param parent - The parent model index
         * @returns the amount of rows in the table.
         */
        int rowCount(const QModelIndex &parent=QModelIndex()) const override;

        /**
         * Returns the data stored under the given role for a given index in the table model. <br>
         * All values are aligned centered. The last column is the rows output,
         * in the other columns are the input values.
         *
         * @param index - The index in the table
         * @param role - The access role
         * @returns the data
         */
        QVariant data(const QModelIndex &index, int role) const override;

        /**
         * Returns the header data fields.
         *
         * @param section - The section (column) index
         * @param orientation - The orientation of the table
         * @param role - The access role
         * @returns the header data field at the given position
         */
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        /**
         * Sets the role data for the item at index to value. Currently unused.
         *
         * @param index - The model index
         * @param value - The value to set
         * @param role - The access role
         * @returns <b>true</b> on success
         */
        bool setData(const QModelIndex &index, const QVariant &value, int role) override;

        /**
         * Overwrites the model's entries with the entries in the specified list.
         *
         * @param entries - The new entries
         */
        void setEntries(QVector<QSharedPointer<BooleanFunctionTableEntry>> entries);

        /**
         * Access an entry at the specified row. The row MUST be valid.
         *
         * @param row - the row
         * @returns the entry at the specified row
         */
        QSharedPointer<BooleanFunctionTableEntry> getEntryAtRow(int row) const;


    private:
        QVector<QSharedPointer<BooleanFunctionTableEntry>> mEntries;

        /// The separator sign between the identifier and the value (e.g. "O [SEPARATOR] I1 & I2")
        QString mSeparator = "=";
    };
}
