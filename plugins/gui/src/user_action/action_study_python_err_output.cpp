#include "gui/user_action/action_study_python_err_output.h"
#include "gui/user_action/user_action_manager.h"
#include <QTabWidget>
#include "gui/gui_globals.h"
#include "gui/python/python_editor.h"
#include "gui/study_questionnaire/study_questionnaire.h"

namespace hal
{
    ActionStudyPythonErrOutputFactory::ActionStudyPythonErrOutputFactory()
       : UserActionFactory("StudyPythonErrOutput") {;}

    ActionStudyPythonErrOutputFactory* ActionStudyPythonErrOutputFactory::sFactory = new ActionStudyPythonErrOutputFactory;

    UserAction* ActionStudyPythonErrOutputFactory::newAction() const
    {
        return new ActionStudyPythonErrOutput;
    }

    QString ActionStudyPythonErrOutput::tagname() const
    {
        return ActionStudyPythonErrOutputFactory::sFactory->tagname();
    }

    ActionStudyPythonErrOutput::ActionStudyPythonErrOutput(const u32 &id_, const QString &output_, const QUuid &ref_)
        : mOutput(output_), mMerged(false), mDuration(0), mRef(ref_)
    {
        if (id_)
            setObject(UserActionObject(id_,UserActionObjectType::PythonOutput));
    }

    bool ActionStudyPythonErrOutput::exec()
    {
        if (UserActionManager::instance()->isUserTriggeredAction() && mergeWithRecent())
        {
            // caller should delete this action to avoid memory leak
            mMerged = true;
            return true;
        }

        return UserAction::exec();
    }

    bool ActionStudyPythonErrOutput::mergeWithRecent()
    {
        UserActionManager* uam = UserActionManager::instance();
        Q_ASSERT(uam);
        if (uam->mActionHistory.isEmpty()) return false;
        UserAction* lastAction = uam->mActionHistory.last();
        qint64 msecSinceLastAction = uam->timeStamp() - lastAction->timeStamp();
        ActionStudyPythonErrOutput* lastPythonErrOutput = dynamic_cast<ActionStudyPythonErrOutput*>(lastAction);
        if (!lastPythonErrOutput) return false;
        lastPythonErrOutput->mTimeStamp = uam->timeStamp();
        lastPythonErrOutput->mOutput   += mOutput;
        lastPythonErrOutput->mDuration += msecSinceLastAction;

        #ifdef HAL_STUDY
            StudyQuestionnaire::instance()->setUserActionDone(tagname());
        #endif

        return true;
    }

    void ActionStudyPythonErrOutput::addToHash(QCryptographicHash& cryptoHash) const
    {
        cryptoHash.addData(mOutput.toUtf8());
    }

    void ActionStudyPythonErrOutput::writeToXml(QXmlStreamWriter& xmlOut) const
    {
        xmlOut.writeAttribute("ref", mRef.toString());
        xmlOut.writeTextElement("output", mOutput);
        if (mDuration > 0)
            xmlOut.writeTextElement("duration", QString::number(mDuration));
    }

    void ActionStudyPythonErrOutput::readFromXml(QXmlStreamReader& xmlIn)
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
