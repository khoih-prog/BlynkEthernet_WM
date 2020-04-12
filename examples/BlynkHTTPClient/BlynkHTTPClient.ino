/****************************************************************************************************************************
   BlynkHTTPClient.ino
   For Mega, Teensy, SAM DUE, SAMD boards using W5100 Ethernet shields or TinyGSM shield

   BlynkEthernet_WM is a library for Mega AVR, Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J69 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk

   Rewritten to merge HTTPClient.ino and BlynkClient.ino examples in
   https://github.com/vshymanskyy/TinyGSM/tree/master/examples

   Library forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
   Licensed under MIT license
   Version: 1.0.10

   Original Blynk Library author:
   @file       BlynkSimpleEsp8266.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
   @date       Jan 2015
   @brief

   For this example, you need to install Blynk library:
     https://github.com/blynkkk/blynk-library/releases/latest

   TinyGSM Getting Started guide:
     https://tiny.cc/tinygsm-readme

   Blynk is a platform with iOS and Android apps to control
   Arduino, Raspberry Pi and the likes over the Internet.
   You can easily build graphic interfaces for all your
   projects by simply dragging and dropping widgets.

   Blynk supports many development boards with WiFi, Ethernet,
   GSM, Bluetooth, BLE, USB/Serial connection methods.
   See more in Blynk library examples and community forum.

                  http://www.blynk.io/

   Change GPRS apm, user, pass, and Blynk auth token to run :)

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.4   K Hoang      14/01/2020 Initial coding
    1.0.5   K Hoang      24/01/2020 Change Synch XMLHttpRequest to Async (https://xhr.spec.whatwg.org/)
    1.0.6   K Hoang      20/02/2020 Add support to ENC28J60 Ethernet shields
    1.0.7   K Hoang      20/02/2020 Add support to SAM DUE and SAMD boards
    1.0.8   K Hoang      03/03/2020 Fix bug. Change default macAddress for boards
    1.0.9   K Hoang      10/03/2020 Reduce html and code size. Enhance GUI.
    1.0.10  K Hoang      11/04/2020 Add MultiBlynk, dynamic parameters, special chars input
 *****************************************************************************************************************************/

#if defined(ESP8266) || defined(ESP32) || defined (CORE_TEENSY)
#error This code is designed to run on Arduino AVR (Mega, Mega1280, Mega2560, Mega ADK) platform, not ESP8266, ESP32 nor Teensy! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define _ETHERNET_WEBSERVER_LOGLEVEL_   0
#define BLYNK_PRINT Serial

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
   || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
   || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD           true
#define USE_DYNAMIC_PARAMETERS      true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE        true
#define USE_DYNAMIC_PARAMETERS      true
#endif

#if ( defined(CORE_TEENSY) && !( defined(__MKL26Z64__) || defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) ) )
#if defined(ETHERNET_USE_TEENSY)
#undef ETHERNET_USE_TEENSY
#endif
#define ETHERNET_USE_TEENSY         true
#define USE_DYNAMIC_PARAMETERS      true
#endif

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
#if defined(ETHERNET_USE_MEGA)
#undef ETHERNET_USE_MEGA
#endif
#define ETHERNET_USE_MEGA           true
#define USE_DYNAMIC_PARAMETERS      false
#endif

#if defined(ETHERNET_USE_SAMD)
#if defined(ARDUINO_SAMD_ZERO)
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#elif defined(ETHERNET_USE_SAM_DUE)
#if ( defined(ARDUINO_SAM_DUE) || (__SAM3X8E__) )
#define BOARD_TYPE      "SAM DUE"
#else
#define BOARD_TYPE      "SAM Unknown"
#endif

#elif defined(ETHERNET_USE_MEGA)
// For Mega
#define BOARD_TYPE      "AVR Mega"

#else
#error Unknown Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

//#define USE_BLYNK_WM      false
#define USE_BLYNK_WM      true

#if !USE_BLYNK_WM
//#define USE_LOCAL_SERVER      true
#define USE_LOCAL_SERVER      false

#if USE_LOCAL_SERVER
#define blynk_auth     "****"
#define blynk_server   "****"
#else
#define blynk_auth     "****"
#define blynk_server   "blynk-cloud.com"
#endif

#define BLYNK_HARDWARE_PORT       8080
#endif

//#define USE_ETHERNET_W5X00    false
#define USE_ETHERNET_W5X00    true
//#define USE_UIP_ETHERNET      false
//#define USE_UIP_ETHERNET      true

#if ( USE_ETHERNET_W5X00 || USE_UIP_ETHERNET )
#include <SPI.h>

#if USE_BLYNK_WM
// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
#define EEPROM_START     0

#if USE_ETHERNET_W5X00
#include <BlynkSimpleEthernet_WM.h>
#else
#include <BlynkSimpleUIPEthernet_WM.h>
#endif

// Mega has too small memory and can't run dynamic parameters
#if (!ETHERNET_USE_MEGA)

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleEsp8266_WM.h> and <BlynkSimpleEsp8266_SSL_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

#else

MenuItem myMenuItems [] = {};

#endif


uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;
/////// // End dynamic Credentials ///////////

#endif    //(!ETHERNET_USE_MEGA)

#else
#if USE_ETHERNET_W5X00
#include <BlynkSimpleEthernet.h>
#else
#include <BlynkSimpleUIPEthernet.h>
#endif
#endif

// You can specify your board mac adress
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Use this for static IP
IPAddress local_ip      (192, 168, 2, 99);
IPAddress local_dns     (192, 168, 2, 1);
IPAddress local_gateway (192, 168, 2, 1);
IPAddress local_subnet  (255, 255, 255, 0);

#if USE_ETHERNET_W5X00
// Ethernet shield and SDcard pins
#define W5100_CS  10
#define SDCARD_CS 4
#endif

EthernetClient client;

#else
// Select your modem:
#define TINY_GSM_MODEM_SIM800
// #define TINY_GSM_MODEM_SIM808
// #define TINY_GSM_MODEM_SIM900
// #define TINY_GSM_MODEM_UBLOX
// #define TINY_GSM_MODEM_BG96
// #define TINY_GSM_MODEM_A6
// #define TINY_GSM_MODEM_A7
// #define TINY_GSM_MODEM_M590
// #define TINY_GSM_MODEM_ESP8266
// #define TINY_GSM_MODEM_XBEE

// Increase RX buffer if needed
//#define TINY_GSM_RX_BUFFER 512

#include <TinyGsmClient.h>
//#include <BlynkSimpleSIM800.h>
#include <BlynkSimpleTinyGSM.h>

// Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// Your GPRS credentials
// Leave empty, if missing user or pass
#define apn     "YourAPN"
#define user   "****"
#define pass    "****"

#define blynk_gsm_auth     "****"

// Uncomment this if you want to see all AT commands
//#define DUMP_AT_COMMANDS

#ifdef DUMP_AT_COMMANDS
#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif

TinyGsmClient client(modem);
#endif

#include <ArduinoHttpClient.h>

// Server details. Currently hardcoded.
//http://account.duckdns.org
//#define http_server     "account.duckdns.org"
//#define resource        "/"

#define http_server     "vsh.pp.ua"
#define resource        "/TinyGSM/logo.txt"

#define http_port       80

HttpClient http(client, http_server, http_port);

void setup()
{
  // Set console baud rate
  SerialMon.begin(115200);
  delay(10);
  SerialMon.println("\nStart BlynkHTTPClient on " + String(BOARD_TYPE));


#if ( USE_ETHERNET_W5X00 || USE_UIP_ETHERNET )

#if USE_ETHERNET_W5X00
  // Deselect the SD card
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);
#endif

#else
  // Set GSM module baud rate
  SerialAT.begin(115200);
  delay(3000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  SerialMon.println("Initializing modem...");
  modem.restart();

  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem: ");
  SerialMon.println(modemInfo);

  // Unlock your SIM card with a PIN
  //modem.simUnlock("1234");
#endif

#if ( USE_ETHERNET_W5X00 || USE_UIP_ETHERNET )
#if USE_BLYNK_WM
  Blynk.begin();
#else
#if USE_LOCAL_SERVER
  Blynk.begin(blynk_auth, blynk_server, BLYNK_HARDWARE_PORT);
#else
  Blynk.begin(blynk_auth);
#endif
#endif
#else
  Blynk.begin(blynk_gsm_auth, modem, apn, user, pass);
#endif

  if (Blynk.connected())
    SerialMon.println("Blynk connected");
}

void HTTPClientHandle(void)
{
#if !( USE_ETHERNET_W5X00 || USE_UIP_ETHERNET )

  SerialMon.print(F("Waiting for network..."));
  if (!modem.waitForNetwork())
  {
    SerialMon.println(" fail");
    return;
  }

  SerialMon.println(" OK");

  SerialMon.print(F("Connecting to "));
  SerialMon.print(apn);
  if (!modem.gprsConnect(apn, user, pass))
  {
    SerialMon.println(" fail");
    return;
  }
  SerialMon.println(" OK");
#endif

#define USE_DIRECT_CLIENT     true

#if USE_DIRECT_CLIENT

  // Test client directly, see Arduino_TinyGSM.ino
  // https://github.com/Xinyuan-LilyGO/TTGO-T-Call/blob/master/examples/Arduino_TinyGSM/Arduino_TinyGSM.ino
  // Just added
  SerialMon.print(F("Connecting to "));
  SerialMon.print(http_server);
  if (!client.connect(http_server, http_port))
  {
    SerialMon.println(F(" fail"));
    //delay(10000);
    return;
  }
  SerialMon.println(F(" OK"));

  // Make a HTTP GET request:
  SerialMon.println(F("Performing HTTP GET request..."));
  client.print(String(F("GET ")) + resource + F(" HTTP/1.1\r\n"));
  client.print(String(F("Host: ")) + http_server + F("\r\n"));
  client.print(F("Connection: close\r\n\r\n"));
  client.println();

  unsigned long timeout = millis();
  while (client.connected() && millis() - timeout < 10000L)
  {
    // Print available data
    while (client.available())
    {
      char c = client.read();
      SerialMon.print(c);
      timeout = millis();
    }
  }
  SerialMon.println();

  // Shutdown

  client.stop();

#else
  SerialMon.print(F("Performing HTTP GET request... "));
  int err = http.get(resource);
  if (err != 0)
  {
    SerialMon.print(F("failed to connect, error = "));
    SerialMon.println(err);
    return;
  }

  int status = http.responseStatusCode();
  SerialMon.println(status);
  if (!status)
  {
    SerialMon.print(F("Status Code is: "));
    SerialMon.println(status);
    return;
  }

  while (http.headerAvailable())
  {
    String headerName = http.readHeaderName();
    String headerValue = http.readHeaderValue();
    //SerialMon.println(headerName + " : " + headerValue);
  }

  int length = http.contentLength();
  if (length >= 0)
  {
    SerialMon.print(F("Content length is: "));
    SerialMon.println(length);
  }

  if (http.isResponseChunked())
  {
    SerialMon.println(F("The response is chunked"));
  }

  String body = http.responseBody();
  SerialMon.println(F("Response:"));
  SerialMon.println(body);

  SerialMon.print(F("Body length is: "));
  SerialMon.println(body.length());

  // Shutdown

  http.stop();
#endif

  SerialMon.println(F("Server disconnected"));

#if !( USE_ETHERNET_W5X00 || USE_UIP_ETHERNET )
  modem.gprsDisconnect();
  SerialMon.println(F("GPRS disconnected"));
#endif
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     60000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    HTTPClientHandle();
    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

#if USE_DYNAMIC_PARAMETERS
void displayCredentials(void)
{
  Serial.println("\nYour stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if USE_DYNAMIC_PARAMETERS
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
#endif    
}
