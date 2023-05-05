/*
Map Remote to 21708 - Xbox 360 Remote
by Smiths
https://infosec.exchange/@quasirealsmiths
*/

#include <IRremote.hpp>
#include <Arduino.h>
#include "USB.h"
#include "USBHIDKeyboard.h" 

//TESTMODE sets output to Serial
//Clear flag for Keyboard Emulation mode
//#define TESTMODE

//--------Other Variables------
#define RECV_PIN 7     // define your receive PIN here; I chose 7
#define DECODE_RC6     // protocol for XB360 remote
#define USE_LED false  // set to true to flash LED when button pressed / false to disable
#define LED_PIN 15     // pin for LED
#define KB_DELAY 175   // delay between keypresses in ms
#define KEY_MENU 0xED  // Right-click button keyboard
#define USE_OTA true   // OTA Mode - define SSID/PW below - false to disable

#if USE_OTA

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include "OTA.h"
<<<<<<< HEAD
<<<<<<< HEAD
const char* host = "IR_S2_TEST";
=======
const char* host = "<INSERT HOST NAME FOR DEVICE>";
>>>>>>> 1eded0d (Revert "Updated for latest IRRemote Library")
=======
const char* host = "IR_S2_TEST";
>>>>>>> ddecb4255a243001e55b7ce3585d2e5711a5020e
const char* ssid = "<INSERT WIFI SSID>";
const char* password = "<INSERT WIFI PASSWORD>";
const char* www_username = "admin"; //Username for OTA page, change if desired
const char* www_password = "arduino"; //Password for OTA page, change if desired
bool ledState = 0;
WebServer server(80);

#endif

#if ARDUINO_USB_MODE
#warning This sketch should be used when USB is in OTG mode
void setup() {}
void loop() {}
#else
USBHIDKeyboard Keyboard;
decode_results results;
int prev_code = 0;
int rptcount = 0;
int prev_kd = KB_DELAY;
int kd = KB_DELAY;

void setup() {
#if USE_OTA
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if (!MDNS.begin(host)) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");

  /*return index page which is stored in serverIndex */
  server.on("/", HTTP_GET, []() {
    if (!server.authenticate(www_username, www_password))
      return server.requestAuthentication();
    server.sendHeader("Connection", "close");
    IPAddress LAN_IP = WiFi.localIP();
    String output = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><title>OTA Upload " + String(host) + "</title></head>";
    output += serverIndex;
    output += "<br><br><hr>";
    output += "<u>Network information</u><br>";
    output += "   Host:        " + String(host) + "<br>";
    output += "   IP address:  " + LAN_IP.toString() + "<br>";
    output += "   MAC address: " + WiFi.macAddress() + "<br><hr>";
    output += "<u>Sketch information</u><br>";
    output += "   Sketch hash: " + ESP.getSketchMD5() + "<br>";
    output += "   Sketch size: " + formatBytes(ESP.getSketchSize()) + "<br>";
    output += "   Free space available: " + formatBytes(ESP.getFreeSketchSpace() - ESP.getSketchSize()) + "<br><hr>";
    output += "<p><hr><div><button onclick=\"logoutButton()\">Logout</button></div>";
    output += "</html>";
    server.send(200, "text/html", output);
  });
  server.on("/logout", HTTP_GET, []() {
    server.send(401);
  });

  server.on("/logged-out", HTTP_GET, []() {
    server.send(200, "text/html", logout_html);
  });
  /*handling uploading firmware file */
  server.on(
    "/update", HTTP_POST, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
      ESP.restart();
    },
    []() {
      HTTPUpload &upload = server.upload();
      if (upload.status == UPLOAD_FILE_START) {
        Serial.printf("Update: %s\n", upload.filename.c_str());
        if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {  //start with max available size
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        /* flashing firmware to ESP*/
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_END) {
        if (Update.end(true)) {  //true to set the size to the current progress
          Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          Update.printError(Serial);
        }
      }
    });
  server.begin();
#endif

#if USE_LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
#endif
  IrReceiver.begin(RECV_PIN);
#ifdef TESTMODE
  Serial.println("TEST DONE");

  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("receiving?");
#else
  Keyboard.begin();
  USB.begin();
#endif
}

void loop() {
#if USE_OTA
  server.handleClient();
#endif

  kd = prev_kd;
  if (IrReceiver.decode(&results)) {
#if USE_LED
    digitalWrite(LED_PIN, HIGH);
#endif
#ifdef TESTMODE
    // In test mode, print the HEX code on the serial monitor
    if (results.decode_type == 0x0F) {
      switch (IrReceiver.decodedIRData.decodedRawData) {
        case 0x800f7428: Serial.println("KEY_OPEN"); break;         // Open
        case 0x800ff428: Serial.println("KEY_OPEN"); break;         // Open
        case 0x800ff464: Serial.println("Fancy Button"); break;     // Fancy Button
        case 0x800f7464: Serial.println("Fancy Button"); break;     // Fancy Button
        case 0x800ff40c: Serial.println("KEY_POWER"); break;        // Power
        case 0x800f740c: Serial.println("KEY_POWER"); break;        // Power
        case 0x800ff419: Serial.println("KEY_STOP"); break;         // Stop
        case 0x800f7419: Serial.println("KEY_STOP"); break;         // Stop
        case 0x800f7418: Serial.println("KEY_PAUSE"); break;        // Pause (Does play/pause)
        case 0x800ff418: Serial.println("KEY_PAUSE"); break;        // Pause (Does play/pause)
        case 0x800ff415: Serial.println("KEY_REWIND"); break;       // Rewind
        case 0x800f7415: Serial.println("KEY_REWIND"); break;       // Rewind
        case 0x800f7414: Serial.println("KEY_FASTFORWARD"); break;  // Fast Forward
        case 0x800ff414: Serial.println("KEY_FASTFORWARD"); break;  // Fast Forward
        case 0x800ff41b: Serial.println("KEY_PREVIOUS"); break;     // Prev
        case 0x800f741b: Serial.println("KEY_PREVIOUS"); break;     // Prev
        case 0x800ff41a: Serial.println("KEY_NEXT"); break;         // Next
        case 0x800f741a: Serial.println("KEY_NEXT"); break;         // Next
        case 0x800ff416: Serial.println("KEY_PLAY"); break;         // Play (Does play/pause)
        case 0x800f7416: Serial.println("KEY_PLAY"); break;         // Play (Does play/pause)
        case 0x800f744f: Serial.println("Display"); break;          // Display
        case 0x800ff44f: Serial.println("Display"); break;          // Display
        case 0x800ff451: Serial.println("KEY_TITLE"); break;        // Title
        case 0x800f7451: Serial.println("KEY_TITLE"); break;        // Title
        case 0x800f7424: Serial.println("KEY_MENU"); break;         // DVD Menu
        case 0x800ff424: Serial.println("KEY_MENU"); break;         // DVD Menu
        case 0x800ff423: Serial.println("KEY_BACKSPACE"); break;    // Back
        case 0x800f7423: Serial.println("KEY_BACKSPACE"); break;    // Back
        case 0x800f740f: Serial.println("KEY_INFO"); break;         // Info
        case 0x800ff40f: Serial.println("KEY_INFO"); break;         // Info
        case 0x800ff41e: Serial.println("KEY_UP_ARROW"); break;     // Up
        case 0x800f741e: Serial.println("KEY_UP_ARROW"); break;     // Up
        case 0x800f7420: Serial.println("KEY_LEFT_ARROW"); break;   // Left
        case 0x800ff420: Serial.println("KEY_LEFT_ARROW"); break;   // Left
        case 0x800f7421: Serial.println("KEY_RIGHT_ARROW"); break;  // Right
        case 0x800ff421: Serial.println("KEY_RIGHT_ARROW"); break;  // Right
        case 0x800f741f: Serial.println("KEY_DOWN_ARROW"); break;   // Down
        case 0x800ff41f: Serial.println("KEY_DOWN_ARROW"); break;   // Down
        case 0x800ff422: Serial.println("KEY_RETURN"); break;       // OK
        case 0x800f7422: Serial.println("KEY_RETURN"); break;       // OK
        case 0x800f7426: Serial.println("Y_BUTT"); break;           // Button Y
        case 0x800ff426: Serial.println("Y_BUTT"); break;           // Button Y
        case 0x800ff468: Serial.println("X_BUTT"); break;           // Button X
        case 0x800f7468: Serial.println("X_BUTT"); break;           // Button X
        case 0x800ff466: Serial.println("A_BUTT"); break;           // Button A
        case 0x800f7466: Serial.println("A_BUTT"); break;           // Button A
        case 0x800ff425: Serial.println("B_BUTT"); break;           // Button B
        case 0x800f7425: Serial.println("B_BUTT"); break;           // Button B
        case 0x800ff412: Serial.println("KEY_CHANNELUP"); break;    // Channel Up
        case 0x800f7412: Serial.println("KEY_CHANNELUP"); break;    // Channel Up
        case 0x800ff413: Serial.println("KEY_CHANNELDOWN"); break;  // Channel Down
        case 0x800f7413: Serial.println("KEY_CHANNELDOWN"); break;  // Channel Down
        case 0x800ff411: Serial.println("VOL_DOWN"); break;         // Vol Down
        case 0x800f7411: Serial.println("VOL_DOWN"); break;         // Vol Down
        case 0x800ff410: Serial.println("VOL_UP"); break;           // Vol Up
        case 0x800f7410: Serial.println("VOL_UP"); break;           // Vol Up
        case 0x800ff40e: Serial.println("KEY_MUTE"); break;         // Mute
        case 0x800f740e: Serial.println("KEY_MUTE"); break;         // Mute
        case 0x800f740d: Serial.println("START"); break;            // Start
        case 0x800ff40d: Serial.println("START"); break;            // Start
        case 0x800f740b: Serial.println("KEY_ENTER"); break;        // Enter
        case 0x800ff40b: Serial.println("KEY_ENTER"); break;        // Enter
        case 0x800f7417: Serial.println("KEY_RECORD"); break;       // Record
        case 0x800ff417: Serial.println("KEY_RECORD"); break;       // Record
        case 0x800ff40a: Serial.println("KEY_CLEAR"); break;        // Clear
        case 0x800f740a: Serial.println("KEY_CLEAR"); break;        // Clear
        case 0x800f7401: Serial.println('1'); break;                // 1
        case 0x800ff401: Serial.println('1'); break;                // 1
        case 0x800f7402: Serial.println('2'); break;                // 2
        case 0x800ff402: Serial.println('2'); break;                // 2
        case 0x800f7403: Serial.println('3'); break;                // 3
        case 0x800ff403: Serial.println('3'); break;                // 3
        case 0x800f7404: Serial.println('4'); break;                // 4
        case 0x800ff404: Serial.println('4'); break;                // 4
        case 0x800f7405: Serial.println('5'); break;                // 5
        case 0x800ff405: Serial.println('5'); break;                // 5
        case 0x800f7406: Serial.println('6'); break;                // 6
        case 0x800ff406: Serial.println('6'); break;                // 6
        case 0x800f7407: Serial.println('7'); break;                // 7
        case 0x800ff407: Serial.println('7'); break;                // 7
        case 0x800f7408: Serial.println('8'); break;                // 8
        case 0x800ff408: Serial.println('8'); break;                // 8
        case 0x800f7409: Serial.println('9'); break;                // 9
        case 0x800ff409: Serial.println('9'); break;                // 9
        case 0x800f741d: Serial.println("X_KEY_100"); break;        // 100
        case 0x800ff41d: Serial.println("X_KEY_100"); break;        // 100
        case 0x800f7400: Serial.println('0'); break;                // 0
        case 0x800ff400: Serial.println('0'); break;                // 0
        case 0x800f741c: Serial.println("Reload"); break;           // Reload
        case 0x800ff41c: Serial.println("Reload"); break;           // Reload

        case 0xFFFFFFFF: break;  // Repeat
        default: break;
      }
      if (prev_code == IrReceiver.decodedIRData.decodedRawData) {
        rptcount++;
        if (rptcount % 2 == 0) {
          if (kd > 95) {
            kd = 10;
          }
        } else {
          kd = prev_kd;
        }
      } else {
        kd = KB_DELAY;
        rptcount = 0;
      }
      Serial.print(kd);
      Serial.print(" | ");
      Serial.println(rptcount);
      delay(kd);
    }
    /*END TESTMODE*/
#else /*NOT TESTMODE*/
    if (results.decode_type == 0x0F) {
      switch (IrReceiver.decodedIRData.decodedRawData) {
<<<<<<< HEAD
<<<<<<< HEAD
        case 0x800f7428: Keyboard.write(KEY_F12); break;          // KEY_OPEN | Fire Stick Remote Home Button
        case 0x800ff428: Keyboard.write(KEY_F12); break;          // KEY_OPEN | Fire Stick Remote Home Button
=======
        case 0x800f7428: Keyboard.press(KEY_LEFT_GUI); delay(200); Keyboard.press(KEY_RETURN); Keyboard.releaseAll(); break; // KEY_OPEN | Fire Stick Remote Home Button (LWIN+ENTER)
        case 0x800ff428: Keyboard.press(KEY_LEFT_GUI); delay(200); Keyboard.press(KEY_RETURN); Keyboard.releaseAll(); break; // KEY_OPEN | Fire Stick Remote Home Button (LWIN+ENTER)
>>>>>>> 1eded0d (Revert "Updated for latest IRRemote Library")
=======
        case 0x800f7428: Keyboard.write(KEY_F12); break;          // KEY_OPEN | Fire Stick Remote Home Button
        case 0x800ff428: Keyboard.write(KEY_F12); break;          // KEY_OPEN | Fire Stick Remote Home Button
>>>>>>> ddecb4255a243001e55b7ce3585d2e5711a5020e
        case 0x800ff464: Keyboard.write(KEY_MENU); break;         // XboxFancyButton | Context Menu - 3 dash button on Fire Remote | needed for Amazon Home GUI
        case 0x800f7464: Keyboard.write(KEY_MENU); break;         // XboxFancyButton | Context Menu - 3 dash button on Fire Remote | needed for Amazon Home GUI
        case 0x800ff40c: Keyboard.write('s'); break;              // KEY_POWER
        case 0x800f740c: Keyboard.write('s'); break;              // KEY_POWER
        case 0x800ff419: Keyboard.write('x'); break;              // KEY_STOP
        case 0x800f7419: Keyboard.write('x'); break;              // KEY_STOP
        case 0x800f7418: Keyboard.write(' '); break;              // KEY_PAUSE
        case 0x800ff418: Keyboard.write(' '); break;              // KEY_PAUSE
        case 0x800ff415: Keyboard.write('r'); break;              // KEY_REWIND
        case 0x800f7415: Keyboard.write('r'); break;              // KEY_REWIND
        case 0x800f7414: Keyboard.write('f'); break;              // KEY_FASTFORWARD
        case 0x800ff414: Keyboard.write('f'); break;              // KEY_FASTFORWARD
        case 0x800ff41b: Keyboard.write(KEY_PAGE_DOWN); break;    // KEY_PREVIOUS
        case 0x800f741b: Keyboard.write(KEY_PAGE_DOWN); break;    // KEY_PREVIOUS
        case 0x800ff41a: Keyboard.write(KEY_PAGE_UP); break;      // KEY_NEXT
        case 0x800f741a: Keyboard.write(KEY_PAGE_UP); break;      // KEY_NEXT
        case 0x800ff416: Keyboard.write(' '); break;              // KEY_PLAY
        case 0x800f7416: Keyboard.write(' '); break;              // KEY_PLAY
        case 0x800f744f: Keyboard.write('o'); break;              //Display | Player Process Info
        case 0x800ff44f: Keyboard.write('o'); break;              //Display | Player Process Info
        case 0x800ff451: Keyboard.write('m'); break;              // KEY_TITLE | Menu / OSD
        case 0x800f7451: Keyboard.write('m'); break;              // KEY_TITLE | Menu / OSD
        case 0x800f7424: Keyboard.write('z'); break;              // KEY_MENU | Display Info | DVD Menu button on Xbox Remote
        case 0x800ff424: Keyboard.write('z'); break;              // KEY_MENU | Display Info | DVD Menu button on Xbox Remote
        case 0x800ff423: Keyboard.write(KEY_BACKSPACE); break;    // KEY_BACK
        case 0x800f7423: Keyboard.write(KEY_BACKSPACE); break;    // KEY_BACK
        case 0x800f740f: Keyboard.write('i'); break;              // KEY_INFO
        case 0x800ff40f: Keyboard.write('i'); break;              // KEY_INFO
        case 0x800ff41e: Keyboard.write(KEY_UP_ARROW); break;     // UpArrow
        case 0x800f741e: Keyboard.write(KEY_UP_ARROW); break;     // UpArrow
        case 0x800f7420: Keyboard.write(KEY_LEFT_ARROW); break;   // LeftArrow
        case 0x800ff420: Keyboard.write(KEY_LEFT_ARROW); break;   // LeftArrow
        case 0x800f7421: Keyboard.write(KEY_RIGHT_ARROW); break;  // RightArrow
        case 0x800ff421: Keyboard.write(KEY_RIGHT_ARROW); break;  // RightArrow
        case 0x800f741f: Keyboard.write(KEY_DOWN_ARROW); break;   // DownArrow
        case 0x800ff41f: Keyboard.write(KEY_DOWN_ARROW); break;   // DownArrow
        case 0x800ff422: Keyboard.write(KEY_RETURN); break;       // KEY_OK
        case 0x800f7422: Keyboard.write(KEY_RETURN); break;       // KEY_OK
        case 0x800f7426: Keyboard.write(KEY_ESC); break;          // KEY_Y | ESCAPE - Fire Stick Back Button
        case 0x800ff426: Keyboard.write(KEY_ESC); break;          // KEY_Y | ESCAPE - Fire Stick Back Button
        case 0x800ff468: Keyboard.write('c'); break;              // KEY_X | Context Menu
        case 0x800f7468: Keyboard.write('c'); break;              // KEY_X | Context Menu
        case 0x800ff466: Keyboard.write('t'); break;              // KEY_A | Toggle Subtitles
        case 0x800f7466: Keyboard.write('t'); break;              // KEY_A | Toggle Subtitles
        case 0x800ff425: Keyboard.write('$'); break;              // KEY_B <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f7425: Keyboard.write('$'); break;              // KEY_B <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800ff412: Keyboard.write('%'); break;              // KEY_CHANNELUP <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f7412: Keyboard.write('%'); break;              // KEY_CHANNELUP <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800ff413: Keyboard.write('^'); break;              // KEY_CHANNELDOWN <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f7413: Keyboard.write('^'); break;              // KEY_CHANNELDOWN <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800ff411: Keyboard.write('-'); break;              // KEY_VOLUMEDOWN
        case 0x800f7411: Keyboard.write('-'); break;              // KEY_VOLUMEDOWN
        case 0x800ff410: Keyboard.write('+'); break;              // KEY_VOLUMEUP
        case 0x800f7410: Keyboard.write('+'); break;              // KEY_VOLUMEUP
        case 0x800ff40e: Keyboard.write(KEY_F8); break;           // KEY_MUTE
        case 0x800f740e: Keyboard.write(KEY_F8); break;           // KEY_MUTE
        case 0x800f740d: Keyboard.write(KEY_RETURN); break;       // Start
        case 0x800ff40d: Keyboard.write(KEY_RETURN); break;       // Start
        case 0x800f740b: Keyboard.write(KEY_RETURN); break;       // KEY_ENTER
        case 0x800ff40b: Keyboard.write(KEY_RETURN); break;       // KEY_ENTER
        case 0x800f7417: Keyboard.write('m'); break;              // KEY_RECORD
        case 0x800ff417: Keyboard.write('m'); break;              // KEY_RECORD
        case 0x800ff40a: Keyboard.write('&'); break;              // KEY_CLEAR <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f740a: Keyboard.write('&'); break;              // KEY_CLEAR <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f7401: Keyboard.write('1'); break;              // KEY_1
        case 0x800ff401: Keyboard.write('1'); break;              // KEY_1
        case 0x800f7402: Keyboard.write('2'); break;              // KEY_2
        case 0x800ff402: Keyboard.write('2'); break;              // KEY_2
        case 0x800f7403: Keyboard.write('3'); break;              // KEY_3
        case 0x800ff403: Keyboard.write('3'); break;              // KEY_3
        case 0x800f7404: Keyboard.write('4'); break;              // KEY_4
        case 0x800ff404: Keyboard.write('4'); break;              // KEY_4
        case 0x800f7405: Keyboard.write('5'); break;              // KEY_5
        case 0x800ff405: Keyboard.write('5'); break;              // KEY_5
        case 0x800f7406: Keyboard.write('6'); break;              // KEY_6
        case 0x800ff406: Keyboard.write('6'); break;              // KEY_6
        case 0x800f7407: Keyboard.write('7'); break;              // KEY_7
        case 0x800ff407: Keyboard.write('7'); break;              // KEY_7
        case 0x800f7408: Keyboard.write('8'); break;              // KEY_8
        case 0x800ff408: Keyboard.write('8'); break;              // KEY_8
        case 0x800f7409: Keyboard.write('9'); break;              // KEY_9
        case 0x800ff409: Keyboard.write('9'); break;              // KEY_9
        case 0x800f741d: Keyboard.write('*'); break;              // X_KEY_100 <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800ff41d: Keyboard.write('*'); break;              // X_KEY_100 <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800f7400: Keyboard.write('0'); break;              // KEY_0
        case 0x800ff400: Keyboard.write('0'); break;              // KEY_0
        case 0x800f741c: Keyboard.write('!'); break;              // Reload <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>
        case 0x800ff41c: Keyboard.write('!'); break;              // Reload <PLACEHOLDER TO MAP BUTTON AND ASSIGN IN KEYMAP>

        case 0xFFFFFFFF: break;  // Repeat
        default: break;
      }
      if (prev_code == IrReceiver.decodedIRData.decodedRawData) {
        rptcount++;
        if (rptcount % 2 == 0) {
          if (kd > 95) {
            kd = 10;
          }
        } else {
          kd = prev_kd;
        }
      } else {
        kd = KB_DELAY;
        rptcount = 0;
      }
      delay(kd);
      //Keyboard.release();
    }
#endif
#if USE_LED
    digitalWrite(LED_PIN, LOW);
#endif
    prev_code = IrReceiver.decodedIRData.decodedRawData;  //set variable to current keypress to check for repeat
    prev_kd = kd;
    IrReceiver.resume();  // Receive the next value  }
  }
}

#endif /* ARDUINO_USB_MODE */
