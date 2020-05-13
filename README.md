## BlynkEthernet_Manager

[![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/BlynkEthernet_WM.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/BlynkEthernet_WM.svg)](http://github.com/khoih-prog/BlynkEthernet_WM/issues)

### Releases v1.0.15

1. Update to use LittleFS for ESP8266 core 2.7.1+ to store Credentials and Dynamic Parameters' data in addition to deprecated SPIFFS and EEPROM.
2. Add support to several more W5x00 Ethernet libraries. Now Ethernet, Ethernet2, Ethernet3, EthernetLarge libraries are supported. W5100 is now re-supported.
3. Fix bug.

### Releases v1.0.14

1. Add support to nRF52-based boards, , such as ***Adafruit's NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, NINA_B302_ublox, etc.*** The Credentials and Dynamic Parameters' data will be stored in ***LittleFS/InternalFS***.

Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52 would have never been started and finished.

### Releases v1.0.13

1. Optional default ***Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal*** to use or change instead of manually input.
2. ***DoubleDetectDetector*** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
3. Configurable ***Config Portal Title*** to be either HostName, BoardName or default undistinguishable names.
4. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.

Thanks to [thorathome in GitHub](https://github.com/thorathome) to test, suggest and encourage to add those new features to [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD.

### Releases v1.0.12

1. Drop ***AVR Mega*** support because of not enough marginal memory.
2. Add support to ***SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)***.

### Releases v1.0.11

1. Fix potential dangerous bug in code and examples of v1.0.10.

### Releases v1.0.10

#### Potential dangerous bug, Don't use this version

1. New ***powerful-yet-simple-to-use feature to enable adding dynamic custom parameters*** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
2. Dynamic custom parameters to be saved ***automatically in EEPROM, DueFlashStorage or FlashStorage***.
3. Permit to input special chars such as ***%*** and ***#*** into data fields.
4. MultiBlynk Servers and Tokens with Auto(Re)Connect feature.

### New Releases v1.0.9
1. Reduce html and code size for faster Config Portal response. Enhance GUI.

### New Releases v1.0.8

1. Fix bug
2. Change default macAddress for boards to avoid macAddress conflict while simultaneously testing multiple boards.

- This is the new library, adding to the current Blynk_WiFiManager. It's designed to help you eliminate `hardcoding` your Blynk credentials in ***Teensy, SAM DUE, SAMD, etc. boards using Ethernet shields (W5200, W5500, ENC28J60, etc)***. It's currently ***not supporting SSL***. 
- It's not supporting UNO/Nano/Mega and other AVR boards for not enough memory.
- It's not supporting W5100 Ethernet shields boards for not enough memory and small buffer size.
- You can update Blynk Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in EEPROM, DueFlashStorage or FlashStorage
- Teensy LC, 2.0++ and 2.0 not supported.

## Prerequisite
 1. [`Arduino IDE 1.8.12 or later` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. `Arduino AVR core 1.8.2 or later` for Arduino (Use Arduino Board Manager)
 3. [`Teensy core 1.51 or later`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 4. [`Arduino SAM DUE core 1.6.12 or later`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards
 5. [`Arduino SAMD core 1.8.5 or later`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards
 6. [`Adafruit SAMD core 1.5.11 or later`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.)
 7. [`Adafruit nRF52 v0.20.1 or later`](https://www.adafruit.com/) for nRF52 boards such as AdaFruit Feather nRF52840 Express, NINA_B302_ublox, etc.
 8. [`Blynk library 0.6.1 or later`](https://www.arduino.cc/en/guide/libraries#toc3)
 9. Depending on which Ethernet card you're using:
   - [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) for W5200 and W5500
   - [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library)
   - [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.
   - [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet_Shield_W5200 library`](https://github.com/khoih-prog/Ethernet_Shield_W5200) for W5200
   - [`UIPEthernet library`](https://github.com/khoih-prog/UIPEthernet) for ENC28J60
10. Depending on which board you're using:
   - [`DueFlashStorage library`](https://github.com/sebnil/DueFlashStorage) for SAM DUE
   - [`FlashStorage_SAMD library`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD (DUE, ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)
11. [`EthernetWebServer library v1.0.8+`](https://github.com/khoih-prog/EthernetWebServer)
12. [`ESP_DoubleResetDetector library`](https://github.com/khoih-prog/ESP_DoubleResetDetector) for ESP32 and ESP8266
13. [`DoubleResetDetector_Generic library`](https://github.com/khoih-prog/DoubleResetDetector_Generic) for other boards (not ESP32 or ESP8266)
14. [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp)
15. [`ArduinoBearSSL library`](https://github.com/khoih-prog/ArduinoBearSSL) for SSL (not working yet)
16. [`ArduinoECCX08  library`](https://github.com/khoih-prog/ArduinoECCX08)  for SSL (not working yet)

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager
The best way is to use `Arduino Library Manager`. Search for `BlynkEthernet_WM`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager) for more detailed instructions.

#### Manual Install

1. Navigate to [BlynkEthernet_WM](https://github.com/khoih-prog/BlynkEthernet_WM) page.
2. Download the latest release `BlynkEthernet_WM-master.zip`.
3. Extract the zip file to `BlynkEthernet_WM-master` directory 
4. Copy whole 
  - `BlynkEthernet_WM-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### Important notes

1. If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

3. To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/EthernetLarge/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/EthernetLarge/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

4. To fix [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet), just copy these following files into the [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) directory to overwrite the old files:
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

5. To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

6. To add NINA_B302_ublox boards running as nRF52840, you have to copy the whole [nRF52 directory](https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/LibraryPatches/nRF52) into Adafruit nRF52 directory (normally ./.arduino15/packages/adafruit/hardware/nrf52). Supposing the Adafruit nRF52 version is 0.20.1
These files must be copied into the directory:
- `nRF52/0.20.1/board.txt`
- `nRF52/0.20.1/variants/variant.h`
- `nRF52/0.20.1/variants/variant.cpp`

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:
- `nRF52/x.yy.z/board.txt`
- `nRF52/x.yy.z/variants/variant.h`
- `nRF52/x.yy.z/variants/variant.cpp`

7. ***How to select which built-in Ethernet or shield to use***

- Standard Ethernet library is used by default, just check in the sketch these line are commented out

```
//#define USE_UIP_ETHERNET        true
//#define USE_CUSTOM_ETHERNET     true
//#include <Ethernet2.h>
//#include <Ethernet3.h>
//#include <EthernetLarge.h>
```

- To use built-in UIPEthernet built-in or shield:

```
#define USE_UIP_ETHERNET        true
//#define USE_CUSTOM_ETHERNET     true
//#include <Ethernet2.h>
//#include <Ethernet3.h>
//#include <EthernetLarge.h>
```

- To use any of the custom Ethernet library, such as Ethernet2, Ethernet3, EthernetLarge:

```
//#define USE_UIP_ETHERNET        true
#define USE_CUSTOM_ETHERNET     true
#include <Ethernet2.h>
//#include <Ethernet3.h>
//#include <EthernetLarge.h>
```

- To use another Ethernet library
For example, Ethernet_XYZ library uses ***Ethernet_XYZ.h***

```
//#define USE_UIP_ETHERNET        true
#define USE_CUSTOM_ETHERNET     true
//#include <Ethernet2.h>
//#include <Ethernet3.h>
//#include <EthernetLarge.h>
#include <Ethernet_XYZ.h>
...
//Must be placed before #include <EthernetWebServer.h>
#include <WiFi_XYZ.h>
#include <WiFiWebServer.h>
```
8. ***How to select another CS/SS pin to use***

- For ***Ethernet, Ethernet3 and EthernetLarge*** libraries, use as follows

```
// Select a GPIO pin to use, for example GPIO13 for ESP32. Default is 10 if not called
Ethernet.setCsPin (13);
```

- For ***Ethernet2*** library, use as follows

```
// Select a GPIO pin to use, for example GPIO13 for ESP32. Default is 10 if not called
Ethernet.init (13);
```

9. ***How to use W5x00 with ESP8266***

To avoid using the default  not-working Ethernet library of ESP8266, rename the Ethernet.h/cpp to Ethernet_ESP8266.h/cpp to avoid library conflict if you're using the Ethernet library. The Ethernet2, Ethernet3, EthernetLarge library can be used without conflict.

These pins are tested OK with ESP8266 and W5x00

```
// For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D1 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  Ethernet.setCsPin (D1);

```

10. ***How to increase W5x00 TX/RX buffer***

- For ***Ethernet3*** library only,  use as follows

```
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #define ETHERNET3_MAX_SOCK_NUM      4
  
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
```

#### Important:

- The ***Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported***. Don't use unless you know how to modify those libraries to make them compatible. Will do in the near future.
- Requests to support for any future custom Ethernet library will be ignored. ***Use at your own risk***.

### How to use

In your code, replace
1. `BlynkSimpleEthernet.h`      with `BlynkSimpleEthernet_WM.h`        for board using W5x00 `without SSL`
2. `BlynkSimpleEthernet2.h`     with `BlynkSimpleEthernet2_WM.h`       for board using only W5500 `without SSL`
3. `BlynkSimpleEthernetV2_0.h`  with `BlynkSimpleEthernetV2_0_WM.h`    for board using only W5500 `without SSL`
4. `BlynkSimpleUIPEthernet.h`   with `BlynkSimpleUIPEthernet_WM.h`     for board using ENC28J60 `without SSL`
5. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleEthernetSSL_WM.h`     for other boards (not Mega) using W5200, W5500 `with SSL (not working yet)`
6. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleUIPEthernetSSL_WM.h`  for other AVR boards (not Mega) using ENC28J60 `with SSL (not working yet)`


```
// Start location to store config data to avoid conflict with other functions
#define EEPROM_START   0

```

Then replace `Blynk.begin(...)` with :

1. `Blynk.begin()`

in your code. Keep `Blynk.run()` intact.

That's it.

### How to add dynamic parameters from sketch

- To add custom parameters, just modify from the example below

```
#define USE_DYNAMIC_PARAMETERS     true

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
- If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS     false
```

Also see examples: 
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

This is the terminal output of a ESP32 board with W5500 Ethernet shield running [W5500_WM_Config](examples/W5500_WM_Config) example (note that Buffer Size **SSIZE** of W5500 is 4096 now) when ***no doubleResetDetected***.

```
Start W5500_WM_Config on ESP32
EEPROM size = 2048, start = 0
EEPROM Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[1108] ======= Start Default Config Data =======
[1108] Hdr=NonSSL,BName=Air-Control
[1108] Svr=account.duckdns.org,Tok=token1
[1110] Svr1=blynk-cloud.com,Tok1=<<my real Blynk auth>>
[1115] Prt=8080,SIP=192.168.2.230
[1124] EEPROMsz:2048
[1124] ======= Start Stored Config Data =======
[1124] Hdr=W5X00,BName=Air-Control
[1128] Svr=account.duckdns.org,Tok=token
[1133] Svr1=account.ddns.net,Tok1=token
[1139] Prt=8080,SIP=192.168.2.230
[1142] CCSum=0x2ba3,RCSum=0x2ba3
[1145] ChkCrR: Error Small Buffer.
[1148] Hdr=W5X00,BName=Air-Control
[1151] Svr=account.duckdns.org,Tok=token
[1157] Svr1=account.ddns.net,Tok1=token
[1163] Prt=8080,SIP=192.168.2.230
[1166] MAC:FE-9B-D9-D5-9C-E5
w5100 init, using SS_PIN_DEFAULT = 13
W5100::init: W5500, SSIZE =4096
[2749] IP:192.168.2.230
[2749] bg: noConfigPortal = true
[2749] bg: noConfigPortal = true
[2749] bg:ECon.TryB
[2749] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[2760] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[2926] Ready (ping: 6ms).
[2993] Connected to Blynk Server = account.duckdns.org, Token = token
[2993] bg:EBCon
Conn2Blynk: server = account.duckdns.org, port = 8080
Token = token, IP = 192.168.2.230
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic

Pubs Topics = default-mqtt-PubTopic
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

and when ***doubleResetDetected***.

```cpp
Start W5500_WM_Config on ESP32
EEPROM size = 2048, start = 0
EEPROM Flag read = 0xd0d01234
doubleResetDetected
ClearFlag write = 0xd0d04321
[1106] Double Reset Detected
[1106] ======= Start Default Config Data =======
[1106] Hdr=NonSSL,BName=Air-Control
[1107] Svr=account.duckdns.org,Tok=token1
[1111] Svr1=blynk-cloud.com,Tok1=<<my real Blynk auth>>
[1116] Prt=8080,SIP=192.168.2.230
[1125] EEPROMsz:2048
[1125] ======= Start Stored Config Data =======
[1125] Hdr=W5X00,BName=Air-Control
[1128] Svr=account.duckdns.org,Tok=token
[1134] Svr1=account.ddns.net,Tok1=token
[1140] Prt=8080,SIP=192.168.2.230
[1143] CCSum=0x2ba3,RCSum=0x2ba3
[1146] ChkCrR: Error Small Buffer.
[1149] Hdr=W5X00,BName=Air-Control
[1152] Svr=account.duckdns.org,Tok=token
[1158] Svr1=account.ddns.net,Tok1=token
[1164] Prt=8080,SIP=192.168.2.230
[1167] MAC:FE-9B-D9-D5-9C-E5
w5100 init, using SS_PIN_DEFAULT = 13
W5100::init: W5500, SSIZE =4096
[2749] IP:192.168.2.230
[2749] bg: noConfigPortal = false
[2749] bg:CfgPortal Forced.Stay
[2749] CfgIP=192.168.2.230
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic

```

## Example
Please take a look at example [W5500_Blynk](examples/W5500_Blynk) below

1. File [W5500_Blynk](examples/W5500_Blynk/W5500_Blynk.ino)

```
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <SPI.h>

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  #if ( USE_LITTLEFS || USE_SPIFFS)
  Serial.println("\nStart W5500_Blynk using " + String(CurrentFileFS) + " on " + String(BOARD_TYPE));
#else
  Serial.println("\nStart W5500_Blynk on " + String(BOARD_TYPE));
#endif

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

// Just info to know how to connect correctly
  Serial.println("=========================");
  Serial.println("Default SPI pinout:");
  Serial.print("MOSI:");
  Serial.println(MOSI);
  Serial.print("MISO:");
  Serial.println(MISO);
  Serial.print("SCK:");
  Serial.println(SCK);
  Serial.print("SS:");
  Serial.println(SS);
  Serial.println("=========================");

#if defined(ESP8266)
// For ESP8266, change for other boards if necessary
#if ( USE_ETHERNET || USE_ETHERNET3 || USE_ETHERNET_LARGE )
  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  Ethernet.setCsPin (D2);

#if USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #define ETHERNET3_MAX_SOCK_NUM      4
  
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
#endif
  
#elif ( USE_ETHERNET2 )
  Ethernet.init (D2);
#endif

#else

#define USE_THIS_SS_PIN   10
// For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET3 || USE_ETHERNET_LARGE )
  // Must use library patch for Ethernet, EthernetLarge libraries
  // ESP32 => GPIO13 OK with Ethernet, EthernetLarge, not Ethernet3
  
  Serial.println("setCsPin " + String(USE_THIS_SS_PIN));
  Ethernet.setCsPin (USE_THIS_SS_PIN);

#if USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #define ETHERNET3_MAX_SOCK_NUM      4
  
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
#endif
  
#elif ( USE_ETHERNET2 )
// ESP32 => GPIO13 OK with Ethernet2
  Serial.println("setCsPin " + String(USE_THIS_SS_PIN));
  Ethernet.init (USE_THIS_SS_PIN);
#endif

#endif    //defined(ESP8266)

#if USE_BLYNK_WM
  Blynk.begin();
#else
#if USE_LOCAL_SERVER
  Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
#else
  //Blynk.begin(auth);
  // You can also specify server:
  Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
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
    Serial.print(F(", IP = "));
#else
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(server);
    Serial.print(F(", port = "));
    Serial.println(BLYNK_HARDWARE_PORT);
    Serial.print(F("Token = "));
    Serial.print(auth);
    Serial.print(F(", IP = "));
#endif    
    Serial.println(Ethernet.localIP());
  }
}

void heartBeatPrint(void)
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
void displayCredentials(void)
{
  Serial.println("\nYour stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
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
#endif  
}
```

2. File [defines.h](examples/W5500_Blynk/defines.h)

```
#ifndef defines_h
#define defines_h

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
#error This code is designed to run on SAMD, SAM-DUE, Teensy platform, ESP8266, ESP32 not AVR Mega! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ESP32) || defined(ESP8266) )
#define DOUBLERESETDETECTOR_DEBUG     false   //true
#else
#define DRD_GENERIC_DEBUG             false   //true
#endif

#define BLYNK_WM_DEBUG                0

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

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) | defined(NINA_B302_ublox) )  
#if defined(ETHERNET_USE_NRF52)
#undef ETHERNET_USE_NRF528XX
#endif
#define ETHERNET_USE_NRF528XX         true
#define USE_DYNAMIC_PARAMETERS        true
#endif

#if defined(ETHERNET_USE_NRF528XX)
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
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#elif defined(NRF52_SERIES)
#define BOARD_TYPE      "NRF52_SERIES"
#else
#define BOARD_TYPE      "NRF52_UNKNOWN"
#endif


#elif defined(ETHERNET_USE_SAMD)
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

//#define USE_LITTLEFS                true
#define USE_LITTLEFS                false
#define USE_SPIFFS                  false
//#define USE_SPIFFS                  true

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
//#define USE_SPIFFS                    true
#define USE_SPIFFS                    false

#endif    //#if defined(ESP8266)


#else   //#if ( defined(ESP32) || defined(ESP8266) )
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

// Note: To rename ESP628266 Ethernet lib files to Ethernet_ESP8266.h and Ethernet_ESP8266.cpp
// Only one if the following to be true. If none selected, default to Ethernet lib
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false //true
#define USE_ETHERNET_LARGE    false //true

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
#define USE_CUSTOM_ETHERNET   true
#else
#define USE_ETHERNET          true
#endif

// Ethernet_Shield_W5200, EtherCard, EtherSia not supported
// Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
// Otherwise, standard Ethernet library will be used for W5x00


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
```

3. File [Credentials.h](examples/W5500_Blynk/Credentials.h)

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

Blynk_WM_Configuration defaultConfig;

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

#define BLYNK_HARDWARE_PORT       8080

#endif      //#if USE_BLYNK_WM

#endif    //Credentials_h
```

4. File [dynamicParams.h](examples/W5500_Blynk/dynamicParams.h)

```
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

#if USE_BLYNK_WM

#define USE_DYNAMIC_PARAMETERS      true

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

### Releases v1.0.15

1. Update to use LittleFS for ESP8266 core 2.7.1+ to store Credentials and Dynamic Parameters' data in addition to deprecated SPIFFS and EEPROM.
2. Add support to several more W5x00 Ethernet libraries. Now Ethernet, Ethernet2, Ethernet3, EthernetLarge libraries are supported. W5100 is now re-supported.
3. Fix bug.

### Releases v1.0.14

1. Add support to nRF52-based boards, , such ***Adafruit's NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, NINA_B302_ublox, etc.*** The Credentials and Dynamic Parameters' data will be stored in ***LittleFS/InternalFS***.

Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52 would have never been started and finished.

### Releases v1.0.13

1. Optional default ***Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal*** to use or change instead of manually input.
2. ***DoubleDetectDetector*** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
3. Configurable ***Config Portal Title*** to be either HostName, BoardName or default undistinguishable names.
4. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.

Thanks to [thorathome in GitHub](https://github.com/thorathome) to test, suggest and encourage to add those new features to [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD.

### Releases v1.0.12

1. Drop ***AVR Mega*** support because of not enough marginal memory.
2. Add support to ***SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)***.

### Releases v1.0.11

1. Fix potential dangerous bug in code and examples of v1.0.10.

### Releases v1.0.10

#### Potential dangerous bug, Don't use this version

***New in this version***

1. New ***powerful-yet-simple-to-use feature to enable adding dynamic custom parameters*** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
2. Dynamic custom parameters to be saved ***automatically in EEPROM, DueFlashStorage or FlashStorage***.
3. Permit to input special chars such as ***%*** and ***#*** into data fields.

### Releases v1.0.9

1. Reduce html and code size for faster Config Portal response. Enhance GUI.

### Releases v1.0.8

1. Fix bug
2. Change default macAddress for boards to avoid macAddress conflict while simultaneously testing multiple boards.

### Releases v1.0.7

***New in this version***

1. Add support to SAM DUE and SAMD boards
2. Add clearConfigData() to enable resetting Config Data when necessary. 

### Releases v1.0.6

***New in this version***

1. Support ENC28J60 Ethernet shields and other boards such as SAMD, Teensy
2. Add checksum

### Releases v1.0.5

***New in this version***

1. Change Synch XMLHttpRequest to Async to avoid  "InvalidAccessError" DOMException (https://xhr.spec.whatwg.org/)
2. Reduce memory usage.

### Releases v1.0.4 (Fast jumping to v1.0.4 to synch with other Blynk_WM Library)

***New in this version***

1. Add Blynk WiFiManager support to Arduino AVR boards (Mega 1280, Mega 2560, etc.) with Ethernet adapters (W5x00)
2. Configuration data (Blynk Server,Hardware Port, Token, Board Name) saved in configurable EEPROM locations.

## TO DO

1. Same features for other boards with new Ethernet shields.
2. Add SSL/TLS Client and Server support. Currently, Ethernet SSL is not supported by Blynk code yet.
3. Bug Searching and Killing
4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia.

## DONE

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
11. Add ***MultiBlynk*** features with Auto(Re)Connect to the available Server.
12. Easy-to-use ***Dynamic Parameters*** without the necessity to write complicated ArduinoJSon functions
13. Permit to input special chars such as ***%*** and ***#*** into data fields.
14. Support more types of boards using Ethernet shields : ***nRF52*** boards, such as ***AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B30_ublox, etc.***
Default Credentials and dynamic parameters
15. ***DoubleDetectDetector*** to force Config Portal when double reset is detected within predetermined time, default 10s.
16. Configurable Config Portal Title
17. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
18. Add ***LittleFS*** support to ESP8266 as SPIFFS deprecated since ***ESP8266 core 2.7.1.***

### Contributions and thanks

1. Thanks to [thorathome in GitHub](https://github.com/thorathome) to test, suggest and encourage to add those new features to [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Those features are included in this library now.
2. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. See [ESP32-based U-BLOX NINA W102 running ENC28J60](https://u-blox-ethernet-ninaw.blogspot.com/).

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

## Copyright

Copyright 2020- Khoi Hoang
