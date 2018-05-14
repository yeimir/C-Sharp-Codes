//leds intermitentes

#define pinLED7 7 //asigna nombres a los pines
#define pinLED5 5

void setup()
{
pinMode(pinLED7, OUTPUT); //declara la funcion del pin
pinMode(pinLED5, OUTPUT);
}

void loop()
{
digitalWrite(pinLED7, HIGH);
digitalWrite(pinLED5, LOW);
delay(1000);
digitalWrite(pinLED7, LOW);
digitalWrite(pinLED5, HIGH);
delay(1000);
}