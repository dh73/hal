#include "gui/user_action/action_study_questionnaire.h"

namespace hal
{
    ActionStudyQuestionnaireFactory::ActionStudyQuestionnaireFactory()
       : UserActionFactory("StudyQuestionnaire") {;}

    ActionStudyQuestionnaireFactory* ActionStudyQuestionnaireFactory::sFactory = new ActionStudyQuestionnaireFactory;

    UserAction* ActionStudyQuestionnaireFactory::newAction() const
    {
        return new ActionStudyQuestionnaire;
    }

    QString ActionStudyQuestionnaire::tagname() const
    {
        return ActionStudyQuestionnaireFactory::sFactory->tagname();
    }

    ActionStudyQuestionnaire::ActionStudyQuestionnaire(QStringList checkedBoxes_, QString furtherInformation_) :
        mCheckedBoxes(checkedBoxes_), mFurtherInformation(furtherInformation_)
    { }

    void ActionStudyQuestionnaire::addToHash(QCryptographicHash& cryptoHash) const
    {

        cryptoHash.addData(mCheckedBoxes.join(",").toUtf8());
        cryptoHash.addData(mFurtherInformation.toUtf8());
    }

    void ActionStudyQuestionnaire::writeToXml(QXmlStreamWriter& xmlOut) const
    {
        xmlOut.writeTextElement("checkboxes", mCheckedBoxes.join(",").toUtf8());
        xmlOut.writeTextElement("furtherinformation", mFurtherInformation);
    }

    void ActionStudyQuestionnaire::readFromXml(QXmlStreamReader& xmlIn)
    {
        while (xmlIn.readNextStartElement())
        {
            if (xmlIn.name() == "checkboxes")
                mCheckedBoxes = xmlIn.readElementText().split(",");
            if (xmlIn.name() == "furtherinformation")
                mFurtherInformation = xmlIn.readElementText();
        }
    }
}
