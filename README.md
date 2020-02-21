## BlynkEthernet_Manager

[![arduino-library-badge](https://www.ardu-badge.com/badge/BlynkEthernet_Manager.svg?)](https://www.ardu-badge.com/BlynkEthernet_Manager)

I'm inspired by [`EasyBlynk8266`](https://github.com/Barbayar/EasyBlynk8266)

- This is the new library, adding to the current Blynk_WiFiManager. It's designed to help you eliminate `hardcoding` your Blynk credentials in `Mega 1280, Mega 2560`, Teensy, SAMD, etc. boards using with Ethernet board (W5100, W5200, W5500, ENC28J60, etc). It's currently not supporting SSL because there is not enough memory (only `8 KBytes`) in Mega boards. 
- It's not supporting UNO/Nano and other AVR boards having only `32KBytes` of program storage space.

- You can update Blynk Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in EEPROM.

## Prerequisite
1. [`Arduino IDE 1.8.10 or later` for Arduino](https://www.arduino.cc/en/Main/Software)
2. `Arduino AVR core 1.8.2 or later` for Arduino (Use Arduino Board Manager)
3. [`Blynk library 0.6.1 or later`](https://www.arduino.cc/en/guide/libraries#toc3)
4. Depending on which Ethernet card you're using:
   - [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500
   - [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library)
   - [`Ethernet_Shield_W5200 library`](https://github.com/khoih-prog/Ethernet_Shield_W5200) for W5200
   - [`UIPEthernet library`] (https://github.com/khoih-prog/UIPEthernet) for ENC28J60
5. [`EthernetWebServer library`](https://github.com/khoih-prog/EthernetWebServer)
6. [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp)
7. [`ArduinoBearSSL library`](https://github.com/khoih-prog/ArduinoBearSSL) for SSL
8. [`ArduinoECCX08  library`](https://github.com/khoih-prog/ArduinoECCX08)  for SSL

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager
Another way is to use `Arduino Library Manager`. Search for `BlynkEthernet_WM`, then select / install the latest version.

#### Manual Install

1. Navigate to [BlynkEthernet_WM](https://github.com/khoih-prog/BlynkEthernet_WM) page.
2. Download the latest release `BlynkEthernet_WM-master.zip`.
3. Extract the zip file to `BlynkEthernet_WM-master` directory 
4. Copy whole 
  - `BlynkEthernet_WM-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### How to use

In your code, replace
1. `BlynkSimpleEthernet.h`      with `BlynkSimpleEthernet_WM.h`        for board using W5100, W5200, W5500 `without SSL`
2. `BlynkSimpleEthernet2.h`     with `BlynkSimpleEthernet2_WM.h`       for board using only W5500 `without SSL`
3. `BlynkSimpleEthernetV2_0.h`  with `BlynkSimpleEthernetV2_0_WM.h`    for board using only W2500 `without SSL`
4. `BlynkSimpleUIPEthernet.h`   with `BlynkSimpleUIPEthernet_WM.h`     for board using ENC28J60 `without SSL`
5. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleEthernetSSL_WM.h`     for other boards (not Mega) using W5100, W5200, W5500 `with SSL`
6. `BlynkSimpleEthernetSSL.h`   with `BlynkSimpleUIPEthernetSSL_WM.h`  for other AVR boards (not Mega) using ENC28J60 `with SSL`


```
// EEPROM size of Mega is 4096 bytes
// Start location to store config data to avoid conflict with other functions
// Config Data use 112 bytes from EEPROM_START
#define EEPROM_START   1024

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
3. [ENC28J60_Blynk](examples/ENC28J60_Blynk) 
4. [ENC28J60_WM_Config](examples/ENC28J60_WM_Config)
5. [ENC28J60_Blynk_Email](examples/ENC28J60_Blynk_Email)
6. [BlynkHTTPClient](examples/BlynkHTTPClient)


## So, how it works?
If no valid config data are stored in EEPROM, it will switch to `Configuration Mode`. Connect to access point at the IP address displayed on Terminal or Router's DHCP server as in the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_1.png">
</p>

After you connected to, for example, `192.168.2.86`, the Browser will display the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/BlynkEthernet_WM/blob/master/pics/Selection_2.png">
</p>

Enter your credentials (Blynk Server and Port). If you prefer static IP, input it (for example `192.168.2.79`) in the corresponding field. Otherwise, just leave it `blank` or `nothing` to use auto IP assigned by DHCP server.

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

## TO DO

1. Same features for other boards with Ethernet shields.

## DONE

1. Permit EEPROM size and location configurable to avoid conflict with others.
2. More flexible to configure reconnection timeout.
3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
4. If the config data not entered completely (Server, HardwarePort and Blynk token), entering config portal
5. Change Synch XMLHttpRequest to Async
6. Reduce memory usage.
7. Support ENC28J60 Ethernet shield
8. Add checksum


## Example
Please take a look at examples, as well.
```
#if defined(ESP8266) || defined(ESP32)
#error This code is designed to run on Arduino AVR (Nano, UNO, Mega, etc.) platform, not ESP8266 nor ESP32! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes w/o chksum, 132 with chksum)
#define EEPROM_START     384

#define USE_SSL     false

#define USE_CHECKSUM      true

#define USE_SSL     false

#if USE_SSL
  // Need ArduinoECCX08 and ArduinoBearSSL libraries
  // Currently, error not enough memory for UNO, Mega2560. Don't use
  #include <BlynkSimpleEthernetSSL_WM.h>
#else
  #include <BlynkSimpleEthernet_WM.h>
#endif

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
  Serial.println(F("\nStart W5100_Blynk"));

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

void loop()
{
  Blynk.run();
  check_status();
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
