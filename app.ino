#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ledA 3
#define ledV 4

SoftwareSerial MyBlut(7,8);  // defino los pines que utilizare para el sensor Bluetooth

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char myChar;

void setup() {
  delay(1000);
  Serial.begin(9600);
  MyBlut.begin(9600);
  Serial.println("Ready");
  sensors.begin();
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  
}

void loop() {
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  Serial.println(temp);
  MyBlut.print(temp);
  MyBlut.println(";");
  delay(1000);
  LucesLed();
}

void LucesLed(){
if(MyBlut.available() ){
    myChar = MyBlut.read();
    switch (myChar){
      case '1':
      digitalWrite(ledA,HIGH);
      digitalWrite(ledV,LOW);
      break;
      case '2':
      digitalWrite(ledA,LOW);
      digitalWrite(ledV,HIGH);
      break;
      case '3':
      digitalWrite(ledA,HIGH);
      digitalWrite(ledV,HIGH);
      break;
      case '0':
      digitalWrite(ledA,LOW);
      digitalWrite(ledV,LOW);
      break;
      }
    }
}
