/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 13;
int redpin = 11; // select the pin for the red LED
int bluepin = 10; // select the pin for the blue LED
int greenpin = 9; // select the pin for the green LED
int val;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}
void lightsoff() {
   analogWrite (redpin, 0);
   analogWrite (bluepin, 0);
   analogWrite (greenpin, 0);
}
void lightup() {
  for (val=255; val>0; val--)
  {
    analogWrite (redpin, val);
    analogWrite (bluepin, 255-val);
    analogWrite (greenpin, 255-val);
    delay (1);
  }
  for (val = 0; val <255; val++)
  {
    analogWrite (redpin, val);
    analogWrite (bluepin, 255-val);
    analogWrite (greenpin, 255-val);
    delay (1);
  }
  lightsoff();
}

void loop() {
  if (irrecv.decode(&results)) {
    lightup();
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
