## BlynkEthernet_Manager

[![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/BlynkEthernet_WM.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/BlynkEthernet_WM.svg)](http://github.com/khoih-prog/BlynkEthernet_WM/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.5.2](#releases-v152)
  * [Releases v1.5.1](#releases-v151)
  * [Major Releases v1.5.0](#major-releases-v150)
  * [Major Releases v1.4.0](#major-releases-v140)
  * [Major Releases v1.3.0](#major-releases-v130)
  * [Releases v1.2.1](#releases-v121)
  * [Major Releases v1.2.0](#major-releases-v120)
  * [Major Releases v1.1.0](#major-releases-v110)
  * [Releases v1.0.18](#releases-v1018)
  * [Releases v1.0.17](#releases-v1017)
  * [Releases v1.0.16](#releases-v1016)
  * [Releases v1.0.15](#releases-v1015)
  * [Releases v1.0.14](#releases-v1014)
  * [Releases v1.0.13](#releases-v1013)
  * [Releases v1.0.12](#releases-v1012)
  * [Releases v1.0.11](#releases-v1011)

---
---

## Changelog

### Releases v1.5.2

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.5.1

1. Fix error in v1.5.0

### Major Releases v1.5.0

1. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) with BLYNK_WM feature using LittleFS


### Major Releases v1.4.0

1. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) without BLYNK_WM feature due to LittleFS not ready yet.
2. Fix bugs
3. Drastically simplify and update examples with new features

### Major Releases v1.3.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico core** v1.4.0+](https://github.com/earlephilhower/arduino-pico) with LittleFS.
2. Add support to ESP32-S2 (ESP32-S2 Saola and AI-Thinker ESP-12K)
3. Add Instructions to install ESP32-S2 core
4. Update examples with new features

### Releases v1.2.1

1. To permit autoreset after configurable timeout if DRD/MRD or non-persistent forced-CP. Check [**Good new feature: Blynk.resetAndEnterConfigPortal() Thanks & question #27**](https://github.com/khoih-prog/Blynk_WM/issues/27)

### Major Releases v1.2.0

1. Fix Config Portal Bug. 
2. Add functions to control Config Portal from software or Virtual Switches. Check [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
3. Use more efficient [FlashStorage_SAMD v1.1.0](https://github.com/khoih-prog/FlashStorage_SAMD).


### Major Releases v1.1.0

1. Add support to LittleFS for ESP32 using [LITTLEFS](https://github.com/lorol/LITTLEFS) Library
2. Add support to [NativeEthernet Library](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1
3. Clean-up all compiler warnings possible.
4. Optimize code
5. Add Table of Contents
6. Add examples for Teensy 4.1 NativeEthernet
7. Add Version String 

### Releases v1.0.18

1. Add support to new [**`EthernetENC library`**](https://github.com/jandrassy/EthernetENC) for ENC28J60.
2. Add more examples for ENC28J60 using [**`EthernetENC library`**](https://github.com/jandrassy/EthernetENC).

#### Releases v1.0.17

1. Fix bug and logic of USE_DEFAULT_CONFIG_DATA.
2. **Auto format SPIFFS/LittleFS** for first time usage
3. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
4. Add examples for nRF52 boards.
5. Sync with [`EthernetWebServer library v1.0.11`](https://github.com/khoih-prog/EthernetWebServer)

#### Releases v1.0.16

1. Sync with EthernetWebServer v.1.0.9
2. Use 25MHz for W5x00.
3. Use EthernetWrapper feature of EthernetWebServer v.1.0.9.

#### Releases v1.0.15

1. Update to use LittleFS for ESP8266 core 2.7.1+ to store Credentials and Dynamic Parameters' data in addition to deprecated SPIFFS and EEPROM.
2. Add support to several more W5x00 Ethernet libraries. Now Ethernet, Ethernet2, Ethernet3, EthernetLarge libraries are supported. W5100 is now re-supported.
3. Fix bug.

#### Releases v1.0.14

1. Add support to nRF52-based boards, , such as **Adafruit's NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, NINA_B302_ublox, etc.** The Credentials and Dynamic Parameters' data will be stored in **LittleFS/InternalFS**.

Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52 would have never been started and finished.

#### Releases v1.0.13

1. Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
2. **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
3. Configurable **Config Portal Title** to be either HostName, BoardName or default undistinguishable names.
4. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.

Thanks to [thorathome in GitHub](https://github.com/thorathome) to test, suggest and encourage to add those new features to [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD.

#### Releases v1.0.12

1. Drop **AVR Mega** support because of not enough marginal memory.
2. Add support to **SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.

#### Releases v1.0.11

1. Fix potential dangerous bug in code and examples of v1.0.10.


