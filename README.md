# emergency-patch
Code required to get the Arduino Nano I have soldered to a bunch of other components to play nicely with the emergency beacon light it is meant to drive.

# EmergencyPatchArduino
This is the sketch that is run on the Arduino.  It won't do anything until you send it a message over the serial port.

# EmergencyPatchComputer
The sketch to be run on the computer to trigger the emergency beacon.  You'll need to execute it when you want to turn on the beacon.  I originally had this called by a custom Outlook rule.