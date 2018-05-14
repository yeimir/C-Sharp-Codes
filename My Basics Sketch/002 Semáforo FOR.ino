/* Semáforo FOR */

void setup()
{
	pinMode(2, OUTPUT); //declara la funcion del pin
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
}
void loop()
{
	digitalWrite(4, HIGH);
	delay(4000);
	digitalWrite(4, LOW);

	for (int i = 0; i < 5; ++i)
		{
			digitalWrite(3, HIGH);
			delay(1000);
			digitalWrite(3, LOW);
			delay(200);
		}

	digitalWrite(2, HIGH);
	delay(5000);
	digitalWrite(2, LOW);
}  