// Turns on an external emergency beacon light for a duration of time in response to receiving an emergency patch email
#define LED 12   // LED connected to digital pin 12

unsigned long onTime = 900000; // duration for light to stay on after receiving an email; currently 15 minutes
int checkPeriod = 1000; // time between subsequent checks for new email
byte inByte = 0; // buffer for reading bytes from the serial port
String recentBytes = String("012345678");
unsigned long startTime = 0; // the time the beacon was last turned on

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0) {
    inByte = Serial.read();
    recentBytes = recentBytes.substring(1);
    recentBytes.concat(char(inByte));
    String output = recentBytes + "\n";
    Serial.write(output.c_str());
    if (recentBytes == "EMERGENCY") {
      digitalWrite(LED, HIGH);
      startTime = millis();
    }
  }
  
  if (startTime + onTime < millis()) {
    digitalWrite(LED, LOW);
  }
  
  delay(checkPeriod);
}
