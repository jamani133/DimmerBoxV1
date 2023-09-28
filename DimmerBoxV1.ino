#include <DMXSerial.h>

#define Ch1Pin 2
#define Ch2Pin 3
#define Ch3Pin 4
#define Ch4Pin 5

#define muxAdr1 6
#define muxAdr1 7
#define muxAdr1 8

#define adr9    9

#define muxRet  10
uint16_t Adress = 0;

void setup(){
    DMXSerial.init(DMXReceiver);
    pinMode(Ch1Pin);
}
void loop(){
    analogWrite(Ch1Pin, DMXSerial.read(Adress+0));
    analogWrite(Ch2Pin, DMXSerial.read(Adress+1));
    analogWrite(Ch3Pin, DMXSerial.read(Adress+2));
    analogWrite(Ch4Pin, DMXSerial.read(Adress+3));

}
void getAdr(){
    Adress = 0;
    for(uint8_t i = 0; i < 9; i++){
        Adress = (Adress << 1) + getMuxPin(i);
    }
    Adress = Adress >> 1;
}

Boolean getMuxPin(uint8_t pinNum){
    if(pinNum == 8){
        return digitalRead(adr9);
    }
    digitalWrite(muxAdr1,pinNum & 1);
    digitalWrite(muxAdr2,pinNum >> 1 & 1);
    digitalWrite(muxAdr3,pinNum >> 2 & 1);
    return digitalRead(muxRet);
}