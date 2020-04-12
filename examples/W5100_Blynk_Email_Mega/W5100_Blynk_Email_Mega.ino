/****************************************************************************************************************************
   W5100_Blynk_Email_Mega.ino
   For Mega boards using W5100 Ethernet shields

   BlynkEthernet_WM is a library for Mega AVR, Teensy, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J60 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk

   Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
   Licensed under MIT license
   Version: 1.0.10

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
 *****************************************************************************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
#if defined(ETHERNET_USE_MEGA)
#undef ETHERNET_USE_MEGA
#endif
#define ETHERNET_USE_MEGA           true
#else
#error This code is designed to run on Arduino AVR (Mega1280, 2560, ADK, etc.), SAMD, SAM-DUE, Teensy platform, not ESP8266 nor ESP32! Please check your Tools->Board setting.
#endif

// For Mega
#if defined(ARDUINO_AVR_ADK)       
  #define BOARD_TYPE  "AVR Mega ADK"
#elif defined(ARDUINO_AVR_MEGA2560)  
  #define BOARD_TYPE  "AVR Mega2560"
#elif defined(ARDUINO_AVR_MEGA)       
  #define BOARD_TYPE  "AVR Mega"
#else
  #error Unknown Board. Please check your Tools->Board setting.
#endif    //BOARD_TYPE

#include <SPI.h>

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
#define EEPROM_START     0

#include <BlynkSimpleEthernet_WM.h>

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

#define W5100_CS  10
#define SDCARD_CS 4
#define BUTTON_PIN      2

volatile unsigned int count       = 0;
volatile bool isButtonPressed     = false;

BlynkTimer timer;

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
  Serial.println("\nStart W5100_Blynk_Email on " + String(BOARD_TYPE));

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

void loop()
{
  Blynk.run();
  timer.run();
  check_status();
}
