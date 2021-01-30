/****************************************************************************************************************************
  EthernetENC_Blynk_SAM_DUE.ino
  For SAM DUE boards using ENC28J60 Ethernet shields with EthernetENC library
  
  BlynkEthernet_WM is a library for Teensy, ESP, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J69 shields,
  to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk
  
  Library forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
  Licensed under MIT license
  Version: 1.2.0

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
  1.0.16    K Hoang      15/05/2020 Sync with EthernetWebServer v.1.0.9 to use 25MHz for W5x00 and EthernetWrapper feature.
  1.0.17    K Hoang      25/07/2020 New logic for USE_DEFAULT_CONFIG_DATA. Add support to Seeeduino SAMD21/SAMD51 boards.
  1.0.18    K Hoang      15/09/2020 Add support to new EthernetENC library for ENC28J60.
  1.1.0     K Hoang      13/01/2021 Add support to new NativeEthernet library for Teensy 4.1. Fix compiler warnings.
  1.2.0     K Hoang      29/01/2021 Fix bug. Add feature. Use more efficient FlashStorage_STM32 and FlashStorage_SAMD.
 *****************************************************************************************************************************/

#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <SPI.h>

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  delay(200);
  
  Serial.print(F("\nStart EthernetENC_Blynk_SAM_DUE on ")); Serial.print(BOARD_NAME);
  Serial.println(" with " + String(SHIELD_TYPE));
  Serial.println(BLYNK_ETHERNET_WM_VERSION);

  BLYNK_LOG4(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);
  
  Ethernet.init (USE_THIS_SS_PIN);
  
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
