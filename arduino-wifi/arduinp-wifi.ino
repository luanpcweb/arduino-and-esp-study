#include "SoftwareSerial.h"

SoftwareSerial ESP(2, 3); // RX, TX

const int RST = 4;

void setup(){
  Serial.begin(9600);
  ESP.begin(9600);
  
  //Pulso em Reset para aceitar comunicacao
  pinMode(RST, OUTPUT);
  digitalWrite(RST, LOW);
  delay(300);
  digitalWrite(RST, HIGH);
}

void loop(){
  if (ESP.available()){
    Serial.write(ESP.read());
  }
  if (Serial.available()){
    ESP.write(Serial.read());
  }
}
