/****************************************************************************************************************************
  BlynkSimpleEthernetENC_SSL.h
  For ENC28J60 Ethernet shields using EthernetENC (https://github.com/jandrassy/EthernetENC) library.

  BlynkEthernet_WM is a library for Teensy, STM32, SAM DUE and SAMD boards, with Ethernet W5x00, ENC28J60 or NativeEthernet shields,
  to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk.
  AVR Mega is not supported.
  Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
  Licensed under MIT license

  Original Blynk Library author:
  @file       BlynkSimpleEthernet.h
  @author     Volodymyr Shymanskyy
  @license    This project is released under the MIT License (MIT)
  @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
  @date       Jan 2015
  @brief

  Version: 1.5.2

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
  1.0.14    K Hoang      01/05/2020 Add support to Adafruit nRF52, including NINA_B302_ublox.
  1.0.15    K Hoang      12/05/2020 Fix bug and Update to use LittleFS for ESP8266 core 2.7.1+.
  1.0.16    K Hoang      15/05/2020 Sync with EthernetWebServer v.1.0.9 to use 25MHz for W5x00 and EthernetWrapper feature.
  1.0.17    K Hoang      25/07/2020 New logic for USE_DEFAULT_CONFIG_DATA. Add support to Seeeduino SAMD21/SAMD51 boards.
  1.0.18    K Hoang      15/09/2020 Add support to new EthernetENC library for ENC28J60.
  1.1.0     K Hoang      13/01/2021 Add support to new NativeEthernet library for Teensy 4.1. Fix compiler warnings.
  1.2.0     K Hoang      29/01/2021 Fix bug. Add feature. Use more efficient FlashStorage_STM32 and FlashStorage_SAMD.
  1.2.1     K Hoang      31/01/2021 To permit autoreset after timeout if DRD/MRD or non-persistent forced-CP
  1.3.0     K Hoang      16/05/2021 Add support to RP2040-based boards such as RASPBERRY_PI_PICO
  1.4.0     K Hoang      18/05/2021 Add support to RP2040-based boards using Arduino-mbed RP2040 core
  1.5.0     K Hoang      05/06/2021 Add LittleFS/WiFiManager support to RP2040-based boards using Arduino-mbed RP2040 core
  1.5.1     K Hoang      05/06/2021 Fix bug
  1.5.2     K Hoang      09/10/2021 Update `platform.ini` and `library.json` 
 *****************************************************************************************************************************/
 
#ifndef BlynkSimpleEthernetENC_SSL_h
#define BlynkSimpleEthernetENC_SSL_h

#error Ethernet SSL for Blynk not ready yet

#ifndef BLYNK_INFO_CONNECTION
#define BLYNK_INFO_CONNECTION "ENC28J60"
#endif

#ifndef BLYNK_ETHERNET_WM_VERSION
  #define BLYNK_ETHERNET_WM_VERSION     "BlynkEthernet_WM v1.5.2"
#endif

#include <EthernetENC.h>
#include <EthernetClient.h>
#include <EthernetUdp.h>
#include <ArduinoECCX08.h>
#include <ArduinoBearSSL.h>

#define BLYNK_USE_SSL

#include <Adapters/BlynkEthernetENC.h>

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

  for (int i=0; i<10; i++)
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

#endif    // BlynkSimpleEthernetENC_SSL_h
