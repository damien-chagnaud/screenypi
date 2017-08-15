#ifndef USERS_H
#define USERS_H

#include <QObject>

class Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = nullptr);

    enum userType{Admin, User, Null};
    Q_ENUM(userType)



    struct Session{
        bool activ;
        QString login;
        userType type;
        //friend bool operator==(const Session &mess1, const Message &mess2){return mess1.type==mess2.type && mess1.text==mess2.text && mess1.pos==mess2.pos;};
        //friend bool operator!=(const Message &mess1, const Message &mess2){return mess1.type!=mess2.type || mess1.text!=mess2.text || mess1.pos!=mess2.pos;};
    };

    bool credential(QString login, QString passwd);

signals:
    void timeOut();

public slots:
    //delete sessions by token:
    bool disconnect();


private:

    Session m_session;

};

#endif // USERS_H
