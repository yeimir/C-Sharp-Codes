
/* Led Controlado por Boton, conn el boton A se enciende el led
y con el boton B se apaga el led */

int led= 13;
int buttonA= 9;
int buttonB= 8;

void setup() {
	pinMode(led, OUTPUT);
	pinMode(buttonA, INPUT_PULLUP);
	pinMode(buttonB, INPUT_PULLUP);
}
void loop() {
	if(digitalRead(buttonA) == HIGH) {
		digitalWrite(led, HIGH);
	}
	if(digitalRead(buttonB) == HIGH) {
		digitalWrite(led, LOW);
	}
}