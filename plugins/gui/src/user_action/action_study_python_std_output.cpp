#include "gui/user_action/action_study_python_std_output.h"
#include "gui/user_action/user_action_manager.h"
#include <QTabWidget>
#include "gui/gui_globals.h"
#include "gui/python/python_editor.h"
#include "gui/study_questionnaire/study_questionnaire.h"

namespace hal
{
    ActionStudyPythonStdOutputFactory::ActionStudyPythonStdOutputFactory()
       : UserActionFactory("StudyPythonStdOutput") {;}

    ActionStudyPythonStdOutputFactory* ActionStudyPythonStdOutputFactory::sFactory = new ActionStudyPythonStdOutputFactory;

    UserAction* ActionStudyPythonStdOutputFactory::newAction() const
    {
        return new ActionStudyPythonStdOutput;
    }

    QString ActionStudyPythonStdOutput::tagname() const
    {
        return ActionStudyPythonStdOutputFactory::sFactory->tagname();
    }

    ActionStudyPythonStdOutput::ActionStudyPythonStdOutput(const u32 &id_, const QString &output_, const QUuid &ref_)
        : mOutput(output_), mMerged(false), mDuration(0), mRef(ref_)
    {
        if (id_)
            setObject(UserActionObject(id_,UserActionObjectType::PythonOutput));
    }

    bool ActionStudyPythonStdOutput::exec()
    {
        if (UserActionManager::instance()->isUserTriggeredAction() && mergeWithRecent())
        {
            // caller should delete this action to avoid memory leak
            mMerged = true;
            return true;
        }

        return UserAction::exec();
    }

    bool ActionStudyPythonStdOutput::mergeWithRecent()
    {
        UserActionManager* uam = UserActionManager::instance();
        Q_ASSERT(uam);
        if (uam->mActionHistory.isEmpty()) return false;
        UserAction* lastAction = uam->mActionHistory.last();
        qint64 msecSinceLastAction = uam->timeStamp() - lastAction->timeStamp();
        ActionStudyPythonStdOutput* lastPythonStdOutput = dynamic_cast<ActionStudyPythonStdOutput*>(lastAction);
        if (!lastPythonStdOutput) return false;
        lastPythonStdOutput->mTimeStamp = uam->timeStamp();
        lastPythonStdOutput->mOutput   += mOutput;
        lastPythonStdOutput->mDuration += msecSinceLastAction;

        #ifdef HAL_STUDY
            StudyQuestionnaire::instance()->setUserActionDone(tagname());
        #endif

        return true;
    }

    void ActionStudyPythonStdOutput::addToHash(QCryptographicHash& cryptoHash) const
    {
        cryptoHash.addData(mOutput.toUtf8());
    }

    void ActionStudyPythonStdOutput::writeToXml(QXmlStreamWriter& xmlOut) const
    {
        xmlOut.writeAttribute("ref", mRef.toString());
        xmlOut.writeTextElement("output", mOutput);
        if (mDuration > 0)
            xmlOut.writeTextElement("duration", QString::number(mDuration));
    }

    void ActionStudyPythonStdOutput::readFromXml(QXmlStreamReader& xmlIn)
    {
        while (xmlIn.readNextStartElement())
        {
            if (xmlIn.name() == "output")
                mOutput = xmlIn.readElementText();
            if (xmlIn.name() == "duration")
                // we don't need this value,
                // but we have to read it, to read next start element
                xmlIn.readElementText();
        }
    }
}
