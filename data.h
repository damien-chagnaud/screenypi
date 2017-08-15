#ifndef DATA_H
#define DATA_H

#include <QObject>

class data : public QObject
{
    Q_OBJECT
public:
    explicit data(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATA_H