/****************************************************************************************************************************
 * Blynk_HTTPClient_Ethernet_GSM.ino
 * For Mega boards using either W5X00 Ethernet shield or TinyGSM shield
 * 
 * Rewritten to merge HTTPClient.ino and BlynkClient.ino examples in
 * https://github.com/vshymanskyy/TinyGSM/tree/master/examples
 *  
 *  Built by Khoi Hoang https://github.com/khoih-prog
 * Licensed under MIT license
 * 
 * Original Blynk Library author:
 * @file       BlynkSimpleEsp8266.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Jan 2015
 * @brief
 * 
 * For this example, you need to install Blynk library:
 *   https://github.com/blynkkk/blynk-library/releases/latest
 *
 * TinyGSM Getting Started guide:
 *   https://tiny.cc/tinygsm-readme
 *
 *
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 * Blynk supports many development boards with WiFi, Ethernet,
 * GSM, Bluetooth, BLE, USB/Serial connection methods.
 * See more in Blynk library examples and community forum.
 *
 *                http://www.blynk.io/
 *
 * Change GPRS apm, user, pass, and Blynk auth token to run :)
 *
 *****************************************************************************************************************************/

#if defined(ESP8266) || defined(ESP32)
#error This code is designed to run on Arduino AVR (Mega, Mega1280, Mega2560, Mega ADK) platform, not ESP8266 nor ESP32! Please check your Tools->Board setting.
#endif

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

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

#if USE_ETHERNET_W5X00
  #include <SPI.h>
  #include <Ethernet.h>

  #if USE_BLYNK_WM
    // Start location in EEPROM to store config data. Default 0
    // Config data Size currently is 128 bytes)
    #define EEPROM_START     256
    
    #include <EthernetWebServer.h>
    #include <BlynkSimpleEthernet_WM.h>
  #else
    #include <BlynkSimpleEthernet.h>
  #endif

  // You can specify your board mac adress
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  
  // Use this for static IP
  IPAddress ip      (192, 168, 2, 99);
  IPAddress dns     (192, 168, 2, 1);
  IPAddress gateway (192, 168, 2, 1);
  IPAddress subnet   (255, 255, 255, 0);
  
  // Ethernet shield and SDcard pins
  #define W5100_CS  10
  #define SDCARD_CS 4
  
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
#define http_server     "vsh.pp.ua"
#define resource        "/TinyGSM/logo.txt"

#define http_port       80

HttpClient http(client, http_server, http_port);

void setup()
{
  // Set console baud rate
  SerialMon.begin(115200);
  delay(10);


#if USE_ETHERNET_W5X00
  // Deselect the SD card
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);
  
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

  #if USE_ETHERNET_W5X00
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
  #if !USE_ETHERNET_W5X00
  
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

  SerialMon.print(F("Performing HTTP GET request... "));
  int err = http.get(resource);
  if (err != 0) 
  {
    SerialMon.println(F("failed to connect"));
    return;
  }

  int status = http.responseStatusCode();
  SerialMon.println(status);
  if (!status) 
  {
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
  SerialMon.println(F("Server disconnected"));

  #if !USE_ETHERNET_W5X00
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

void loop()
{
  Blynk.run();
  check_status();
}
