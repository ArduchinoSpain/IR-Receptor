// hace que cuando le das a los botones 1 2 o 3 de un mando se enciendan los LEDs
// los leds se mantienen encendidos hasta que se pulsa otro boton
// Descargarse la última versión de la librería IRemote.h desde https://github.com/z3t0/Arduino-IRremote/releases

#include <IRremote.h>  
 
const int PinReceptor = 2; // Nombro el pin que recibe la información del IR
int Led1 = 7; //
int Led2 = 6; // nombro los pines que irán a los LEDs
int Led3 = 5; //
 
IRrecv irrecv(PinReceptor); //Establezco el pin que recibirá la señal 
decode_results results;    //se establece que results guarda la información recibida del IR
 
void setup()
{
  pinMode(Led1, OUTPUT); //
  pinMode(Led2, OUTPUT); // Los pins de los LEDs los establezco como salida
  pinMode(Led3, OUTPUT); //
  Serial.begin(9600); //inicializo el puerto serial  
  irrecv.enableIRIn();   //comienza a recibir información el IR
}
 
void loop() 
{
  if (irrecv.decode(&results)) //si el IR recibe informacion la guarda en results
                               // y hace la secuencia del if
  {   
    Serial.print("Codigo IR: ");         //escribe "Codigo IR" y muestra el valor 
    Serial.print(results.value, HEX);    //en hexadecimal del código recibido
                                         //que se guarda en results.value
                                         
    Serial.print(",  bits: ");           //Escribe "Bits" y muestra la cantidad
    Serial.println(results.bits);        //de bits utilizada en el código 
                                         //(que se guarda en results.bits)
                                         
    irrecv.resume();                     //Resetea el IR y lo prepara para volver a recibir información
  }  
  delay(600);                            //retardo de 600ms
 

   
  if(results.value == 0xFF30CF)         // Si se recibe el código en hexadecimal deseado se ejecuta la acción dentro del if
  {
    digitalWrite(Led1,HIGH);
  }
  
  else if(results.value == 0xFF18E7)
  {
   digitalWrite(Led2,HIGH);
  }
  
  else if(results.value == 0xFF7A85)
  {
   digitalWrite(Led3,HIGH);
  }
  else
  {
    digitalWrite(Led1,LOW);     //
    digitalWrite(Led2,LOW);     // si se recibe un código diferente de los que se quieren se apagan los 3 LEDs
    digitalWrite(Led3,LOW);     //
  }

}
