/****************************************************************************************************************************
   BlynkEthernet_WM.h
   For W5x00, ENC28J60 Ethernet shields

   BlynkEthernet_WM is a library for the AVR / Teensy / SAMD, etc. platform to enable easy
   configuration/reconfiguration and autoconnect/autoreconnect of Ethernet Shield W5x00/Blynk
   Forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/BlynkGSM_ESPManager
   Licensed under MIT license
   Version: 1.0.11

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
    1.0.11  K Hoang      14/04/2020 Fix bug
 *****************************************************************************************************************************/

#ifndef BlynkEthernet_WM_h
#define BlynkEthernet_WM_h

#define BLYNK_ETHERNET_DEBUG      0

#ifndef BLYNK_INFO_CONNECTION
#define BLYNK_INFO_CONNECTION "W5000"
#endif

#ifdef BLYNK_USE_SSL
#define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT_SSL
#else
#define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT
#endif

#include <BlynkApiArduino.h>
#include <Blynk/BlynkProtocol.h>
#include <Adapters/BlynkArduinoClient.h>
#include <EthernetWebServer.h>

//Use EEPROM
#include <EEPROM.h>

// Comment out or define false in sketch to reduce sketch size
#ifndef USE_CHECKSUM
#define USE_CHECKSUM      false
#endif

// Configurable items besides fixed Header
#define NUM_CONFIGURABLE_ITEMS    5
typedef struct Configuration
{
  char header         [16];
  char blynk_server   [32];
  int  blynk_port;
  char blynk_token    [36];
  char static_IP      [16];
  char board_name     [24];
#if USE_CHECKSUM
  int  checkSum;
#endif
} Blynk_Configuration;

// Currently CONFIG_DATA_SIZE  =  132 with chksum, 128 wo chksum

#define root_html_template "\
<!DOCTYPE html><html><head><title>BlynkEthernet_WM</title><style>.em{padding-bottom:0px;}div,input{padding:5px;font-size:1em;}input{width:95%;}\
body{text-align: center;}button{background-color:#16A1E7;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}\
</style></head><div style=\"text-align:left;display:inline-block;min-width:260px;\">\
<fieldset><div class=\"\"><label for=\"sv\">Server</label><input type=\"text\"value=\"[[sv]]\"id=\"sv\"><div class=\"em\"></div></div>\
<div class=\"\"><label for=\"pt\">Port</label><input type=\"number\"value=\"[[pt]]\"id=\"pt\"><div class=\"em\"></div></div>\
<div class=\"\"><label for=\"tk\">Token</label><input type=\"text\"value=\"[[tk]]\"id=\"tk\"><div class=\"em\"></div></div>\
<div class=\"\"><label for=\"ip\">StaticIP</label><input type=\"text\"value=\"[[ip]]\"id=\"ip\"><div class=\"em\"></div></div></fieldset>\
<fieldset><div class=\"\"><label for=\"nm\">Name</label><input type=\"text\"value=\"[[nm]]\"id=\"nm\">\
<div class=\"em\"></div></div></fieldset><button onclick=\"sv()\">Save</button></div>\
<script id=\"jsbin-javascript\">\
function udVal(key,val){var request=new XMLHttpRequest();var url='/?key='+key+'&value='+val;\
request.open('GET',url,false);request.send(null);}\
function sv(){udVal('sv',document.getElementById('sv').value);udVal('pt',document.getElementById('pt').value);\
udVal('tk',document.getElementById('tk').value);udVal('ip',document.getElementById('ip').value);\
udVal('nm',document.getElementById('nm').value);alert('Updated');}\
</script></html>"

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
      BLYNK_LOG1(BLYNK_F("Use sIP"));
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
      BLYNK_LOG1(BLYNK_F("Use sIP"));
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
      BLYNK_LOG1(BLYNK_F("Use sIP"));
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
      BLYNK_LOG1(BLYNK_F("Use sIP"));
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
        config( BlynkEthernet_WM_config.blynk_token,
                BlynkEthernet_WM_config.blynk_server,
                BlynkEthernet_WM_config.blynk_port);

        if (ethernetConnected)
        {
          BLYNK_LOG1(BLYNK_F("bg:Econ.TryB"));

          int i = 0;
          while ( (i++ < 10) && !this->connect() )
          {
          }

          if  (connected())
          {
            BLYNK_LOG1(BLYNK_F("bg:EBcon"));
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("bg:Econ,Bno"));
            // failed to connect to Blynk server, will start configuration mode
            startConfigurationMode();
          }
        }
        else
        {
          // Can't do anything here
          BLYNK_LOG1(BLYNK_F("bg:E&Bnocon"));
          // failed to connect to Blynk server, will start configuration mode
          //startConfigurationMode();
        }
      }
      else
      {
        BLYNK_LOG1(BLYNK_F("bg:No dat.Stay"));
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
            server->handleClient();

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
              BLYNK_LOG2(BLYNK_F("r:Blost,t-out.TryB.#:"), retryTimes);
            }
            else
            {
              BlynkReset();
            }
          }
#endif

          // Not in config mode, try reconnecting before forcing to config mode
          BLYNK_LOG1(BLYNK_F("r:Blost.TryB"));
          if (connect())
          {
            // turn the LED_BUILTIN OFF to tell us we exit configuration mode.
            digitalWrite(LED_BUILTIN, HIGH);
            BLYNK_LOG1(BLYNK_F("r:Brecon"));
          }
        }
      }
      else if (configuration_mode)
      {
        configuration_mode = false;
        BLYNK_LOG1(BLYNK_F("run: got E&B"));
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

    String getServerName()
    {
      return (String(BlynkEthernet_WM_config.blynk_server));
    }

    String getToken()
    {
      return (String(BlynkEthernet_WM_config.blynk_token));
    }

    int getHWPort()
    {
      return (BlynkEthernet_WM_config.blynk_port);
    }

    void clearConfigData()
    {
      memset(&BlynkEthernet_WM_config, 0, sizeof(BlynkEthernet_WM_config));
      
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

#define RFC952_HOSTNAME_MAXLEN      24
    char RFC952_hostname[RFC952_HOSTNAME_MAXLEN + 1];

    void setRFC952_hostname(const char* iHostname = "")
    {
      if (iHostname[0] == 0)
      {
        String _hostname = "W5X00-XXXXXX";    // + String(macAddress, HEX);
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
      BLYNK_LOG4(BLYNK_F("Hdr="), BlynkEthernet_WM_config.header, BLYNK_F(",Tok="), BlynkEthernet_WM_config.blynk_token);
      BLYNK_LOG4(BLYNK_F("Svr="), BlynkEthernet_WM_config.blynk_server,
                 BLYNK_F(",Prt="), BlynkEthernet_WM_config.blynk_port);
      BLYNK_LOG4(BLYNK_F("SIP="), BlynkEthernet_WM_config.static_IP,
                 BLYNK_F(",BName="), BlynkEthernet_WM_config.board_name);
    }

#define BLYNK_BOARD_TYPE      BLYNK_INFO_CONNECTION

#define WM_NO_CONFIG          "nothing"

    // Currently 128 + 4 (chsum)
    uint16_t CONFIG_DATA_SIZE = sizeof(Blynk_Configuration);

#define EEPROM_SIZE     (E2END + 1)

#if (EEPROM_SIZE < CONFIG_DATA_SIZE)
#error EEPROM_SIZE must be > CONFIG_DATA_SIZE.
#endif

#ifndef EEPROM_START
#define EEPROM_START     0
#else
#if (EEPROM_START + CONFIG_DATA_SIZE > EEPROM_SIZE)
#error EPROM_START + CONFIG_DATA_SIZE > EEPROM_SIZE. Please adjust.
#endif
#endif

#if USE_CHECKSUM
    int calcChecksum()
    {
      int checkSum = 0;
      for (uint16_t index = 0; index < (sizeof(BlynkEthernet_WM_config) - sizeof(BlynkEthernet_WM_config.checkSum)); index++)
      {
        checkSum += * ( ( (byte*) &BlynkEthernet_WM_config ) + index);
      }

      return checkSum;
    }
#endif

    bool getConfigData()
    {
      EEPROM.begin();
      BLYNK_LOG2(BLYNK_F("EEPROMsz:"), EEPROM_SIZE);
      EEPROM.get(EEPROM_START, BlynkEthernet_WM_config);

#if USE_CHECKSUM
      int calChecksum = calcChecksum();

      BLYNK_LOG4(BLYNK_F("CCSum=0x"), String(calChecksum, HEX),
                 BLYNK_F(",RCSum=0x"), String(BlynkEthernet_WM_config.checkSum, HEX));

      if ( (strncmp(BlynkEthernet_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0) ||
           (calChecksum != BlynkEthernet_WM_config.checkSum) )
#else

      if (strncmp(BlynkEthernet_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0)
#endif
      {
        memset(&BlynkEthernet_WM_config, 0, sizeof(BlynkEthernet_WM_config));

        BLYNK_LOG1(BLYNK_F("InitEEPROM"));
        // doesn't have any configuration
        strcpy(BlynkEthernet_WM_config.header,           BLYNK_BOARD_TYPE);
        strcpy(BlynkEthernet_WM_config.blynk_server,     WM_NO_CONFIG);
        BlynkEthernet_WM_config.blynk_port = BLYNK_SERVER_HARDWARE_PORT;
        strcpy(BlynkEthernet_WM_config.blynk_token,      WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.static_IP,        WM_NO_CONFIG);
        strcpy(BlynkEthernet_WM_config.board_name,       WM_NO_CONFIG);
#if USE_CHECKSUM
        // Don't need
        BlynkEthernet_WM_config.checkSum = 0;
#endif

        EEPROM.put(EEPROM_START, BlynkEthernet_WM_config);

        return false;
      }
      else if ( !strncmp(BlynkEthernet_WM_config.blynk_server,    WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(BlynkEthernet_WM_config.blynk_token,     WM_NO_CONFIG, strlen(WM_NO_CONFIG) ) )
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
#if USE_CHECKSUM
      int calChecksum = calcChecksum();
      BlynkEthernet_WM_config.checkSum = calChecksum;
      BLYNK_LOG2(BLYNK_F("Save,cSum=0x"), String(calChecksum, HEX));
#endif

      EEPROM.put(EEPROM_START, BlynkEthernet_WM_config);
    }

    void handleRequest()
    {
      if (server)
      {
        String key = server->arg("key");
        String value = server->arg("value");

        static int number_items_Updated = 0;

        if (key == "" && value == "")
        {
          String result = root_html_template;

#if (BLYNK_ETHERNET_DEBUG > 1)
          BLYNK_LOG1(BLYNK_F("h:Repl"));
#endif

          // Reset configTimeout to stay here until finished.
          configTimeout = 0;

          result.replace("[[sv]]",     BlynkEthernet_WM_config.blynk_server);
          result.replace("[[pt]]",     String(BlynkEthernet_WM_config.blynk_port));
          result.replace("[[tk]]",     BlynkEthernet_WM_config.blynk_token);
          result.replace("[[ip]]",     BlynkEthernet_WM_config.static_IP);
          result.replace("[[nm]]",     BlynkEthernet_WM_config.board_name);

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
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.blynk_server) - 1)
            strcpy(BlynkEthernet_WM_config.blynk_server, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.blynk_server, value.c_str(), sizeof(BlynkEthernet_WM_config.blynk_server) - 1);
        }
        else if (key == "pt")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:pt"));
#endif
          number_items_Updated++;
          BlynkEthernet_WM_config.blynk_port = value.toInt();
        }
        else if (key == "tk")
        {
#if (BLYNK_ETHERNET_DEBUG > 2)
          BLYNK_LOG1(BLYNK_F("h:tk"));
#endif
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(BlynkEthernet_WM_config.blynk_token) - 1)
            strcpy(BlynkEthernet_WM_config.blynk_token, value.c_str());
          else
            strncpy(BlynkEthernet_WM_config.blynk_token, value.c_str(), sizeof(BlynkEthernet_WM_config.blynk_token) - 1);
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

        server->send(200, "text/html", "OK");

        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS)
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
        Ethernet.begin(SelectMacAddress(BlynkEthernet_WM_config.blynk_token, NULL), staticIP);
        ethernetConnected = true;
      }
      else
      {
        // If static_IP ="nothing"  or NULL, use DHCP dynamic IP
        ethernetConnected = Ethernet.begin(SelectMacAddress(BlynkEthernet_WM_config.blynk_token, NULL));
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
        BLYNK_LOG1(BLYNK_F("DHCP Failed"));

        if (Ethernet.linkStatus() == LinkOFF)
        {
          BLYNK_LOG1(BLYNK_F("Bad Ecable."));
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
      macAddress[2] = 0xAB;
      macAddress[3] = 0xCD;
      macAddress[4] = 0xEF;
      macAddress[5] = 0xED;

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