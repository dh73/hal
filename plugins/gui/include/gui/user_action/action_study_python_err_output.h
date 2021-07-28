#pragma once
#include "user_action.h"

#include <QUuid>

namespace hal
{
    /**
     * @ingroup user_action
     */
    class ActionStudyPythonErrOutput : public UserAction
    {
        QString mOutput;

        bool mMerged;

        qint64 mDuration;

        // merge with previous action if recent text change in event queue
        bool mergeWithRecent();

        // maximum duration in msec for single text change
        static qint64 sRecentOutputMsec;

        QUuid mRef;
    public:
        ActionStudyPythonErrOutput(const u32& id_ = 0, const QString& output_ = QString(), const QUuid& ref_ = QUuid());
        QString tagname() const override;
        bool exec() override;
        void writeToXml(QXmlStreamWriter& xmlOut) const override;
        void readFromXml(QXmlStreamReader& xmlIn) override;
        void addToHash(QCryptographicHash& cryptoHash) const override;

        // needs to be deleted by caller since action was merged and not executed
        bool wasMergedWithRecent() const {return mMerged; }
    };

    /**
     * @ingroup user_action
     */
    class ActionStudyPythonErrOutputFactory : public UserActionFactory
    {
    public:
        ActionStudyPythonErrOutputFactory();
        UserAction* newAction() const;
        static ActionStudyPythonErrOutputFactory* sFactory;
    };
}
