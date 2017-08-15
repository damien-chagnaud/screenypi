#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <QObject>

class Dialogue : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Message message MEMBER m_message NOTIFY messageChanged FINAL)

public:
    enum MessageType{Info, Warning, Error};
    Q_ENUM(MessageType)

    struct Message{
        MessageType type;
        QString text;
        QString pos;
        friend bool operator==(const Message &mess1, const Message &mess2){return mess1.type==mess2.type && mess1.text==mess2.text && mess1.pos==mess2.pos;};
        friend bool operator!=(const Message &mess1, const Message &mess2){return mess1.type!=mess2.type || mess1.text!=mess2.text || mess1.pos!=mess2.pos;};
    };

    explicit Dialogue(QObject *parent = nullptr);
    void setMessage(Message &message);

signals:
    void messageChanged(Message $message);

public slots:


private:
    Message m_message;
};

#endif // DIALOGUE_H
