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
void string_recieve(char *punt);

/****************************** Pins ******************************************/

#define LAMP            2  // power switch tail

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "INFINITUM2937"
#define WLAN_PASS       "3523738115"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "AlbertoIztatik"
#define AIO_KEY         "003859a64a634978847115cff8c2b450"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

 const char MQTT_SERVER[] PROGMEM    = AIO_SERVER;
 const char MQTT_CLIENTID[] PROGMEM  = __TIME__ AIO_USERNAME;
/****************************** Feeds ***************************************/

// Setup a feed called 'lamp' for subscribing to changes.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>


/*************************** Sketch Code ************************************/

char SID[40],PASS[40],USER[40],KEY[40];


void setup() {

  // set power switch tail pin as an output
  pinMode(LAMP, OUTPUT);
  digitalWrite(LAMP, 0);
  
  Serial.begin(57600);
  delay(50);

  string_recieve(SID);
  string_recieve(PASS);
  string_recieve(USER);
  string_recieve(KEY);
  
  Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, AIO_SERVERPORT, MQTT_CLIENTID, USER, PASS);

  Adafruit_MQTT_Subscribe lamp = Adafruit_MQTT_Subscribe(&mqtt, USER);

  WiFi.begin(SID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
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
     // Serial.print(F("Received: "));
     // Serial.println(value);
      //int current = atoi(value);

     // Apply message to lamp
      String message = String(value);
      message.trim();
      if (message == "ON") {digitalWrite(LAMP, HIGH);Serial.print("s");}
      else if (message == "OFF") {digitalWrite(LAMP, LOW);Serial.print("e");}

      


    }

  }

}

// connect to adafruit io via MQTT
void connect() {

  int8_t ret;

  while ((ret = mqtt.connect()) != 0) {

    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    //Serial.println(F("Retrying connection..."));
    delay(3000);

  }

  //Serial.print("Y");

}

void string_recieve(char *punt){

  while (!Serial.available());

  do{
  *punt=Serial.read();
  punt++;
  } while((*punt));
  return;
}

