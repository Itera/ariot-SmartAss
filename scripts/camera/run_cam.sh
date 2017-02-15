
echo 'Running camera'
ssh pi@172.16.202.130 'python3' < camera.py
echo 'Retrieving video'
scp pi@172.16.202.130:/home/pi/Documents/scripts/img/video.h264 .
echo 'Playing video'
cvlc video.h264 &
