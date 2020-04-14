/*
 * Medir temperatura sensor  2 sensores DS18B20
 * taloselectronics.com
 * soporte@taloselectronics.com
 */
#include <OneWire.h>                
#include <DallasTemperature.h>
 
OneWire ourWire(2);//Se establece el pin 2 commo bus de datos
 
DallasTemperature DS18B20(&ourWire); //Se declara una el objeto tipo DallasTemperature
DeviceAddress Direccion_S1 = {0x28, 0x48, 0xD9, 0x23, 0x5F, 0x14, 0x1, 0x32};//dirección del sensor 1
DeviceAddress Direccion_S2 = {0x28, 0xAE, 0x86, 0x91, 0x5E, 0x14, 0x1, 0x6E};//dirección del sensor 2

void setup() {
Serial.begin(9600);//Se inicializa el monitor serial a 9600 bps
DS18B20.begin();   //Se inicia el el sensor DS18b20
}
 
void loop() {
DS18B20.requestTemperatures();   //Se envía el comando para leer la temperatura

float temperatura_1= DS18B20.getTempC(Direccion_S1);//Se obtiene la temperatura del sensor 1
float temperatura_2= DS18B20.getTempC(Direccion_S2);//Se obtiene la temperatura del sensor 1

Serial.print("Temperatura 1 = ");
Serial.print(temperatura_1);
Serial.print(" C\t");
Serial.print("   Temperatura 2 = ");
Serial.print(temperatura_2);
Serial.println(" C");
delay(500);
                 
}
