/***************************************************
  Adafruit MQTT Library ESP8266 Example

  Must use ESP8266 Arduino from:
    https://github.com/esp8266/Arduino

  Works great with Adafruit's Huzzah ESP board:
  ----> https://www.adafruit.com/product/2471
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Tony DiCola for Adafruit Industries.
  Adafruit IO example additions by Todd Treece.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// function prototypes
void connect(void);
void recieve_string(char *punt);


char WLAN_SSID[20], WLAN_PASS[20],ck=0;
/****************************** Pins ******************************************/

#define LAMP            2  // power switch tail

//************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "AlbertoIztatik"
#define AIO_KEY         "003859a64a634978847115cff8c2b450"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

// Store the MQTT server, client ID, username, and password in flash memory.
// This is required for using the Adafruit MQTT library.
const char MQTT_SERVER[] PROGMEM    = AIO_SERVER;
// Set a unique MQTT client ID using the AIO key + the date and time the sketch
// was compiled (so this should be unique across multiple devices for a user,
// alternatively you can manually set this to a GUID or other random value).
const char MQTT_CLIENTID[] PROGMEM  = __TIME__ AIO_USERNAME;
const char MQTT_USERNAME[] PROGMEM  = AIO_USERNAME;
const char MQTT_PASSWORD[] PROGMEM  = AIO_KEY;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, AIO_SERVERPORT, MQTT_CLIENTID, MQTT_USERNAME, MQTT_PASSWORD);

/****************************** Feeds ***************************************/

// Setup a feed called 'lamp' for subscribing to changes.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
const char LAMP_FEED[] PROGMEM = AIO_USERNAME "/feeds/lamp";
Adafruit_MQTT_Subscribe lamp = Adafruit_MQTT_Subscribe(&mqtt, LAMP_FEED);

/*************************** Sketch Code ************************************/

void setup() {

  // set power switch tail pin as an output
  pinMode(LAMP, OUTPUT);
  digitalWrite(LAMP, 0);
  
  Serial.begin(57600);
   delay(10);
   recieve_string(WLAN_SSID);
   recieve_string(WLAN_PASS);
   Serial.println(WLAN_SSID);
   Serial.println(WLAN_PASS);

  WiFi.begin(WLAN_SSID,WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.print(F("+"));
  // listen for events on the lamp feed
  mqtt.subscribe(&lamp);

  // connect to adafruit io
  connect();

}

void loop() {

  Adafruit_MQTT_Subscribe *subscription;

  // ping adafruit io a few times to make sure we remain connected
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }

  // this is our 'wait for incoming subscription packets' busy subloop
  while (subscription = mqtt.readSubscription(1000)) {

    // we only care about the lamp events
    if (subscription == &lamp) {

      // convert mqtt ascii payload to int
      char *value = (char *)lamp.lastread;
      
     // Apply message to lamp
      String message = String(value);
      message.trim();
      if (message == "ON") {digitalWrite(LAMP, HIGH);Serial.print("s");}
      if (message == "OFF") {digitalWrite(LAMP, LOW);Serial.print("e");}


    }

  }

}

// connect to adafruit io via MQTT
void connect() {

  Serial.print(F("..."));

  int8_t ret;

  while ((ret = mqtt.connect()) != 0) {

    switch (ret) {
      case 1: Serial.println(F("-")); break;
      case 2: Serial.println(F("-")); break;
      case 3: Serial.println(F("-l")); break;
      case 4: Serial.println(F("-")); break;
      case 5: Serial.println(F("-")); break;
      case 6: Serial.println(F("-")); break;
      default: Serial.println(F("-")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    Serial.println(F("..."));
    delay(5000);

  }

  Serial.println(F("+"));

}
