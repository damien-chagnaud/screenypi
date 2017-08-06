#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebView/QtWebView>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QGuiApplication app(argc, argv);
    QtWebView::initialize();

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

//A) Load Conf files


//B) Load and configure RESTFUl system


//C) configure player


//D) Load player

    engine.load(QUrl(QStringLiteral("qrc:/admin.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
