/*  Fichier     : cardio.c
 *  Auteur      : Hugo Le Boennec
 *  Description : Contient les fonctions pour la lecture des pulsations et le calcul du pouls
 */

#include "cardio.h"

#define INTERVALLE 10000

double pouls(unsigned int pulsations)
{
  return pulsations * (INTERVALLE / 60000);
}




int mesure(int t)
{
  //Serial.begin(9600);
  unsigned long ms,duree;

  ms = t*4;
  
  int m,p,pouls,ms_start,ms_fin;
  unsigned long i;
  boolean level,last,plus;

  i=0;
  p=0;
  m=0;
  level=0;
  last=0;
  plus=0;

  
  /*Serial.print("T = ");
  Serial.println(t);
  Serial.print("ms = ");
  Serial.println(ms);*/
  while (m<500)
  {
    m=analogRead(A0);
   // Serial.println("attente présence doigt");
  }
  //Serial.println("fin du while");

  ms_start=millis();
  for(i=0;i<ms;i++)
  {
   if(analogRead(A0) > 650)
    {
      level=1;
      if(level!=last)
      {
        p++;
       #ifdef MODE_CHENILLE
        Chenille();
       #endif
       #ifdef MODE_CLIGNOTEMENT
        Clignotement();
       #endif
       #ifdef MODE_LED2
        LED_2();
       #endif
       #ifdef MODE_LED3
        LED_3();
       #endif
       #ifdef MODE_LED1
        LED_1(LED_NUMBER);
       #endif
       plus=1;
      }
      last=1;
      
    }
    else
    {
      last=0;
      //Serial.println("Pas de changement");
    }
    if(plus==1)
    {
       #ifdef MODE_CHENILLEP
        Chenille_a();
        delay(25);
        Chenille_b();
        delay(25);
        Chenille_c();
        delay(25);
        Chenille_d();
        delay(25);
        Chenille_e();
        delay(25);
        Chenille_f();
        delay(25);
        Chenille_g();
        delay(25);
        Chenille_h();
        delay(25);
        Chenille_i();
        delay(25);
        Chenille_j();
        delay(25);
        Chenille_k();
       #endif
       #ifdef MODE_CLIGNOTEMENTP
        Clignotement_a();
        delay(100);
        Clignotement_b();
        delay(100);
        Clignotement_a();
        delay(50);
        Clignotement_b();
       #endif
       #ifdef MODE_BATTEMENT
        Battement_a();
        delay(25);
        Battement_b();
        delay(25);
        Battement_c();
        delay(25);
        Battement_d();
        delay(25);
        Battement_e();
        delay(50);
        Battement_f();
        delay(25);
        Battement_g();
        delay(25);
        Battement_h();
        delay(25);
        Battement_i();
        delay(25);
        Battement_j();
       #endif
       plus=0;
    }
    else
    {
    delay(250);
    }
  }
  ms_fin=millis();
  duree=(ms_fin-ms_start)/1000;
  pouls=(p*60)/duree;
 /* Serial.print("battement");
  Serial.println(p);
  Serial.print("Durée de la mesure en seconde : ");
  Serial.println(duree);
  Serial.print("Pouls : ");
  Serial.println(pouls);*/
 return pouls;
}

