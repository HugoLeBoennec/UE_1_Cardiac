#include "coeur.h"
#include "param.h"

void setup() {
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);

  light_time = 50;
}

void loop(){
  //if (pulse==1){
    #ifdef MODE_CHENILLE
       Chenille();       
    #elif MODE_CLIGNOTEMENT
      Clignotement();
    #elif MODE_LED2
      LED_2();
    #elif MODE_LED3
      LED_3();
    #endif
    //}  
  }
 /*else {
   
 }*/
