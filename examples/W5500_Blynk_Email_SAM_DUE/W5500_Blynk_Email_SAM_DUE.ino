/****************************************************************************************************************************
   W5500_Blynk_Email_SAM_DUE.ino
   For Teensy, SAM DUE, SAMD boards using W5100 Ethernet shields

   BlynkEthernet_WM is a library for Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J69 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk

   Library forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
   Licensed under MIT license
   Version: 1.0.12

   Original Blynk Library author:
   @file       BlynkGsmClient.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
   @date       Jan 2015
   @brief

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.4   K Hoang      14/01/2020 Initial coding
    1.0.5   K Hoang      24/01/2020 Change Synch XMLHttpRequest to Async (https://xhr.spec.whatwg.org/)
    1.0.6   K Hoang      20/02/2020 Add support to ENC28J60 Ethernet shields
    1.0.7   K Hoang      20/02/2020 Add support to SAM DUE and SAMD boards
    1.0.8   K Hoang      03/03/2020 Fix bug. Change default macAddress for boards
    1.0.9   K Hoang      10/03/2020 Reduce html and code size. Enhance GUI.
    1.0.10  K Hoang      11/04/2020 Add MultiBlynk, dynamic parameters, special chars input
    1.0.11  K Hoang      14/04/2020 Fix bug
    1.0.12  K Hoang      15/04/2020 Drop W5100 and AVR Mega support because of not enough memory. Add SAMD51 support.
 *****************************************************************************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE      true
#else
#error This code is designed to run on SAMD DUE platform, not ESP8266, ESP32, AVR, Teensy or SAMD! Please check your Tools->Board setting.
#endif

#if defined(ETHERNET_USE_SAM_DUE)
#if ( defined(ARDUINO_SAM_DUE) || (__SAM3X8E__) )
#define BOARD_TYPE      "SAM DUE"
#else
#define BOARD_TYPE      "SAM Unknown"
#endif
#endif

#include <SPI.h>

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
#define EEPROM_START     0

#define USE_SSL     false

#define USE_CHECKSUM      true

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleEthernetSSL_WM.h>
#else
#include <BlynkSimpleEthernet_WM.h>
#endif

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkEthernet_WM.h>
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
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
#endif


/////// // End dynamic Credentials ///////////


#define USE_BLYNK_WM      true

#if !USE_BLYNK_WM
#define USE_LOCAL_SERVER      true

#if USE_LOCAL_SERVER
char auth[] = "******";
char server[] = "account.duckdns.org";
//char server[] = "192.168.2.112";
#else
char auth[] = "******";
char server[] = "blynk-cloud.com";
#endif

#define BLYNK_HARDWARE_PORT       8080
#endif

BlynkTimer timer;

#define W5100_CS        10
#define SDCARD_CS       4
#define BUTTON_PIN      2

volatile unsigned int count       = 0;
volatile bool isButtonPressed     = false;

void emailOnButtonPress()
{
  //isButtonPressed = !digitalRead(BUTTON_PIN); // Invert state, since button is "Active LOW"

  if ( !isButtonPressed && !digitalRead(BUTTON_PIN)) // You can write any condition to trigger e-mail sending
  {
    isButtonPressed = true;
    count++;
    Serial.println("Button pressed");
  }
}

void processButton(void)
{
  // *** WARNING: You are limited to send ONLY ONE E-MAIL PER 5 SECONDS! ***
  // Let's send an e-mail when you press the button
  // connected to digital pin BUTTON_PIN (2) on your Arduino
  static String body;

  if (isButtonPressed) // You can write any condition to trigger e-mail sending
  {
    body = String("You pushed the button ") + count + " times.";

    // This can be seen in the Serial Monitor
    Serial.println(body);

    Blynk.email("your_email@gmail.com", "Subject: Button Logger", body);

    isButtonPressed = false;
  }

}

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("\nStart W5500_Blynk_Email_SAM_DUE on " + String(BOARD_TYPE));

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

#if USE_BLYNK_WM
  Blynk.begin();
#else
#if USE_LOCAL_SERVER
  Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
#else
  Blynk.begin(auth);
  // You can also specify server:
  //Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
#endif
#endif

  if (Blynk.connected())
  {
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(Blynk.getServerName());
    Serial.print(F(", port = "));
    Serial.println(Blynk.getHWPort());
    Serial.print(F("Token = "));
    Serial.print(Blynk.getToken());
    Serial.print(F(", IP = "));
    Serial.println(Ethernet.localIP());
  }

  // Attach pin BUTTON_PIN (2) interrupt to our handler
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), emailOnButtonPress, FALLING /*CHANGE*/);

  timer.setInterval(30000L, processButton);
}

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
    Serial.print(F("B"));
  else
    Serial.print(F("F"));

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(F(" "));
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     60000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    heartBeatPrint();
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
  timer.run();
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
