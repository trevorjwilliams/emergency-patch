// Turns on an external emergency beacon light for a duration of time in response to receiving an emergency patch email

import processing.serial.*;

Serial port;

//println(Serial.list());
//String arduinoPort = Serial.list()[2];

port = new Serial(this, "COM4", 9600);
port.write("EMERGENCY");
port.stop();

exit();
