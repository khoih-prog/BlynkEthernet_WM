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

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
  #error This code is designed to run on SAMD, SAM-DUE, Teensy platform, ESP8266, ESP32 not AVR Mega! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ESP32) || defined(ESP8266) )
  #define DOUBLERESETDETECTOR_DEBUG     true
#else
  #define DRD_GENERIC_DEBUG             false   //true
#endif

#define BLYNK_WM_DEBUG                  1

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
  #if defined(ETHERNET_USE_SAMD)
    #undef ETHERNET_USE_SAMD
  #endif
  #define ETHERNET_USE_SAMD           true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(ETHERNET_USE_SAM_DUE)
    #undef ETHERNET_USE_SAM_DUE
  #endif
  #define ETHERNET_USE_SAM_DUE        true
#endif

#if ( defined(CORE_TEENSY) && !( defined(__MKL26Z64__) || defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) ) )
  #if defined(ETHERNET_USE_TEENSY)
    #undef ETHERNET_USE_TEENSY
  #endif
  #define ETHERNET_USE_TEENSY         true
#endif

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
  #if defined(ETHERNET_USE_NRF52)
    #undef ETHERNET_USE_NRF528XX
  #endif
  #define ETHERNET_USE_NRF528XX         true
#endif

#if defined(ETHERNET_USE_NRF528XX)

  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10

  #if defined(NRF52840_FEATHER)
    #define BOARD_TYPE      "NRF52840_FEATHER"
  #elif defined(NRF52832_FEATHER)
    #define BOARD_TYPE      "NRF52832_FEATHER"
  #elif defined(NRF52840_FEATHER_SENSE)
    #define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
  #elif defined(NRF52840_ITSYBITSY)
    #define BOARD_TYPE      "NRF52840_ITSYBITSY"
  #elif defined(NRF52840_CIRCUITPLAY)
    #define BOARD_TYPE      "NRF52840_CIRCUITPLAY"
  #elif defined(NRF52840_CLUE)
    #define BOARD_TYPE      "NRF52840_CLUE"
  #elif defined(NRF52840_METRO)
    #define BOARD_TYPE      "NRF52840_METRO"
  #elif defined(NRF52840_PCA10056)
    #define BOARD_TYPE      "NRF52840_PCA10056"
  #elif defined(NINA_B302_ublox)
    #define BOARD_TYPE      "NINA_B302_ublox"
  #elif defined(NINA_B112_ublox)
    #define BOARD_TYPE      "NINA_B112_ublox"
  #elif defined(PARTICLE_XENON)
    #define BOARD_TYPE      "PARTICLE_XENON"
  #elif defined(ARDUINO_NRF52_ADAFRUIT)
    #define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
  #else
    #define BOARD_TYPE      "nRF52 Unknown"
  #endif


#elif defined(ETHERNET_USE_SAMD)

  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10

  #if ( defined(ARDUINO_SAMD_ZERO) && !defined(SEEED_XIAO_M0) )
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
  #elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
  #elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
  #elif defined(ADAFRUIT_GEMMA_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
  #elif defined(ADAFRUIT_TRINKET_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
  #elif defined(ADAFRUIT_ITSYBITSY_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
  #elif defined(ARDUINO_SAMD_HALLOWING_M0)
    #define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
  #elif defined(ADAFRUIT_METRO_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
  #elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
  #elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
  #elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
  #elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYPORTAL)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
  #elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
  #elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
  #elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
  #elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
  #elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
  #elif defined(SEEED_WIO_TERMINAL)
    #define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
  #elif defined(SEEED_FEMTO_M0)
    #define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
  #elif defined(SEEED_XIAO_M0)
    #define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
    #define USE_THIS_SS_PIN       A1
    #warning define SEEED_XIAO_M0 USE_THIS_SS_PIN == A1
  #elif defined(Wio_Lite_MG126)
    #define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
  #elif defined(WIO_GPS_BOARD)
    #define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
  #elif defined(SEEEDUINO_ZERO)
    #define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
  #elif defined(SEEEDUINO_LORAWAN)
    #define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
  #elif defined(SEEED_GROVE_UI_WIRELESS)
    #define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
  #elif defined(__SAMD21E18A__)
    #define BOARD_TYPE      "SAMD21E18A"
  #elif defined(__SAMD21G18A__)
    #define BOARD_TYPE      "SAMD21G18A"
  #elif defined(__SAMD51G19A__)
    #define BOARD_TYPE      "SAMD51G19A"
  #elif defined(__SAMD51J19A__)
    #define BOARD_TYPE      "SAMD51J19A"
  #elif defined(__SAMD51J20A__)
    #define BOARD_TYPE      "SAMD51J20A"
  #elif defined(__SAM3X8E__)
    #define BOARD_TYPE      "SAM3X8E"
  #elif defined(__CPU_ARC__)
    #define BOARD_TYPE      "CPU_ARC"
  #elif defined(__SAMD51__)
    #define BOARD_TYPE      "SAMD51"
  #else
    #define BOARD_TYPE      "SAMD Unknown"
  #endif

#elif defined(ETHERNET_USE_SAM_DUE)

  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  
  #if ( defined(ARDUINO_SAM_DUE) || (__SAM3X8E__) )
    #define BOARD_TYPE      "SAM DUE"
  #else
    #define BOARD_TYPE      "SAM Unknown"
  #endif

#elif ( defined(CORE_TEENSY) )

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

#elif ( defined(ESP8266) )

  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  
  // Default pin D2/GIO4 to SS/CS
  #define USE_THIS_SS_PIN       4     // GPIO4 / D2
  
  #warning Use ESP8266 architecture
  #include <ESP8266mDNS.h>
  #define ETHERNET_USE_ESP8266
  #define BOARD_TYPE      ARDUINO_BOARD     //"ESP8266"

#elif ( defined(ESP32) )

  // For ESP32
  // Default pin GPIO 22 to SS/CS
  #define USE_THIS_SS_PIN       22
  
  #warning Use ESP32 architecture
  #define ETHERNET_USE_ESP32
  #define BOARD_TYPE      ARDUINO_BOARD     //"ESP32"
  
#else

  #error Unknown or unsupported Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library" 

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM    false   //true

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
  
  #if ( defined(ESP32) || defined(ESP8266) )
  
    #if defined(ESP8266)
    
      // #define USE_SPIFFS and USE_LITTLEFS   false        => using EEPROM for configuration data in WiFiManager
      // #define USE_LITTLEFS    true                       => using LITTLEFS for configuration data in WiFiManager
      // #define USE_LITTLEFS    false and USE_SPIFFS true  => using SPIFFS for configuration data in WiFiManager
      // Be sure to define USE_LITTLEFS and USE_SPIFFS before #include <BlynkSimpleEsp8266_WM.h>
      // From ESP8266 core 2.7.1, SPIFFS will be deprecated and to be replaced by LittleFS
      // Select USE_LITTLEFS (higher priority) or USE_SPIFFS
      
      #define USE_LITTLEFS                false
      #define USE_SPIFFS                  false
      
      #if USE_LITTLEFS
        //LittleFS has higher priority
        #define CurrentFileFS     "LittleFS"
        #ifdef USE_SPIFFS
          #undef USE_SPIFFS
        #endif
        #define USE_SPIFFS                  false
      #elif USE_SPIFFS
        #define CurrentFileFS     "SPIFFS"
      #endif
    
    #else     //#if defined(ESP8266)
    
      // For ESP32
      // Not use #define USE_LITTLEFS and #define USE_SPIFFS  => using SPIFFS for configuration data in WiFiManager
      // (USE_LITTLEFS == false) and (USE_SPIFFS == false)    => using EEPROM for configuration data in WiFiManager
      // (USE_LITTLEFS == true) and (USE_SPIFFS == false)     => using LITTLEFS for configuration data in WiFiManager
      // (USE_LITTLEFS == true) and (USE_SPIFFS == true)      => using LITTLEFS for configuration data in WiFiManager
      // (USE_LITTLEFS == false) and (USE_SPIFFS == true)     => using SPIFFS for configuration data in WiFiManager
      #define USE_LITTLEFS          true
      #define USE_SPIFFS            false

      #if USE_LITTLEFS
        //LittleFS has higher priority
        #define CurrentFileFS     "LittleFS"
        #ifdef USE_SPIFFS
          #undef USE_SPIFFS
        #endif
        #define USE_SPIFFS                  false
      #elif USE_SPIFFS
        #define CurrentFileFS     "SPIFFS"
      #endif
      
    #endif    //#if defined(ESP8266)
  
  
  #else   //#if ( defined(ESP32) || defined(ESP8266) )
    #define USE_LITTLEFS                  false
    #define USE_SPIFFS                    false
  #endif  //#if ( defined(ESP32) || defined(ESP8266) )
  
  #if !( USE_LITTLEFS || USE_SPIFFS)
  
    #if !( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
      // EEPROM_SIZE must be <= 2048 and >= CONFIG_DATA_SIZE (currently 172 bytes)
      #define EEPROM_SIZE    (2 * 1024)
    #endif
    
    // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
    #define EEPROM_START   0
  #endif
  
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

#define DHT_PIN     5
#define DHT_TYPE    DHT11

#define BLYNK_HOST_NAME   "EthernetENC-Teensy"

#endif      //defines_h
