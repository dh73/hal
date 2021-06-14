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

#include <QAbstractItemModel>
#include "gui/new_selection_details_widget/models/tree_item.h"

namespace hal
{
    class Module;
    /**
     * @ingroup utility_widgets-selection_details
     * @brief A model to display arbitrary elements of the netlist.
     */
    class NetlistElementsTreeModel : public QAbstractItemModel
    {
        Q_OBJECT
    public:
        /**
         * The constructor.
         *
         * @param parent - The model's parent.
         */
        NetlistElementsTreeModel(QObject* parent = nullptr);

        /**
          * The destructor.
          */
        ~NetlistElementsTreeModel();

        /** @name Overwritten model functions
         */
        ///@{

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        QModelIndex parent(const QModelIndex &index) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        Qt::ItemFlags flags(const QModelIndex& index) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        /**
          * Overwritten Qt function that is necessary for the model. For further information pleaser
          * refer to the Qt documentation.
          */
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        ///@}

        /**
         * Sets the module's content to the specified ids. Adds all Elements to the top level of
         * the tree.
         *
         * @param modIds - Ids of modules.
         * @param gateIds - Ids of gates.
         * @param netIds - Ids of nets.
         * @param displayModulesRecursive - True to add all submodules of the given module list to the tree.
         * @param showGatesInSubmod - True to show the gates in the submodules that were added if displayModulesRecursive = true.
         */
        void setContent(QList<int> modIds, QList<int> gateIds, QList<int> netIds, bool displayModulesRecursive = false, bool showGatesInSubmod = false);

        /**
         * Updates the model's content to the given module. Convenient functions that can be used
         * instead of the more general setContent() function.
         *
         * @param mod - The module to display.
         * @param showGates - True to add gates, False to show only module hierarchy.
         * @param displayModulesRecursive - True to show
         */
        void setModule(Module* mod, bool showGates = true, bool displayModulesRecursive = true);

        // important converter methods
        /**
         * Helper method to convert between the item and its index.
         *
         * @param item - The item from which to get the index.
         * @return The index.
         */
        QModelIndex getIndexFromItem(TreeItem* item) const;

        /**
         * Helper method to convert between the index and its item.
         *
         * @param index - The index to convert.
         * @return The internal item.
         */
        TreeItem* getItemFromIndex(QModelIndex index) const;

        /**
         * Resets the model (deletes the tree).
         */
        void clear();


        //Column identifier
        static const int sNameColumn = 0;
        static const int sIdColumn = 1;
        static const int sTypeColumn = 2;

    private:
        TreeItem* mRootItem;

        //necessary because setModule uses beginResetModel (should not be called by each recursive iteration)
        void moduleRecursive(Module* mod, TreeItem* modItem,  bool showGates = true);


    };

}
