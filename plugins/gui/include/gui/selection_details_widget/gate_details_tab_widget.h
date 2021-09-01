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

#include "gui/selection_details_widget/details_tab_widget.h"
#include "hal_core/netlist/gate_library/gate_type.h"

namespace hal
{
    class Gate;
    class DetailsFrameWidget;
    class GateInfoTable;
    class GatePinTree;

    class GateDetailsTabWidget : public DetailsTabWidget
    {
        Q_OBJECT

    public:

        /**
         * The constructor.
         *
         * @param parent - The widget's parent.
         */
         GateDetailsTabWidget(QWidget* parent = nullptr);

        /**
         * Sets the gate which details are shown in the tabs and various widgets.
         *
         * @param gate - The gate.
         */
        void setGate(Gate* gate);

    private:
        /**
         * Shows the tab "(LUT / FF / LATCH)" and their corresponding type widgets depending on which gate type property is provided.
         * 
         * @param gateTypeProperty - The property.
         */
        void showMultiTab(GateTypeProperty gateTypeProperty);

        /**
         * Hides the "(LUT / FF / LATCH)" tab.
         *
         */
        void hideMultiTab();

        /**
         * Checks wheter the "(LUT / FF / LATCH)" tab must be hidden or shown depending on gate and changes the visibility of the tab depending on the result of the check.
         *
         * @param gate - The gate to check.
         */
        void hideOrShorMultiTab(Gate* gate);

        bool mMultiTabVisible = true; 
        int mMultiTabIndex;
        QWidget* mMultiTabContent;

        //general tab
        GateInfoTable* mGateInfoTable;
        DetailsFrameWidget* mGateInformationFrame;
        //add groupings-widget in this line
        DetailsFrameWidget* mGroupingsFrame;

        //pins tab
        GatePinTree* mPinsTree;
        DetailsFrameWidget* mPinsFrame;

        //ff tab
        //put ff-widget in this line
        DetailsFrameWidget* mFfFrame;

        //latch tab
        //put latch-widget in this line
        DetailsFrameWidget* mLatchFrame;

        //lut tab
        //put lut-widget in this line
        DetailsFrameWidget* mLutFrame;
        //put truthtable-widget in this line
        DetailsFrameWidget* mTruthTableFrame;

        //boolean function tab
        //put boolean-function in this line
        DetailsFrameWidget* mBooleanFunctionsFrame;

        //data tab
        //put data-table in this line
        DetailsFrameWidget* mDataFrame;
    };
}
