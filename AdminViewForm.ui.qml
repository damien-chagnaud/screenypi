import QtQuick 2.4
import QtQuick.Dialogs.qml 1.0

Item {
    width: 400
    height: 400

    Grid {
        id: grid
        x: 0
        y: 0
        width: 400
        height: 400
        rows: 4
        columns: 3
    }

    Rectangle {
        id: rectangle
        x: 17
        y: 38
        width: 146
        height: 55
        color: "#ffffff"
    }
}
