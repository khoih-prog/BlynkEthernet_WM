/****************************************************************************************************************************
   BlynkEthernet_NRF52_WM.h
   For NRF52 or NRF52-based boards running W5x00, ENC28J60 Ethernet shields

   BlynkEthernet_WM is a library for Teensy, STM32, SAM DUE and SAMD boards, with Ethernet W5200, W5500 or ENC28J60 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk.
.  AVR Mega and W5100 is not supported.
   Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
   Licensed under MIT license
   Version: 1.0.15

   Example created by Miguel Alexandre Wisintainer (https://github.com/tcpipchip)

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
    1.0.14    K Hoang      01/05/2020 Add support to Adafruit nRF522, including NINA_B302_ublox. 
    1.0.15    K Hoang      12/05/2020 Fix bug and Update to use LittleFS for ESP8266 core 2.7.1+.                                
*****************************************************************************************************************************/

#include <bluefruit.h>

#define BLYNK_PRINT Serial

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
#endif

//#define USE_UIP_ETHERNET   true
#define USE_UIP_ETHERNET   false  //true

#if USE_UIP_ETHERNET
#include <UIPEthernet.h>
#include <BlynkSimpleUIPEthernet.h>
#else
//#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#endif

#define USE_LOCAL_SERVER      true

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
#if USE_LOCAL_SERVER
// Local Blynk Server
char token[] = "****";

// Fill the name of Blynk Server
char server[] = "account.ddns.net";
//char server[] = "****.ddns.net";
//char server[] = "192.168.2.112";

#else

//Cloud Blynk Server
char token[] = "******";
char server[] = "blynk-cloud.com";

#endif

#define BLYNK_HARDWARE_PORT       8080

WidgetLED led1(V1);

WidgetLCD lcd(V0);

unsigned short Temp_D1, Temp_D2;

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue())
  {
    led1.off();
    Serial.println("LED on V1: off");
  }
  else
  {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

int cnt = 0;

char Temp[32];

void doSomething(void)
{
  Serial.println("============ Print Every 120s ============");
  blinkLedWidget();
  Serial.println("========== And Blink LED widget ==========");
  sprintf(Temp, "%0d.%0d", Temp_D1, Temp_D2);
  lcd.print(0, 0, String(Temp));
}

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
    Serial.print(F("B"));     // For Blynk OK
  else
    Serial.print(F("F"));     // Failure

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

#define BLYNK_CONNECT_TIMEOUT_MS      20000
#define USE_NON_BLOCKING_BLYNK        false


void setup()
{
  // Debug console
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb

  Serial.println("\nStart nRF52840_BLE_Scanner on " + String(BOARD_TYPE));

#if USE_NON_BLOCKING_BLYNK
  Blynk.config(token, server, BLYNK_HARDWARE_PORT);
  Blynk.connect(BLYNK_CONNECT_TIMEOUT_MS);
#else
  //Blynk.begin(auth);
  // You can also specify server:
  Blynk.begin(token, server, BLYNK_HARDWARE_PORT);
#endif

  if (Blynk.connected())
  {
    Serial.print(F("Conn2Blynk: server = "));
    Serial.print(server);
    Serial.print(F(", port = "));
    Serial.println(BLYNK_HARDWARE_PORT);
    Serial.print(F("Token = "));
    Serial.print(token);
    Serial.print(F(", IP = "));
    Serial.println(Ethernet.localIP());
  }

  // Every 120s, doSomething => print and blink LED (V1) on APP
  timer.setInterval(5000L, doSomething);

  Serial.println("Bluefruit52 Central Scan Example");
  Serial.println("--------------------------------\n");

  // Initialize Bluefruit with maximum connections as Peripheral = 0, Central = 1
  // SRAM usage required by SoftDevice will increase dramatically with number of connections
  Bluefruit.begin(0, 1);
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
  Bluefruit.setName("Bluefruit52");

  // Start Central Scan
  Bluefruit.setConnLedInterval(250);
  Bluefruit.Scanner.setRxCallback(scan_callback);
  Bluefruit.Scanner.start(0);

  Serial.println("Scanning ...");
}

//DB:9C:ED:D2:A2:F7
unsigned char smart_watch_mac[] = {0xDB, 0x9C, 0xED, 0xD2, 0xA2, 0xF7};

void scan_callback(ble_gap_evt_adv_report_t* report)
{
  if (report->peer_addr.addr[5] == smart_watch_mac[0])
    if (report->peer_addr.addr[4] == smart_watch_mac[1])
      if (report->peer_addr.addr[3] == smart_watch_mac[2])
        if (report->peer_addr.addr[2] == smart_watch_mac[3])
          if (report->peer_addr.addr[1] == smart_watch_mac[4])
            if (report->peer_addr.addr[0] == smart_watch_mac[5])
            {
              // MAC is in little endian --> print reverse
              Serial.printBufferReverse(report->peer_addr.addr, 6, ':');
              Serial.printBuffer(report->data.p_data, report->data.len, '-');
              Serial.println();
              Serial.print(report->data.p_data[11]);
              Serial.print(".");
              Serial.println(report->data.p_data[12]);
              Temp_D1 = report->data.p_data[11]; //to blynk
              Temp_D2 = report->data.p_data[12]; //to blynk
            }
  // For Softdevice v6: after received a report, scanner will be paused
  // We need to call Scanner resume() to continue scanning
  Bluefruit.Scanner.resume();
}

void loop()
{
  Blynk.run();
  timer.run();
  check_status();
}
