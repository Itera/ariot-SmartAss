from flask import Flask
from flask import send_file
from picamera import PiCamera
from time import sleep

app = Flask(__name__)
camera = PiCamera()
image = "./assets/image.jpg"


def capture_image(img):
    camera.start_preview()
    sleep(2)
    camera.capture(img)
    camera.stop_preview()


@app.route('/image')
def get_image():
    capture_image(image)
    return send_file(image, mimetype='image/gif')

if __name__ == '__main__':
    app.run()
