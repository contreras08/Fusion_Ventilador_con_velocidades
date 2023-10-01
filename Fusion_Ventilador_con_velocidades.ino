#include <IRremote.h>

IRrecv IR(3);
int vel1 = 8;
int vel2 = 9;
int vel3 = 10;


void setup() {
  //pinMode(10, OUTPUT);
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
  pinMode(vel3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int dato=Serial.read();
    if(dato=='A'){
      digitalWrite(vel3, HIGH);
      delay(10);
    }
    if(dato=='B'){
      digitalWrite(vel3, LOW);
      delay(10);
    }
  }
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
          if (IR.decodedIRData.decodedRawData == 0xEE11FB04){
      digitalWrite(vel1, HIGH);
    }
          if (IR.decodedIRData.decodedRawData == 0xF708FB04){
      digitalWrite(vel1, LOW);
    }
          if (IR.decodedIRData.decodedRawData == 0xED12FB04){
      digitalWrite(vel3, HIGH);
    }
          if (IR.decodedIRData.decodedRawData == 0xF708FB04){
      digitalWrite(vel3, LOW);
    }
          if (IR.decodedIRData.decodedRawData == 0xEC13FB04){
      digitalWrite(vel2, HIGH);
    }
          if (IR.decodedIRData.decodedRawData == 0xF708FB04){
      digitalWrite(vel2, LOW);
    }
   
    delay(10);
    IR.resume();
   }
  }
