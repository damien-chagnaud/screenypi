#include "dialogue.h"

Dialogue::Dialogue(QObject *parent) : QObject(parent)
{

}

void Dialogue::setMessage(Message &message)
{
    if(message == m_message) return;
    m_message = message;
    emit messageChanged(m_message);
}
