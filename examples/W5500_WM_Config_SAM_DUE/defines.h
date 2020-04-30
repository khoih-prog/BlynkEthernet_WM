/****************************************************************************************************************************
   defines.h for ESP32WM_Config.ino
   For ESP32, ESP8266, Teensy, SAMD, SAM DUE using W5x00 Ethernet shields
   
   BlynkEthernet_WM is a library for Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J60 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk
   AVR Mega and W5100 is not supported.
   Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
   Licensed under MIT license
   Version: 1.0.13

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
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define _ETHERNET_WEBSERVER_LOGLEVEL_   0

#define DRD_GENERIC_DEBUG             true
#define BLYNK_WM_DEBUG                3

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

#define DRD_GENERIC_DEBUG             true
#define BLYNK_WM_DEBUG                3

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM    false

//#define USE_SSL   true
#define USE_SSL   false

#if USE_BLYNK_WM

// EEPROM_SIZE must be <= 2048 and >= CONFIG_DATA_SIZE (currently 172 bytes)
//#define EEPROM_SIZE       2048
// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
// EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
#define EEPROM_START   0

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleEthernetSSL_WM.h>
#else
#include <BlynkSimpleEthernet_WM.h>
#endif

#else   ////USE_BLYNK_WM

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleEthernetSSL.h>
#else
#include <BlynkSimpleEthernet.h>
#endif

#endif    //USE_BLYNK_WM

#define W5100_CS        10
#define SDCARD_CS       4

#define DHT_PIN     5
#define DHT_TYPE    DHT11

#define BLYNK_HOST_NAME   "W5500-Master-Controller"

#endif      //defines_h
