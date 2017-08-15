#ifndef CONF_H
#define CONF_H

#include <QObject>

class Configuration : public QObject
{
    Q_OBJECT
public:
    explicit Configuration(QObject *parent = nullptr);

    QString getConf();
    void setConf(QString confJson);
    bool Status;

signals:

public slots:


private:
    QString m_confJSON;
};

#endif // CONF_H
