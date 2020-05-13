/****************************************************************************************************************************
   BlynkSimpleEthernetSSL_WM.h
   For W5200, W5500 Ethernet shields.

   BlynkEthernet_WM is a library for Teensy, STM32, SAM DUE and SAMD boards, with Ethernet W5200, W5500 or ENC28J60 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk.
.  AVR Mega and W5100 is not supported.
   Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
   Licensed under MIT license
   Version: 1.0.15

   Original Blynk Library author:
   @file       BlynkGsmClient.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
   @date       Jan 2015
   @brief

   Version  Modified By   Date      Comments
   -------  -----------  ---------- -----------
    1.0.4     K Hoang      14/01/2020 Initial coding
    1.0.5     K Hoang      24/01/2020 Change Synch XMLHttpRequest to Async (https://xhr.spec.whatwg.org/)
    1.0.6     K Hoang      20/02/2020 Add support to ENC28J60 Ethernet shields
    1.0.7     K Hoang      20/02/2020 Add support to SAM DUE and SAMD boards
    1.0.8     K Hoang      03/03/2020 Fix bug. Change default macAddress for boards
    1.0.9     K Hoang      10/03/2020 Reduce html and code size. Enhance GUI.
    1.0.10    K Hoang      11/04/2020 Add MultiBlynk, dynamic parameters, special chars input
    1.0.11    K Hoang      14/04/2020 Fix bug
    1.0.12    K Hoang      15/04/2020 Drop W5100 and AVR Mega support because of not enough memory.  Add SAMD51 support.
    1.0.13    K Hoang      29/04/2020 Add ESP32, including u-blox NINA-W10 series (ESP32) and ESP8266 support.  
                                      Add Configurable Config Portal Title, Default Config Data and DRD. Update examples.
    1.0.14    K Hoang      01/05/2020 Add support to Adafruit nRF522, including NINA_B302_ublox. 
    1.0.15    K Hoang      12/05/2020 Fix bug and Update to use LittleFS for ESP8266 core 2.7.1+.      
 *****************************************************************************************************************************/

#ifndef BlynkSimpleEthernetSSL_WM_h
#define BlynkSimpleEthernetSSL_WM_h

#error Ethernet SSL for Blynk not ready yet

#ifndef BLYNK_INFO_CONNECTION
#define BLYNK_INFO_CONNECTION "W5000-SSL"
#endif

#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetUdp.h>
#include <ArduinoECCX08.h>
#include <ArduinoBearSSL.h>

#define BLYNK_USE_SSL

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) \
   || defined(ARDUINO_SAMD_MKRWAN1310) || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) \
   || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) \
   || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD      true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE      true
#endif

#if ( defined(CORE_TEENSY) && !( defined(__MKL26Z64__) || defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) ) )
#if defined(ETHERNET_USE_TEENSY)
#undef ETHERNET_USE_TEENSY
#endif
#define ETHERNET_USE_TEENSY         true
#endif

#if ( defined(ESP8266) )
// For ESP8266
#if defined(ETHERNET_USE_ESP8266)
#undef ETHERNET_USE_ESP8266
#endif
#define ETHERNET_USE_ESP8266         true
#endif

#if ( defined(ESP32) )
// For ESP32
#if defined(ETHERNET_USE_ESP32)
#undef ETHERNET_USE_ESP32
#endif
#define ETHERNET_USE_ESP32         true
#endif

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) | defined(NINA_B302_ublox) )  
#if defined(ETHERNET_USE_NRF52)
#undef ETHERNET_USE_NRF528XX
#endif
#define ETHERNET_USE_NRF528XX         true
#endif

#if (ETHERNET_USE_SAMD)
#include <Adapters/BlynkEthernet_SAMD_WM.h>
#elif (ETHERNET_USE_SAM_DUE)
#include <Adapters/BlynkEthernet_DUE_WM.h>
#elif (ETHERNET_USE_TEENSY)
#include <Adapters/BlynkEthernet_WM.h>
#elif (ETHERNET_USE_ESP32)
#include <Adapters/BlynkEthernet_ESP32_WM.h>
#elif (ETHERNET_USE_ESP8266)
#include <Adapters/BlynkEthernet_ESP8266_WM.h>
#elif (ETHERNET_USE_NRF528XX)
#include <Adapters/BlynkEthernet_NRF52_WM.h>
#else
#error This code for SAMD, SAM-DUE, Teensy (4.0, 3.x) boards, ESP8266, ESP32, nRF52, not AVR Mega nor STM32! Please check your Tools->Board setting.
#endif

static EthernetClient _blynkEthernetClient;
static BearSSLClient _blynkEthernetClientSSL(_blynkEthernetClient);

static BlynkArduinoClient _blynkTransport(_blynkEthernetClientSSL);
BlynkEthernet Blynk(_blynkTransport);

#include <BlynkWidgets.h>

unsigned long ntpGetTime() {
  static const char timeServer[] = "time.nist.gov";

  const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
  byte packetBuffer[NTP_PACKET_SIZE];

  EthernetUDP Udp;
  Udp.begin(8888);

  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  for (int i = 0; i < 10; i++)
  {
    // all NTP fields have been given values, now
    // you can send a packet requesting a timestamp:
    Udp.beginPacket(timeServer, 123); // NTP requests are to port 123
    Udp.write(packetBuffer, NTP_PACKET_SIZE);
    Udp.endPacket();

    millis_time_t started = BlynkMillis();
    while (BlynkMillis() - started < 1000)
    {
      delay(100);
      if (Udp.parsePacket()) {
        // We've received a packet, read the data from it
        Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

        // the timestamp starts at byte 40 of the received packet and is four bytes,
        // or two words, long. First, extract the two words:
        unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
        unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
        // combine the four bytes (two words) into a long integer
        // this is NTP time (seconds since Jan 1 1900):
        unsigned long secsSince1900 = highWord << 16 | lowWord;
        //Serial.print("Seconds since Jan 1 1900 = ");
        //Serial.println(secsSince1900);

        // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
        const unsigned long seventyYears = 2208988800UL;
        // subtract seventy years:
        unsigned long epoch = secsSince1900 - seventyYears;

        // print Unix time:
        Serial.print("Unix time = ");
        Serial.println(epoch);

        return epoch;
      }
    }
    Serial.println("Retry NTP");
  }
  Serial.println("NTP failed");
  return 0;
}

#endif
