#!/usr/bin/python

from picamera import PiCamera
from time import sleep

camera = PiCamera()
image = "/home/pi/ariot-SmartAss/devices/camera/assets/image.jpg"

def capture_image(img):
    camera.start_preview()
    sleep(2)
    camera.capture(img)
    camera.stop_preview()

capture_image(image)
