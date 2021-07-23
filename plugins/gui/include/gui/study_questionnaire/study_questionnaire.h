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
#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QCheckBox>
#include <QMap>
#include <QPlainTextEdit>

namespace hal
{
    /**
     * @ingroup user_action
     * @brief Handles and manages study questionnaire.
     *
     * The StudyQuestionnaire class manages the study questionnaire, which is shown after a specific time without actions in HAL. It is implemented as a
     * singleton pattern.
     */
    class StudyQuestionnaire : public QDialog
    {
        Q_OBJECT
    public:

        /**
         * Get the singleton instance.
         *
         * @return The singleton instance.
         */
        static StudyQuestionnaire* instance();

        /**
         * Set time when content widget window has been deactivated.
         */
        void setContentWidgetDeactivated(QString widgetName);

        /**
         * Set time when HAL main window has been deactivated.
         */
        void setWindowDeactivated();

        /**
         * Set time when content widget window has been activated.
         */
        void setContentWidgetActivated(QString widgetName);

        /**
         * Set time when HAL main window has been activated.
         */
        void setWindowActivated();

        /**
         * Inform study questionnaire instance that a user action has been executed.
         */
        void setUserActionDone(const QString& userActionName);

        void setMacroPlay(const bool macroPlay_);

    private:
        StudyQuestionnaire(QWidget *parent = nullptr);

        static StudyQuestionnaire* inst;

        void initDialog();
        void checkDialog();
        void addCheckBox(QString shortName, QString description);

        QVBoxLayout* mLayout;
        QVBoxLayout* mCheckBoxLayout;

        bool mHalFocusLost;
        uint mLastDialogShown;
        uint mLastHALFocusLost;
        uint mLastUserActionExecutedTime;
        bool mMainWindowActivated;
        bool mMacroPlay;
        QStringList mContentWidgetsActivated;
        QMap<QString,QCheckBox*> mQuestionnaireCheckboxes;
        QPlainTextEdit* mFurtherInformation;
    private Q_SLOTS:
        void questionnaireClosed(int resultCode);
    };
}
