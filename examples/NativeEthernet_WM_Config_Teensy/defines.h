/****************************************************************************************************************************
  defines.h
  For ESP32, ESP8266, Teensy, SAMD, SAM DUE using W5x00 Ethernet shields
  
  BlynkEthernet_WM is a library for Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J60 shields,
  to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk
  AVR Mega and W5100 is not supported.
  Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(CORE_TEENSY) && !( defined(__MKL26Z64__) || defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) ) )
  #if defined(ETHERNET_USE_TEENSY)
    #undef ETHERNET_USE_TEENSY
  #endif
  #define ETHERNET_USE_TEENSY         true
  #define USE_DYNAMIC_PARAMETERS      true
#else
  #error This code is designed to run on Teensy platform! Please check your Tools->Board setting.  
#endif

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define DRD_GENERIC_DEBUG             true

#define BLYNK_WM_DEBUG                4

#if ( defined(CORE_TEENSY) )
  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  
  #if defined(__IMXRT1062__)
    // For Teensy 4.1/4.0
    #if defined(ARDUINO_TEENSY41)
      #define BOARD_TYPE      "TEENSY 4.1"
      // Use true for NativeEthernet Library, false if using other Ethernet libraries
      #define USE_NATIVE_ETHERNET     true
    #elif defined(ARDUINO_TEENSY40)
      #define BOARD_TYPE      "TEENSY 4.0"
    #else
      #define BOARD_TYPE      "TEENSY 4.x"
    #endif      
  #elif defined(__MK66FX1M0__)
    #define BOARD_TYPE "Teensy 3.6"
  #elif defined(__MK64FX512__)
    #define BOARD_TYPE "Teensy 3.5"
  #elif defined(__MKL26Z64__)
    #define BOARD_TYPE "Teensy LC"
  #elif defined(__MK20DX256__)
    #define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
  #elif defined(__MK20DX128__)
    #define BOARD_TYPE "Teensy 3.0"
  #elif defined(__AVR_AT90USB1286__)
    #error Teensy 2.0++ not supported yet
  #elif defined(__AVR_ATmega32U4__)
    #error Teensy 2.0 not supported yet
  #else
    // For Other Boards
    #define BOARD_TYPE      "Unknown Teensy Board"
  #endif

#else

  #error Unknown or unsupported Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM    false

#define USE_SSL   false

#if USE_BLYNK_WM

  // Start location in EEPROM to store config data. Default 0
  // Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
  // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
  #define EEPROM_START   0

  // To use faster 25MHz clock instead of defaulf 14MHz. Only for W5200 and W5500. W5100 also tested OK.
  //#define USE_W5100     false
  
  //#define USE_ETHERNET_WRAPPER    true
  #define USE_ETHERNET_WRAPPER    false

  // To override the default CS/SS pin. Don't use unless you know exactly which pin to use
  // You can define here or customize for each board at same place with BOARD_TYPE
  // Check @ defined(SEEED_XIAO_M0)
  //#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
  
  // Only one if the following to be true
  #define USE_ETHERNET          false
  #define USE_ETHERNET2         false
  #define USE_ETHERNET3         false
  #define USE_ETHERNET_LARGE    false
  #define USE_ETHERNET_ESP8266  false 
  #define USE_ETHERNET_ENC      false
  //#define USE_CUSTOM_ETHERNET   false
  
  #if !USE_ETHERNET_WRAPPER
  
    #if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC || USE_NATIVE_ETHERNET )
      #ifdef USE_CUSTOM_ETHERNET
        #undef USE_CUSTOM_ETHERNET
      #endif
      #define USE_CUSTOM_ETHERNET   false
    #endif

    #if USE_NATIVE_ETHERNET
      #include "NativeEthernet.h"
      #warning Using NativeEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
      #define SHIELD_TYPE           "Teensy 4.1 NativeEthernet Library"
      //#define USE_CUSTOM_ETHERNET     true
    #elif USE_ETHERNET3
      #include "Ethernet3.h"
      #warning Using Ethernet3 lib
      #define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
    #elif USE_ETHERNET2
      #include "Ethernet2.h"
      #warning Using Ethernet2 lib
      #define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
    #elif USE_ETHERNET_LARGE
      #include "EthernetLarge.h"
      #warning Using EthernetLarge lib
      #define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
    #elif USE_ETHERNET_ESP8266
      #include "Ethernet_ESP8266.h"
      #warning Using Ethernet_ESP8266 lib 
      #define SHIELD_TYPE           "W5x00 using Ethernet_ESP8266 Library" 
    #elif USE_ETHERNET_ENC
      #include "EthernetENC.h"
      #warning Using EthernetENC lib
      #define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
    #elif USE_CUSTOM_ETHERNET
      //#include "Ethernet_XYZ.h"
      #include "EthernetENC.h"
      //#warning Using Custom Ethernet library. You must include a library and initialize.
      #define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
    #else
      #ifdef USE_ETHERNET
        #undef USE_ETHERNET
      #endif
      #define USE_ETHERNET   false  //true
      #include "Ethernet.h"
      #warning Using Ethernet lib
      #define SHIELD_TYPE           "W5x00 using Ethernet Library"
    #endif
    
    // Ethernet_Shield_W5200, EtherCard, EtherSia not supported
    // Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
    // Otherwise, standard Ethernet library will be used for W5x00
  
  #endif    //  USE_ETHERNET_WRAPPER

  #if USE_SSL
    // Need ArduinoECCX08 and ArduinoBearSSL libraries
    // Currently, error not enough memory for UNO, Mega2560. Don't use
    #include <BlynkSimpleEthernetSSL_WM.h>
  #else
    #include <BlynkSimpleEthernet_WM.h>
  #endif

#else   ////USE_BLYNK_WM

  // Only one if the following to be true
  #define USE_ETHERNET          true
  #define USE_ETHERNET2         false
 
  #if USE_SSL
    // Need ArduinoECCX08 and ArduinoBearSSL libraries
    // Currently, error not enough memory for UNO, Mega2560. Don't use
    #include <BlynkSimpleEthernetSSL.h>
    #warning Using Ethernet lib
    #define SHIELD_TYPE           "W5x00 using Ethernet Library"
      
    #define BLYNK_SERVER_HARDWARE_PORT    9443
  #else
    #if USE_ETHERNET
      #include <BlynkSimpleEthernet.h>
      #warning Using Ethernet lib
      #define SHIELD_TYPE           "W5x00 using Ethernet Library"
    #else
      #include <BlynkSimpleEthernet2.h>
      #warning Using Ethernet2 lib
      #define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
    #endif
    
    #define BLYNK_SERVER_HARDWARE_PORT    8080
  #endif

  #if defined(BLYNK_INFO_DEVICE)
    #undef BLYNK_INFO_DEVICE
  #endif
  
  #define BLYNK_INFO_DEVICE       BOARD_TYPE
  
  #define USE_LOCAL_SERVER      true
 
#endif    //USE_BLYNK_WM

#define W5100_CS        10
#define SDCARD_CS       4

#define BLYNK_HOST_NAME   "Teensy_W5500-Controller"

#endif      //defines_h
