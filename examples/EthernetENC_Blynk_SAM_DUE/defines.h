/****************************************************************************************************************************
  defines.h
  
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

#define DRD_GENERIC_DEBUG             false   //true

#define BLYNK_WM_DEBUG                  1

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(ETHERNET_USE_SAM_DUE)
    #undef ETHERNET_USE_SAM_DUE
  #endif
  #define ETHERNET_USE_SAM_DUE        true
#endif

#if defined(ETHERNET_USE_SAM_DUE)

  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  
  #if ( defined(ARDUINO_SAM_DUE) || (__SAM3X8E__) )
    #define BOARD_TYPE      "SAM DUE"
  #else
    #define BOARD_TYPE      "SAM Unknown"
  #endif
 
#else

  #error Unknown or unsupported Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library" 

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM    false   //true

#define USE_SSL   false

#if USE_BLYNK_WM
 
  // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
  #define EEPROM_START   0
  
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
  #else
    // To create
    #include <BlynkSimpleEthernetENC.h>
  #endif

#endif    //USE_BLYNK_WM

#define BLYNK_HOST_NAME   "EthernetENC-SAMDUE"

#endif      //defines_h
