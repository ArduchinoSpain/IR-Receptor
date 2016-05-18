// Muestra el codigo recibido por el IR

#include <NECIRrcv.h>
#define IRPIN 8    // Datos IR en pin 4. IR es NEGATIVO,POSITIVO Y DATOS

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
    Serial.print("got code: 0x") ;
    Serial.println(ircode,HEX) ;
  }
}
