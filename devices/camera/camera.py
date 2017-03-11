from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()

camera.start_recording('/home/pi/Documents/scripts/img/video.h264')

print("RECORDING...")
sleep(10)

camera.stop_recording()

print("SAVING VIDEO")

camera.stop_preview()
