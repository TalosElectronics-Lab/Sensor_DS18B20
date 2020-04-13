/*
 * Medir temperatura sensor DS18B20
 * taloselectronics.com
 * soporte@taloselectronics.com
 */
#include <OneWire.h>                
#include <DallasTemperature.h>
 
OneWire ourWire(2);                //Se establece el pin 2 commo bus de datos
 
DallasTemperature DS18B20(&ourWire); //Se declara una el objeto tipo DallasTemperature

void setup() {
Serial.begin(9600);//Se inicializa el monitor serial a 9600 bps
DS18B20.begin();   //Se inicia el el sensor DS18b20
}
 
void loop() {
DS18B20.requestTemperatures();   //Se envía el comando para leer la temperatura
float temperatura= DS18B20.getTempCByIndex(0); //Se obtiene la temperatura en ºC

Serial.print("Temperatura= ");
Serial.print(temperatura);
Serial.println(" C");
delay(500);                     
}
