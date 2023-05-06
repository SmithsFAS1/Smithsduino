This is a program for hooking up a TSOP IR Receiver to an Arduino board (in my case a LOLIN S2 Mini) and using it as a virtual keyboard device for an Amazon Fire Stick (a 4K for me)  

It is based off this 2010 code I found when beginning to program from scratch and searching for some IRremote Library Examples: http://www.righto.com/2010/12/64-bit-rc6-codes-arduino-and-xbox.html  

In fact, the IRremote library is based off Ken Shirriff's original work @ http://www.righto.com/2009/08/multi-protocol-infrared-remote-library.html  

It was built with a TSOP38238 (https://www.aliexpress.us/item/2251832658861424.html) plugged into GPIO 7 / 3.3V / GND and allows a Comcast Remote to be programmed as an Xbox 360 Media Controller (code 21708) for buttons to be used in Kodi on a Fire Stick (along with the regular Amazon UI)  

A USB Y-Cable OTG adapter was used (https://www.amazon.com/Samsung-Galaxy-Amazon-Android-Tablet/dp/B08DQVKGZ5/) for this as well.  

Uses the Arduino-IRremote library: https://github.com/Arduino-IRremote/Arduino-IRremote  

OTA updating is supported via http://[ARDUINO IP]/ using Basic Auth (username/password defined in the code)  

