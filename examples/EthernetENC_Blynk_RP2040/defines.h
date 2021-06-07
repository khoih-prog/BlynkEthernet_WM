/****************************************************************************************************************************
  defines.h
  For nRF52 boards using ENC28J60 Ethernet shields with EthernetENC library
  
  BlynkEthernet_WM is a library for Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J69 shields,
  to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk
  
  Library forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ESP32) || defined(ESP8266) )
  #define DOUBLERESETDETECTOR_DEBUG     true
#else
  #define DRD_GENERIC_DEBUG             false   //true
#endif

#define BLYNK_WM_DEBUG                  1

#if ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) )
  #if defined(ETHERNET_USE_RPIPICO)
    #undef ETHERNET_USE_RPIPICO
  #endif
  #define ETHERNET_USE_RPIPICO      true
#else
  #error This code is designed to run on RP2040 platform! Please check your Tools->Board setting.  
#endif
 
// Default pin 5 (in Mbed) or 17 to SS/CS
#if defined(ARDUINO_ARCH_MBED)
  // For RPI Pico using Arduino Mbed RP2040 core
  // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
  
  #define USE_THIS_SS_PIN       5

  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(ARDUINO_RASPBERRY_PI_PICO) 
    #define BOARD_TYPE      "MBED RASPBERRY_PI_PICO"
  #elif defined(ARDUINO_ADAFRUIT_FEATHER_RP2040)
    #define BOARD_TYPE      "MBED DAFRUIT_FEATHER_RP2040"
  #elif defined(ARDUINO_GENERIC_RP2040)
    #define BOARD_TYPE      "MBED GENERIC_RP2040"
  #else
    #define BOARD_TYPE      "MBED Unknown RP2040"
  #endif
  
#else
  // For RPI Pico using E. Philhower RP2040 core
  // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
  #define USE_THIS_SS_PIN       17

#endif
  
#define SS_PIN_DEFAULT        USE_THIS_SS_PIN

// For RPI Pico
#warning Use RPI-Pico RP2040 architecture  

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library" 

#define USE_BLYNK_WM      true

#define USE_SSL   false

#if USE_BLYNK_WM
  
  #if USE_SSL
    // Need ArduinoECCX08 and ArduinoBearSSL libraries
    // Currently, error not enough memory for UNO, Mega2560. Don't use
    #include <BlynkSimpleEthernetENC_SSL_WM.h>
  #else
    #include <BlynkSimpleEthernetENC_WM.h>
  #endif

#else   ////USE_BLYNK_WM

  #if USE_SSL
    // Need ArduinoECCX08 and ArduinoBearSSL libraries
    // Currently, error not enough memory for UNO, Mega2560. Don't use
    // To create
    #include <BlynkSimpleEthernetENC_SSL.h>
      
    #define BLYNK_SERVER_HARDWARE_PORT    9443
  #else
    // To create
    #include <BlynkSimpleEthernetENC.h>

    #define BLYNK_SERVER_HARDWARE_PORT    8080
  #endif

  #if defined(BLYNK_INFO_DEVICE)
    #undef BLYNK_INFO_DEVICE
  #endif
  
  #define BLYNK_INFO_DEVICE       BOARD_TYPE

#endif    //USE_BLYNK_WM

#define BLYNK_HOST_NAME   "EthernetENC-nRF52"

#endif      //defines_h
