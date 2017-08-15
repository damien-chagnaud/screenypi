
#include <QApplication>
#include <QtCore/QUrl>
#include <QtCore/QCommandLineOption>
#include <QtCore/QCommandLineParser>
#include <QQmlContext>
#include <QWebChannel>
#include <QWebEngineView>
#include <QSettings>
#include <QFileInfo>
#include <QShortcut>
#include <QKeySequence>

#include "configuration.h"
#include "webengineviewplus.h"


const QString maintenancePage =  "qrc:/maintenace/index.html";
const QString playerPage =  "qrc:/player/index.html";

int main(int argc, char *argv[])
{
   // qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QApplication app(argc, argv);

    //COMMAND LINE Options:
    QCommandLineOption keyboardOption({{"k", "keyboard"}, "Activate virtual keyboard."});
   // QCommandLineOption cacheOption({{"c", "cache"}, "Enable cache."});
    QCommandLineOption confOption({{"c", "config"}, "Configuration file (ini)."});
    QCommandLineParser parser;

    parser.setApplicationDescription(QApplication::applicationDisplayName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(keyboardOption);
   // parser.addOption(cacheOption);
    parser.addOption(confOption);
    parser.addPositionalArgument("source","url or filename");

    QStringList arguments = app.arguments();

    #ifdef Q_OS_WINRT
        arguments.removeAt(1); // The launcher always passes in the -ServerName parameter, breaking the command line parser
    #endif

    parser.process(arguments);

    QString initialUrl = parser.positionalArguments().isEmpty() ? maintenancePage : parser.positionalArguments().first();
   //bool keyboard = parser.isSet(keyboardOption) ? true : false;

    bool confManager = false;

    //app.setAutoSipEnabled(false);




    //if(parser.isSet(cacheOption))qputenv("QML_DISABLE_DISK_CACHE", QByteArray("0"));




    WebEngineViewPlus view;
    view.setAdminURL(QUrl(QStringLiteral("qrc:/admin/index.html")));
    view.load(QUrl(initialUrl));
    view.showFullScreen();

    /* KEY SEQUENCE for Admin Page*/
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Shift+F12"), &view);
    QObject::connect(shortcut, SIGNAL(activated()), &view, SLOT(adminPage()));

    QWebChannel* channel = new QWebChannel(view.page());


    view.page()->setWebChannel(channel);

    /*1- find conf file:
        - attribute
        - localstorage
    */


    //Set Configuration:

    QString confPath = "";


    if(parser.isSet(confOption)){
        QFileInfo check_file(parser.value(confOption));
        if (check_file.exists() && check_file.isFile()) confPath = parser.value(confOption);
    }else{
        QFileInfo check_file("/etc/OpenQtKiosk/oqk.conf");
         if (check_file.exists() && check_file.isFile()) confPath = parser.value("/etc/OpenQtKiosk/oqk.conf");
    }

    Configuration *conf = new Configuration();

    if(confPath.length()>0){
        conf->Status = true;
        QString confJSON = "";

        QSettings settings(confPath);




    }else{
        conf->Status = false;
    }

    channel->registerObject(QString("Configuration"), conf);

            //.setProperty(QStringLiteral("keyboardVisible"), keyboard);
    //rootContext()->setContextProperty(QStringLiteral("keyboardVisible"), keyboard);

    //




    view.show();
    return app.exec();
}
