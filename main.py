import matplotlib.image as img
from PIL import Image, ImageDraw, ImageGrab
import numpy as np
import serial
import time
from led import get_colors, max_brightness
import random

ser = serial.Serial('COM3', 9600, timeout=5)
print('Serial opened')
time.sleep(3)

while True:

    color_list = get_colors(numcolors=5)
    r, g, b = random.choice(color_list)
    i = 0
    while r < 100 and g < 100 and b < 100:
        r, g, b = random.choice(color_list)
        i += 1
        if i == 25:
            r, g, b = 255, 255, 255

    if True:
        r, g, b = max_brightness(r, g, b)

    r = '0' + hex(r)[2:]
    g = '0' + hex(g)[2:]
    b = '0' + hex(b)[2:]
    # print(r, g, b)
    msg = (r[len(r) - 2:len(r)] + g[len(g) - 2:len(g)] + b[len(b) - 2:len(b)]).upper()
    # print(msg)
    msg = msg.encode('utf-8')
    # print(msg)

    ser.write(msg)
    time.sleep(3)

while False:
    msg = input('Enter hexadecimal RGB code: ')
    ser.write(msg.encode('utf-8'))
