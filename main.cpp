#include <QCoreApplication>
// Thu vien Qt cung cap giao tiep vs DBus
#include <QtDBus/QtDBus>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Tên service và path object
    QString serviceName = "com.example.Service"; // Ten cua DBus service
    QString objectPath = "/com/example/Service"; // objectPath cua doi tuong DBus
    QString interfaceName = "com.example.ServiceInterface";

    // Tạo proxy object D-Bus qua QDbusInterface, QDBusConnection::sessionBus() la ket noi vs session bus tren he thong
    QDBusInterface iface(serviceName, objectPath, interfaceName, QDBusConnection::sessionBus());

    // Kiem tra proxy object da ket noi thanh cong DBus
    if (!iface.isValid()) {
        qDebug() << "Failed to connect to D-Bus service.";
        return 1;
    }

    // Gọi method say_hello
    QDBusReply<QString> reply = iface.call("chao_em"); // Goi phuong thuc chao_em

    // QDBusReply chua ket qua tra ve tu service DBus
    if (reply.isValid()) {
        qDebug() << "Response from Python service:" << reply.value();
    } else {
        qDebug() << "D-Bus call failed:" << reply.error().message();
    }

    return 0;
}
