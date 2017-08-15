#include "network.h"

Network::Network(QObject *parent) : QObject(parent)//https://cgit.freedesktop.org/NetworkManager/NetworkManager/tree/examples/C/qt/
{
   /* void listConnections(QDBusInterface& interface) {
        // Call ListConnections D-Bus method
        QDBusReply<QList<QDBusObjectPath> > result = interface.call("ListConnections");
        foreach (const QDBusObjectPath& connection, result.value()) {
            qDebug() << connection.path();
        }
    }

    int main() {
        // Create a D-Bus proxy; NM_DBUS_* defined in NetworkManager.h
        QDBusInterface interface(
            NM_DBUS_SERVICE,
            NM_DBUS_PATH_SETTINGS,
            NM_DBUS_INTERFACE_SETTINGS,
            QDBusConnection::systemBus());

        listConnections(interface);
    }*/
}
