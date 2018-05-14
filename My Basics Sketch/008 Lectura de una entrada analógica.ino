/*
Leer una entrada análoga y mostrar por la pantalla del
computador (consola serial) el valor luego de girar
el potenciómetro
*/
void setup(){
	Serial.begin(9600); //Inicia comunicación serial
}
void loop(){
	int valor = analogRead(A0); //Guardar en una variable entera el valor del potenciómetro 0 a 1024
	Serial.println(valor); //Imprime en la consola serial el valor de la variable
	delay(1000); //Retardo para la visualización de datos en la consola
}