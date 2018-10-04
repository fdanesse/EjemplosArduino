# -*- coding: utf-8 -*-

import serial, time
arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=0.1)
arduino.flushInput()
while True:
    time.sleep(0.2)
    texto = arduino.readline().strip().replace("\n", "")
    if texto:
        print(texto)
arduino.close()

'''
Instalar el módulo serial para python:
    sudo apt-get install python-serial
o si vas a programar en python 3:
    sudo apt-get install python3-serial
'''