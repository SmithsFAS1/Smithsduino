/*
Map Remote to 21708 - Xbox 360 Remote
*/
#define TESTMODE

#include <IRremote.hpp>
#include <Arduino.h>
#define IR_RECEIVE_PIN 7
#define DECODE_RC6
#include "USB.h"
#include "USBHIDKeyboard.h"

#if ARDUINO_USB_MODE
#warning This sketch should be used when USB is in OTG mode
void setup() {}
void loop() {}
#else
USBHIDKeyboard Keyboard;
int RECV_PIN = 7;
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
        case 0x800f7428: Serial.println("KEY_OPEN"); break;              // Open
        case 0x800ff428: Serial.println("KEY_OPEN"); break;              // Open
        case 0x800ff464 : Serial.println("Fancy Button"); break; // 
        case 0x800f7464 : Serial.println("Fancy Button"); break; // 
        case 0x800ff40c: Serial.println("KEY_POWER"); break;  // Power
        case 0x800f740c: Serial.println("KEY_POWER"); break;  // Power
        case 0x800ff419: Serial.println("KEY_STOP"); break;              // Stop
        case 0x800f7419: Serial.println("KEY_STOP"); break;              // Stop
        case 0x800f7418: Serial.println("KEY_PAUSE"); break;  // Pause (Does play/pause)
        case 0x800ff418: Serial.println("KEY_PAUSE"); break;  // Pause (Does play/pause)
        case 0x800ff415: Serial.println("KEY_REWIND"); break;              // Rewind
        case 0x800f7415: Serial.println("KEY_REWIND"); break;              // Rewind
        case 0x800f7414: Serial.println("KEY_FASTFORWARD"); break;              // Fast Forward
        case 0x800ff414: Serial.println("KEY_FASTFORWARD"); break;              // Fast Forward
        case 0x800ff41b: Serial.println("KEY_PREVIOUS"); break;              // Prev
        case 0x800f741b: Serial.println("KEY_PREVIOUS"); break;              // Prev 
        case 0x800ff41a: Serial.println("KEY_NEXT"); break;              // Next
        case 0x800f741a: Serial.println("KEY_NEXT"); break;              // Next     
        case 0x800ff416: Serial.println("KEY_PLAY"); break;              // Play (Does play/pause)
        case 0x800f7416: Serial.println("KEY_PLAY"); break;              // Play (Does play/pause)
        case 0x800f744f: Serial.println("Display"); break;
        case 0x800ff44f: Serial.println("Display"); break;
        case 0x800ff451: Serial.println("KEY_TITLE"); break;              // Title
        case 0x800f7451: Serial.println("KEY_TITLE"); break;              // Title
        case 0x800f7424: Serial.println("KEY_MENU"); break;              // DVD Menu
        case 0x800ff424: Serial.println("KEY_MENU"); break;              // DVD Menu
        case 0x800ff423: Serial.println("KEY_BACKSPACE"); break;    // Back
        case 0x800f7423: Serial.println("KEY_BACKSPACE"); break;    // Back
        case 0x800f740f: Serial.println("KEY_INFO"); break;     // Info
        case 0x800ff40f: Serial.println("KEY_INFO"); break;     // Info
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
        case 0x800f7426: Serial.println("Y_BUTT"); break;  // Button Y
        case 0x800ff426: Serial.println("Y_BUTT"); break;  // Button Y
        case 0x800ff468 : Serial.println("X_BUTT"); break; // Button X
        case 0x800f7468 : Serial.println("X_BUTT"); break; // Button X
        case 0x800ff425: Serial.println("B_BUTT"); break;  // Button A (toggle subtitles)
        case 0x800f7425: Serial.println("B_BUTT"); break;  // Button A (toggle subtitles)
        case 0x800ff466 :  Serial.println("A_BUTT"); break; // Button B
        case 0x800f7466 :  Serial.println("A_BUTT"); break; // Button B
        case 0x800ff412: Serial.println("KEY_CHANNELUP"); break;
        case 0x800f7412: Serial.println("KEY_CHANNELUP"); break;
        case 0x800ff413: Serial.println("KEY_CHANNELDOWN"); break;
        case 0x800f7413: Serial.println("KEY_CHANNELDOWN"); break;
        case 0x800ff411: Serial.println("VOL_DOWN"); break;            // Vol Down
        case 0x800f7411: Serial.println("VOL_DOWN"); break;            // Vol Down
        case 0x800ff410: Serial.println("VOL_UP"); break;            // Vol Up
        case 0x800f7410: Serial.println("VOL_UP"); break;            // Vol Up
        case 0x800ff40e: Serial.println("KEY_MUTE"); break;         // Mute
        case 0x800f740e: Serial.println("KEY_MUTE"); break;         // Mute        
        case 0x800f740d: Serial.println("START"); break;
        case 0x800ff40d: Serial.println("START"); break;
        case 0x800f740b: Serial.println("KEY_ENTER"); break;              // Enter
        case 0x800ff40b: Serial.println("KEY_ENTER"); break;              // Enter
        case 0x800f7417: Serial.println("KEY_RECORD"); break;              // A
        case 0x800ff417: Serial.println("KEY_RECORD"); break;              // A
        case 0x800ff40a: Serial.println("KEY_CLEAR"); break;
        case 0x800f740a: Serial.println("KEY_CLEAR"); break;
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
        case 0x800f741c: Serial.println("Reload"); break;  // Reload?
        case 0x800ff41c: Serial.println("Reload"); break;  // Reload?  

        case 0xFFFFFFFF: break;  // Repeat
        default: break;
      }
      delay(200);
    }


#else
    if (results.decode_type == 0x0F) {
     switch (IrReceiver.decodedIRData.decodedRawData) {
        case 0x800f7420: Keyboard.write(KEY_LEFT_ARROW); break;   // Left
        case 0x800ff420: Keyboard.write(KEY_LEFT_ARROW); break;   // Left
        case 0x800f7421: Keyboard.write(KEY_RIGHT_ARROW); break;  // Right
        case 0x800ff421: Keyboard.write(KEY_RIGHT_ARROW); break;  // Right
        case 0x800ff41e: Keyboard.write(KEY_UP_ARROW); break;     // Up
        case 0x800f741e: Keyboard.write(KEY_UP_ARROW); break;     // Up
        case 0x800f741f: Keyboard.write(KEY_DOWN_ARROW); break;   // Down
        case 0x800ff41f: Keyboard.write(KEY_DOWN_ARROW); break;   // Down
        case 0x800ff422: Keyboard.write(KEY_RETURN); break;       // OK
        case 0x800f7422: Keyboard.write(KEY_RETURN); break;       // OK
        case 0x800ff423: Keyboard.write(KEY_BACKSPACE); break;    // Exit
        case 0x800f7423: Keyboard.write(KEY_BACKSPACE); break;    // Exit
        case 0x800ff451: Keyboard.write('i'); break;              // NICAM
        case 0x800f7451: Keyboard.write('i'); break;              // NICAM
        case 0x800f7424: Keyboard.write('c'); break;              // Menu
        case 0x800ff424: Keyboard.write('c'); break;              // Menu
        case 0x800ff415: Keyboard.write('r'); break;              // Rewind
        case 0x800f7415: Keyboard.write('r'); break;              // Rewind
        case 0x800f7414: Keyboard.write('f'); break;              // Fast Forward
        case 0x800ff414: Keyboard.write('f'); break;              // Fast Forward
        case 0x800ff416: Keyboard.write(' '); break;              // Play (Does play/pause)
        case 0x800f7416: Keyboard.write(' '); break;              // Play (Does play/pause)
        case 0x800f7417: Keyboard.write('u'); break;              // A
        case 0x800ff417: Keyboard.write('u'); break;              // A
        case 0x800ff419: Keyboard.write('x'); break;              // Stop
        case 0x800f7419: Keyboard.write('x'); break;              // Stop
        case 0x800f7418: Keyboard.write(' '); break;  // Pause (Does play/pause)
        case 0x800ff418: Keyboard.write(' '); break;  // Pause (Does play/pause)
        //case 0xc80E8B04FLL :  Keyboard.write(''); break; // TV/AV
        case 0x800ff410: Keyboard.write('+'); break;            // Vol Up
        case 0x800f7410: Keyboard.write('+'); break;            // Vol Up
        case 0x800ff411: Keyboard.write('-'); break;            // Vol Down
        case 0x800f7411: Keyboard.write('-'); break;            // Vol Down
        case 0x80E8926D: Keyboard.write(KEY_PAGE_UP); break;    // Prog Up
        case 0x80E852AD: Keyboard.write(KEY_PAGE_DOWN); break;  // Prog Down
        case 0x800ff40e: Keyboard.write(KEY_F8); break;         // Mute
        case 0x800f740e: Keyboard.write(KEY_F8); break;         // Mute
        case 0x80E8D827: Keyboard.write('t'); break;            // LCR (Toggle Subtitles)
        case 0x80E8B847: Keyboard.write('w'); break;            // Button below mute (Mark Watched)
        case 0x800f7426: Keyboard.write('t'); break;  // Button A (toggle subtitles)
        case 0x800ff426: Keyboard.write('t'); break;  // Button A (toggle subtitles)
        //case 0x800ff468 :  Keyboard.write(''); break; // Button B
        //case 0x800f7466 :  Keyboard.write(''); break; // Button C
        //case 0x800ff425 :  Keyboard.write(''); break; // Button D
        case 0x800f7401: Keyboard.write('1'); break;  // 1
        case 0x800ff401: Keyboard.write('1'); break;  // 1
        case 0x800f7402: Keyboard.write('2'); break;  // 2
        case 0x800ff402: Keyboard.write('2'); break;  // 2
        case 0x800f7403: Keyboard.write('3'); break;  // 3
        case 0x800ff403: Keyboard.write('3'); break;  // 3
        case 0x800f7404: Keyboard.write('4'); break;  // 4
        case 0x800ff404: Keyboard.write('4'); break;  // 4
        case 0x800f7405: Keyboard.write('5'); break;  // 5
        case 0x800ff405: Keyboard.write('5'); break;  // 5
        case 0x800f7406: Keyboard.write('6'); break;  // 6
        case 0x800ff406: Keyboard.write('6'); break;  // 6
        case 0x800f7407: Keyboard.write('7'); break;  // 7
        case 0x800ff407: Keyboard.write('7'); break;  // 7
        case 0x800f7408: Keyboard.write('8'); break;  // 8
        case 0x800ff408: Keyboard.write('8'); break;  // 8
        case 0x800f7409: Keyboard.write('9'); break;  // 9
        case 0x800ff409: Keyboard.write('9'); break;  // 9
        case 0x800f7400: Keyboard.write('0'); break;  // 0
        case 0x800ff400: Keyboard.write('0'); break;  // 0
          //case 0x80E8F20D :  Keyboard.write(''); break; // 12

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
