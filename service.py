# service.py
import dbus
import dbus.service
import dbus.mainloop.glib
from gi.repository import GLib

class ExampleService(dbus.service.Object):
    def __init__(self, bus, name):
        super().__init__(bus, '/com/example/Service')

    @dbus.service.method('com.example.ServiceInterface',
                         in_signature='', out_signature='s')
    def chao_em(self):
        return "Hello anh yeu em from python!"

def main():
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True) # Thiet lap vong lap GLib la vong lặp chính cho Dbus
    bus = dbus.SessionBus()
    name = dbus.service.BusName('com.example.Service', bus)
    service = ExampleService(bus, '/com/example/Service')
    loop = GLib.MainLoop()
    print("Python D-Bus service running...")
    loop.run()

if __name__ == '__main__':
    main()

# Vòng lặp GLib (GLib MainLoop) giữ cho chương trình chạy 
# và sẵn sàng xử lý các yêu cầu từ các ứng dụng khác thông qua D-Bus.
