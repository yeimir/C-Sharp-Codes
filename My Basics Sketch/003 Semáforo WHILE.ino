/* Semáforo WHILE */

void setup()
{
	pinMode(2, OUTPUT); //declara la funcion del pin
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
}

void loop() {
	int cuenta = 0;
	digitalWrite(4,HIGH); //Asigna un estado 1 lógico al pin 2
	delay(4000);
	digitalWrite(4,LOW); //Asigna un estado 0 lógico al pin 2
	
	while(cuenta<5) {
		digitalWrite(3,HIGH);
		delay(1000);
		digitalWrite(3,LOW);
		delay(200);
		cuenta++;
	}
	digitalWrite(2,HIGH);
	delay(5000);
	digitalWrite(2,LOW);
}
