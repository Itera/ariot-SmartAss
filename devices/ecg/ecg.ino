/******************************************************************************
  Heart_Rate_Display.ino
  Demo Program for AD8232 Heart Rate sensor.
  Casey Kuhns @ SparkFun Electronics
  6/27/2014
  https://github.com/sparkfun/AD8232_Heart_Rate_Monitor

  The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
  how to create an ECG with real time display.  The display is using Processing.
  This sketch is based heavily on the Graphing Tutorial provided in the Arduino
  IDE. http://www.arduino.cc/en/Tutorial/Graph

  Resources:
  This program requires a Processing sketch to view the data in real time.

  Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Pro 3.3V/8MHz
  AD8232 Heart Monitor Version: 1.0

  This code is beerware. If you see me (or any other SparkFun employee) at the
  local pub, and you've found our code helpful, please buy us a round!

  Distributed as-is; no warranty is given.
******************************************************************************/

#include <dummy.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define LO_PLUSS D3
#define LO_MNUS D2
#define ALERT_BUTTON D1
#define VIAGRA RISING

const char* ssid = "wlankonferanse";
const char* password = "Voksen2013";
const char* mqtt_server = "10.59.2.228";
volatile bool alertTriggered = false;

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  
  pinMode(LO_PLUSS, INPUT); // Setup for leads off detection LO +
  pinMode(LO_MNUS, INPUT); // Setup for leads off detection LO -
  pinMode(ALERT_BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(ALERT_BUTTON), isr_alert, VIAGRA);

  setupWifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if(alertTriggered) {
    Serial.println("Alert button pushed, sending message");
    client.publish("nodemcu/alert", "Alert button has been pushed");
    alertTriggered = false;
  }

  if ((digitalRead(LO_PLUSS) == 1) || (digitalRead(LO_MNUS) == 1)) {
    Serial.println("!");
    client.publish("nodemcu/ecg", "!");
  }
  else {
    // send the value of analog input 0:
    char* str = new char[8];
    int val = analogRead(A0);
    Serial.println(val);
    sprintf(str, "%d", val);
    client.publish("nodemcu/ecg", str);
  }
  
  //Wait for a bit to keep serial data from saturating
  assembly_delay(1);
}

void setupWifi() {
  delay(10);
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("keynote-client")) {
      Serial.println("connected");

      client.publish("nodemcu/status", "Connected");      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

static inline unsigned get_ticks()
{
 unsigned r;
 asm volatile ("rsr %0, ccount" : "=r"(r));
 return r;
}

void assembly_delay(unsigned mega_ticks){
 unsigned start = get_ticks();
 while(get_ticks() < start + (mega_ticks * 1000000)) {}
}//80MHz: ticks -> 12.5 ns, kilo_ticks -> 12.5 us, mega_ticks -> 12.5 ms

void isr_alert() {
  alertTriggered = true;
}


