/*
--------------------------------------
Lectura serial de una entrada digital
--------------------------------------
Leer una entrada digital y mostrar por la pantalla del
computador (consola serial) el estado del pulsador
*/

int pulsador=2;

void setup(){
	pinMode(pulsador,INPUT); //Configurar el pulsador como una entrada
	Serial.begin(9600); //Inicia comunicación serial
}
void loop(){
// Lee el botón
int estado = digitalRead(pulsador);
//Condicional para saber estado del pulsador
	if(estado==1){
		Serial.println("Pulsado"); //Imprime en la consola serial "Pulsado"
	}	
	else{
		Serial.println("NO Pulsado"); //Imprime en la consola serial "NO Pulsado"
	}
delay(1000);
}