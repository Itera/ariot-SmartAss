# EspruinoHub (https://github.com/espruino/EspruinoHub)
# Install a modern version of nodejs and nodered
sudo apt-get install build-essential python-rpi.gpio
bash <(curl -sL https://raw.githubusercontent.com/node-red/raspbian-deb-package/master/resources/update-nodejs-and-nodered)
# Get dependencies
sudo apt-get install mosquitto mosquitto-clients bluetooth bluez libbluetooth-dev libudev-dev

# Auto start node-red
sudo systemctl enable nodered.service
# Start nodered manually this one time (this creates ~/.node-red)
sudo systemctl start nodered.service
# Install the node-red UI
cd ~/.node-red && npm install node-red-contrib-ui
# Now get this repository
cd ~/
git clone https://github.com/espruino/EspruinoHub
# Install its' requirements
cd EspruinoHub
npm install

# Give Node.js access to Bluetooth
sudo setcap cap_net_raw+eip $(eval readlink -f `which node`)
# EspruinoHub install end

# Node RED Packages install
cd ~/.node-red
npm install node-red-contrib-sensortag
npm install node-red-contrib-mssql
npm install node-red-dashboard

cd 
