#!/usr/bin/python

from picamera import PiCamera

camera = PiCamera()
image = "/home/pi/ariot-SmartAss/devices/camera/assets/image.jpg"
camera.capture(image)
