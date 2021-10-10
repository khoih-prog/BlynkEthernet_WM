## BlynkEthernet_Manager

[![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/BlynkEthernet_WM.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/BlynkEthernet_WM.svg)](http://github.com/khoih-prog/BlynkEthernet_WM/issues)

---
---

## Table of Contents

* [Why do we need this BlynkEthernet_Manager library](#why-do-we-need-this-blynkethernet_manager-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
* [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide)
  * [1. Save the original esp32 core](#1-save-the-original-esp32-core)
  * [2. Install esp32 core v1.0.6](#2-install-esp32-core-v106)
    * [2.1 Install esp32 core](#21-install-esp32-core)
    * [2.2 Download latest zip with esp32-s2 support](#22-download-latest-zip-with-esp32-s2-support)
    * [2.3 Unzip](#23-unzip)
    * [2.3 Update esp32 core directories](#24-update-esp32-core-directories)
  * [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
    * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
    * [3.2 Download esptool](#32-download-esptool)
    * [3.3 Unzip](#33-unzip)
  * [4. Update tools](#4-update-tools)
    * [4.1 Update Toolchain](#41-update-toolchain)
    * [4.2 Update esptool](#42-update-esptool)
  * [5. Download tools for ESP32-C3](#5-download-tools-for-esp32-c3)
  * [6. esp32-s2 WebServer Library Patch](#6-esp32-s2-webserver-library-patch)
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Important Notes](#important-notes)
* [Configuration Notes](#configuration-notes)
  * [1. How to select which built-in Ethernet or shield to use](#1-how-to-select-which-built-in-ethernet-or-shield-to-use)
  * [Important](#important)
  * [2. How to select another CS/SS pin to use](#2-how-to-select-another-csss-pin-to-use)
  * [3. How to use W5x00 with ESP8266](#3-how-to-use-w5x00-with-esp8266)
  * [4. How to increase W5x00 TX/RX buffer](#4-how-to-increase-w5x00-txrx-buffer) 
* [How to use](#how-to-use)
* [HOWTO use default Credentials and have them pre-loaded onto Config Portal](#howto-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [ 1. To load Default Credentials](#1-to-load-default-credentials)
  * [ 2. To use system default to load "blank" when there is no valid Credentials](#2-to-use-system-default-to-load-blank-when-there-is-no-valid-credentials)
  * [ 3. Example of Default Credentials](#3-example-of-default-credentials)
  * [ 4. How to add dynamic parameters from sketch](#4-how-to-add-dynamic-parameters-from-sketch)
  * [ 5. If you don't need to add dynamic parameters](#5-if-you-dont-need-to-add-dynamic-parameters)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Why using this BlynkEthernet_Manager with MultiBlynk features](#why-using-this-blynkethernet_manager-with-multiblynk-features)
* [Examples](#examples)
  * [ 1. AM2315_W5500](examples/AM2315_W5500)
  * [ 2. DHT11_W5500](examples/DHT11_W5500)
  * [ 3. W5500_Blynk](examples/W5500_Blynk)
  * [ 4. W5500_WM_Config](examples/W5500_WM_Config)
  * [ 5. W5500_Blynk_Email](examples/W5500_Blynk_Email)
  * [ 6. W5500_WM_Config_Teensy](examples/W5500_WM_Config_Teensy)
  * [ 7. W5500_Blynk_Email_Teensy](examples/W5500_Blynk_Email_Teensy)
  * [ 8. W5500_Blynk_Teensy](examples/W5500_Blynk_Teensy)
  * [ 9. W5500_WM_Config_SAMD](examples/W5500_WM_Config_SAMD)
  * [10. W5500_Blynk_Email_SAMD](examples/W5500_Blynk_Email_SAMD)
  * [11. W5500_Blynk_SAMD](examples/W5500_Blynk_SAMD)
  * [12. W5500_WM_Config_SAM_DUE](examples/W5500_WM_Conf_SAM_DUE)
  * [13. W5500_Blynk_Email_SAM_DUE](examples/W5500_Blynk_Email_SAM_DUE)
  * [14. W5500_Blynk_SAM_DUE](examples/W5500_Blynk_SAM_DUE)
  * [15. ENC28J60_Blynk](examples/ENC28J60_Blynk)
  * [16. ENC28J60_Blynk_Email](examples/ENC28J60_Blynk_Email)
  * [17. ENC28J60_WM_Config](examples/ENC28J60_WM_Config)
  * [18. nRF52840_BLE_Scanner](examples/nRF52840_BLE_Scanner)
  * [19. W5500_WM_Config_nRF52](examples/W5500_WM_Config_nRF52)
  * [20. W5500_Blynk_Email_nRF52](examples/W5500_Blynk_Email_nRF52)
  * [21. W5500_Blynk_nRF52](examples/W5500_Blynk_nRF52)
  * [22. EthernetENC_Blynk_nRF52](examples/EthernetENC_Blynk_nRF52)
  * [23. EthernetENC_Blynk_SAMD](examples/EthernetENC_Blynk_SAMD)
  * [24. EthernetENC_Blynk_SAM_DUE](examples/EthernetENC_Blynk_SAM_DUE)
  * [25. EthernetENC_Blynk_Teensy](examples/EthernetENC_Blynk_Teensy)
  * [26. NativeEthernet_WM_Config_Teensy](examples/NativeEthernet_WM_Config_Teensy)
  * [27. W5500_WM_Config_RP2040](examples/W5500_WM_Config_RP2040). **New**
  * [28. W5500_Blynk_Email_RP2040](examples/W5500_Blynk_Email_RP2040). **New**
  * [29. W5500_Blynk_RP2040](examples/W5500_Blynk_RP2040). **New**
  * [30. EthernetENC_Blynk_RP2040](examples/EthernetENC_Blynk_RP2040). **New**
* [So, how it works?](#so-how-it-works)
* [Example W5500_Blynk](#example-w5500_blynk)
  * [1. File W5500_Blynk.ino](#1-file-w5500_blynkino)
  * [2. File defines.h](#2-file-definesh) 
  * [3. File Credentials.h](#3-file-credentialsh) 
  * [4. File dynamicParams.h](#4-file-dynamicparamsh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. W5500_WM_Config on ESP32_DEV](#1-w5500_wm_config-on-esp32_dev)
    * [1.1. No DoubleReset Detected => Running normally](#11-no-doublereset-detected--running-normally)
    * [1.2. DoubleReset Detected => Enter Config Portal](#12-doublereset-detected--enter-config-portal)
    * [1.3. Enter non-persistent ConfigPortal](#13-enter-non-persistent-configportal)
    * [1.4. Enter persistent ConfigPortal](#14-enter-persistent-configportal)
  * [2. W5500_WM_Config_SAMD on SAMD21 SEEED_XIAO_M0](#2-w5500_wm_config_samd-on-samd21-seeed_xiao_m0)
    * [2.1. No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal](#21-no-config-data-without-load_default_config_data--config-portal)
    * [2.2. Input valid Credentials and Save => Exit Config Portal](#22-input-valid-credentials-and-save--exit-config-portal)
    * [2.3. Enter non-persistent ConfigPortal](#23-enter-non-persistent-configportal)
    * [2.4. Enter persistent ConfigPortal](#24-enter-persistent-configportal)
  * [3. W5500_WM_Config_SAM_DUE on SAM-DUE](#3-w5500_wm_config_sam_due-on-sam-due)
  * [4. ENC28J60_Blynk on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library](#4-enc28j60_blynk-on-nrf52840_feather-with-enc28j60-using-uipethernet-library)
  * [5. W5500_WM_Config_Teensy on TEENSY 4.0 with W5x00 using EthernetLarge Library](#5-w5500_wm_config_teensy-on-teensy-40-with-w5x00-using-ethernetlarge-library)
  * [6. W5500_WM_Config on ESP8266 with W5x00 using EthernetLarge Library](#6-w5500_wm_config-on-esp8266-with-w5x00-using-ethernetlarge-library)
  * [7. AM2315_W5500 on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library](#7-am2315_w5500-on-raspberry_pi_pico-with-w5x00-using-ethernetlarge-library)
    * [7.1. No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal](#71-no-config-data-without-load_default_config_data--config-portal)
    * [7.2. Input valid Credentials and Save => Exit Config Portal](#72-input-valid-credentials-and-save--exit-config-portal)
  * [8. W5500_Blynk_RP2040 on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library](#8-w5500_blynk_rp2040-on-mbed-raspberry_pi_pico-with-w5x00-using-ethernetlarge-library)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)


---
---

### Why do we need this [BlynkEthernet_Manager library](https://github.com/khoih-prog/BlynkEthernet_WM)

#### Features

This is a Blynk and WiFiManager Library for configuring/auto(re)connecting boards to available MultiBlynk servers at runtime. Connection is with or without SSL. Configuration data to be saved in either LittleFS, SPIFFS, EEPROM, DueFlashStorage or FlashStorage. Default Credentials as well as Dynamic custom parameters can be added and modified easily without coding knowledge. 

DoubleResetDetector is used to force Config Portal opening even if the Credentials are still valid.

This is the new library, adding to the current Blynk_WiFiManager. It's designed to help you eliminate `hardcoding` your Blynk credentials in **Teensy, SAM DUE, SAMD21, SAMD51, nRF52, ESP8266, ESP32, RP2040-based, etc. boards using Ethernet shields (W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet, etc)**. It's currently **not supporting SSL**. 

- It's not supporting UNO/Nano/Mega and other AVR boards for not enough memory.
- You can update Blynk Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in LittleFS, SPIFFS, EEPROM, DueFlashStorage or FlashStorage
- Teensy LC, 2.0++ and 2.0 not supported.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

The **RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**, are currently supported using [**Earle Philhower's arduino-pico** core v1.4.0+](https://github.com/earlephilhower/arduino-pico) or [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) with Blynk/WiFiManager features thanks to LittleFS support. 

New recent features:

- **MultiBlynk** feature for configuring/auto(re)connecting boards to one of the available MultiBlynk Servers at runtime.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

#### Currently supported Boards

This [**EthernetWebServer** library](https://github.com/khoih-prog/EthernetWebServer) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 2. **SAM DUE**
 3. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 4. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0)**
 6. **AVR Mega1280, 2560, ADK.**
 7. **ESP32 including ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)**
 8. ESP8266
 
 9. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [Earle Philhower's arduino-pico core](https://github.com/earlephilhower/arduino-pico).

10. RP2040-based boards, such as **Nano RP2040 Connect**, using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
 
11. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed)


#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge), [`Ethernet2`](https://github.com/adafruit/Ethernet2) or [`Ethernet3`](https://github.com/sstaub/Ethernet3) library
2. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
3. Teensy 4.1 built-in NativeEthernet using [NativeEthernet Library](https://github.com/vjmuzik/NativeEthernet)

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.16+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Teensy core v1.55+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards using W5500, ENC28J60 Ethernet shields. [`Teensy core v1.55+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1) boards using NativeEthernet.
 4. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 5. [`Arduino SAMD core 1.8.11+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 6. [`Adafruit SAMD core 1.7.5+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 7. [`Seeeduino SAMD core 1.8.2+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 
 8. [`Adafruit nRF52 v1.1.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
  
 9. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
10. [`ESP32 Core 2.0.0+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg?style=plastic)](https://github.com/espressif/arduino-esp32/releases/latest/)
11. [`Earle Philhower's arduino-pico core v1.9.5+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
12. [`Arduino mbed_rp2040 core 2.5.2+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) RP2040-based boards, such as RASPBERRY_PI_PICO. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
13. [`Blynk library 1.0.1`](https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1). [![Latest release](https://img.shields.io/github/release/blynkkk/blynk-library.svg)](https://github.com/blynkkk/blynk-library/releases/latest/). Never use the `Blynk beta` versions. You can also use [`Blynk library v1.0.0`](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0)

14. Depending on which Ethernet card you're using:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
   - [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.10+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest). It's not advisable to use this library. Use [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) instead.
   - [`NativeEthernet Library version stable111+`](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1 built-in NativeEthernet. **New**
15. Depending on which board you're using:
   - [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DueFlashStorage.svg?)](https://www.ardu-badge.com/DueFlashStorage)
   - [`FlashStorage_SAMD library v1.2.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.). [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest)
16. [`EthernetWebServer library v1.7.1+`](https://github.com/khoih-prog/EthernetWebServer). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
17. [`ESP_DoubleResetDetector library v1.1.1+`](https://github.com/khoih-prog/ESP_DoubleResetDetector) for ESP32 and ESP8266.  To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_DoubleResetDetector.svg?)](https://www.ardu-badge.com/ESP_DoubleResetDetector).
18. [`DoubleResetDetector_Generic library v1.7.2+`](https://github.com/khoih-prog/DoubleResetDetector_Generic) for other boards (not ESP32 or ESP8266). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic).
19. [`Functional-VLPP library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
20. [`ArduinoBearSSL library`](https://github.com/khoih-prog/ArduinoBearSSL) for SSL (not working yet)
21. [`ArduinoECCX08  library`](https://github.com/khoih-prog/ArduinoECCX08)  for SSL (not working yet)

---
---

### Installation

The suggested way to install is :

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `BlynkEthernet_WM`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager) for more detailed instructions.

Then copy

#### For Blynk v0.6.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkProtocol.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkProtocol.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkProtocol.h`.
3. [BlynkDebug.cpp](LibraryPatches/Blynk-0.6.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

#### For Blynk v1.0.0

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-1.0.0/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkDebug.cpp](LibraryPatches/Blynk-1.0.0/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

---

#### Manual Install

1. Navigate to [BlynkEthernet_WM](https://github.com/khoih-prog/BlynkEthernet_WM) page.
2. Download the latest release `BlynkEthernet_WM-master.zip`.
3. Extract the zip file to `BlynkEthernet_WM-master` directory 
4. Copy whole 
  - `BlynkEthernet_WM-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.
  
Then copy

#### For Blynk v0.6.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkProtocol.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkProtocol.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkProtocol.h`.
3. [BlynkDebug.cpp](LibraryPatches/Blynk-0.6.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

#### For Blynk v1.0.0

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-1.0.0/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkDebug.cpp](LibraryPatches/Blynk-1.0.0/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.
  
  By doing this, the correct board type can be displayed correctly along with Blynk logo as follows:

```
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on NRF52840_ITSYBITSY_EXPRESS
```

not just unknown Arduino board type:

```
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino
```

---

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**BlynkEthernet_Manager** library](https://platformio.org/lib/show/11685/BlynkEthernet_Manager) by using [Library Manager](https://platformio.org/lib/show/11685/BlynkEthernet_Manager/installation). Search for **BlynkEthernet_Manager** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.1.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0). 

Supposing the Adafruit nRF52 version is 1.1.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.15/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.15. These files must be copied into the directory:

- `./arduino-1.8.15/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.11) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.11).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.11. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.11/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.5) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.5). 

Supposing the Adafruit SAMD core version is 1.7.5. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2). 

Supposing the Seeeduino SAMD core version is 1.8.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.1.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.1.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.1.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.1.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.1.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.1.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`

---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)


---
---

## HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE


These are instructions demonstrating the steps to install esp32-s2/c3 core on Ubuntu machines. For Windows or other OS'es, just follow the the similar principles and steps.

* Windows 10, follows these steps in [Steps to install Arduino ESP32 support on Windows](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md) 

* Mac OS, follows these steps in [Installation instructions for Mac OS](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/mac.md)

* Fedora, follows these steps in [Installation instructions for Fedora](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/fedora.md)

* openSUSE, follows these steps in [Installation instructions for openSUSE](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/opensuse.md)

* You can also try to add [package_esp32_dev_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json) into Arduino IDE `File - Preferences - Additional Boards Manager URLs` 


```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
```

and have Board Manager auto-install the **development** esp32 core. For example : esp32 core `v2.0.0-alpha1`


---

If you're already successful in testing the core, after installing by using the above procedures, you don't need to follows the hereafter manual steps.

---

Assuming you already installed Arduino IDE ESP32 core and the installed directory is

`/home/your_account/.arduino15/packages/esp32`


### 1. Save the original esp32 core

First, copy the whole original esp32 core to another safe place. Then delete all the sub-directories of

`/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.4`

---


### 2. Install esp32 core v1.0.6

#### 2.1 Install esp32 core

Just use Arduino IDE Board Manager to install [ESP32 Arduino Release 1.0.6 based on ESP-IDF v3.3.5](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6). This official v1.06 core doesn't have esp32-s2/s3 support. You have to download and use the latest master branch.


#### 2.2 Download latest zip with esp32-s2 support

As of **April 16th 2021**, the **esp32-s2/c3** board support has been included in master branch of esp32 core. Download [**esp32 core, master branch**](https://github.com/espressif/arduino-esp32) in the zip format.

#### 2.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/esp32_s2_Core_Unzipped.png">
</p>

#### 2.4 Update esp32 core directories

Copy all subdirectories of esp32 core into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6`


---

### 3 Download tools for ESP32-S2


#### 3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC

Download [**esp32-s2 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#xtensa-esp32s2-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example `xtensa-esp32s2-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz`, then un-archive.


<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/esp32_s2_Toolchain.png">
</p>

#### 3.2 Download esptool


Download [esptool](https://github.com/espressif/esptool/releases) int the `zip` format:

`esptool-3.0.zip`

#### 3.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/esp32_s2_esptool.png">
</p>

---

### 4. Update tools

#### 4.1 Update Toolchain

Copy whole `xtensa-esp32s2-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


#### 4.2 Update esptool

Rename `esptool-3.0` directory to `esptool`


Copy whole `esptool` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/esp32_s2_tools.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/BlynkEthernet_WM_ESP32_S2_Support.png">
</p>


### 5 Download tools for ESP32-C3

Download [**esp32-c3 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#riscv32-esp-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example`riscv32-esp-elf-gcc8_4_0-crosstool-ng-1.24.0-123-g64eb9ff-linux-amd64.tar.gz`, then un-archive.

Then using the similar steps as in

* [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
  * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
  * [3.2 Download esptool](#32-download-esptool)
  * [3.3 Unzip](#33-unzip)
* [4. Update tools](#4-update-tools)
  * [4.1 Update Toolchain](#41-update-toolchain)
  * [4.2 Update esptool](#42-update-esptool)

then copy whole `riscv32-esp-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


### 6. esp32-s2 WebServer Library Patch

#### Necessary only for esp32 core v1.0.6-

If you haven't installed a new version with [WebServer.handleClient delay PR #4350](https://github.com/espressif/arduino-esp32/pull/4350) or haven't applied the above mentioned PR, you have to use the following patch.


**To be able to run Config Portal on ESP32-S2 boards**, you have to copy the files in [esp32-s2 WebServer Patch](esp32s2_WebServer_Patch/) directory into esp32-s2 WebServer library directory (~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer).

Supposing the esp32-s2 version is 1.0.4, these files `WebServer.h/cpp` must be copied into the directory to replace:

- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.h`
- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.cpp`


---

That's it. You're now ready to compile and test for **ESP32-S2 and ESP32-C3** now

---
---

### Note for Platform IO using ESP32 LittleFS

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.6+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---


### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### Important Notes

1. Code is restructured to provide flexibility to make it easy to support many more **WiFi/Ethernet** modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

2. For **Adafruit nRF52**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = MO(SI)
  - SPI_MISO  = MI(SO)
  - SPI_SCK   = SCK

3. For **Adafruit SAMD21/SAMD51**, use the SPI's CS/SS pin as follows:

  - Itsy-Bitsy M0/M4, Feather M0 (Express), Hallowing M0 Express, Zero, Metro M0 => use CS = 16 = pin A2
  - Feather M4 (SAMD51)   => use SS/CS = 9
  - Grand Central M4      => use SS/CS = 53
  - Hallowing M4          => use SS/CS = 10
  - Metro M4 AirLift      => use SS/CS = 36

To know the default CS/SS pins of not listed boards, check the related `variant.h` files in 

`~/.arduino15/packages/adafruit/hardware/samd/x.y.zz/variants/board_name/variant.h`

4. For **Arduino SAM DUE**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = 75 ( pin 4 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_MISO  = 74 ( pin 1 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_SCK   = 76 ( pin 3 @ [ICSP connector](pics/ICSP_connector.jpg) )
  
<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/ICSP_connector.jpg">
</p>
  

---
---

### Configuration Notes

#### 1. How to select which built-in Ethernet or shield to use

The easiest way is to use 

```cpp
#define USE_ETHERNET_WRAPPER    true
```

then select **one and only one** Ethernet library to use as follows:

- Standard W5x00 Ethernet library is used by default, in the sketch, just be sure to comment out or leave these #defines to be false :

```cpp
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET          true
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ESP8266  false 
#define USE_ETHERNET_ENC      false
#define USE_CUSTOM_ETHERNET   false
```

To use W5x00 Ethernet, for example using EthernetLarge library

```cpp
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           false
#define USE_ETHERNET_LARGE      true
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        false
#define USE_CUSTOM_ETHERNET     false
```

- To use ENC28J60 Ethernet, using EthernetENC library (**NEW and Better**)

```cpp
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           false
#define USE_ETHERNET_LARGE      false
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        true
#define USE_CUSTOM_ETHERNET     false
```

- To use ENC28J60 Ethernet, using UIPEthernet library:

```cpp
#define USE_UIP_ETHERNET        true

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           false
#define USE_ETHERNET_LARGE      false
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        false
#define USE_CUSTOM_ETHERNET     false
```

- To use any of the Ethernet libraries, such as Ethernet2, Ethernet3, EthernetLarge, EthernetENC:

```cpp
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           true
#define USE_ETHERNET_LARGE      false
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        false
#define USE_CUSTOM_ETHERNET     false
```

- To use another Ethernet library
For example, Ethernet_XYZ library uses **Ethernet_XYZ.h**

```cpp
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           false
#define USE_ETHERNET_LARGE      false
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        false
#define USE_CUSTOM_ETHERNET     true

//Must be placed before #include <EthernetWebServer.h>
#include <Ethernet_XYZ.h>
...

#include <EthernetWebServer.h>
```

- Only for Teensy 4.1, to use NativeEthernet library

```
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
  ....
```

- Only for Teensy 4.1, to use another Ethernet library, for example Ethernet3 library

```
#if defined(__IMXRT1062__)
  // For Teensy 4.1/4.0
  #if defined(ARDUINO_TEENSY41)
    #define BOARD_TYPE      "TEENSY 4.1"
    // Use true for NativeEthernet Library, false if using other Ethernet libraries
    #define USE_NATIVE_ETHERNET     false
  #elif defined(ARDUINO_TEENSY40)
    #define BOARD_TYPE      "TEENSY 4.0"
  #else
    #define BOARD_TYPE      "TEENSY 4.x"
  #endif      
#elif defined(__MK66FX1M0__)
  ....
  
#define USE_UIP_ETHERNET        false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false
#define USE_ETHERNET3           true
#define USE_ETHERNET_LARGE      false
#define USE_ETHERNET_ESP8266    false
#define USE_ETHERNET_ENC        false
#define USE_CUSTOM_ETHERNET     false  
```
---

#### Important:

- The **Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported**. Don't use unless you know how to modify those libraries.
- Requests to support for any future custom Ethernet library will be ignored. **Use at your own risk**.

---

#### 2. How to select another CS/SS pin to use

The default CS/SS pin is GPIO4(D2) for ESP8266, GPIO22 for ESP32, 10 for all other boards.

If the default pin is not corect, the easiest way is to change is to use 

```cpp
#define USE_ETHERNET_WRAPPER    true
```

then select the CS/SS pin (e.g. 22) to use as follows:

```cpp
// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
#define USE_THIS_SS_PIN   22
```

#### 3. How to use W5x00 with ESP8266

To avoid using the default but not-working Ethernet library of ESP8266, rename the Ethernet.h/cpp to Ethernet_ESP8266.h/cpp to avoid library conflict if you're using the Arduino Ethernet library. The Ethernet2, Ethernet3, EthernetLarge library can be used without conflict.

These pins are tested OK with ESP8266 and W5x00

```cpp
  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);

```

#### 4. How to increase W5x00 TX/RX buffer

- For **Ethernet3** library only,  use as follows

```cpp
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #ifndef ETHERNET3_MAX_SOCK_NUM
    #define ETHERNET3_MAX_SOCK_NUM      4
  #endif
  
  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
```

---
---


### How to use

In your code, replace

1. `BlynkSimpleEthernet.h`      with `BlynkSimpleEthernet_WM.h`        for board using W5x00 `without SSL`
2. `BlynkSimpleEthernet2.h`     with `BlynkSimpleEthernet2_WM.h`       for board using only W5500 `without SSL`
3. `BlynkSimpleEthernetV2_0.h`  with `BlynkSimpleEthernetV2_0_WM.h`    for board using only W5500 `without SSL`
4. `BlynkSimpleUIPEthernet.h`   with `BlynkSimpleUIPEthernet_WM.h`     for board using ENC28J60 and UIPEthernet library `without SSL`
5. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleEthernetSSL_WM.h`     for other boards (not Mega) using W5200, W5500 `with SSL (not working yet)`
6. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleUIPEthernetSSL_WM.h`  for other AVR boards (not Mega) using ENC28J60 `with SSL (not working yet)`
7. `BlynkSimpleEthernet.h`      with `BlynkSimpleEthernetENC_WM.h`     for board using ENC28J60 and EthernetENC library `without SSL`


```
// Start location to store config data to avoid conflict with other functions
#define EEPROM_START   0

```

Then replace `Blynk.begin(...)` with :

1. `Blynk.begin()`

in your code. Keep `Blynk.run()` intact.

That's it.

---

### HOWTO use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To load [Default Credentials](examples/W5500_Blynk/Credentials.h)

```
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To use system default to load "blank" when there is no valid Credentials


```
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](examples/W5500_Blynk/Credentials.h)


```cpp
/// Start Default Config Data //////////////////

/*
  #define BLYNK_SERVER_MAX_LEN      32
#define BLYNK_TOKEN_MAX_LEN       36

typedef struct
{
  char blynk_server[BLYNK_SERVER_MAX_LEN];
  char blynk_token [BLYNK_TOKEN_MAX_LEN];
}  Blynk_Credentials;

#define NUM_BLYNK_CREDENTIALS     2

// Configurable items besides fixed Header
#define NUM_CONFIGURABLE_ITEMS    ( 3 + (2 * NUM_BLYNK_CREDENTIALS) )

typedef struct Configuration
{
  char header         [16];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char static_IP      [16];
  char board_name     [24];
  int  checkSum;
} Blynk_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      true

#if TO_LOAD_DEFAULT_CONFIG_DATA

bool LOAD_DEFAULT_CONFIG_DATA = true;

Blynk_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL
  "SSL",
#else
  "NonSSL",
#endif
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.duckdns.org",  "token1",
  "blynk-cloud.com",     "<<my real Blynk auth>>",
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  // char static_IP      [16];
  //"192.168.2.230",
  // Use dynamic DHCP IP
  "",
  //char board_name     [24];
  "Air-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

#### 4. How to add dynamic parameters from sketch

- To add custom parameters, just modify from the example below

In `defines.h`

```
#define USE_DYNAMIC_PARAMETERS     false
```

in `dynamicParams.h`

```
#if (USE_DYNAMIC_PARAMETERS)
  #warning USE_DYNAMIC_PARAMETERS
#endif

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in BlynkEthernet_WM.h, <BlynkEthernet_ESP8266_WM.h>, <BlynkEthernet_ESP32 or_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
#endif


/////// // End dynamic Credentials ///////////

```

#### 5. If you don't need to add dynamic parameters

Use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS     false
```

---
---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"sv"    for Blynk Server
"tk"    for Blynk Token
"sv1"   for Blynk Server1
"tk1"   for Blynk Token1
"pt"    for Blynk Port
"ip"    for Static IP Address
"nm"    for Board Name
```

---
---

### Why using this [BlynkEthernet_Manager](https://github.com/khoih-prog/BlynkEthernet_WM) with MultiBlynk features

You can see that the system **automatically detects and connects to the avaiable Blynk Servers**, whenever interruption happens. This feature is very useful for systems requiring high degree of reliability.

Moreover, this `Blynk.begin()` is **not a blocking call**, so you can use it for critical functions requiring in loop().

Anyway, this is better for projects using Blynk just for GUI (graphical user interface).

In operation, if WiFi or Blynk connection is lost, `Blynk.run()` will try reconnecting automatically. Therefore, `Blynk.run()` must be called in the `loop()` function. Don't use:

```cpp
void loop()
{
  if (Blynk.connected())
     Blynk.run();
     
  ...
}
```
just

```cpp
void loop()
{
  Blynk.run();
  ...
}
```

---
---

### Examples

 1. [AM2315_W5500](examples/AM2315_W5500)
 2. [DHT11_W5500](examples/DHT11_W5500)
 3. [W5500_Blynk](examples/W5500_Blynk) 
 4. [W5500_WM_Config](examples/W5500_WM_Config)
 5. [W5500_Blynk_Email](examples/W5500_Blynk_Email)
 6. [W5500_WM_Config_Teensy](examples/W5500_WM_Config_Teensy)
 7. [W5500_Blynk_Email_Teensy](examples/W5500_Blynk_Email_Teensy)
 8. [W5500_Blynk_Teensy](examples/W5500_Blynk_Teensy) 
 9. [W5500_WM_Config_SAMD](examples/W5500_WM_Config_SAMD)
10. [W5500_Blynk_Email_SAMD](examples/W5500_Blynk_Email_SAMD)
11. [W5500_Blynk_SAMD](examples/W5500_Blynk_SAMD) 
12. [W5500_WM_Config_SAM_DUE](examples/W5500_WM_Conf_SAM_DUE)
13. [W5500_Blynk_Email_SAM_DUE](examples/W5500_Blynk_Email_SAM_DUE)
14. [W5500_Blynk_SAM_DUE](examples/W5500_Blynk_SAM_DUE) 
15. [ENC28J60_Blynk](examples/ENC28J60_Blynk)
16. [ENC28J60_Blynk_Email](examples/ENC28J60_Blynk_Email)
17. [ENC28J60_WM_Config](examples/ENC28J60_WM_Config)
18. [nRF52840_BLE_Scanner](examples/nRF52840_BLE_Scanner)
19. [W5500_WM_Config_nRF52](examples/W5500_WM_Config_nRF52)
20. [W5500_Blynk_Email_nRF52](examples/W5500_Blynk_Email_nRF52)
21. [W5500_Blynk_nRF52](examples/W5500_Blynk_nRF52)
22. [EthernetENC_Blynk_nRF52](examples/EthernetENC_Blynk_nRF52)
23. [EthernetENC_Blynk_SAMD](examples/EthernetENC_Blynk_SAMD)
24. [EthernetENC_Blynk_SAM_DUE](examples/EthernetENC_Blynk_SAM_DUE)
25. [EthernetENC_Blynk_Teensy](examples/EthernetENC_Blynk_Teensy)
26. [NativeEthernet_WM_Config_Teensy](examples/NativeEthernet_WM_Config_Teensy)
27. [**W5500_WM_Config_RP2040**](examples/W5500_WM_Config_RP2040). **New**
28. [**W5500_Blynk_Email_RP2040**](examples/W5500_Blynk_Email_RP2040). **New**
29. [**W5500_Blynk_RP2040**](examples/W5500_Blynk_RP2040). **New**
30. [**EthernetENC_Blynk_RP2040**](examples/EthernetENC_Blynk_RP2040). **New**
  
---

## So, how it works?
If no valid config data are stored in EEPROM, it will switch to `Configuration Mode`. Connect to access point at the IP address displayed on Terminal or Router's DHCP server as in the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_1.png">
</p>

After you connected to, for example, `192.168.2.86`, the Browser will display the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_2.png">
</p>

Enter your credentials (Blynk Servers/Tokens and Port). If you prefer static IP, input it (for example `192.168.2.220`) in the corresponding field. Otherwise, just leave it `blank` or `nothing` to use auto IP assigned by DHCP server.

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_3.png">
</p>

Then click `Save`. After the  board auto-restarted, you will see if it's connected to your Blynk server successfully as in  the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_4.png">
</p>

This `Blynk.begin()` is not a blocking call, so you can use it for critical functions requiring in loop(). 
Anyway, this is better for projects using Blynk just for GUI (graphical user interface).

In operation, if Ethernet or Blynk connection is lost, `Blynk.run()` will try reconnecting automatically. Therefore, `Blynk.run()` must be called in the `loop()` function. Don't use:

```cpp
void loop()
{
  if (Blynk.connected())
     Blynk.run();
     
  ...
}
```
just

```cpp
void loop()
{
  Blynk.run();
  ...
}
```


---
---

### Example [W5500_Blynk](examples/W5500_Blynk)

#### 1. File [W5500_Blynk.ino](examples/W5500_Blynk/W5500_Blynk.ino)

```
#include <SPI.h>

#include "defines.h"
#include "Credentials.h"

#if USE_BLYNK_WM
  
  #include "dynamicParams.h"

  #define BLYNK_PIN_FORCED_CONFIG           V10
  #define BLYNK_PIN_FORCED_PERS_CONFIG      V20

// Use button V10 (BLYNK_PIN_FORCED_CONFIG) to forced Config Portal
BLYNK_WRITE(BLYNK_PIN_FORCED_CONFIG)
{ 
  if (param.asInt())
  {
    Serial.println( F("\nCP Button Hit. Rebooting") ); 

    // This will keep CP once, clear after reset, even you didn't enter CP at all.
    Blynk.resetAndEnterConfigPortal(); 
  }
}

// Use button V20 (BLYNK_PIN_FORCED_PERS_CONFIG) to forced Persistent Config Portal
BLYNK_WRITE(BLYNK_PIN_FORCED_PERS_CONFIG)
{ 
  if (param.asInt())
  {
    Serial.println( F("\nPersistent CP Button Hit. Rebooting") ); 
   
    // This will keep CP forever, until you successfully enter CP, and Save data to clear the flag.
    Blynk.resetAndEnterConfigPortalPersistent();
  }
}

#endif

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  delay(200);

#if ( USE_LITTLEFS || USE_SPIFFS)
  Serial.print(F("\nStart W5500_Blynk using ")); Serial.print(CurrentFileFS);
  Serial.print(F(" on ")); Serial.print(BOARD_NAME);
#else
  Serial.print(F("\nStart W5500_Blynk on ")); Serial.print(BOARD_NAME);
#endif

  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);

#if USE_BLYNK_WM 
  Serial.println(BLYNK_ETHERNET_WM_VERSION);
#endif

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  #if USE_ETHERNET_WRAPPER

    EthernetInit();

  #else

    #if USE_ETHERNET
      Serial.println(F("=========== USE_ETHERNET ==========="));
    #elif USE_ETHERNET2
      Serial.println(F("=========== USE_ETHERNET2 ==========="));
    #elif USE_ETHERNET3
      Serial.println(F("=========== USE_ETHERNET3 ==========="));
    #elif USE_ETHERNET_LARGE
      Serial.println(F("=========== USE_ETHERNET_LARGE ==========="));
    #elif USE_ETHERNET_ESP8266
      Serial.println(F("=========== USE_ETHERNET_ESP8266 ==========="));
    #else
      Serial.println(F("========================="));
    #endif
   
      Serial.println(F("Default SPI pinout:"));
      Serial.print(F("MOSI:")); Serial.println(MOSI);
      Serial.print(F("MISO:")); Serial.println(MISO);
      Serial.print(F("SCK:"));  Serial.println(SCK);
      Serial.print(F("SS:"));   Serial.println(SS);
      Serial.println(F("========================="));
       
    #if defined(ESP8266)
      // For ESP8266, change for other boards if necessary
      #ifndef USE_THIS_SS_PIN
        #define USE_THIS_SS_PIN   D2    // For ESP8266
      #endif
      
      Serial.print(F("ESP8266 setCsPin::")); Serial.println(USE_THIS_SS_PIN);
      
      #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 )
        // For ESP8266
        // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
        // Ethernet           0                 X            X            X            X        0
        // Ethernet2          X                 X            X            X            X        0
        // Ethernet3          X                 X            X            X            X        0
        // EthernetLarge      X                 X            X            X            X        0
        // Ethernet_ESP8266   0                 0            0            0            0        0
        // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
        // Must use library patch for Ethernet, EthernetLarge libraries
        //Ethernet.setCsPin (USE_THIS_SS_PIN);
        Ethernet.init (USE_THIS_SS_PIN);
  
      #elif USE_ETHERNET3
        // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
        #ifndef ETHERNET3_MAX_SOCK_NUM
          #define ETHERNET3_MAX_SOCK_NUM      4
        #endif
        
        Ethernet.setCsPin (USE_THIS_SS_PIN);
        Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
 
      #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
        
    #elif defined(ESP32)
  
      // You can use Ethernet.init(pin) to configure the CS pin
      //Ethernet.init(10);  // Most Arduino shields
      //Ethernet.init(5);   // MKR ETH shield
      //Ethernet.init(0);   // Teensy 2.0
      //Ethernet.init(20);  // Teensy++ 2.0
      //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
      //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet
      
      #ifndef USE_THIS_SS_PIN
        #define USE_THIS_SS_PIN   22    // For ESP32
      #endif
      
      Serial.print(F("ESP32 setCsPin::")); Serial.println(USE_THIS_SS_PIN);
      
      // For other boards, to change if necessary
      #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 )
        // Must use library patch for Ethernet, EthernetLarge libraries
        // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
        // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3
           
        //Ethernet.setCsPin (USE_THIS_SS_PIN);
        Ethernet.init (USE_THIS_SS_PIN);
  
      #elif USE_ETHERNET3
        // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
        #ifndef ETHERNET3_MAX_SOCK_NUM
          #define ETHERNET3_MAX_SOCK_NUM      4
        #endif
        
        Ethernet.setCsPin (USE_THIS_SS_PIN);
        Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
              
      #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
  
    #else   //defined(ESP8266)
      // unknown board, do nothing, use default SS = 10
      #ifndef USE_THIS_SS_PIN
        #define USE_THIS_SS_PIN   10    // For other boards
      #endif
           
      Serial.print(BOARD_NAME); Serial.print(F(" setCsPin::")); Serial.println(USE_THIS_SS_PIN);
  
      // For other boards, to change if necessary
      #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 )
        // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
  
        Ethernet.init (USE_THIS_SS_PIN);
  
      #elif USE_ETHERNET3
        // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
        #ifndef ETHERNET3_MAX_SOCK_NUM
          #define ETHERNET3_MAX_SOCK_NUM      4
        #endif
        
        Ethernet.setCsPin (USE_THIS_SS_PIN);
        Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
                        
      #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
      
    #endif    //defined(ESP8266)
  
  
  #endif  //USE_ETHERNET_WRAPPER

#if USE_BLYNK_WM
  Blynk.begin();
#else
#if USE_LOCAL_SERVER
  Blynk.begin(auth, server, BLYNK_SERVER_HARDWARE_PORT);
#else
  //Blynk.begin(auth);
  // You can also specify server:
  Blynk.begin(auth, server, BLYNK_SERVER_HARDWARE_PORT);
#endif
#endif

  if (Blynk.connected())
  {
#if USE_BLYNK_WM    
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(Blynk.getServerName());
    Serial.print(F(", port = "));
    Serial.println(Blynk.getHWPort());
    Serial.print(F("Token = "));
    Serial.print(Blynk.getToken());
   
#else
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(server);
    Serial.print(F(", port = "));
    Serial.println(BLYNK_SERVER_HARDWARE_PORT);
    Serial.print(F("Token = "));
    Serial.print(auth);   
#endif
    Serial.print(F(", IP = "));
    Serial.println(Ethernet.localIP());
  }
}

void heartBeatPrint()
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

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
void displayCredentials()
{
  Serial.println("\nYour stored Credentials :");

  for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}

void displayCredentialsInLoop()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
  displayCredentialsInLoop();
#endif  
}
```

#### 2. File [defines.h](examples/W5500_Blynk/defines.h)

```
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

#if ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) )
  #if defined(ETHERNET_USE_RPIPICO)
    #undef ETHERNET_USE_RPIPICO
  #endif
  #define ETHERNET_USE_RPIPICO      true
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
  #if defined(ETHERNET_USE_NRF528XX)
    #undef ETHERNET_USE_NRF528XX
  #endif
  #define ETHERNET_USE_NRF528XX         true
#endif

#if defined(ETHERNET_USE_SAMD)
  // For SAMD
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
    #define USE_THIS_SS_PIN       10
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
    #ifdef USE_THIS_SS_PIN
      #undef USE_THIS_SS_PIN
    #endif
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

#elif (ETHERNET_USE_SAM_DUE)
  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  #define BOARD_TYPE      "SAM DUE"

#elif (ETHERNET_USE_NRF528XX)
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
    #define USE_THIS_SS_PIN   10    // For other boards
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
  #warning Use ESP8266 architecture
  #include <ESP8266mDNS.h>
  #define ETHERNET_USE_ESP8266
  #define BOARD_TYPE      "ESP8266"

#elif ( defined(ESP32) )
  // For ESP32
  #warning Use ESP32 architecture
  #define ETHERNET_USE_ESP32
  #define BOARD_TYPE      "ESP32"
  
  #define W5500_RST_PORT   21

#elif ETHERNET_USE_RPIPICO
  
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

    // For RPI Pico
    #warning Use RPI-Pico Mbed RP2040 architecture
    
  #else
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    #define USE_THIS_SS_PIN       17

    // For RPI Pico
    #warning Use RPI-Pico RP2040 architecture 

  #endif
    
  #define SS_PIN_DEFAULT        USE_THIS_SS_PIN

   
  
#else

  #error Unknown or unsupported Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define USE_BLYNK_WM      true

#define USE_SSL   false

#define USE_SSL   false

#if USE_BLYNK_WM

  #define USE_DYNAMIC_PARAMETERS                    true

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
  
  // To use faster 25MHz clock instead of defaulf 14MHz. Only for W5200 and W5500. W5100 also tested OK.
  //#define USE_W5100     false
  
  //#define USE_ETHERNET_WRAPPER    true
  #define USE_ETHERNET_WRAPPER    false
  
  // Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
  // Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)
  
  //#define USE_UIP_ETHERNET   true
  //#define USE_UIP_ETHERNET   false
  
  #define USE_CUSTOM_ETHERNET     false //true
  
  // Note: To rename ESP628266 Ethernet lib files to Ethernet_ESP8266.h and Ethernet_ESP8266.cpp
  // In order to USE_ETHERNET_ESP8266
  #if ( !defined(USE_UIP_ETHERNET) || !USE_UIP_ETHERNET )
  
    // To override the default CS/SS pin. Don't use unless you know exactly which pin to use
    // You can define here or customize for each board at same place with BOARD_TYPE
    // Check @ defined(SEEED_XIAO_M0)
    //#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
    
    // Only one if the following to be true
    #define USE_ETHERNET          false
    #define USE_ETHERNET2         false
    #define USE_ETHERNET3         false
    #define USE_ETHERNET_LARGE    true
    #define USE_ETHERNET_ESP8266  false 
    #define USE_CUSTOM_ETHERNET   false
    
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
        #define SHIELD_TYPE           "Custom Ethernet using Teensy 4.1 NativeEthernet Library"
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
       #elif USE_CUSTOM_ETHERNET
        //#include "Ethernet_XYZ.h"
        #include "EthernetENC.h"
        #warning Using Custom Ethernet library. You must include a library and initialize.
        #define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
      #else
        #ifdef USE_ETHERNET
          #undef USE_ETHERNET
        #endif
        #define USE_ETHERNET   true
        #include "Ethernet.h"
        #warning Using Ethernet lib
        #define SHIELD_TYPE           "W5x00 using Ethernet Library"
      #endif
    
      // Ethernet_Shield_W5200, EtherCard, EtherSia not supported
      // Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
      // Otherwise, standard Ethernet library will be used for W5x00
    
    #endif    //USE_ETHERNET_WRAPPER
  #endif    //#if !USE_UIP_ETHERNET
  
  
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
  
#endif    //USE_BLYNK_WM

#define W5100_CS        10
#define SDCARD_CS       4

#define BLYNK_HOST_NAME   "W5500-Master-Controller"

#endif      //defines_h
```

#### 3. File [Credentials.h](examples/W5500_Blynk/Credentials.h)

```
#ifndef Credentials_h
#define Credentials_h

#include "defines.h"

#if USE_BLYNK_WM

/// Start Default Config Data //////////////////

/*
  #define BLYNK_SERVER_MAX_LEN      32
#define BLYNK_TOKEN_MAX_LEN       36

typedef struct
{
  char blynk_server[BLYNK_SERVER_MAX_LEN];
  char blynk_token [BLYNK_TOKEN_MAX_LEN];
}  Blynk_Credentials;

#define NUM_BLYNK_CREDENTIALS     2

// Configurable items besides fixed Header
#define NUM_CONFIGURABLE_ITEMS    ( 3 + (2 * NUM_BLYNK_CREDENTIALS) )

typedef struct Configuration
{
  char header         [16];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char static_IP      [16];
  char board_name     [24];
  int  checkSum;
} Blynk_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      true

#if TO_LOAD_DEFAULT_CONFIG_DATA

bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL
  "SSL",
#else
  "NonSSL",
#endif
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.duckdns.org",  "token1",
  "blynk-cloud.com",     "<<my real Blynk auth>>",
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  // char static_IP      [16];
  //"192.168.2.230",
  // Use dynamic DHCP IP
  "",
  //char board_name     [24];
  "Air-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////

#else     //#if USE_BLYNK_WM

#define USE_LOCAL_SERVER      true

#if USE_LOCAL_SERVER
char auth[] = "******";
char server[] = "account.duckdns.org";
//char server[] = "192.168.2.112";
#else
char auth[] = "******";
char server[] = "blynk-cloud.com";
#endif

#endif      //#if USE_BLYNK_WM

#endif    //Credentials_h
```

#### 4. File [dynamicParams.h](examples/W5500_Blynk/dynamicParams.h)

```
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

#if USE_BLYNK_WM

#if (USE_DYNAMIC_PARAMETERS)
  #warning USE_DYNAMIC_PARAMETERS
#endif

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in BlynkEthernet_WM.h, <BlynkEthernet_ESP8266_WM.h>, <BlynkEthernet_ESP32 or_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
#endif


/////// // End dynamic Credentials ///////////

#endif      //#if USE_BLYNK_WM


#endif      //dynamicParams_h
```

---
---

### Debug Terminal Output Samples

### 1. W5500_WM_Config on ESP32_DEV


This is the terminal output of a ESP32 board with W5500 Ethernet shield running [W5500_WM_Config](examples/W5500_WM_Config) example (note that Buffer Size **SSIZE** of W5500 is 4096 now) when **no doubleResetDetected**.

#### 1.1 No DoubleReset Detected => Running normally


```
Start W5500_WM_Config using LittleFS on ESP32 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
LittleFS Flag read = 0xD0D04321
No doubleResetDetected
Saving config file...
Saving config file OK
[312] LoadCfgFile 
[317] OK
[317] CCSum=0x2c18,RCSum=0x2c18
[326] LoadCredFile 
[329] OK
[329] CrCCsum=0x29a6,CrRCsum=0x29a6
[329] Hdr=W5X00,BName=ESP32_LittleFS
[330] Svr=account.duckdns.org,Tok=token
[332] Svr1=account.duckdns.org,Tok1=token1
[338] Prt=8080,SIP=192.168.2.222
[341] MAC:FE-C6-B0-96-FE-B9

W5100 init, using SS_PIN_DEFAULT = 22, new ss_pin = 10, W5100Class::ss_pin = 27
W5100::init: W5500, SSIZE =8192
[1923] IP:192.168.2.222
[1936] LoadCPFile 
[1941] OK
[1941] bg:ECon.TryB
[1941] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[1945] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[2064] Ready (ping: 8ms).
[2131] Connected to Blynk Server = account.duckdns.org, Token = token
[2131] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.222
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop doubleResetDetecting
Saving config file...
Saving config file OK
B
```

#### 1.2 DoubleReset Detected => Enter Config Portal


```cpp
Start W5500_WM_Config using LittleFS on ESP32 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
LittleFS Flag read = 0xD0D01234
doubleResetDetected
Saving config file...
Saving config file OK
[287] MAC:FE-AB-CD-EF-ED-BA
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 22, new ss_pin = 10, W5100Class::ss_pin = 27
W5100::init: W5500, SSIZE =8192
[1970] IP:192.168.2.158
[1982] LoadCPFile 
[1987] OK
[1987] bg:Stay forever in CP:DRD/MRD
[1998] SaveCPFile 
[2003] OK
[2014] SaveBkUpCPFile 
[2187] OK
[2187] CfgIP=192.168.2.158
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic

```

#### 1.3 Enter non-persistent ConfigPortal

```
CP Button Hit. Rebooting
[38251] SaveCPFile 
[38256] OK
[38273] SaveBkUpCPFile 
[38278] OK

Start W5500_WM_Config using LittleFS on ESP32 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
LittleFS Flag read = 0xD0D04321
No doubleResetDetected
Saving config file...
Saving config file OK
[518] LoadCfgFile 
[520] OK
[521] CCSum=0x2c18,RCSum=0x2c18
[527] LoadCredFile 
[529] OK
[530] CrCCsum=0x29a6,CrRCsum=0x29a6
[530] Hdr=W5X00,BName=ESP32_LittleFS
[530] Svr=account.duckdns.org,Tok=token
[532] Svr1=account.duckdns.org,Tok1=token1
[537] Prt=8080,SIP=192.168.2.222
[540] MAC:FE-C6-B0-96-FE-B9

W5100 init, using SS_PIN_DEFAULT = 22, new ss_pin = 10, W5100Class::ss_pin = 27
W5100::init: W5500, SSIZE =8192
[2123] IP:192.168.2.222
[2129] LoadCPFile 
[2131] OK
[2131] bg:Stay forever in CP:Forced-non-Persistent
[2138] SaveCPFile 
[2141] OK
[2147] SaveBkUpCPFile 
[2150] OK
[2151] CfgIP=192.168.2.222
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop doubleResetDetecting
Saving config file...
Saving config file OK
F
```

#### 1.4 Enter persistent ConfigPortal

```
Persistent CP Button Hit. Rebooting
[9064] SaveCPFile 
[9067] OK
[9074] SaveBkUpCPFile 
[9077] OK

Start W5500_WM_Config using LittleFS on ESP32 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
LittleFS Flag read = 0xD0D01234
doubleResetDetected
Saving config file...
Saving config file OK
[302] LoadCfgFile 
[305] OK
[306] CCSum=0x2c18,RCSum=0x2c18
[316] LoadCredFile 
[320] OK
[320] CrCCsum=0x29a6,CrRCsum=0x29a6
[320] Hdr=W5X00,BName=ESP32_LittleFS
[320] Svr=account.duckdns.org,Tok=token
[322] Svr1=account.duckdns.org,Tok1=token1
[328] Prt=8080,SIP=192.168.2.222
[331] MAC:FE-C6-B0-96-FE-B9

W5100 init, using SS_PIN_DEFAULT = 22, new ss_pin = 10, W5100Class::ss_pin = 27
W5100::init: W5500, SSIZE =8192
[1914] IP:192.168.2.222
[1923] LoadCPFile 
[1926] OK
[1927] bg:Stay forever in CP:Forced-Persistent
[1927] CfgIP=192.168.2.222
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
FFFF
```

---

### 2. W5500_WM_Config_SAMD on SAMD21 SEEED_XIAO_M0

The following is the sample terminal output when running example [W5500_WM_Config_SAMD](examples/W5500_WM_Config_SAMD) on Seeeduino SAMD21 SEEED_XIAO_M0 using W5500 Ethernet shield:

#### 2.1 No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal

No Config Data with **LOAD_DEFAULT_CONFIG_DATA = false** => Config Portal don't loads default Credential

```
Start W5500_WM_Config_SAMD on SEEED_XIAO_M0 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[936] CCSum=0xb8f6,RCSum=0xffffffff
[936] ChkCrR:CrCCsum=0xaf50,CrRCsum=0xffffffff
[937] InitCfgFile,Sz=200
[937] InitCfgFile,DataSz=0
[937] SaveEEPROM,Sz=1024,DataSz=0,WCSum=0xe23
[944] CrCCSum=0xc30
[951] MAC:FE-8F-83-CC-C5-A6
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 1
W5100::init: W5500, SSIZE =8192
[4641] IP:192.168.2.149
[4642] bg:Stay forever in CP:No ConfigDat
[4649] CfgIP=192.168.2.149
F
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
RFRF
```

#### 2.2 Input valid Credentials and Save => Exit Config Portal

Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = false**. Click `Save` => reboot

```
Start W5500_WM_Config_SAMD on SEEED_XIAO_M0 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[1367] CCSum=0x2a5b,RCSum=0x2a5b
[1368] ChkCrR:CrCCsum=0x15bd,CrRCsum=0x15bd
[1368] CrCCSum=15bd,CrRCSum=15bd
[1368] ======= Start Stored Config Data =======
[1369] Hdr=W5X00,BName=SEEED_XIAO
[1369] Svr=account.duckdns.org,Tok=token
[1369] Svr1=account.duckdns.org,Tok1=token1
[1369] Prt=8080,SIP=192.168.2.222
[1370] connectEthernet: Use static_IP=192.168.2.222
[1370] MAC:FE-80-92-D4-B8-CE

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 1
W5100::init: W5500, SSIZE =8192
[2951] IP:192.168.2.222
[2952] bg:ECon.TryB
[2952] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on SAMD SEEED_XIAO_M0

[2953] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[3067] Ready (ping: 8ms).
[3134] Connected to BlynkServer=account.duckdns.org,Token=token
[3135] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.222
B
Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pwd
Subs Topics = Subs_Topics
Pubs Topics = Pubs_Topics
BBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

#### 2.3 Enter non-persistent ConfigPortal

```
CP Button Hit. Rebooting

Start W5500_WM_Config_SAMD on SEEED_XIAO_M0 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[2128] CCSum=0x2a5b,RCSum=0x2a5b
[2128] ChkCrR:CrCCsum=0x15bd,CrRCsum=0x15bd
[2129] CrCCSum=15bd,CrRCSum=15bd
[2129] ======= Start Stored Config Data =======
[2129] Hdr=W5X00,BName=SEEED_XIAO
[2129] Svr=account.duckdns.org,Tok=token
[2129] Svr1=account.duckdns.org,Tok1=token1
[2130] Prt=8080,SIP=192.168.2.222
[2130] connectEthernet: Use static_IP=192.168.2.222
[2130] MAC:FE-80-92-D4-B8-CE

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 1
W5100::init: W5500, SSIZE =8192
[3712] IP:192.168.2.222
[3712] bg:Stay forever in CP:Forced-non-Persistent
[3719] CfgIP=192.168.2.222
F
Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pwd
Subs Topics = Subs_Topics
Pubs Topics = Pubs_Topics
```

#### 2.4 Enter persistent ConfigPortal

```
Persistent CP Button Hit. Rebooting

Start W5500_WM_Config_SAMD on SEEED_XIAO_M0 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[1427] CCSum=0x2a5b,RCSum=0x2a5b
[1428] ChkCrR:CrCCsum=0x15bd,CrRCsum=0x15bd
[1428] CrCCSum=15bd,CrRCSum=15bd
[1428] ======= Start Stored Config Data =======
[1429] Hdr=W5X00,BName=SEEED_XIAO
[1429] Svr=account.duckdns.org,Tok=token
[1429] Svr1=account.duckdns.org,Tok1=token1
[1429] Prt=8080,SIP=192.168.2.222
[1430] connectEthernet: Use static_IP=192.168.2.222
[1430] MAC:FE-80-92-D4-B8-CE

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 1
W5100::init: W5500, SSIZE =8192
[3011] IP:192.168.2.222
[3012] bg:Stay forever in CP:Forced-Persistent
[3012] CfgIP=192.168.2.222
F
Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pwd
Subs Topics = Subs_Topics
Pubs Topics = Pubs_Topics
```

---

### 3. W5500_WM_Config_SAM_DUE on SAM-DUE

The following is the sample terminal output when running example [W5500_WM_Config_SAM_DUE](examples/W5500_WM_Config_SAM_DUE) on SAM-DUE using W5100 Ethernet shield

```
Start W5500_WM_Config_SAM_DUE on SAM DUE with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[9] Simulate EEPROM,Sz=1024
[9] CCSum=0x29f2,RCSum=0x29f2
[10] ChkCrR:CrCCsum=0x1465,CrRCsum=0x1465
[10] CrCCsum=0x1465,CrRCsum=0x1465,TotalDataSz=380
[12] ======= Start Stored Config Data =======
[16] Hdr=W5X00,BName=SAM_DUE
[18] Svr=account.duckdns.org,Tok=token
[24] Svr1=account.duckdns.org,Tok1=token1
[30] Prt=8080,SIP=192.168.2.188
[32] MAC:FE-80-A3-D2-DE-EC

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
[1595] GetIP:
[1595] IP:192.168.2.188
[1595] bg:ECon.TryB
[1595] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino Due

[1602] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[1670] Ready (ping: 5ms).
[1738] Connected to BlynkServer=account.duckdns.org,Token=token
[1738] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.188
B
Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pwd
Subs Topics = mqtt_Subs
Pubs Topics = mqtt_Pubs
```

---

### 4. ENC28J60_Blynk on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library

The following is the sample terminal output when running example [ENC28J60_Blynk](examples/ENC28J60_Blynk) on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library

```
Start ENC28J60_Blynk on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library
BlynkEthernet_WM v1.5.2
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[7791] LoadCfgFile 
[7792] OK
[7792] CCSum=0x29de,RCSum=0x29de
[7794] LoadCredFile 
[7794] OK
[7794] ChkCrR: Buffer allocated, Sz=35
[7794] ChkCrR:pdata=new-mqtt-server,len=34
[7794] ChkCrR:pdata=1883,len=6
[7794] ChkCrR:pdata=default-mqtt-username,len=34
[7794] ChkCrR:pdata=default-mqtt-password,len=34
[7795] ChkCrR:pdata=default-mqtt-SubTopic,len=34
[7795] ChkCrR:pdata=default-mqtt-PubTopic,len=34
[7795] CrCCsum=0x280b,CrRCsum=0x280b
[7796] Buffer freed
[7797] LoadCredFile 
[7797] OK
[7797] CrR:pdata=new-mqtt-server,len=34
[7797] CrR:pdata=1883,len=6
[7798] CrR:pdata=default-mqtt-username,len=34
[7798] CrR:pdata=default-mqtt-password,len=34
[7798] CrR:pdata=default-mqtt-SubTopic,len=34
[7798] CrR:pdata=default-mqtt-PubTopic,len=34
[7798] CrCCsum=0x280b,CrRCsum=0x280b
[7799] Valid Stored Dynamic Data
[7799] ======= Start Stored Config Data =======
[7799] Hdr=ENC28J60,BName=nRF52_ENC
[7799] Svr=account.duckdns.org,Tok=token
[7799] Svr1=account.ddns.net,Tok1=n1u-uhfrc0chbmLRqSjl8SjphkGfHRTN
[7799] Prt=8080,SIP=192.168.2.188
[7799] i=0,id=mqtt,data=new-mqtt-server
[7800] i=1,id=mqpt,data=1883
[7800] i=2,id=user,data=default-mqtt-username
[7800] i=3,id=mqpw,data=default-mqtt-password
[7800] i=4,id=subs,data=default-mqtt-SubTopic
[7801] i=5,id=pubs,data=default-mqtt-PubTopic
[7801] MAC:FE-C6-B0-96-FE-B9
ENC28J60_CONTROL_CS =10
SS =5
SPI_MOSI =25
SPI_MISO =24
SPI_SCK =26
[8853] IP:192.168.2.188
[8853] Check if isForcedCP
[8856] LoadCPFile 
[8856] OK
[8856] bg: noConfigPortal = true
[8856] bg:ECon.TryB
[8856] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ARDUINO_NRF52_ADAFRUIT

[8857] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[10772] Ready (ping: 15ms).
[10839] Connected to Blynk Server = account.duckdns.org, Token = token
[10840] bg:EBCon
Local IP = 192.168.2.188
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.188
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
```

---

### 5. W5500_WM_Config_Teensy on TEENSY 4.0 with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [W5500_WM_Config_Teensy](examples/W5500_WM_Config_Teensy) on TEENSY 4.1/4.0 with W5x00 using EthernetLarge Library

```
Start W5500_WM_Config_Teensy on TEENSY 4.1/4.0 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
Warning: W5x00 and ENC EthernetWebServer/Config-Portal only works with Teensy core v1.51
[16480] CCSum=0x28d0,RCSum=0x28d0
[16486] ChkCrR:CrCCSum=0x280b,CrRCSum=0x280b
[16487] CrCCSum=0x280b,CrRCSum=0x280b
[16487] ======= Start Stored Config Data =======
[16487] Hdr=W5X00,BName=Teensy_W5500
[16487] Svr=account.duckdns.org,Tok=token
[16487] Svr1=account.duckdns.org,Tok1=token1
[16487] Prt=8080,SIP=
[16487] MAC:FE-80-D6-B4-FC-EE
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192
[20168] IP:192.168.2.156
[20168] bg:ECon.TryB
[20168] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Teensy 4.1/4.0

[20169] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[20279] Ready (ping: 7ms).
[20346] Connected to Blynk Server = account.duckdns.org, Token = token
[20346] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.156
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
```

---

### 6. W5500_WM_Config on ESP8266 with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [W5500_WM_Config](examples/W5500_WM_Config) on ESP8266 with W5x00 using EthernetLarge Library

```
Start W5500_WM_Config on ESP8266 with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
EEPROM size = 2048, start = 0
EEPROM Flag read = 0xD0D04321
No doubleResetDetected
SetFlag write = 0xD0D01234
[1311] EEPROMsz:2048
[1311] CCSum=0x2b55,RCSum=0x2b55
[1311] ChkCrR:CrCCsum=0x25dd,CrRCsum=0x25dd
[1311] CrCCsum=0x25dd,CrRCsum=0x25dd
[1313] ======= Start Stored Config Data =======
[1318] Hdr=W5X00,BName=ESP8266_EEPROM
[1321] Svr=account.duckdns.org,Tok=token
[1327] Svr1=account.duckdns.org,Tok1=token1
[1333] Prt=8080,SIP=192.168.2.188
[1336] MAC:FE-C6-B0-96-FE-B9

W5100 init, using SS_PIN_DEFAULT = 15, new ss_pin = 10, W5100Class::ss_pin = 4
W5100::init: W5500, SSIZE =8192
[2921] IP:192.168.2.188
[2921] bg:ECon.TryB
[2921] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on NodeMCU

[2927] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[3043] Ready (ping: 5ms).
[3110] Connected to Blynk Server = account.duckdns.org, Token = token
[3110] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.188
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-user
MQTT PWD = default-mqtt-pwd
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop doubleResetDetecting
ClearFlag write = 0xD0D04321
BBBBBBB
```

---

### 7. AM2315_W5500 on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [AM2315_W5500](examples/AM2315_W5500) on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library, using [**Earle Philhower's arduino-pico core** v1.4.0+](https://github.com/earlephilhower/arduino-pico) with LittleFS.

#### 7.1 No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal

No Config Data with **LOAD_DEFAULT_CONFIG_DATA = false** => Config Portal don't loads default Credential

```
Start AM2315_W5500 on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[2036] LoadCfgFile 
[2040] OK
[2040] CCSum=0xeb1,RCSum=0x0
[2045] LoadCredFile 
[2045] OK
[2045] CrCCsum=0x5c1,CrRCsum=0x200019c4
[2046] InitCfgFile,Sz=200
[2046] InitCfgFile,DataSz=0
[2046] SaveCfgFile 
[2046] WCSum=0xda7
[2121] OK
[2121] SaveBkUpCfgFile 
[2135] OK
[2144] SaveCredFile 
[2151] OK
[2151] CrWCSum=0xc30
[2161] SaveBkUpCredFile 
[2169] OK
[2169] MAC:FE-C9-A1-8E-83-D1
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
[6417] IP:192.168.2.128
[6423] LoadCPFile 
[6423] failed
[6427] LoadBkUpCPFile 
[6428] failed
[6428] bg:Stay forever in CP:No ConfigDat
[6501] SaveCPFile 
[6568] OK
[6577] SaveBkUpCPFile 
[6588] OK
[6588] CfgIP=192.168.2.128
F
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
FF

Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
FFFF[249132] h:mqtt=mqtt_server
[249171] h:mqpt=1883
[249211] h:user=mqtt_user
[249247] h:mqpw=mqtt_pass
[249283] h:subs=mqtt_Subs
[249318] h:pubs=mqtt_Pubs
[249320] SaveCfgFile 
[249320] WCSum=0x25b4
[249336] OK
[249337] SaveBkUpCfgFile 
[249354] OK
[249366] SaveCredFile 
[249442] OK
[249442] CrWCSum=0x14d1
[249451] SaveBkUpCredFile 
[249459] OK
Rst
```

#### 7.2 Input valid Credentials and Save => Exit Config Portal

Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = false**. Click `Save` => reboot

```
Start AM2315_W5500 on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
[58816] LoadCfgFile 
[58821] OK
[58821] CCSum=0x25b4,RCSum=0x25b4
[58826] LoadCredFile 
[58827] OK
[58827] CrCCsum=0x14d1,CrRCsum=0x14d1
[58832] LoadCredFile 
[58832] OK
[58832] CrCCsum=0x14d1,CrRCsum=0x14d1
[58832] ======= Start Stored Config Data =======
[58833] Hdr=RP2040,BName=RP2040
[58833] Svr=account.duckdns.org,Tok=token
[58833] Svr1=account.ddns.net,Tok1=token1
[58833] Prt=8080,SIP=0
[58833] MAC:FE-C6-B0-96-FE-B9
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
[62429] IP:192.168.2.129
[62435] LoadCPFile 
[62435] OK
[62436] bg:ECon.TryB
[62436] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on RASPBERRY_PI_PICO

[62551] Ready (ping: 6ms).
[62618] Connected to Blynk Server = account.duckdns.org, Token = token
[62619] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.129
B
Your stored Credentials :
MQTT Server = mqtt_server
Port = 1883
MQTT UserName = mqtt_user
MQTT PWD = mqtt_pass
Subs Topics = mqtt_Subs
Pubs Topics = mqtt_Pubs
BBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

---

### 8. W5500_Blynk_RP2040 on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [W5500_Blynk_RP2040](examples/W5500_Blynk_RP2040) on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library


```
Start W5500_Blynk_RP2040 on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
BlynkEthernet_WM v1.5.2
=========== USE_ETHERNET_LARGE ===========
Default SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
LittleFS size (KB) = 64
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[1845] LoadCfgFile 
[1847] OK
[1848] CCSum=0x2383,RCSum=0x2383
[1850] LoadCredFile 
[1850] OK
[1851] CrCCsum=0x219f,CrRCsum=0x219f
[1853] LoadCredFile 
[1854] OK
[1854] CrCCsum=0x219f,CrRCsum=0x219f
[1855] ======= Start Stored Config Data =======
[1855] Hdr=RP2040,BName=MBED-RP2040
[1856] Svr=192.168.2.112,Tok=token
[1856] Svr1=account.duckdns.org,Tok1=token1
[1857] Prt=8080,SIP=0
[1857] MAC:FE-C6-B0-96-FE-B9
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
[7544] IP:192.168.2.129
[7547] LoadCPFile 
[7547] OK
[7548] bg:ECon.TryB
[7548] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v1.0.0 on MBED RASPBERRY_PI_PICO

[8508] Connecting to 192.168.2.112:8080
[8727] Ready (ping: 217ms).
[8795] Connected to Blynk Server = 192.168.2.112, Token = token
[8795] bg:EBCon
Conn2Blynk: server = 192.168.2.112, port = 8080
Token = token, IP = 192.168.2.129
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
BBBB
```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT                         Serial
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       1

#if ( defined(ESP32) || defined(ESP8266) )
  #define DOUBLERESETDETECTOR_DEBUG     false   //true
#else
  #define DRD_GENERIC_DEBUG             false   //true
#endif

#define BLYNK_WM_DEBUG                      0
```
---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues

Submit issues to: [BlynkEthernet_Manager issues](https://github.com/khoih-prog/BlynkEthernet_Manager/issues)

---

### TO DO

1. Same features for other boards with new Ethernet shields.
2. Add SSL/TLS Client and Server support. Currently, Ethernet SSL is not supported by Blynk code yet.
3. Bug Searching and Killing
4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia.


### DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (Serves, HardwarePort and Blynk tokens), entering config portal
 5. Change Synch XMLHttpRequest to Async
 6. Reduce memory usage.
 7. Support ENC28J60 as well as W5200/W5500 Ethernet shields
 8. Add checksums
 9. Support SAM DUE, SAMD, Teensy boards
10. Support STM32 boards
11. Add **MultiBlynk** features with Auto(Re)Connect to the available Server.
12. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
13. Permit to input special chars such as **%** and **#** into data fields.
14. Support more types of boards using Ethernet shields : **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, etc.**
Default Credentials and dynamic parameters
15. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
16. Configurable Config Portal Title
17. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
18. Add **LittleFS** support to ESP8266 as SPIFFS deprecated since **ESP8266 core 2.7.1.**
19. **Auto format SPIFFS/LittleFS** for first time usage
20. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
21. Add support to new [**`EthernetENC library`**](https://github.com/jandrassy/EthernetENC) for ENC28J60.
22. Add support to LittleFS for ESP32 using [LITTLEFS](https://github.com/lorol/LITTLEFS) Library
23. Add support to [NativeEthernet Library](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1
24. Add Table of Contents and Version String
25. Add support to **ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)**
26. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico) to use LittleFS with or without Blynk/WiFiManager features.
27. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) to use LittleFS with or without Blynk/WiFiManager features.

---
---

### Contributions and Thanks

1. Thanks to [thorathome in GitHub](https://github.com/thorathome) to test, suggest and encourage to add those new features to [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Those features are included in this library now.
2. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. See [ESP32-based U-BLOX NINA W102 running ENC28J60](https://u-blox-ethernet-ninaw.blogspot.com/).

<table>
  <tr>
    <td align="center"><a href="https://github.com/thorathome"><img src="https://github.com/thorathome.png" width="100px;" alt="thorathome"/><br /><sub><b>⭐️ Thor Johnson</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/BlynkEthernet_Manager/blob/master/LICENSE)

---

### Copyright

Copyright 2020- Khoi Hoang
