# -*- coding: utf-8 -*-

import serial
import sys

import gi
gi.require_version("Gtk", "3.0")

from gi.repository import Gtk
from gi.repository import GLib

class Ventana(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self)

        self.arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=0.1)
        self.arduino.flushInput()

        self.set_title("Termómetro Arduino")
        self.set_resizable(True)
        self.set_position(Gtk.WindowPosition.CENTER)

        self.set_size_request(200, 100)
        self.label = Gtk.Label("")
        self.add(self.label)
        self.show_all()

        self.connect("delete-event", self.__exit)

        GLib.timeout_add(200, self.update)

    def __exit(self, widget=False, event=False):
        self.arduino.close()
        Gtk.main_quit()
        sys.exit(0)

    def update(self):
        texto = self.arduino.readline().strip().replace("\n", "")
        if texto:
            self.label.set_text(texto)
        return True

if __name__=="__main__":
    Ventana()
    Gtk.main()

'''
Instalar el módulo serial para python:
    sudo apt-get install python-serial
o si vas a programar en python 3:
    sudo apt-get install python3-serial
'''