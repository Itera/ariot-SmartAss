#!/usr/bin/python

from picamera import PiCamera

resolutionX = 320
resolutionY = 240

# buffer
filePath = "/home/pi/ariot-SmartAss/devices/camera/assets/image.jpg"
fileType = "jpeg"
picfile = open(filePath, 'wb')

# take the photo
camera = PiCamera()
camera.resolution = (resolutionX, resolutionY)
camera.capture(picfile, fileType)

# flush the buffer
picfile.close()