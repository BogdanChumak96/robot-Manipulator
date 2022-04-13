#include <SerialFlow.h>

SerialFlow rd(7,8);

const unsigned long data_to = 100; 
unsigned long tm, data_next;

void setup(void){
    rd.setPacketFormat(2, 1);
    rd.begin(0xF0F0F0F0E1LL,0xF0F0F0F0D2LL);
}
void loop(void){
    tm = millis();
    if( tm > data_next ){
        data_next = tm + data_to;
        rd.setPacketValue( tm );
        rd.sendPacket();
    }
}
