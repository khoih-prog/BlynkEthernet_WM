## BlynkEthernet_Manager

[![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager)

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

- This is the new library, adding to the current Blynk_WiFiManager. It's designed to help you eliminate `hardcoding` your Blynk credentials in `Mega 1280, Mega 2560, Mega ADK`, ***Teensy, SAM DUE, SAMD, etc. boards using Ethernet shields (W5100, W5200, W5500, ENC28J60, etc)***. It's currently ***not supporting SSL***. 
- It's not supporting UNO/Nano and other AVR boards having only `32KBytes` of program storage space.
- Mega boards can't use dynamic parameter feature because of too small memory size.
- You can update Blynk Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in EEPROM, DueFlashStorage or FlashStorage
- Teensy LC, 2.0++ and 2.0 not supported.

## Prerequisite
 1. [`Arduino IDE 1.8.12 or later` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. `Arduino AVR core 1.8.2 or later` for Arduino (Use Arduino Board Manager)
 3. [`Teensy core 1.51 or later`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 4. [`Arduino SAM DUE core 1.6.12 or later`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards
 5. [`Arduino SAMD core 1.8.5 or later`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards
 6. [`Adafruit SAMD core 1.5.11 or later`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.)
 7. [`Blynk library 0.6.1 or later`](https://www.arduino.cc/en/guide/libraries#toc3)
 8. Depending on which Ethernet card you're using:
   - [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500
   - [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library)
   - [`Ethernet_Shield_W5200 library`](https://github.com/khoih-prog/Ethernet_Shield_W5200) for W5200
   - [`UIPEthernet library`](https://github.com/khoih-prog/UIPEthernet) for ENC28J60
 9. Depending on which board you're using:
   - [`DueFlashStorage library`](https://github.com/sebnil/DueFlashStorage) for SAM DUE
   - [`FlashStorage_SAMD library`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD (DUE, ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)
10. [`EthernetWebServer library`](https://github.com/khoih-prog/EthernetWebServer)
11. [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp)
12. [`ArduinoBearSSL library`](https://github.com/khoih-prog/ArduinoBearSSL) for SSL (not working yet)
13. [`ArduinoECCX08  library`](https://github.com/khoih-prog/ArduinoECCX08)  for SSL (not working yet)

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

### Important note

1. Because using dynamic parameters requires HTML page for Config Portal larger than 2K, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5x00 Ethernet shields.
2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](Ethernet/src/Ethernet.h)
- [EthernetServer.cpp](Ethernet/src/EthernetServer.cpp)
- [w5100.cpp](Ethernet/src/utility/w5100.cpp)

### How to use

In your code, replace
1. `BlynkSimpleEthernet.h`      with `BlynkSimpleEthernet_WM.h`        for board using W5100, W5200, W5500 `without SSL`
2. `BlynkSimpleEthernet2.h`     with `BlynkSimpleEthernet2_WM.h`       for board using only W5500 `without SSL`
3. `BlynkSimpleEthernetV2_0.h`  with `BlynkSimpleEthernetV2_0_WM.h`    for board using only W5500 `without SSL`
4. `BlynkSimpleUIPEthernet.h`   with `BlynkSimpleUIPEthernet_WM.h`     for board using ENC28J60 `without SSL`
5. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleEthernetSSL_WM.h`     for other boards (not Mega) using W5100, W5200, W5500 `with SSL (not working yet)`
6. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleUIPEthernetSSL_WM.h`  for other AVR boards (not Mega) using ENC28J60 `with SSL (not working yet)`


```
// EEPROM size of Mega is 4096 bytes
// Start location to store config data to avoid conflict with other functions
// Config Data use 132 bytes from EEPROM_START
#define EEPROM_START   0

```

Then replace `Blynk.begin(...)` with :

1. `Blynk.begin()`

in your code. Keep `Blynk.run()` intact.

That's it.

Also see examples: 
 1. [AM2315_W5100](examples/AM2315_W5100)
 2. [DHT11_W5100](examples/DHT11_W5100)
 3. [W5100_Blynk](examples/W5100_Blynk) 
 4. [W5100_WM_Config](examples/W5100_WM_Config)
 5. [W5100_Blynk_Email](examples/W5100_Blynk_Email)
 6. [W5100_Blynk](examples/W5100_Blynk) 
 7. [W5100_WM_Config_Teensy](examples/W5100_WM_Config_Teensy)
 8. [W5100_Blynk_Email_Teensy](examples/W5100_Blynk_Email_Teensy)
 9. [W5100_Blynk_Teensy](examples/W5100_Blynk_Teensy) 
10. [W5100_WM_Config_SAMD](examples/W5100_WM_Config_SAMD)
11. [W5100_Blynk_Email_SAMD](examples/W5100_Blynk_Email_SAMD)
12. [W5100_Blynk_SAMD](examples/W5100_Blynk_SAMD) 
13. [W5100_WM_Config_SAM_DUE](examples/W5100_WM_Conf_SAM_DUE)
14. [W5100_Blynk_Email_SAM_DUE](examples/W5100_Blynk_Email_SAM_DUE)
15. [W5100_Blynk_SAM_DUE](examples/W5100_Blynk_SAM_DUE) 
16. [W5100_WM_Config_Mega](examples/W5100_WM_Config_Mega)
17. [W5100_Blynk_Email_Mega](examples/W5100_Blynk_Email_Mega)
18. [ENC28J60_Blynk_Mega](examples/ENC28J60_Blynk_Mega)
19. [ENC28J60_WM_Config](examples/ENC28J60_WM_Config)
20. [ENC28J60_Blynk_Email](examples/ENC28J60_Blynk_Email)
21. [BlynkHTTPClient](examples/BlynkHTTPClient)


## So, how it works?
If no valid config data are stored in EEPROM, it will switch to `Configuration Mode`. Connect to access point at the IP address displayed on Terminal or Router's DHCP server as in the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_1.png">
</p>

After you connected to, for example, `192.168.2.86`, the Browser will display the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_2.png">
</p>

or for Mega boards

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_2_Mega.png">
</p>

Enter your credentials (Blynk Servers/Tokens and Port). If you prefer static IP, input it (for example `192.168.2.220`) in the corresponding field. Otherwise, just leave it `blank` or `nothing` to use auto IP assigned by DHCP server.

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_3.png">
</p>

or for Mega boards

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_3_Mega.png">
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

This is the terminal output of a SAM DUE board with W5100 Ethernet shield running [W5100_WM_Config](examples/W5100_WM_Config) example (note that Buffer Size **SSIZE** of W5100 is 4096 now)

```
Start W5100_Blynk on SAM DUE
[1] Simulate EEPROM, sz:1024
[1] CrCCsum=7278,CrRCsum=7278,TotalDataSz=380
[1] CCSum=0x28dd,RCSum=0x28dd
[1] Hdr=W5X00,BName=SAM-DUE_W5100-WM
[5] Svr=192.168.2.112,Tok=token
[10] Svr1=account.duckdns.org,Tok1=token1
[18] MAC:FE-DD-CA-91-BC-B0
W5100::init: W5100, SSIZE =4096
[1581] GetIP:
[1581] IP:192.168.2.220
[1581] bg:ECon.TryB
[1581] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino Due

[1588] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[1605] Ready (ping: 9ms).
[1605] Free RAM: 89887
[1673] Connected to BlynkServer=192.168.2.112,Token=token
[1673] bg:EBCon
Conn2Blynk: server = 192.168.2.112, port = 8080
Token = token, IP = 192.168.2.220
B
Your stored Credentials :
MQTT Server = mqtt.duckdns.org
Port = 1883
MQTT UserName = mqtt-username
MQTT PWD = mqtt-password
Subs Topics = SubTopic_SAMDUE
Pubs Topics = PubTopic_SAMDUE
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

## TO DO

1. Same features for other boards with Ethernet shields.
2. To write code and make SSL working. Currently, Ethernet SSL is not supported by Blynk code yet.

## DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (Serves, HardwarePort and Blynk tokens), entering config portal
 5. Change Synch XMLHttpRequest to Async
 6. Reduce memory usage.
 7. Support ENC28J60 as well as W5x00 Ethernet shields
 8. Add checksums
 9. Support SAM DUE, SAMD, Teensy besides AVR Mega boards
10. Support STM32 boards
11. Add MultiBlynk features with Auto(Re)Connect to the available Server.
12. Easy-to-use Dynamic Parameters without the necessity to write complicated ArduinoJSon functions
13. Permit to input special chars such as ***%*** and ***#*** into data fields.


## Example
Please take a look at example [W5100_Blynk](examples/W5100_Blynk) below

```
#if defined(ESP8266) || defined(ESP32)
#error This code is designed to run on Arduino AVR (Mega1280, 2560, ADK, etc.), SAMD, SAM-DUE, Teensy platform, not ESP8266 nor ESP32! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define _ETHERNET_WEBSERVER_LOGLEVEL_   0
#define BLYNK_PRINT Serial

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
   || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
   || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) )
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

#if ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) )
#if defined(ETHERNET_USE_MEGA)
#undef ETHERNET_USE_MEGA
#endif
#define ETHERNET_USE_MEGA           true
#define USE_DYNAMIC_PARAMETERS      false
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

#elif defined(ETHERNET_USE_MEGA)
// For Mega
#define BOARD_TYPE      "AVR Mega"

#else
#error Unknown Board. Please check your Tools->Board setting.

#endif    //BOARD_TYPE

#include <SPI.h>

// Start location in EEPROM to store config data. Default 0.
#define EEPROM_START     0

#define USE_SSL     false
//#define USE_SSL     true

#if USE_SSL
// Need ArduinoECCX08 and ArduinoBearSSL libraries
// Currently, error not enough memory for UNO, Mega2560. Don't use
#include <BlynkSimpleEthernetSSL_WM.h>
#else
#include <BlynkSimpleEthernet_WM.h>
#endif

// Mega has too small memory and can't run dynamic parameters
#if (!ETHERNET_USE_MEGA)

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleEsp8266_WM.h> and <BlynkSimpleEsp8266_SSL_WM.h>
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
char MQTT_Server  [MAX_MQTT_SERVER_LEN]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

#else

MenuItem myMenuItems [] = {};

#endif


uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;
/////// // End dynamic Credentials ///////////

#endif    //(!ETHERNET_USE_MEGA)

#define USE_BLYNK_WM      true

#if !USE_BLYNK_WM
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
#endif

#define W5100_CS  10
#define SDCARD_CS 4

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("\nStart W5100_Blynk on " + String(BOARD_TYPE));

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

#if USE_BLYNK_WM
  Blynk.begin();
#else
#if USE_LOCAL_SERVER
  Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
#else
  Blynk.begin(auth);
  // You can also specify server:
  //Blynk.begin(auth, server, BLYNK_HARDWARE_PORT);
#endif
#endif

  if (Blynk.connected())
  {
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(Blynk.getServerName());
    Serial.print(F(", port = "));
    Serial.println(Blynk.getHWPort());
    Serial.print(F("Token = "));
    Serial.print(Blynk.getToken());
    Serial.print(F(", IP = "));
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

#if USE_DYNAMIC_PARAMETERS
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

#if USE_DYNAMIC_PARAMETERS
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

The following is the sample terminal output when running example [BlynkHTTPClient](examples/ESP8266WM_Config) on Mega2560 wth ENC28J0 Ethernet shield.

```
[9] EEPROM, sz:4096
[10] Hdr=ENC28J60,Auth=****
[11] Svr=account.duckdns.org,Port=8080
[14] SIP=192.168.2.220,BName=ENC28J60-WM
[17] MAC: FE-DD-AE-C4-8F-B2
[1073] GetIP:
[1073] IP:192.168.2.220
[1074] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino Mega

[1084] bg: E.con.Try B
[1086] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[6087] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[7916] Ready (ping: 32ms).
[7983] bg: EBconn'd
Blynk connected
Connecting to vsh.pp.ua OK
Performing HTTP GET request...
HTTP/1.1 200 OK
Server: nginx/1.10.3 (Ubuntu)
Date: Fri, 21 Feb 2020 05:02:08 GMT
Content-Type: text/plain; charset=UTF-8
Content-Length: 121
Connection: close
X-DNS-Prefetch-Control: off
X-Frame-Options: SAMEORIGIN
Strict-Transport-Security: max-age=15552000; includeSubDomains
X-Download-Options: noopen
X-Content-Type-Options: nosniff
X-XSS-Protection: 1; mode=block
Accept-Ranges: bytes
Cache-Control: public, max-age=0
Last-Modified: Wed, 27 Sep 2017 09:03:12 GMT
ETag: W/"79-15ec2936080"


  _____            _____  _____  _____
    |  | |\ | \_/ |  ___ |_____ |  |  |
    |  | | \|  |  |_____| _____||  |  |


Server disconnected
```

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

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

## Copyright

Copyright 2020- Khoi Hoang
