#!/usr/bin/python

from picamera import PiCamera
import numpy as np
from time import sleep
from PIL import Image

camera = PiCamera()
image = "/home/pi/ariot-SmartAss/devices/camera/assets/image.jpg"

def capture_image(img):
    camera.start_preview()
    sleep(2)
    camera.capture(img)
    im = Image.open(img)
    camera.stop_preview()
    return im

return capture_image(image)

# def capture_image():
#     camera.start_preview()
#     camera.resolution = (320, 240)
#     camera.framerate = 24
#     sleep(2)
#     output = np.empty((240, 320, 3), dtype=np.uint8)
#     camera.capture(output, 'rgb')
#     camera.stop_preview()
#     return output

# return capture_image()