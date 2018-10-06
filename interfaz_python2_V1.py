# -*- coding: utf-8 -*-

'''
Interfaz de consola que recibe y muestra los datos que envía el brick al puerto serial
'''

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
