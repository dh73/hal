#include "gui/user_action/action_python_close_tab.h"
#include "gui/user_action/action_python_new_tab.h"
#include "gui/user_action/action_python_text_changed.h"
#include "gui/user_action/user_action_compound.h"
#include "gui/gui_globals.h"
#include "gui/python/python_editor.h"

namespace hal
{
    ActionPythonCloseTabFactory::ActionPythonCloseTabFactory()
       : UserActionFactory("PythonCloseTab") {;}

    ActionPythonCloseTabFactory* ActionPythonCloseTabFactory::sFactory = new ActionPythonCloseTabFactory;

    UserAction* ActionPythonCloseTabFactory::newAction() const
    {
        return new ActionPythonCloseTab;
    }

    QString ActionPythonCloseTab::tagname() const
    {
        return ActionPythonCloseTabFactory::sFactory->tagname();
    }

    ActionPythonCloseTab::ActionPythonCloseTab(const u32 &id_)
        : mPythonCodeEditorId(id_)
    {
        if (id_)
            setObject(UserActionObject(id_,UserActionObjectType::PythonCodeEditor));
    }

    bool ActionPythonCloseTab::exec()
    {
        // first discard tab
        gContentManager->getPythonEditorWidget()->execDiscardTab(mPythonCodeEditorId);

        // then create undo actions
        UserActionCompound* act = new UserActionCompound;
        act->setUseCreatedObject();
        ActionPythonNewTab* undoCreate = new ActionPythonNewTab(mPythonCodeEditorId);
        act->addAction(undoCreate);
        ActionPythonTextChanged* undoTextChange = new ActionPythonTextChanged(mPythonCodeEditorId, "", mPythonCodeEditorContent);
        act->addAction(undoTextChange);
        mUndoAction = act;

        return UserAction::exec();
    }

    void ActionPythonCloseTab::addToHash(QCryptographicHash& cryptoHash) const
    {
        cryptoHash.addData(QByteArray::number(mPythonCodeEditorId));
    }

    void ActionPythonCloseTab::writeToXml(QXmlStreamWriter& xmlOut) const
    {
        xmlOut.writeTextElement("uid", QString::number(mPythonCodeEditorId));
    }

    void ActionPythonCloseTab::readFromXml(QXmlStreamReader& xmlIn)
    {
        while (xmlIn.readNextStartElement())
        {
            if (xmlIn.name() == "uid")
                mPythonCodeEditorId = xmlIn.readElementText().toInt();
        }
    }

    void ActionPythonCloseTab::setPlaintext(QString plaintext_)
    {
        mPythonCodeEditorContent = plaintext_;
    }
}
