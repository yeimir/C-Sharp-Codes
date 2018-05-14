/*
Leer una entrada análoga y varía la velocidad de parpadeo de un LED en función del valor leído, luego de girar el potenciómetro.
*/

#define LED 7
#define POT A0

int lectura = 0;
void setup(){
	pinMode(LED, OUTPUT);
}
void loop(){
	lectura = analogRead(POT); //leemos el pin del potenciómetro
	digitalWrite(LED, HIGH);
	delay(lectura); //Esperamos un tiempo equivalente al valor del potenciómetro
	digitalWrite(LED, LOW);
	delay(lectura);
}