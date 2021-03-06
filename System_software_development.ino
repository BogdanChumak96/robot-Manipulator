#define REMOTEXY_MODE__HARDSERIAL
 
#include <RemoteXY.h> 
 
// настройки з'єднання
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 9600 
 
 
// конфігурація інтерфейсу
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,6,0,0,0,199,0,8,13,0,
  4,160,10,7,81,5,2,26,129,0,
  21,0,60,6,17,208,159,208,190,208,
  178,208,190,209,128,208,190,209,130,32,
  208,191,208,187,208,176,209,130,209,132,
  208,190,209,128,208,188,208,184,0,129,
  0,77,13,20,6,17,208,151,208,176,
  208,182,208,184,208,188,0,129,0,1,
  13,18,6,17,49,45,208,181,32,208,
  183,208,178,46,0,129,0,27,13,18,
  6,17,50,45,208,181,32,208,183,208,
  178,46,0,129,0,53,13,18,6,17,
  51,45,208,181,32,208,183,208,178,46,
  0,4,0,7,17,6,31,2,26,4,
  0,32,17,6,31,2,26,4,0,58,
  17,6,31,2,26,4,0,84,17,6,
  30,2,26,129,0,27,48,50,6,17,
  208,159,208,190,208,178,208,190,209,128,
  208,190,209,130,32,208,183,208,176,208,
  182,208,184,208,188,209,131,0,4,160,
  9,55,84,5,2,26 }; 

  // структура визначає всі змінні вашого інтерфейсу управління
struct { 
 
    // input variable
  int8_t slider_1; // =-100..100 положення слайдера 
  int8_t slider_2; // =0..100 положення слайдера 
  int8_t slider_3; // =0..100 положення слайдера 
  int8_t slider_4; // =0..100 положення слайдера 
  int8_t slider_5; // =0..100 положення слайдера 
  int8_t slider_6; // =-100..100 положення слайдера 
 
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 
 
} RemoteXY; 
#pragma pack(pop) 
 
///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 
Servo myservo;  void setup()   {    RemoteXY_Init ();           // TODO you setup code  
