#ifndef WEBENGINEVIEWPLUS_H
#define WEBENGINEVIEWPLUS_H

#include <QWebEngineView>

class WebEngineViewPlus : public QWebEngineView
{
    Q_OBJECT
public:
    explicit WebEngineViewPlus(QWebEngineView *parent = nullptr);
    void setAdminURL(QUrl  url);
signals:

public slots:
    void adminPage();

private:
    bool adminActive = false;
    QUrl activeURL;
    QUrl adminURL;
};

#endif // WEBENGINEVIEWPLUS_H
