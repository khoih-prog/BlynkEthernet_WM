/****************************************************************************************************************************
  BlynkEthernetENC.h
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
 
#ifndef BlynkEthernetENC_h
#define BlynkEthernetENC_h

#ifndef BLYNK_INFO_CONNECTION
  #define BLYNK_INFO_CONNECTION "ENC28J60"
#endif

#ifdef BLYNK_USE_SSL
  #define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT_SSL
#else
  #define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT
#endif

#include <BlynkApiArduino.h>
#include <Blynk/BlynkProtocol.h>
#include <Adapters/BlynkArduinoClient.h>

class BlynkEthernet
    : public BlynkProtocol<BlynkArduinoClient>
{
    typedef BlynkProtocol<BlynkArduinoClient> Base;
public:
    BlynkEthernet(BlynkArduinoClient& transp)
        : Base(transp)
    {}

    void config(const char* auth,
                const char* domain = BLYNK_DEFAULT_DOMAIN,
                uint16_t    port   = BLYNK_SERVER_PORT)
    {
        Base::begin(auth);
        this->conn.begin(domain, port);
    }

    void config(const char* auth,
                IPAddress   ip,
                uint16_t    port = BLYNK_SERVER_PORT)
    {
        Base::begin(auth);
        this->conn.begin(ip, port);
    }

    // DHCP with domain
    void begin( const char* auth,
                const char* domain = BLYNK_DEFAULT_DOMAIN,
                uint16_t port      = BLYNK_SERVER_PORT,
                const byte mac[]   = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Getting IP..."));
        if (!Ethernet.begin(SelectMacAddress(auth, mac))) {
            BLYNK_FATAL(BLYNK_F("DHCP Failed!"));
        }
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, domain, port);
        while(this->connect() != true) {}
    }

    // Static IP with domain
    void begin( const char* auth,
                const char* domain,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                const byte mac[] = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Using static IP"));
        Ethernet.begin(SelectMacAddress(auth, mac), local, dns);
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, domain, port);
        while(this->connect() != true) {}
    }

    // Static IP with domain, gateway, etc
    void begin( const char* auth,
                const char* domain,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                IPAddress gateway,
                IPAddress subnet,
                const byte mac[] = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Using static IP"));
        Ethernet.begin(SelectMacAddress(auth, mac), local, dns, gateway, subnet);
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, domain, port);
        while(this->connect() != true) {}
    }

    // DHCP with server IP
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port    = BLYNK_SERVER_PORT,
                const byte mac[] = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Getting IP..."));
        if (!Ethernet.begin(SelectMacAddress(auth, mac))) {
            BLYNK_FATAL(BLYNK_F("DHCP Failed!"));
        }
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, addr, port);
        while(this->connect() != true) {}
    }

    // Static IP with server IP
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port,
                IPAddress local,
                const byte mac[] = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Using static IP"));
        Ethernet.begin(SelectMacAddress(auth, mac), local);
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, addr, port);
        while(this->connect() != true) {}
    }

    // Static IP with server IP, DNS, gateway, etc
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                IPAddress gateway,
                IPAddress subnet,
                const byte mac[] = NULL)
    {
        BLYNK_LOG1(BLYNK_F("Using static IP"));
        Ethernet.begin(SelectMacAddress(auth, mac), local, dns, gateway, subnet);
        // give the Ethernet shield a second to initialize:
        BlynkDelay(1000);
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);

        config(auth, addr, port);
        while(this->connect() != true) {}
    }

private:

    byte* SelectMacAddress(const char* token, const byte mac[])
    {
        if (mac != NULL) {
            return (byte*)mac;
        }

        macAddress[0] = 0xFE;
        macAddress[1] = 0xED;
        macAddress[2] = 0xBA;
        macAddress[3] = 0xFE;
        macAddress[4] = 0xFE;
        macAddress[5] = 0xED;

        int len = strlen(token);
        int mac_index = 1;
        for (int i=0; i<len; i++) {
            macAddress[mac_index++] ^= token[i];

            if (mac_index > 5) { mac_index = 1; }
        }
         BLYNK_LOG("MAC: %02X-%02X-%02X-%02X-%02X-%02X",
                  macAddress[0], macAddress[1],
                  macAddress[2], macAddress[3],
                  macAddress[4], macAddress[5]);
        
        return macAddress;
    }

private:
    byte macAddress[6];

};

#endif    // BlynkEthernetENC_h
