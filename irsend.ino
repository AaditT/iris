#include <IRremote.h>
IRsend irsend;

int buttonpin = 10; // define the key switch sensor interface
int val;

void setup() {
  
  pinMode (buttonpin, INPUT); // define the key switch sensor output interface
  Serial.begin(9600);
}
void loop() 
{
  val = digitalRead (buttonpin); // digital interface will be assigned a value of 3 to read val
  if (val == LOW) {
    irsend.sendSony(0xa90, 12); // Sony TV power code
    delay(100);
    Serial.println("full send");
  }
}
