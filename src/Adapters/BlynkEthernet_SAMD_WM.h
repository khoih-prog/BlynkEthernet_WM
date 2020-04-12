/****************************************************************************************************************************
   BlynkEthernet_SAMD_WM.h
   For SAMD boards running W5x00, ENC28J60 Ethernet shields

   BlynkEthernet_WM is a library for Mega AVR, Teensy, SAM DUE and SAMD boards, with Ethernet W5X00 or ENC28J60 shields,
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of Ethernet/Blynk

   Library modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkEthernet_WM
   Licensed under MIT license
   Version: 1.0.10

   Original Blynk Library author:
   @file       BlynkGsmClient.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
   @date       Jan 2015
   @brief

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.4   K Hoang      14/01/2020 Initial coding
    1.0.5   K Hoang      24/01/2020 Change Synch XMLHttpRequest to Async (https://xhr.spec.whatwg.org/)
    1.0.6   K Hoang      20/02/2020 Add support to ENC28J60 Ethernet shields
    1.0.7   K Hoang      20/02/2020 Add support to SAM DUE and SAMD boards
    1.0.8   K Hoang      03/03/2020 Fix bug. Change default macAddress for boards
    1.0.9   K Hoang      10/03/2020 Reduce html and code size. Enhance GUI.
    1.0.10  K Hoang      11/04/2020 Add MultiBlynk, dynamic parameters, special chars input
 *****************************************************************************************************************************/

#ifndef BlynkEthernet_SAMD_WM_h
#define BlynkEthernet_SAMD_WM_h

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
   || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
   || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD      true
#else
#error This code is designed to run on SAMD platform! Please check your Tools->Board setting.
#endif

#define BLYNK_ETHERNET_DEBUG      0

#ifndef BLYNK_INFO_CONNECTION
#define BLYNK_INFO_CONNECTION "W5000"
#endif

#ifdef BLYNK_USE_SSL
#define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT_SSL
#else
#define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT
#endif

// Increase HTTP_UPLOAD_BUFLEN to 4K, instead of default 2K in <EthernetWebServer.h>
#define HTTP_UPLOAD_BUFLEN    4096

#include <BlynkApiArduino.h>
#include <Blynk/BlynkProtocol.h>
#include <Adapters/BlynkArduinoClient.h>
#include <EthernetWebServer.h>

// Include EEPROM-like API for FlashStorage
//#include <FlashAsEEPROM.h>                //https://github.com/cmaglie/FlashStorage
#include <FlashAsEEPROM_SAMD.h>             //https://github.com/khoih-prog/FlashStorage_SAMD

//NEW
#define MAX_ID_LEN                5
#define MAX_DISPLAY_NAME_LEN      16

typedef struct
{
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
} MenuItem;
//

///NEW
extern uint16_t NUM_MENU_ITEMS;
extern MenuItem myMenuItems [];

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

// Currently CONFIG_DATA_SIZE  =  ( 64 + (68 * NUM_BLYNK_CREDENTIALS) ) = 200

// -- HTML page fragments
const char BLYNK_WM_HTML_HEAD[]     /*PROGMEM*/ = "<!DOCTYPE html><html><head><title>BlynkEthernet_SAMD_WM</title><style>div,input{padding:2px;font-size:1em;}input{width:95%;}\
body{text-align: center;}button{background-color:#16A1E7;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.5rem;margin:0px;}\
</style></head><div style=\"text-align:left;display:inline-block;min-width:260px;\">\
<fieldset><div><label>Blynk Server</label><input value=\"[[sv]]\"id=\"sv\"><div></div></div>\
<div><label>Token</label><input value=\"[[tk]]\"id=\"tk\"><div></div></div>\
<div><label>Blynk Server1</label><input value=\"[[sv1]]\"id=\"sv1\"><div></div></div>\
<div><label>Token1</label><input value=\"[[tk1]]\"id=\"tk1\"><div></div></div>\
<div><label>Port</label><input value=\"[[pt]]\"id=\"pt\"><div></div></div>\
<div><label>StaticIP</label><input value=\"[[ip]]\"id=\"ip\"><div></div></div></fieldset>\
<fieldset><div><label>Board Name</label><input value=\"[[nm]]\"id=\"nm\"><div></div></div></fieldset>";

const char BLYNK_WM_FLDSET_START[]  /*PROGMEM*/ = "<fieldset>";
const char BLYNK_WM_FLDSET_END[]    /*PROGMEM*/ = "</fieldset>";
const char BLYNK_WM_HTML_PARAM[]    /*PROGMEM*/ = "<div><label>{b}</label><input value='[[{v}]]'id='{i}'><div></div></div>";
const char BLYNK_WM_HTML_BUTTON[]   /*PROGMEM*/ = "<button onclick=\"sv()\">Save</button></div>";
const char BLYNK_WM_HTML_SCRIPT[]   /*PROGMEM*/ = "<script id=\"jsbin-javascript\">\
function udVal(key,val){var request=new XMLHttpRequest();var url='/?key='+key+'&value='+encodeURIComponent(val);request.open('GET',url,false);request.send(null);}\
function sv(){udVal('sv',document.getElementById('sv').value);udVal('tk',document.getElementById('tk').value);\
udVal('sv1',document.getElementById('sv1').value);udVal('tk1',document.getElementById('tk1').value);\
udVal('pt',document.getElementById('pt').value);udVal('ip',document.getElementById('ip').value);\
udVal('nm',document.getElementById('nm').value);";

const char BLYNK_WM_HTML_SCRIPT_ITEM[]  /*PROGMEM*/ = "udVal('{d}',document.getElementById('{d}').value);";
const char BLYNK_WM_HTML_SCRIPT_END[]   /*PROGMEM*/ = "alert('Updated');}</script>";
const char BLYNK_WM_HTML_END[]          /*PROGMEM*/ = "</html>";
///

#define BLYNK_SERVER_HARDWARE_PORT    8080

class BlynkEthernet
  : public BlynkProtocol<BlynkArduinoClient>
{
    typedef BlynkProtocol<BlynkArduinoClient> Base;
  public:
    BlynkEthernet(BlynkArduinoClient& transp)
      : Base(transp)
    {}

    void config(const char* auth,
                const char* domain = BLYNK_DEFAULT_DOMAIN,
                uint16_t    port   = BLYNK_SERVER_PORT)
    {
      // Base == BlynkProtocol.h
      Base::begin(auth);
      // conn == BlynkArduinoClient
      this->conn.begin(domain, port);
    }

    void config(const char* auth,
                IPAddress   ip,
                uint16_t    port = BLYNK_SERVER_PORT)
    {
      Base::begin(auth);
      this->conn.begin(ip, port);
    }

    // DHCP with domain
    void begin( const char* auth,
                const char* domain = BLYNK_DEFAULT_DOMAIN,
                uint16_t port      = BLYNK_SERVER_PORT,
                const byte mac[]   = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("GetIP:"));
#endif

      if (!Ethernet.begin(SelectMacAddress(auth, mac))) {
        BLYNK_FATAL(BLYNK_F("DHCP 0"));
      }
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, domain, port);
      while (this->connect() != true) {}
    }

    // Static IP with domain
    void begin( const char* auth,
                const char* domain,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                const byte mac[] = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("UseStatIP"));
#endif

      Ethernet.begin(SelectMacAddress(auth, mac), local, dns);
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, domain, port);
      while (this->connect() != true) {}
    }

    // Static IP with domain, gateway, etc
    void begin( const char* auth,
                const char* domain,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                IPAddress gateway,
                IPAddress subnet,
                const byte mac[] = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("UseStatIP"));
#endif

      Ethernet.begin(SelectMacAddress(auth, mac), local, dns, gateway, subnet);
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, domain, port);
      while (this->connect() != true) {}
    }

    // DHCP with server IP
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port    = BLYNK_SERVER_PORT,
                const byte mac[] = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("GetIP:"));
#endif

      if (!Ethernet.begin(SelectMacAddress(auth, mac))) {
        BLYNK_FATAL(BLYNK_F("DHCP 0"));
      }
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, addr, port);
      while (this->connect() != true) {}
    }

    // Static IP with server IP
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port,
                IPAddress local,
                const byte mac[] = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("UseStatIP"));
#endif

      Ethernet.begin(SelectMacAddress(auth, mac), local);
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, addr, port);
      while (this->connect() != true) {}
    }

    // Static IP with server IP, DNS, gateway, etc
    void begin( const char* auth,
                IPAddress addr,
                uint16_t port,
                IPAddress local,
                IPAddress dns,
                IPAddress gateway,
                IPAddress subnet,
                const byte mac[] = NULL)
    {
#if (BLYNK_ETHERNET_DEBUG > 1)
      BLYNK_LOG1(BLYNK_F("UseStatIP"));
#endif

      Ethernet.begin(SelectMacAddress(auth, mac), local, dns, gateway, subnet);
      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);
      IPAddress myip = Ethernet.localIP();
      BLYNK_LOG_IP("IP:", myip);

      config(auth, addr, port);
      while (this->connect() != true) {}
    }

    void begin()
    {
      hadConfigData = getConfigData();

      connectEthernet();

      if (hadConfigData)
      {
        if (ethernetConnected)
        {
          BLYNK_LOG1(BLYNK_F("bg:ECon.TryB"));

          int i = 0;
          while ( (i++ < 10) && !this->connectMultiBlynk() )
          {
          }

          if  (connected())
          {
            BLYNK_LOG1(BLYNK_F("bg:EBCon"));
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("bg:ECon,BNo"));
            // failed to connect to Blynk server, will start configuration mode
            startConfigurationMode();
          }
        }
        else
        {
          // Can't do anything here
          BLYNK_LOG1(BLYNK_F("bg:E&BNoCon"));
          // failed to connect to Blynk server, will start configuration mode
          //startConfigurationMode();
        }
      }
      else
      {
        BLYNK_LOG1(BLYNK_F("bg:NoDat.Stay"));
        // failed to connect to Blynk server, will start configuration mode
        hadConfigData = false;
        startConfigurationMode();
      }
    }

    void run()
    {
      static int retryTimes = 0;

      // Be sure to reconnect Ethernet first
      if (!ethernetConnected)
      {
        connectEthernet();
      }

      // Lost connection in running. Give chance to reconfig.
      if ( !connected() )
      {
        // If configTimeout but user hasn't connected to configWeb => try to reconnect Blynk.
        // But if user has connected to configWeb, stay there until done, then reset hardware
        if ( configuration_mode && ( configTimeout == 0 ||  millis() < configTimeout ) )
        {
          retryTimes = 0;

          if (server)
          {
            server->handleClient();
          }

          return;
        }
        else
        {
#if RESET_IF_CONFIG_TIMEOUT
          // If we're here but still in configuration_mode, permit running TIMES_BEFORE_RESET times before reset hardware
          // to permit user another chance to config.
          if ( configuration_mode && (configTimeout != 0) )
          {
            if (++retryTimes <= CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET)
            {
              BLYNK_LOG2(BLYNK_F("r:BLost,TOut.TryB.#:"), retryTimes);
            }
            else
            {
              BlynkReset();
            }
          }
#endif

          // Not in config mode, try reconnecting before forcing to config mode
          BLYNK_LOG1(BLYNK_F("r:BLost.TryB"));

          if (connectMultiBlynk())
          {
            // turn the LED_BUILTIN OFF to tell us we exit configuration mode.
            digitalWrite(LED_BUILTIN, HIGH);
            BLYNK_LOG1(BLYNK_F("r:BRecon"));
          }
        }
      }
      else if (configuration_mode)
      {
        configuration_mode = false;
        BLYNK_LOG1(BLYNK_F("r:E&B OK"));
      }

      if (connected())
      {
        Base::run();
      }
    }

    String getBoardName()
    {
      return (String(BlynkEthernet_WM_config.board_name));
    }

    String getServerName(uint8_t index = 255)
    {
      if (index == 255)
      {
        // Current connected Blynk Server
        index = currentBlynkServerIndex;
      }
        
      if (index >= NUM_BLYNK_CREDENTIALS)
        return String("");

      if (!hadConfigData)
        getConfigData();

      return (String(BlynkEthernet_WM_config.Blynk_Creds[index].blynk_server));
    }

    String getToken(uint8_t index = 255)
    {
      if (index == 255)
      {
        // Current connected Blynk Server
        index = currentBlynkServerIndex;
      }
          
      if (index >= NUM_BLYNK_CREDENTIALS)
        return String("");

      if (!hadConfigData)
        getConfigData();

      return (String(BlynkEthernet_WM_config.Blynk_Creds[index].blynk_token));
    }

    int getHWPort()
    {
      return (BlynkEthernet_WM_config.blynk_port);
    }

    Blynk_Configuration* getFullConfigData(Blynk_Configuration *configData)
    {
      if (!hadConfigData)
        getConfigData();

      // Check if NULL pointer
      if (configData)
        memcpy(configData, &BlynkEthernet_WM_config, sizeof(BlynkEthernet_WM_config));

      return (configData);
    }
    
    void clearConfigData()
    {
      memset(&BlynkEthernet_WM_config, 0, sizeof(BlynkEthernet_WM_config));
      //EEPROM.put(EEPROM_START, BlynkEthernet_WM_config);
      saveConfigData();
    }

  private:

    // Initialize the Ethernet server library
    // with the IP address and port you want to use
    // (port 80 is default for HTTP):
    EthernetWebServer *server;

    bool ethernetConnected = false;

    bool configuration_mode = false;

    unsigned long configTimeout;
    bool hadConfigData = false;

    Blynk_Configuration BlynkEthernet_WM_config;
    
    uint16_t totalDataSize = 0;
    
    uint8_t currentBlynkServerIndex = 255;

#define RFC952_HOSTNAME_MAXLEN      24
    char RFC952_hostname[RFC952_HOSTNAME_MAXLEN + 1];

    void setRFC952_hostname(const char* iHostname = "")
    {
      if (iHostname[0] == 0)
      {
        String _hostname = "SAMD-XXXXXX";    // + String(macAddress, HEX);
        _hostname.toUpperCase();

        getRFC952_hostname(_hostname.c_str());

      }
      else
      {
        // Prepare and store the hostname only not NULL
        getRFC952_hostname(iHostname);
      }

#if (BLYNK_ETHERNET_DEBUG > 0)
      BLYNK_LOG2(BLYNK_F("Hname="), RFC952_hostname);
#endif
    }

    char* getRFC952_hostname(const char* iHostname)
    {
      memset(RFC952_hostname, 0, sizeof(RFC952_hostname));

      size_t len = ( RFC952_HOSTNAME_MAXLEN < strlen(iHostname) ) ? RFC952_HOSTNAME_MAXLEN : strlen(iHostname);

      size_t j = 0;

      for (size_t i = 0; i < len - 1; i++)
      {
        if ( isalnum(iHostname[i]) || iHostname[i] == '-' )
        {
          RFC952_hostname[j] = iHostname[i];
          j++;
        }
      }
      // no '-' as last char
      if ( isalnum(iHostname[len - 1]) || (iHostname[len - 1] != '-') )
        RFC952_hostname[j] = iHostname[len - 1];

      return RFC952_hostname;
    }

    void displayConfigData(void)
    {
      BLYNK_LOG4(BLYNK_F("Hdr="),       BlynkEthernet_WM_config.header,
                 BLYNK_F(",BName="),    BlynkEthernet_WM_config.board_name);
      BLYNK_LOG4(BLYNK_F("Svr="),       BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server,
                 BLYNK_F(",Tok="),      BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token);
      BLYNK_LOG4(BLYNK_F("Svr1="),      BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server,
                 BLYNK_F(",Tok1="),     BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token);
      BLYNK_LOG4(BLYNK_F("Prt="),       BlynkEthernet_WM_config.blynk_port,
                 BLYNK_F(",SIP="),      BlynkEthernet_WM_config.static_IP);
    }

#define BLYNK_BOARD_TYPE      BLYNK_INFO_CONNECTION
#define WM_NO_CONFIG          "blank"

    // Currently 200 (chsum)
    uint16_t CONFIG_DATA_SIZE = sizeof(struct Configuration);

    int calcChecksum()
    {
      int checkSum = 0;
      for (uint16_t index = 0; index < (sizeof(BlynkEthernet_WM_config) - sizeof(BlynkEthernet_WM_config.checkSum)); index++)
      {
        checkSum += * ( ( (byte*) &BlynkEthernet_WM_config ) + index);
      }

      return checkSum;
    }

    bool EEPROM_get()
    {
      // It's too bad that emulate EEPROM.read()/write() can only deal with bytes. 
      // Have to read/write each byte. To rewrite the library
      
      uint16_t offset = EEPROM_START;
                
      uint8_t* _pointer = (uint8_t *) &BlynkEthernet_WM_config;
      
      for (int i = 0; i < sizeof(BlynkEthernet_WM_config); i++, _pointer++, offset++)
      {              
        *_pointer = EEPROM.read(offset);
      }
           
      int checkSum = 0;
      int readCheckSum;
      
      totalDataSize = sizeof(BlynkEthernet_WM_config) + sizeof(readCheckSum);
   
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        _pointer = (uint8_t *) myMenuItems[i].pdata;
        totalDataSize += myMenuItems[i].maxlen;
               
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++, _pointer++, offset++)
        {
          *_pointer = EEPROM.read(offset);          
          checkSum += *_pointer;  
         }       
      }
      
      _pointer = (uint8_t *) &readCheckSum;
      
      for (int i = 0; i < sizeof(readCheckSum); i++, _pointer++, offset++)
      {                  
        *_pointer = EEPROM.read(offset);
      }
         
      BLYNK_LOG4(F("CrCCSum="), checkSum, F(",CrRCSum="), readCheckSum);
      
      if ( checkSum != readCheckSum)
      {
        return false;
      }
      
      return true;
    }    
    
    void EEPROM_put()
    {
      // It's too bad that emulate EEPROM.read()/writ() can only deal with bytes. 
      // Have to read/write each byte. To rewrite the library
      
      uint16_t offset = EEPROM_START;
           
      uint8_t* _pointer = (uint8_t *) &BlynkEthernet_WM_config;
      
      for (int i = 0; i < sizeof(BlynkEthernet_WM_config); i++, _pointer++, offset++)
      {              
        EEPROM.write(offset, *_pointer);
      }
           
      int checkSum = 0;
    
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        _pointer = (uint8_t *) myMenuItems[i].pdata;
        
        BLYNK_LOG4(F("pdata="), myMenuItems[i].pdata, F(",len="), myMenuItems[i].maxlen);
                     
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++,_pointer++,offset++)
        {
          EEPROM.write(offset, *_pointer);
          
          checkSum += *_pointer;     
         }
      }
      
      _pointer = (uint8_t *) &checkSum;
      
      for (int i = 0; i < sizeof(checkSum); i++, _pointer++, offset++)
      {              
        EEPROM.write(offset, *_pointer);
      }
      
      EEPROM.commit();
      
      BLYNK_LOG2(F("CrCCSum="), checkSum);
    }   
    
    bool getConfigData()
    {      
      bool credDataValid;   
      
      hadConfigData = false;    
      
      credDataValid = EEPROM_get();

      int calChecksum = calcChecksum();

      BLYNK_LOG4(BLYNK_F("CCSum=0x"), String(calChecksum, HEX),
                 BLYNK_F(",RCSum=0x"), String(BlynkEthernet_WM_config.checkSum, HEX));

      if ( (strncmp(BlynkEthernet_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0) ||
           (calChecksum != BlynkEthernet_WM_config.checkSum) || !credDataValid )
      {
        memset(&BlynkEthernet_WM_config, 0, sizeof(BlynkEthernet_WM_config));
        
        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen);
        }
        
        // Including Credentials CSum
        BLYNK_LOG2(F("InitEEPROM,Datasz="), totalDataSize);

        // doesn't have any configuration
        strcpy(BlynkEthernet_WM_config.header,                        BLYNK_BOARD_TYPE);
        strcpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server,   WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token,    WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server,   WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token,    WM_NO_CONFIG);
        BlynkEthernet_WM_config.blynk_port = BLYNK_SERVER_HARDWARE_PORT;
        strcpy(BlynkEthernet_WM_config.static_IP,   WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.board_name,  WM_NO_CONFIG);

        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          strncpy(myMenuItems[i].pdata, WM_NO_CONFIG, myMenuItems[i].maxlen - 1);
        }
        
        // Don't need
        BlynkEthernet_WM_config.checkSum = 0;

        EEPROM_put();

        return false;
      }
      else if ( !strncmp(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server, WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token,  WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server, WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token,  WM_NO_CONFIG, strlen(WM_NO_CONFIG) ) )
      {
        // If SSID, PW, Server,Token ="nothing", stay in config mode forever until having config Data.
        return false;
      }
      else
      {
        displayConfigData();
      }

      return true;
    }

    void saveConfigData()
    {
      int calChecksum = calcChecksum();
      BlynkEthernet_WM_config.checkSum = calChecksum;
      
      BLYNK_LOG6(F("SaveEEPROM,sz="), EEPROM.length(), F(",Datasz="), totalDataSize, F(",CSum=0x"), String(calChecksum, HEX));
      
      EEPROM_put();      
    }
    
    bool connectMultiBlynk(void)
    {
#define BLYNK_CONNECT_TIMEOUT_MS      5000L

      for (int i = 0; i < NUM_BLYNK_CREDENTIALS; i++)
      {
        config(BlynkEthernet_WM_config.Blynk_Creds[i].blynk_token,
               BlynkEthernet_WM_config.Blynk_Creds[i].blynk_server, BlynkEthernet_WM_config.blynk_port);

        if (connect(BLYNK_CONNECT_TIMEOUT_MS) )
        {
          BLYNK_LOG4(BLYNK_F("Connected to BlynkServer="), BlynkEthernet_WM_config.Blynk_Creds[i].blynk_server,
                     BLYNK_F(",Token="), BlynkEthernet_WM_config.Blynk_Creds[i].blynk_token);
                     
          currentBlynkServerIndex = i;           
          return true;
        }
      }

      BLYNK_LOG1(BLYNK_F("Blynk not connected"));

      return false;
    }

    void createHTML(String& root_html_template)
    {
      String pitem;
      
      root_html_template = String(BLYNK_WM_HTML_HEAD);
     
      if (NUM_MENU_ITEMS > 0)
      {
        root_html_template += String(BLYNK_WM_FLDSET_START);
           
        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          pitem = String(BLYNK_WM_HTML_PARAM);

          pitem.replace("{b}", myMenuItems[i].displayName);
          pitem.replace("{v}", myMenuItems[i].id);
          pitem.replace("{i}", myMenuItems[i].id);
          
          root_html_template += pitem;      
        }
            
        root_html_template += String(BLYNK_WM_FLDSET_END);
      }
      
      root_html_template += String(BLYNK_WM_HTML_BUTTON) + String(BLYNK_WM_HTML_SCRIPT);   
           
      if (NUM_MENU_ITEMS > 0)
      {        
        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          pitem = String(BLYNK_WM_HTML_SCRIPT_ITEM);
          
          pitem.replace("{d}", myMenuItems[i].id);
          
          root_html_template += pitem;        
        }
      }
      
      root_html_template += String(BLYNK_WM_HTML_SCRIPT_END) + String(BLYNK_WM_HTML_END);
      
      return;      
    }
    ////

    void handleRequest()
    {
      if (server)
      {
        String key = server->arg("key");
        String value = server->arg("value");

        static int number_items_Updated = 0;

        if (key == "" && value == "")
        {
          String result;
          createHTML(result);

#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG2(BLYNK_F("h:Repl:"), result);
#endif

          // Reset configTimeout to stay here until finished.
          configTimeout = 0;

          result.replace("[[sv]]",     BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server);
          result.replace("[[tk]]",     BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token);
          result.replace("[[sv1]]",    BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server);
          result.replace("[[tk1]]",    BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token);
          result.replace("[[pt]]",     String(BlynkEthernet_WM_config.blynk_port));
          result.replace("[[ip]]",     BlynkEthernet_WM_config.static_IP);
          result.replace("[[nm]]",     BlynkEthernet_WM_config.board_name);

          for (int i = 0; i < NUM_MENU_ITEMS; i++)
          {
            String toChange = String("[[") + myMenuItems[i].id + "]]";
            result.replace(toChange, myMenuItems[i].pdata);
          }

          server->send(200, "text/html", result);

          return;
        }

        if (number_items_Updated == 0)
        {
          memset(&BlynkEthernet_WM_config, 0, sizeof(BlynkEthernet_WM_config));
          strcpy(BlynkEthernet_WM_config.header, BLYNK_BOARD_TYPE);
        }

        if (key == "sv")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:sv"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server) - 1)
            strcpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server, value.c_str(), sizeof(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_server) - 1);
        }
        else if (key == "tk")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:tk"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token) - 1)
            strcpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token, value.c_str(), sizeof(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token) - 1);
        }    
        else if (key == "sv1")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:sv1"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server) - 1)
            strcpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server, value.c_str(), sizeof(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_server) - 1);
        }
        else if (key == "tk1")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:tk1"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token) - 1)
            strcpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token, value.c_str(), sizeof(BlynkEthernet_WM_config.Blynk_Creds[1].blynk_token) - 1);
        }               
        else if (key == "pt")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:pt"));
#endif
          number_items_Updated++;
          BlynkEthernet_WM_config.blynk_port = value.toInt();
        }
        else if (key == "ip")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:ip"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.static_IP) - 1)
            strcpy(BlynkEthernet_WM_config.static_IP, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.static_IP, value.c_str(), sizeof(BlynkEthernet_WM_config.static_IP) - 1);
        }
        else if (key == "nm")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:nm"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.board_name) - 1)
            strcpy(BlynkEthernet_WM_config.board_name, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.board_name, value.c_str(), sizeof(BlynkEthernet_WM_config.board_name) - 1);
        }

#if (BLYNK_ETHERNET_DEBUG > 2)
        BLYNK_LOG1(BLYNK_F("h:OK"));
#endif

        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          if (key == myMenuItems[i].id)
          {
            //BLYNK_LOG4(F("h:"), myMenuItems[i].id, F("="), value.c_str() );
            number_items_Updated++;

            if ((int) strlen(value.c_str()) < myMenuItems[i].maxlen - 1)
              strcpy(myMenuItems[i].pdata, value.c_str());
            else
              strncpy(myMenuItems[i].pdata, value.c_str(), myMenuItems[i].maxlen - 1);
          }
        }
        
        server->send(200, "text/html", "OK");

        // NEW
        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS + NUM_MENU_ITEMS)
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:UpdEEPROM"));
#endif

          saveConfigData();

#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:Rst"));
#endif

          // Delay then reset after save data
          delay(200);
          BlynkReset();
        }
      }     // if (server)
    }

    void startConfigurationMode()
    {
#define CONFIG_TIMEOUT			60000L

      BLYNK_LOG2(BLYNK_F("CfgIP="), Ethernet.localIP() );

      if (!server)
        server = new EthernetWebServer;

      //See https://stackoverflow.com/questions/39803135/c-unresolved-overloaded-function-type?rq=1

      if (server)
      {
        server->on("/", [this]() { handleRequest(); } );
        server->begin();
      }

      // If there is no saved config Data, stay in config mode forever until having config Data.
      // or SSID, PW, Server,Token ="nothing"
      if (hadConfigData)
        configTimeout = millis() + CONFIG_TIMEOUT;
      else
        configTimeout = 0;

      configuration_mode = true;
    }

    bool connectEthernet(void)
    {
      // Check go see if static IP is required
      IPAddress staticIP;

      if (staticIP.fromString(BlynkEthernet_WM_config.static_IP))
      {
        // Use static IP
        Ethernet.begin(SelectMacAddress(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token, NULL), staticIP);
        ethernetConnected = true;
      }
      else
      {
        // If static_IP ="nothing"  or NULL, use DHCP dynamic IP
        ethernetConnected = Ethernet.begin(SelectMacAddress(BlynkEthernet_WM_config.Blynk_Creds[0].blynk_token, NULL));
      }

      // give the Ethernet shield a second to initialize:
      BlynkDelay(1000);

      if (ethernetConnected)
      {
        IPAddress myip = Ethernet.localIP();
        BLYNK_LOG_IP("IP:", myip);
      }
      else
      {
        BLYNK_LOG1(BLYNK_F("DHCPFailed"));

        if (Ethernet.linkStatus() == LinkOFF)
        {
          BLYNK_LOG1(BLYNK_F("Bad ECable."));
        }
      }

      return ethernetConnected;
    }

    byte* SelectMacAddress(const char* token, const byte mac[])
    {
      if (mac != NULL) {
        return (byte*)mac;
      }

      macAddress[0] = 0xFE;
      macAddress[1] = 0xED;
      macAddress[2] = 0xEF;
      macAddress[3] = 0xAD;
      macAddress[4] = 0xAB;
      macAddress[5] = 0xCD;

      int len = strlen(token);
      int mac_index = 1;

      for (int i = 0; i < len; i++)
      {
        macAddress[mac_index] ^= token[i];

        if (++mac_index > 5) {
          mac_index = 1;
        }
      }
      BLYNK_LOG("MAC:%02X-%02X-%02X-%02X-%02X-%02X",
                macAddress[0], macAddress[1],
                macAddress[2], macAddress[3],
                macAddress[4], macAddress[5]);

      return macAddress;
    }

    byte macAddress[6];

};

#endif
