#include <FiniteStateMachine.h>

State Off = State(enterOff, updateOff, exitOff); // Quemador Apagado
State Lighting = State(enterLighting, updateLighting, exitLighting); // El quemador está intentado encender
State On = State(enterOn, updateOn, exitOn); // Quemador encendido
State Alarm = State(updateAlarm);  // El quemador no se encendió o se apagó
FSM Burner = FSM(Off); //Se inicializa la FSM en off

// Pre-asignación de pines

#define IgniterRelayPin     2
#define GasRelayPin       3
#define CommandPin        4
#define StatusPin         5
#define FlameSensorPin      6
#define BuzzerPin       7
#define OnStatusLedPin      8
#define OffStatusLedPin     9
#define LightingStatusLedPin  10

//Asignacion de estados

#define RelayOn   1
#define RelayOff  0

#define LedOn 1
#define LedOff  0

#define CommandOn 0
#define CommandOff  1

#define StatusOn  0
#define StatusOff 1

#define FlameOn   0
#define FlameOff  1

#define BuzzerOn 1
#define BuzzerOff 0

#define FlameWaitTime     3000  // Esperar 2 segundos por llama
#define GasClearTime    4000 // 10 seg para que el gas se disipe
#define NumLightingTries  3

int BurnerTries = 1; // Contador de Intentos de Encendido

void setup()
{
  pinMode(GasRelayPin,OUTPUT);
  digitalWrite(GasRelayPin,RelayOff);
  pinMode(IgniterRelayPin,OUTPUT);
  digitalWrite(IgniterRelayPin,RelayOff);
  pinMode(CommandPin,INPUT_PULLUP);
  pinMode(StatusPin,OUTPUT);
  pinMode(OffStatusLedPin,OUTPUT);
  pinMode(LightingStatusLedPin,OUTPUT);
  pinMode(OnStatusLedPin,OUTPUT);
  pinMode(FlameSensorPin,INPUT_PULLUP);
  pinMode(BuzzerPin,OUTPUT);
  digitalWrite(BuzzerPin,BuzzerOff);
} 

void loop()
{  
  Burner.update();
}

//************************************** STATE OFF ********************************************

void enterOff()
{
  digitalWrite(StatusPin,StatusOff);
  digitalWrite(GasRelayPin,RelayOff);
  digitalWrite(IgniterRelayPin,RelayOff);
  digitalWrite(OffStatusLedPin,LedOn);
  digitalWrite(LightingStatusLedPin,LedOff);
  digitalWrite(OnStatusLedPin,LedOff);
}

void updateOff()
{
  if(digitalRead(CommandPin) == CommandOn)
  Burner.transitionTo(Lighting);
}

void exitOff()
  {
    BurnerTries = 1;
  }

//**************************************STATE LIGTHING********************************************

void enterLighting()
  {
    digitalWrite(OffStatusLedPin,LedOff);
    digitalWrite(LightingStatusLedPin,LedOn);
    digitalWrite(OnStatusLedPin,LedOff);
  }

void updateLighting()
  {
      if(BurnerTries > NumLightingTries)
        { 
          digitalWrite(GasRelayPin,RelayOff);
          digitalWrite(IgniterRelayPin,RelayOff);
          Burner.transitionTo(Alarm);
        }
          else
            {
              BurnerTries = BurnerTries + 1;
              digitalWrite(IgniterRelayPin,RelayOn);
              
              digitalWrite(GasRelayPin,RelayOn);
              unsigned long endtime = millis()+ FlameWaitTime;
              while(digitalRead(FlameSensorPin) != FlameOn && millis()< endtime)
                {
                  if(digitalRead(CommandPin) == CommandOff)
                    Burner.transitionTo(Off);
                }
                
              if(digitalRead(FlameSensorPin) == FlameOn)
                {
                  digitalWrite(IgniterRelayPin,RelayOff);
                  Burner.transitionTo(On);
                }
              if(digitalRead(FlameSensorPin) == FlameOff)
                { // Deje tiempo para que el gas se despeje antes de intentar de nuevo
                  unsigned long endtime = millis() + GasClearTime; 
                  digitalWrite(GasRelayPin,RelayOff);
                  digitalWrite(IgniterRelayPin,RelayOff);
                  while(millis() < endtime)
                    {
                      if(digitalRead(CommandPin) == CommandOff)
                        Burner.transitionTo(Off);
                    }
                }
            }
  }

void exitLighting()
  {
  
  }

//***************************************** STATE ON ***********************************************

void enterOn()
  {
    digitalWrite(StatusPin,StatusOn);
    digitalWrite(OnStatusLedPin,LedOn);
    digitalWrite(LightingStatusLedPin,LedOff);
    digitalWrite(OffStatusLedPin,LedOff);
  }

void updateOn()
{
  
  if(digitalRead(FlameSensorPin) == FlameOff)
  Burner.transitionTo(Alarm);
  if(digitalRead(CommandPin) == CommandOff)
  Burner.transitionTo(Off);
  digitalWrite(OnStatusLedPin,LedOff);
  delay(300);
  digitalWrite(OnStatusLedPin,LedOn);
  delay(300);
}

void exitOn()
{
  
}

//************************************** STATE ALARM ********************************************

void updateAlarm()
{
  digitalWrite(GasRelayPin,RelayOff);
  digitalWrite(IgniterRelayPin,RelayOff);
  digitalWrite(BuzzerPin,BuzzerOn);
  digitalWrite(OffStatusLedPin,LedOn);
  digitalWrite(LightingStatusLedPin,LedOn);
  digitalWrite(OnStatusLedPin,LedOn);
  delay(500);
  digitalWrite(BuzzerPin,BuzzerOff);
  digitalWrite(OffStatusLedPin,LedOff);
  digitalWrite(LightingStatusLedPin,LedOff);
  digitalWrite(OnStatusLedPin,LedOff);
  delay(500);
  
  if(digitalRead(CommandPin) == CommandOff)
  Burner.transitionTo(Off);
}
