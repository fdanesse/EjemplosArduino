# -*- coding: utf-8 -*-

import serial
import time
import sys

arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=0.1)
arduino.flushInput()

while True:
    time.sleep(0.2)
    try:
        texto = arduino.readline().strip().replace("\n", "")
        if texto:
            print(texto)
    except KeyboardInterrupt:
        print("Cerrando el programa...")
        break
    except serial.SerialException:
        print('Conexión perdida.')  
        break
    except IOError:
        print('Error de Entrada/Salida')
        break

arduino.close()
sys.exit()

'''
Instalar el módulo serial para python:
    sudo apt-get install python-serial
o si vas a programar en python 3:
    sudo apt-get install python3-serial
'''