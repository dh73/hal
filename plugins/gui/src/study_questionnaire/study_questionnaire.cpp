#include "gui/study_questionnaire/study_questionnaire.h"
#include "gui/user_action/action_study_questionnaire.h"
#include "gui/gui_utils/graphics.h"
#include "gui/main_window/main_window.h"
#include "gui/settings/settings_items/settings_item_dropdown.h"

#include <QPushButton>
#include <QPlainTextEdit>

#include <QDateTime>

#include <QDebug>

namespace hal
{
    StudyQuestionnaire* StudyQuestionnaire::inst = nullptr;
    const uint mMinInactivityTime = 5 * 60; // min inactivity time is 5 minutes
    const uint mMinFocusLostTime = 1 * 60; // min time focus was lost is 3 minutes
    const uint mMinDialogShownTime = 1 * 60; // make sure dialog is not shown again, if less then 5 minutes ago

    StudyQuestionnaire::StudyQuestionnaire(QWidget *parent)
        : QDialog(parent), mHalFocusLost(false), mLastDialogShown(0), mLastHALFocusLost(0), mLastUserActionExecutedTime(0), mDuration(0), mMainWindowActivated(true), mMacroPlay(false), mStyleInitialized(false)
    {
        // const values for icon styling
        mQuestionnaireCheckboxesIcons.insert("hal_research", QList<QString *>({&mApiIconStyle, &mApiIconPath}));
        mQuestionnaireCheckboxesIcons.insert("task_code_external", QList<QString *>({&mPythonIconStyle, &mPythonIconPath}));
        mQuestionnaireCheckboxesIcons.insert("task_explore_netlist_external", QList<QString *>({&mNetlistIconStyle, &mNetlistIconPath}));
        mQuestionnaireCheckboxesIcons.insert("task_description", QList<QString *>({&mTaskIconStyle, &mTaskIconPath}));
        mQuestionnaireCheckboxesIcons.insert("other_supplementary_material", QList<QString *>({&mPaperIconStyle, &mPaperIconPath}));
        mQuestionnaireCheckboxesIcons.insert("other_web_research", QList<QString *>({&mResearchIconStyle, &mResearchIconPath}));
        mQuestionnaireCheckboxesIcons.insert("other_break", QList<QString *>({&mBreakIconStyle, &mBreakIconPath}));

        connect(this, SIGNAL(finished(int)), this, SLOT(questionnaireClosed(int)));
        connect(MainWindow::sSettingStyle,&SettingsItemDropdown::intChanged,this,&StudyQuestionnaire::handleStyleChanged);
    }

    StudyQuestionnaire* StudyQuestionnaire::instance()
    {
        if (!StudyQuestionnaire::inst)
        {
            StudyQuestionnaire::inst = new StudyQuestionnaire;
            StudyQuestionnaire::inst->initDialog();
            StudyQuestionnaire::inst->mLastDialogShown = QDateTime::currentDateTime().toSecsSinceEpoch();
            StudyQuestionnaire::inst->mLastUserActionExecutedTime = QDateTime::currentDateTime().toSecsSinceEpoch();
        }

        return StudyQuestionnaire::inst;
    }

    void StudyQuestionnaire::initDialog()
    {
        setWindowTitle("HAL Study Questionnaire:");

        // remove questionmark from title bar, it is not implemented and only confusing
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
        mLayout = new QVBoxLayout(this);
        QString titleString = QString("No action has been taken in HAL for a while.\nTell us, if you have worked on the task outside of HAL.\nPlease select all checkboxes that apply.");
        mLayout->addWidget(new QLabel(titleString,this));

        mCheckBoxLayout = new QVBoxLayout();
        mLayout->addLayout(mCheckBoxLayout);
        addCheckBox(QString("hal_research"), QString("I did some research on the HAL Python API / read the Coding Guide."));
        addCheckBox(QString("task_code_external"), QString("I worked on the python code in an external editor."));
        addCheckBox(QString("task_explore_netlist_external"), QString("I manually explored the netlist in an external editor."));
        addCheckBox(QString("task_description"), QString("I read task related materials / the task description."));
        addCheckBox(QString("other_supplementary_material"), QString("I read supplementary materials / paper."));
        addCheckBox(QString("other_web_research"), QString("I did some web research. Please add further information."));
        addCheckBox(QString("other_break"), QString("I took a break."));

        mLayout->addWidget(new QLabel(QString("If you like, please add further information:"),this));
        mFurtherInformation = new QPlainTextEdit();
        mLayout->addWidget(mFurtherInformation);

        QPushButton* sendButton = new QPushButton("Save", this);
        mLayout->addWidget(sendButton);

        connect(sendButton, SIGNAL(clicked()), this, SLOT(accept()));
    }

    void StudyQuestionnaire::addCheckBox(QString shortName, QString description)
    {
        QCheckBox* checkBox = new QCheckBox(description, this);
        mCheckBoxLayout->addWidget(checkBox);
        mQuestionnaireCheckboxes.insert(shortName, checkBox);
    }

    void StudyQuestionnaire::setContentWidgetDeactivated(QString widgetName)
    {
        mContentWidgetsActivated.removeAll(widgetName);
        checkDialog();
    }

    void StudyQuestionnaire::setWindowDeactivated()
    {
        mMainWindowActivated = false;
        checkDialog();
    }

    void StudyQuestionnaire::setContentWidgetActivated(QString widgetName)
    {
        mContentWidgetsActivated.append(widgetName);
        checkDialog();
    }

    void StudyQuestionnaire::setWindowActivated()
    {
        mMainWindowActivated = true;
        checkDialog();
    }

    void StudyQuestionnaire::setUserActionDone(const QString &userActionName)
    {
        if(userActionName != "StudyQuestionnaire") {
            checkDialog();
            mLastUserActionExecutedTime = QDateTime::currentDateTime().toSecsSinceEpoch();
        }
    }

    void StudyQuestionnaire::setMacroPlay(const bool macroPlay_)
    {
        mMacroPlay = macroPlay_;
    }

    void StudyQuestionnaire::checkDialog()
    {
        // don't show if macro is currently executed
        if(mMacroPlay) return;

        uint curSecs = QDateTime::currentDateTime().toSecsSinceEpoch();
        uint diffSecsInactivity = curSecs - mMinInactivityTime;
        uint diffSecsFocusLost = curSecs - mMinFocusLostTime;
        uint diffSecsDialogShown = curSecs - mMinDialogShownTime;

        /**
         * if... else condition checks different scenarios
         * if main window and no other content is activated, focus lost variables will be set
         * if focus is not lost, last user action is a specific time ago and the dialog has been inactive for a while, show dialog
         * if focus was lost, but now a hal window is active, check if focus has been lost for a specific time and show dialog
         * */
        if(!mMainWindowActivated && mContentWidgetsActivated.isEmpty()) {
            mLastHALFocusLost = QDateTime::currentDateTime().toSecsSinceEpoch();
            mHalFocusLost = true;
        } else if(!mHalFocusLost && mLastUserActionExecutedTime < diffSecsInactivity && mLastDialogShown < diffSecsDialogShown) {
            mDuration = QDateTime::currentDateTime().toSecsSinceEpoch() - mLastUserActionExecutedTime;
            mLastDialogShown = QDateTime::currentDateTime().toSecsSinceEpoch();
            exec();
        } else if(mHalFocusLost) {
            mHalFocusLost = false;
            if(mLastDialogShown < diffSecsDialogShown && mLastHALFocusLost < diffSecsFocusLost)
            {
                mDuration = QDateTime::currentDateTime().toSecsSinceEpoch() - mLastHALFocusLost;
                mLastDialogShown = QDateTime::currentDateTime().toSecsSinceEpoch();
                exec();
            }
        }
    }

    void StudyQuestionnaire::questionnaireClosed(int resultCode)
    {
        mLastDialogShown = QDateTime::currentDateTime().toSecsSinceEpoch();
        if(QDialog::Accepted == resultCode) {
            QMap<QString, QCheckBox*>::iterator it;
            QStringList listCheckboxes = QStringList();
            for(it = mQuestionnaireCheckboxes.begin(); it != mQuestionnaireCheckboxes.end(); ++it) {
                QString key = it.key();
                QCheckBox* checkBox = it.value();

                if(checkBox->isChecked()) {
                    listCheckboxes.append(key);
                    checkBox->setChecked(false);
                }
            }

            ActionStudyQuestionnaire* act = new ActionStudyQuestionnaire(listCheckboxes, mFurtherInformation->toPlainText(), mDuration);
            act->exec();

            mFurtherInformation->clear();
        }
    }

    void StudyQuestionnaire::handleStyleChanged()
    {
        QMap<QString, QCheckBox*>::iterator it;
        QStringList listCheckboxes = QStringList();
        for(it = mQuestionnaireCheckboxes.begin(); it != mQuestionnaireCheckboxes.end(); ++it) {
            QString key = it.key();
            QCheckBox* checkBox = it.value();

            QList<QString *> list = mQuestionnaireCheckboxesIcons.value(key);
            checkBox->setIcon(gui_utility::getStyledSvgIcon(*list.at(0), *list.at(1)));
        }
    }

    int StudyQuestionnaire::exec()
    {
        if(!mStyleInitialized) {
            handleStyleChanged();
            mStyleInitialized = true;
        }
        return QDialog::exec();
    }

    // Icon properties from here:
    QString StudyQuestionnaire::apiIconPath() const
    {
        return mApiIconPath;
    }

    QString StudyQuestionnaire::apiIconStyle() const
    {
        return mApiIconStyle;
    }

    QString StudyQuestionnaire::breakIconPath() const
    {
        return mBreakIconPath;
    }

    QString StudyQuestionnaire::breakIconStyle() const
    {
        return mBreakIconStyle;
    }

    QString StudyQuestionnaire::netlistIconPath() const
    {
        return mNetlistIconPath;
    }

    QString StudyQuestionnaire::netlistIconStyle() const
    {
        return mNetlistIconStyle;
    }

    QString StudyQuestionnaire::paperIconPath() const
    {
        return mPaperIconPath;
    }

    QString StudyQuestionnaire::paperIconStyle() const
    {
        return mPaperIconStyle;
    }

    QString StudyQuestionnaire::pythonIconPath() const
    {
        return mPythonIconPath;
    }

    QString StudyQuestionnaire::pythonIconStyle() const
    {
        return mPythonIconStyle;
    }

    QString StudyQuestionnaire::researchIconPath() const
    {
        return mResearchIconPath;
    }

    QString StudyQuestionnaire::researchIconStyle() const
    {
        return mResearchIconStyle;
    }

    QString StudyQuestionnaire::taskIconPath() const
    {
        return mTaskIconPath;
    }

    QString StudyQuestionnaire::taskIconStyle() const
    {
        return mTaskIconStyle;
    }

    void StudyQuestionnaire::setApiIconPath(const QString& path)
    {
        mApiIconPath = path;
    }

    void StudyQuestionnaire::setApiIconStyle(const QString& style)
    {
        mApiIconStyle = style;
    }

    void StudyQuestionnaire::setBreakIconPath(const QString& path)
    {
        mBreakIconPath = path;
    }

    void StudyQuestionnaire::setBreakIconStyle(const QString& style)
    {
        mBreakIconStyle = style;
    }

    void StudyQuestionnaire::setNetlistIconPath(const QString& path)
    {
        mNetlistIconPath = path;
    }

    void StudyQuestionnaire::setNetlistIconStyle(const QString& style)
    {
        mNetlistIconStyle = style;
    }

    void StudyQuestionnaire::setPaperIconPath(const QString& path)
    {
        mPaperIconPath = path;
    }

    void StudyQuestionnaire::setPaperIconStyle(const QString& style)
    {
        mPaperIconStyle = style;
    }

    void StudyQuestionnaire::setPythonIconPath(const QString& path)
    {
        mPythonIconPath = path;
    }

    void StudyQuestionnaire::setPythonIconStyle(const QString& style)
    {
        mPythonIconStyle = style;
    }

    void StudyQuestionnaire::setResearchIconPath(const QString& path)
    {
        mResearchIconPath = path;
    }

    void StudyQuestionnaire::setResearchIconStyle(const QString& style)
    {
        mResearchIconStyle = style;
    }

    void StudyQuestionnaire::setTaskIconPath(const QString& path)
    {
        mTaskIconPath = path;
    }

    void StudyQuestionnaire::setTaskIconStyle(const QString& style)
    {
        mTaskIconStyle = style;
    }
}
