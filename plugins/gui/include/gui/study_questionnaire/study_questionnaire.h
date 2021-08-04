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
        Q_PROPERTY(QString apiIconPath READ apiIconPath WRITE setApiIconPath)
        Q_PROPERTY(QString apiIconStyle READ apiIconStyle WRITE setApiIconStyle)
        Q_PROPERTY(QString breakIconPath READ breakIconPath WRITE setBreakIconPath)
        Q_PROPERTY(QString breakIconStyle READ breakIconStyle WRITE setBreakIconStyle)
        Q_PROPERTY(QString netlistIconPath READ netlistIconPath WRITE setNetlistIconPath)
        Q_PROPERTY(QString netlistIconStyle READ netlistIconStyle WRITE setNetlistIconStyle)
        Q_PROPERTY(QString paperIconPath READ paperIconPath WRITE setPaperIconPath)
        Q_PROPERTY(QString paperIconStyle READ paperIconStyle WRITE setPaperIconStyle)
        Q_PROPERTY(QString pythonIconPath READ pythonIconPath WRITE setPythonIconPath)
        Q_PROPERTY(QString pythonIconStyle READ pythonIconStyle WRITE setPythonIconStyle)
        Q_PROPERTY(QString researchIconPath READ researchIconPath WRITE setResearchIconPath)
        Q_PROPERTY(QString researchIconStyle READ researchIconStyle WRITE setResearchIconStyle)
        Q_PROPERTY(QString taskIconPath READ taskIconPath WRITE setTaskIconPath)
        Q_PROPERTY(QString taskIconStyle READ taskIconStyle WRITE setTaskIconStyle)
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

        void handleStyleChanged();

        // =====================================================================
        //   Q_PROPERTY functions
        // =====================================================================

        /** @name Q_PROPERTY Functions
         */
        ///@{

        /**
         * Q_PROPERTY READ function for the 'study api'-icon path.
         *
         * @returns the 'study api'-icon path
         */
        QString apiIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study api'-icon style.
         *
         * @returns the 'study api'-icon style
         */
        QString apiIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study break'-icon path.
         *
         * @returns the 'study break'-icon path
         */
        QString breakIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study break'-icon style.
         *
         * @returns the 'study break'-icon style
         */
        QString breakIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study netlist'-icon path.
         *
         * @returns the 'study netlist'-icon path
         */
        QString netlistIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study netlist'-icon style.
         *
         * @returns the 'study netlist'-icon style
         */
        QString netlistIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study paper'-icon path.
         *
         * @returns the 'study paper'-icon path
         */
        QString paperIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study paper'-icon style.
         *
         * @returns the 'study paper'-icon style
         */
        QString paperIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study python'-icon path.
         *
         * @returns the 'study python'-icon path
         */
        QString pythonIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study python'-icon style.
         *
         * @returns the 'study python'-icon style
         */
        QString pythonIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study research'-icon path.
         *
         * @returns the 'study research'-icon path
         */
        QString researchIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study research'-icon style.
         *
         * @returns the 'study research'-icon style
         */
        QString researchIconStyle() const;

        /**
         * Q_PROPERTY READ function for the 'study task'-icon path.
         *
         * @returns the 'study task'-icon path
         */
        QString taskIconPath() const;

        /**
         * Q_PROPERTY READ function for the 'study task'-icon style.
         *
         * @returns the 'study task'-icon style
         */
        QString taskIconStyle() const;

        /**
         * Q_PROPERTY WRITE function for the 'study api'-icon path.
         *
         * @param path - the new path
         */
        void setApiIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study api'-icon style.
         *
         * @param style - the new style
         */
        void setApiIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study break'-icon path.
         *
         * @param path - the new path
         */
        void setBreakIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study break'-icon style.
         *
         * @param style - the new style
         */
        void setBreakIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study netlist'-icon path.
         *
         * @param path - the new path
         */
        void setNetlistIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study netlist'-icon style.
         *
         * @param style - the new style
         */
        void setNetlistIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study Paper'-icon path.
         *
         * @param path - the new path
         */
        void setPaperIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study Paper'-icon style.
         *
         * @param style - the new style
         */
        void setPaperIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study Python'-icon path.
         *
         * @param path - the new path
         */
        void setPythonIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study Python'-icon style.
         *
         * @param style - the new style
         */
        void setPythonIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study Research'-icon path.
         *
         * @param path - the new path
         */
        void setResearchIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study Research'-icon style.
         *
         * @param style - the new style
         */
        void setResearchIconStyle(const QString& style);

        /**
         * Q_PROPERTY WRITE function for the 'study Task'-icon path.
         *
         * @param path - the new path
         */
        void setTaskIconPath(const QString& path);

        /**
         * Q_PROPERTY WRITE function for the 'study Task'-icon style.
         *
         * @param style - the new style
         */
        void setTaskIconStyle(const QString& style);
        ///@}

    public Q_SLOTS:
        virtual int exec() override;

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
        uint mDuration;
        bool mMainWindowActivated;
        bool mMacroPlay;
        bool mStyleInitialized;
        QStringList mContentWidgetsActivated;
        QMap<QString,QCheckBox*> mQuestionnaireCheckboxes;
        QPlainTextEdit* mFurtherInformation;

        QString mApiIconStyle;
        QString mApiIconPath;

        QString mBreakIconStyle;
        QString mBreakIconPath;

        QString mNetlistIconStyle;
        QString mNetlistIconPath;

        QString mPaperIconStyle;
        QString mPaperIconPath;

        QString mPythonIconStyle;
        QString mPythonIconPath;

        QString mResearchIconStyle;
        QString mResearchIconPath;

        QString mTaskIconStyle;
        QString mTaskIconPath;

        QMap<QString,QList<QString *>> mQuestionnaireCheckboxesIcons;
    private Q_SLOTS:
        void questionnaireClosed(int resultCode);
    };
}
