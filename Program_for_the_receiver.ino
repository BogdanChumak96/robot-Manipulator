#include <SerialFlow.h>

SerialFlow rd(7,8);

void setup(void){
    Serial.begin(57600);
    rd.setPacketFormat(2, 1);
    rd.begin(0xF0F0F0F0D2LL,0xF0F0F0F0E1LL);
}
void loop(void){
    unsigned int v;
    if( rd.receivePacket() ){
        v = rd.getPacketValue(0);
        Serial.println(v);
    }
}
