/*
Map Remote to 21708 - Xbox 360 Remote
by Smiths
https://infosec.exchange/@quasirealsmiths
*/

//TESTMODE sets output to Serial
//Clear flag for Keyboard Emulation mode
//#define TESTMODE 
//#define DECODE_RC6       // protocol for XB360 remote

#include <IRremote.hpp>
#include <Arduino.h>
#define RECV_PIN 7 // define your receive PIN here; I chose 7
#include "USB.h"
#include "USBHIDKeyboard.h"

#if ARDUINO_USB_MODE
#warning This sketch should be used when USB is in OTG mode
void setup() {}
void loop() {}
#else
USBHIDKeyboard Keyboard;
decode_results results;
void setup() {
  IrReceiver.begin(RECV_PIN);
#ifdef TESTMODE
  Serial.begin(115200);
  while (!Serial);
  Serial.println("receiving?");
#else
  Keyboard.begin();
  USB.begin();
#endif
}
IRAM_ATTR
void loop() {
  if (IrReceiver.decode(&results)) {
#ifdef TESTMODE
    // In test mode, print the HEX code on the serial monitor
    if (results.decode_type == 0x0F) {
      switch (IrReceiver.decodedIRData.decodedRawData) {
        case 0x800f7428: Serial.println("KEY_OPEN"); break;       // Open
        case 0x800ff428: Serial.println("KEY_OPEN"); break;       // Open
        case 0x800ff464 : Serial.println("Fancy Button"); break;  // Fancy Button 
        case 0x800f7464 : Serial.println("Fancy Button"); break;  // Fancy Button
        case 0x800ff40c: Serial.println("KEY_POWER"); break;      // Power
        case 0x800f740c: Serial.println("KEY_POWER"); break;      // Power
        case 0x800ff419: Serial.println("KEY_STOP"); break;       // Stop
        case 0x800f7419: Serial.println("KEY_STOP"); break;       // Stop
        case 0x800f7418: Serial.println("KEY_PAUSE"); break;      // Pause (Does play/pause)
        case 0x800ff418: Serial.println("KEY_PAUSE"); break;      // Pause (Does play/pause)
        case 0x800ff415: Serial.println("KEY_REWIND"); break;     // Rewind
        case 0x800f7415: Serial.println("KEY_REWIND"); break;     // Rewind
        case 0x800f7414: Serial.println("KEY_FASTFORWARD"); break;    // Fast Forward
        case 0x800ff414: Serial.println("KEY_FASTFORWARD"); break;    // Fast Forward
        case 0x800ff41b: Serial.println("KEY_PREVIOUS"); break;       // Prev
        case 0x800f741b: Serial.println("KEY_PREVIOUS"); break;       // Prev 
        case 0x800ff41a: Serial.println("KEY_NEXT"); break;       // Next
        case 0x800f741a: Serial.println("KEY_NEXT"); break;       // Next     
        case 0x800ff416: Serial.println("KEY_PLAY"); break;       // Play (Does play/pause)
        case 0x800f7416: Serial.println("KEY_PLAY"); break;       // Play (Does play/pause)
        case 0x800f744f: Serial.println("Display"); break;        // Display
        case 0x800ff44f: Serial.println("Display"); break;        // Display
        case 0x800ff451: Serial.println("KEY_TITLE"); break;      // Title
        case 0x800f7451: Serial.println("KEY_TITLE"); break;      // Title
        case 0x800f7424: Serial.println("KEY_MENU"); break;       // DVD Menu
        case 0x800ff424: Serial.println("KEY_MENU"); break;       // DVD Menu
        case 0x800ff423: Serial.println("KEY_BACKSPACE"); break;  // Back
        case 0x800f7423: Serial.println("KEY_BACKSPACE"); break;  // Back
        case 0x800f740f: Serial.println("KEY_INFO"); break;       // Info
        case 0x800ff40f: Serial.println("KEY_INFO"); break;       // Info
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
        case 0x800f7426: Serial.println("Y_BUTT"); break;     // Button Y
        case 0x800ff426: Serial.println("Y_BUTT"); break;     // Button Y
        case 0x800ff468: Serial.println("X_BUTT"); break;     // Button X
        case 0x800f7468: Serial.println("X_BUTT"); break;     // Button X
        case 0x800ff466: Serial.println("A_BUTT"); break;     // Button A
        case 0x800f7466: Serial.println("A_BUTT"); break;     // Button A
        case 0x800ff425: Serial.println("B_BUTT"); break;     // Button B
        case 0x800f7425: Serial.println("B_BUTT"); break;     // Button B
        case 0x800ff412: Serial.println("KEY_CHANNELUP"); break;    // Channel Up
        case 0x800f7412: Serial.println("KEY_CHANNELUP"); break;    // Channel Up
        case 0x800ff413: Serial.println("KEY_CHANNELDOWN"); break;  // Channel Down
        case 0x800f7413: Serial.println("KEY_CHANNELDOWN"); break;  // Channel Down
        case 0x800ff411: Serial.println("VOL_DOWN"); break;   // Vol Down
        case 0x800f7411: Serial.println("VOL_DOWN"); break;   // Vol Down
        case 0x800ff410: Serial.println("VOL_UP"); break;     // Vol Up
        case 0x800f7410: Serial.println("VOL_UP"); break;     // Vol Up
        case 0x800ff40e: Serial.println("KEY_MUTE"); break;   // Mute
        case 0x800f740e: Serial.println("KEY_MUTE"); break;   // Mute        
        case 0x800f740d: Serial.println("START"); break;      // Start
        case 0x800ff40d: Serial.println("START"); break;      // Start
        case 0x800f740b: Serial.println("KEY_ENTER"); break;  // Enter
        case 0x800ff40b: Serial.println("KEY_ENTER"); break;  // Enter
        case 0x800f7417: Serial.println("KEY_RECORD"); break; // Record
        case 0x800ff417: Serial.println("KEY_RECORD"); break; // Record
        case 0x800ff40a: Serial.println("KEY_CLEAR"); break;  // Clear
        case 0x800f740a: Serial.println("KEY_CLEAR"); break;  // Clear
        case 0x800f7401: Serial.println('1'); break;  // 1
        case 0x800ff401: Serial.println('1'); break;  // 1
        case 0x800f7402: Serial.println('2'); break;  // 2
        case 0x800ff402: Serial.println('2'); break;  // 2
        case 0x800f7403: Serial.println('3'); break;  // 3
        case 0x800ff403: Serial.println('3'); break;  // 3
        case 0x800f7404: Serial.println('4'); break;  // 4
        case 0x800ff404: Serial.println('4'); break;  // 4
        case 0x800f7405: Serial.println('5'); break;  // 5
        case 0x800ff405: Serial.println('5'); break;  // 5
        case 0x800f7406: Serial.println('6'); break;  // 6
        case 0x800ff406: Serial.println('6'); break;  // 6
        case 0x800f7407: Serial.println('7'); break;  // 7
        case 0x800ff407: Serial.println('7'); break;  // 7
        case 0x800f7408: Serial.println('8'); break;  // 8
        case 0x800ff408: Serial.println('8'); break;  // 8
        case 0x800f7409: Serial.println('9'); break;  // 9
        case 0x800ff409: Serial.println('9'); break;  // 9
        case 0x800f741d: Serial.println("X_KEY_100"); break;  // 100
        case 0x800ff41d: Serial.println("X_KEY_100"); break;  // 100
        case 0x800f7400: Serial.println('0'); break;  // 0
        case 0x800ff400: Serial.println('0'); break;  // 0
        case 0x800f741c: Serial.println("Reload"); break;  // Reload
        case 0x800ff41c: Serial.println("Reload"); break;  // Reload

        case 0xFFFFFFFF: break;  // Repeat
        default: break;
      }
      delay(200);
    }


#else
    if (results.decode_type == 0x0F) {
     switch (IrReceiver.decodedIRData.decodedRawData) {
        case 0x800f7428: Keyboard.press('!'); break;   // KEY_OPEN
        case 0x800ff428: Keyboard.press('!'); break;   // KEY_OPEN
        case 0x800ff464: Keyboard.press('@'); break;  // XboxFancyButton
        case 0x800f7464: Keyboard.press('@'); break;  // XboxFancyButton
        case 0x800ff40c: Keyboard.press('s'); break;  // KEY_POWER
        case 0x800f740c: Keyboard.press('s'); break;  // KEY_POWER
        case 0x800ff419: Keyboard.press('x'); break;  // KEY_STOP
        case 0x800f7419: Keyboard.press('x'); break;  // KEY_STOP
        case 0x800f7418: Keyboard.press(' '); break;  // KEY_PAUSE
        case 0x800ff418: Keyboard.press(' '); break;  // KEY_PAUSE
        case 0x800ff415: Keyboard.press('r'); break;  // KEY_REWIND
        case 0x800f7415: Keyboard.press('r'); break;  // KEY_REWIND
        case 0x800f7414: Keyboard.press('f'); break;  // KEY_FASTFORWARD
        case 0x800ff414: Keyboard.press('f'); break;  // KEY_FASTFORWARD
        case 0x800ff41b: Keyboard.press(KEY_PAGE_DOWN); break;   // KEY_PREVIOUS
        case 0x800f741b: Keyboard.press(KEY_PAGE_DOWN); break;   // KEY_PREVIOUS 
        case 0x800ff41a: Keyboard.press(KEY_PAGE_UP); break;   // KEY_NEXT
        case 0x800f741a: Keyboard.press(KEY_PAGE_UP); break;   // KEY_NEXT     
        case 0x800ff416: Keyboard.press(' '); break;  // KEY_PLAY
        case 0x800f7416: Keyboard.press(' '); break;  // KEY_PLAY
        case 0x800f744f: Keyboard.press('o'); break;    //Display | Player Process Info
        case 0x800ff44f: Keyboard.press('o'); break;    //Display | Player Process Info
        case 0x800ff451: Keyboard.press('m'); break;  // KEY_TITLE | Menu / OSD
        case 0x800f7451: Keyboard.press('m'); break;  // KEY_TITLE | Menu / OSD
        case 0x800f7424: Keyboard.press('z'); break;   // KEY_MENU | Display Info
        case 0x800ff424: Keyboard.press('z'); break;   // KEY_MENU | Display Info
        case 0x800ff423: Keyboard.press(KEY_BACKSPACE); break;    // KEY_BACK
        case 0x800f7423: Keyboard.press(KEY_BACKSPACE); break;    // KEY_BACK
        case 0x800f740f: Keyboard.press('i'); break;     // KEY_INFO
        case 0x800ff40f: Keyboard.press('i'); break;     // KEY_INFO
        case 0x800ff41e: Keyboard.press(KEY_UP_ARROW); break;     // UpArrow
        case 0x800f741e: Keyboard.press(KEY_UP_ARROW); break;     // UpArrow
        case 0x800f7420: Keyboard.press(KEY_LEFT_ARROW); break;   // LeftArrow
        case 0x800ff420: Keyboard.press(KEY_LEFT_ARROW); break;   // LeftArrow
        case 0x800f7421: Keyboard.press(KEY_RIGHT_ARROW); break;  // RightArrow
        case 0x800ff421: Keyboard.press(KEY_RIGHT_ARROW); break;  // RightArrow
        case 0x800f741f: Keyboard.press(KEY_DOWN_ARROW); break;   // DownArrow
        case 0x800ff41f: Keyboard.press(KEY_DOWN_ARROW); break;   // DownArrow
        case 0x800ff422: Keyboard.press(KEY_RETURN); break;       // KEY_OK
        case 0x800f7422: Keyboard.press(KEY_RETURN); break;       // KEY_OK
        case 0x800f7426: Keyboard.press(KEY_BACKSPACE); break;   // KEY_Y
        case 0x800ff426: Keyboard.press(KEY_BACKSPACE); break;   // KEY_Y
        case 0x800ff468: Keyboard.press('#'); break;   // KEY_X
        case 0x800f7468: Keyboard.press('#'); break;   // KEY_X
        case 0x800ff466: Keyboard.press('t'); break;   // KEY_A | Toggle Subtitles
        case 0x800f7466: Keyboard.press('t'); break;   // KEY_A | Toggle Subtitles
        case 0x800ff425: Keyboard.press('$'); break;   // KEY_B
        case 0x800f7425: Keyboard.press('$'); break;   // KEY_B
        case 0x800ff412: Keyboard.press('%'); break;    // KEY_CHANNELUP
        case 0x800f7412: Keyboard.press('%'); break;    // KEY_CHANNELUP
        case 0x800ff413: Keyboard.press('^'); break;    // KEY_CHANNELDOWN
        case 0x800f7413: Keyboard.press('^'); break;    // KEY_CHANNELDOWN
        case 0x800ff411: Keyboard.press('-'); break;       // KEY_VOLUMEDOWN
        case 0x800f7411: Keyboard.press('-'); break;       // KEY_VOLUMEDOWN
        case 0x800ff410: Keyboard.press('+'); break;       // KEY_VOLUMEUP
        case 0x800f7410: Keyboard.press('+'); break;       // KEY_VOLUMEUP
        case 0x800ff40e: Keyboard.press(KEY_F8); break;    // KEY_MUTE
        case 0x800f740e: Keyboard.press(KEY_F8); break;    // KEY_MUTE        
        case 0x800f740d: Keyboard.press(KEY_RETURN); break;        // Start
        case 0x800ff40d: Keyboard.press(KEY_RETURN); break;        // Start
        case 0x800f740b: Keyboard.press(KEY_RETURN); break;    // KEY_ENTER
        case 0x800ff40b: Keyboard.press(KEY_RETURN); break;    // KEY_ENTER
        case 0x800f7417: Keyboard.press('m'); break;  // KEY_RECORD
        case 0x800ff417: Keyboard.press('m'); break;  // KEY_RECORD
        case 0x800ff40a: Keyboard.press('&'); break;  // KEY_CLEAR
        case 0x800f740a: Keyboard.press('&'); break;  // KEY_CLEAR
        case 0x800f7401: Keyboard.press('1'); break;  // KEY_1
        case 0x800ff401: Keyboard.press('1'); break;  // KEY_1
        case 0x800f7402: Keyboard.press('2'); break;  // KEY_2
        case 0x800ff402: Keyboard.press('2'); break;  // KEY_2
        case 0x800f7403: Keyboard.press('3'); break;  // KEY_3
        case 0x800ff403: Keyboard.press('3'); break;  // KEY_3
        case 0x800f7404: Keyboard.press('4'); break;  // KEY_4
        case 0x800ff404: Keyboard.press('4'); break;  // KEY_4
        case 0x800f7405: Keyboard.press('5'); break;  // KEY_5
        case 0x800ff405: Keyboard.press('5'); break;  // KEY_5
        case 0x800f7406: Keyboard.press('6'); break;  // KEY_6
        case 0x800ff406: Keyboard.press('6'); break;  // KEY_6
        case 0x800f7407: Keyboard.press('7'); break;  // KEY_7
        case 0x800ff407: Keyboard.press('7'); break;  // KEY_7
        case 0x800f7408: Keyboard.press('8'); break;  // KEY_8
        case 0x800ff408: Keyboard.press('8'); break;  // KEY_8
        case 0x800f7409: Keyboard.press('9'); break;  // KEY_9
        case 0x800ff409: Keyboard.press('9'); break;  // KEY_9
        case 0x800f741d: Keyboard.press('*'); break;  // X_KEY_100
        case 0x800ff41d: Keyboard.press('*'); break;  // X_KEY_100
        case 0x800f7400: Keyboard.press('0'); break;  // KEY_0
        case 0x800ff400: Keyboard.press('0'); break;  // KEY_0
        case 0x800f741c: Keyboard.press('('); break;  // Reload
        case 0x800ff41c: Keyboard.press('('); break;  // Reload

        case 0xFFFFFFFF: break;  // Repeat
        default: break;
      }
      delay(220);
    }
  #endif
  IrReceiver.resume();  // Receive the next value  }
  }
}
#endif /* ARDUINO_USB_MODE */
