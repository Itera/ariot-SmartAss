NodeMCU
======

OS X:
----

You will need to install the SiLabs 
[serial driver for the chip](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx) 
([direct link](https://www.silabs.com/Support%20Documents/Software/Mac_OSX_VCP_Driver.zip))
[source](https://github.com/nodemcu/nodemcu-devkit/wiki/Getting-Started-on-OSX)

Arduino:
------

Files > Preferences
Paste url into Additional Boards Manager URLs: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`

Tools > Board > Boards Manager
Install esp8266 by esp8266 community

Tools > Board > NodeMCU 1.0


Usage:
-----

### Pins:

* Analog: A0 (lower right with USB facing up)
* I2C using GPIO 1 and 2: D3 (SCL), D4 (SDA) `Wire.begin(2,0);`
