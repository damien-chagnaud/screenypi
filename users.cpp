#include <QSettings>
#include "users.h"

Users::Users(QObject *parent) : QObject(parent)
{

}


//QDateTime::currentMSecsSinceEpoch()

bool Users::credential(QString login, QString passwd)
{
    QSettings settings;

    if(settings.value("adminLogin")==login && settings.value("adminPassword")==passwd){
        return true;
        m_session.activ = true;
        m_session.login = login;
        m_session.type = Admin;

    }else if(settings.value("userLogin")==login && settings.value("userPassword")==passwd){
        m_session.activ = true;
        m_session.login = login;
        m_session.type = User;
        return true;
    }else{
        return false;
    }


}

bool Users::disconnect(){
    m_session.activ = false;
    m_session.login = "";
    m_session.type = Null;

}
