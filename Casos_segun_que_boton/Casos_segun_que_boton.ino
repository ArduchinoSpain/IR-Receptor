#include <NECIRrcv.h>
#define IRPIN 4    // Pin donde esta conectado el sensor IR

#define n1 0xF30CFF00
#define n2 0xE718FF00
#define n3 0xA15EFF00
#define n4 0xF708FF00
#define n5 0xE31CFF00
#define n6 0xA55AFF00
#define n7 0xBD42FF00
#define n8 0xAD52FF00
#define n9 0xB54AFF00

NECIRrcv ir(IRPIN) ;

void setup()
{
  Serial.begin(9600) ;
  Serial.println("NEC IR code reception") ;
  ir.begin() ;
}

void loop()
{
  unsigned long ircode ;

  while (ir.available()) {
    ircode = ir.read() ;
    //Serial.println(ircode);
    switch(ircode)
    {
        case n1:
        {
                Serial.println(1);
                break;
        }
        case n2:
        {
                Serial.println(2);
                break;
        }
        case n3:
        {
                Serial.println(3);
                break;
        }
        case n4:
        {
                Serial.println(4);
                break;
        }
        case n5:
        {
                Serial.println(5);
                break;
        }
        case n6:
        {
                Serial.println(6);
                break;
        }
        case n7:
        {
                Serial.println(7);
                break;
        }
        case n8:
        {
                Serial.println(8);
                break;
        }
        case n9:
        {
                Serial.println(9);
                break;
        }
    }    
  }
} 
