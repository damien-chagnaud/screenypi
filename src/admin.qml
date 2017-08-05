import QtQuick 2.7
import QtQuick.Controls 2.0
import QtWebView 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

ApplicationWindow {
    id: appContainer
    width: 1024
    height: 750
    visible: true
    visibility: "FullScreen"

    WebView {
        id: webView
        anchors.fill: parent
        url: "qrc:/admin/index.html"
    }
}
