#pragma once
#include "user_action.h"

#include <QUuid>

namespace hal
{
    /**
     * @ingroup user_action
     */
    class ActionPythonConsoleCommand : public UserAction
    {
        QString mInput;
        bool mMultipleExpressions;
        QUuid mRef;
    public:
        ActionPythonConsoleCommand(const QString& input_ = QString(), const bool& multipleExpressions_ = false);
        QString tagname() const override;
        bool exec() override;
        void writeToXml(QXmlStreamWriter& xmlOut) const override;
        void readFromXml(QXmlStreamReader& xmlIn) override;
        void addToHash(QCryptographicHash& cryptoHash) const override;
    };

    /**
     * @ingroup user_action
     */
    class ActionPythonConsoleCommandFactory : public UserActionFactory
    {
    public:
        ActionPythonConsoleCommandFactory();
        UserAction* newAction() const;
        static ActionPythonConsoleCommandFactory* sFactory;
    };
}
