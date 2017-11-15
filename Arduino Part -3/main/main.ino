#include "cardio.h"
#include "coeur.h"
#include "param.h"

boolean detection;
const int A=0;
int pulse;      //mesure en direct 
int f_cardiac;  //frequence cardiaque calculé

short ledPhase;

unsigned long time; //temps passer depuis le debut du calcule du pouds

unsigned long envois;

void setup() {
  
  Serial.begin(9600);
  pinMode(A, INPUT);
  pinMode (11, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);

  envois = 0;
  ledPhase = 0;

  #ifdef MODE_CHENILLE
  digitalWrite (11, HIGH);
  #endif
  #ifdef MODE_LED2
  digitalWrite (2,HIGH);
  digitalWrite (4,HIGH);
  digitalWrite (6,HIGH);
  digitalWrite (8,HIGH);
  digitalWrite (10,HIGH);
  #endif
  #ifdef MODE_LED3
  digitalWrite (3,HIGH);
  digitalWrite (6,HIGH);
  digitalWrite (9,HIGH);
  #endif
}

void loop()
{
 f_cardiac=mesure(10);
 time = millis();
 Serial.print(time);
 Serial.print(";");
 Serial.print(f_cardiac);
 Serial.print(";");
}

