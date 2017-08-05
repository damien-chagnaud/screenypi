#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebView/QtWebView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtWebView::initialize();

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();


   // engine.rootContext()->setContextProperty(QStringLiteral("initialUrl"), initialUrl);

    engine.load(QUrl(QStringLiteral("qrc:/admin.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
