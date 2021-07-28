#include "gui/user_action/action_python_console_command.h"
#include "gui/gui_globals.h"
#include "gui/python/python_editor.h"

namespace hal
{
    ActionPythonConsoleCommandFactory::ActionPythonConsoleCommandFactory()
       : UserActionFactory("PythonConsoleCommand") {;}

    ActionPythonConsoleCommandFactory* ActionPythonConsoleCommandFactory::sFactory = new ActionPythonConsoleCommandFactory;

    UserAction* ActionPythonConsoleCommandFactory::newAction() const
    {
        return new ActionPythonConsoleCommand;
    }

    QString ActionPythonConsoleCommand::tagname() const
    {
        return ActionPythonConsoleCommandFactory::sFactory->tagname();
    }

    ActionPythonConsoleCommand::ActionPythonConsoleCommand(const QString& input_, const bool& multipleExpressions_)
        : mInput(input_), mMultipleExpressions(multipleExpressions_)
    {
        mWaitForReady = true;

        mRef = QUuid::createUuid();
    }

    bool ActionPythonConsoleCommand::exec()
    {
        gPythonContext->setRefLastExecution(mRef);
        gPythonContext->interpret(mInput, mMultipleExpressions);
        return UserAction::exec();
    }

    void ActionPythonConsoleCommand::addToHash(QCryptographicHash& cryptoHash) const
    {
        cryptoHash.addData(mInput.toUtf8());
    }

    void ActionPythonConsoleCommand::writeToXml(QXmlStreamWriter& xmlOut) const
    {
        xmlOut.writeAttribute("ref", mRef.toString());
        xmlOut.writeTextElement("command", mInput);
        xmlOut.writeTextElement("multipleexpressions", QString::number(mMultipleExpressions));
    }

    void ActionPythonConsoleCommand::readFromXml(QXmlStreamReader& xmlIn)
    {
        while (xmlIn.readNextStartElement())
        {
            if (xmlIn.name() == "command")
                mInput = xmlIn.readElementText();
            if (xmlIn.name() == "multipleexpressions")
                mMultipleExpressions = xmlIn.readElementText().toInt();
        }
    }
}
