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

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
#error This code is designed to run on SAMD, SAM-DUE, Teensy platform, ESP8266, ESP32 not AVR Mega! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ESP32) || defined(ESP8266) )
#define EEPROM_SIZE                   2048
#define DOUBLERESETDETECTOR_DEBUG     true
#else
#define DRD_GENERIC_DEBUG             true
#endif

#define BLYNK_WM_DEBUG                3

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) \
   || defined(ARDUINO_SAMD_MKRWAN1310) || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) \
   || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) \
   || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD           true
#define USE_DYNAMIC_PARAMETERS      true
#define EEPROM_SIZE                 2048
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
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#elif defined(ETHERNET_USE_SAM_DUE)
#if ( defined(ARDUINO_SAM_DUE) || (__SAM3X8E__) )
#define BOARD_TYPE      "SAM DUE"
#else
#define BOARD_TYPE      "SAM Unknown"
#endif

#elif ( defined(CORE_TEENSY) )
// For Teensy 4.0
#if defined(__IMXRT1062__)
#define BOARD_TYPE      "TEENSY 4.0"
#elif defined(__MK66FX1M0__)
#define BOARD_TYPE      "Teensy 3.6"
#elif defined(__MK64FX512__)
#define BOARD_TYPE      "Teensy 3.5"
#elif defined(__MK20DX256__)
#define BOARD_TYPE      "Teensy 3.2/3.1"
#elif defined(__MK20DX128__)
#define BOARD_TYPE      "Teensy 3.0"
#elif ( defined(__MKL26Z64__) || defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) )
#error "Teensy LC, 2.0++ and 2.0 not supported"
#else
#define BOARD_TYPE      "Teensy Unknown"
#endif

#elif ( defined(ESP8266) )
#define BOARD_TYPE      "ESP8266"

#elif ( defined(ESP32) )
#define BOARD_TYPE      "ESP32"

#else
#error Unknown or unsupported Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM    false

//#define USE_SSL   true
#define USE_SSL   false

#if USE_BLYNK_WM

// Not use #define USE_SPIFFS  => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    false => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    true  => using SPIFFS for configuration data in WiFiManager
// Be sure to define USE_SPIFFS before #include <BlynkSimpleEsp8266_WM.h>

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
//#define EEPROM_START     1024
//#define EEPROM_START     0

#if ( defined(ESP32) || defined(ESP8266) )
//#define USE_SPIFFS                  true
#define USE_SPIFFS                  false
#else
#define USE_SPIFFS                  false
#endif

#if (!USE_SPIFFS)
// EEPROM_SIZE must be <= 2048 and >= CONFIG_DATA_SIZE (currently 172 bytes)
//#define EEPROM_SIZE    (2 * 1024)
// EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
#define EEPROM_START   0
#endif

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleUIPEthernetSSL_WM.h>
#else
#include <BlynkSimpleUIPEthernet_WM.h>
#endif

#else   ////USE_BLYNK_WM

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleUIPEthernetSSL.h>
#else
#include <BlynkSimpleUIPEthernet.h>
#endif

#endif    //USE_BLYNK_WM

#define W5100_CS        10
#define SDCARD_CS       4

#define DHT_PIN     5
#define DHT_TYPE    DHT11

#define BLYNK_HOST_NAME   "ENC28J60-MasterController"

#endif      //defines_h
