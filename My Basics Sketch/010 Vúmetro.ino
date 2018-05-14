/*Se necesita diseñar un sistema de señalización en función del voltaje muestreado por el PINA3 del Arduino.
El rango es:
0v < Valor <= 1v		Leds apagados
1v < Valor <= 2,2v		Led verde encendido
2,2v < Valor <= 3,6v	Led verde y amarillo encendid
3,6v < Valor <= 4,6 	Led verde,-amarillo y rojo encendido
4,6v < Valor <= 5v  	Todos los Leds parpadean

0V   = 0%	--- 0
1v   = 20%	--- 204,8
2,2v = 44%	--- 450,56
3,6v = 72%	--- 737,28
4,6v = 92%	--- 942,08
5v   = 100%	--- 1024

*/

#define LED1 3
#define LED2 5
#define LED3 7
#define POT A0

float valor = 0;

void setup(){
	Serial.begin(9600);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
}
void loop(){
	Serial.println(valor);
	valor = analogRead(POT);
	if (valor>0 && valor<=204.8){
		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
	}
	if(valor>204.8 && valor<=450.56){
	    digitalWrite(LED1, HIGH);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
	}
	if(valor>450.56 && valor<=737.28){
	    digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, LOW);
	}
	if(valor>737.28 && valor<=942.08){
	    digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
	}
	if(valor>942.08 && valor<=1023.00){
	    digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
		delay(500);
		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		delay(500);
	}
	
}
