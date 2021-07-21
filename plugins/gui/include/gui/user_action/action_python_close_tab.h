#pragma once
#include "user_action.h"

namespace hal
{
    /**
     * @ingroup user_action
     */
    class ActionPythonCloseTab : public UserAction
    {
        u32 mPythonCodeEditorId;
        QString mPythonCodeEditorContent = "";
        QString mPythonCodeEditorTabText = "";
        int mLastTextCursorPosition;
    public:
        ActionPythonCloseTab(const u32& id_ = 0);
        QString tagname() const override;
        bool exec() override;
        void writeToXml(QXmlStreamWriter& xmlOut) const override;
        void readFromXml(QXmlStreamReader& xmlIn) override;
        void addToHash(QCryptographicHash& cryptoHash) const override;
        void setPlaintext(QString plaintext_);
        void setTabText(QString tabtext_);
        void setLastTextCursorPosition(int lastTextCursorPosition);
    };

    /**
     * @ingroup user_action
     */
    class ActionPythonCloseTabFactory : public UserActionFactory
    {
    public:
        ActionPythonCloseTabFactory();
        UserAction* newAction() const;
        static ActionPythonCloseTabFactory* sFactory;
    };
}
