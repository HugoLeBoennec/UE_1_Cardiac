
void Chenille(){
        switch (ledPhase)
        {
          case 0 : digitalWrite (11, LOW); digitalWrite (2, HIGH); ledPhase++; break;
          case 1 : digitalWrite (2, LOW); digitalWrite (3, HIGH); ledPhase++; break;
          case 2 : digitalWrite (3, LOW); digitalWrite (4, HIGH); ledPhase++; break;
          case 3 : digitalWrite (4, LOW); digitalWrite (5, HIGH); ledPhase++; break;
          case 4 : digitalWrite (5, LOW); digitalWrite (6, HIGH); ledPhase++; break;
          case 5 : digitalWrite (6, LOW); digitalWrite (7, HIGH); ledPhase++; break;
          case 6 : digitalWrite (7, LOW); digitalWrite (8, HIGH); ledPhase++; break;
          case 7 : digitalWrite (8, LOW); digitalWrite (9, HIGH); ledPhase++; break;
          case 8 : digitalWrite (9, LOW); digitalWrite (10, HIGH); ledPhase++; break;
          case 9 : digitalWrite (10, LOW); digitalWrite (11, HIGH); ledPhase = 0; break;
        }
}
void Clignotement(){
   if (ledPhase==0)
   {
        digitalWrite (11, HIGH);
        digitalWrite (2, HIGH);
        digitalWrite (3, HIGH);
        digitalWrite (4, HIGH);
        digitalWrite (5, HIGH);
        digitalWrite (6, HIGH);
        digitalWrite (7, HIGH);
        digitalWrite (8, HIGH);
        digitalWrite (9, HIGH);
        digitalWrite (10, HIGH);

        ledPhase=1;
   }
   else
   {
        digitalWrite (11, LOW);
        digitalWrite (2, LOW);
        digitalWrite (3, LOW);
        digitalWrite (4, LOW);
        digitalWrite (5, LOW);
        digitalWrite (6, LOW);
        digitalWrite (7, LOW);
        digitalWrite (8, LOW);
        digitalWrite (9, LOW);
        digitalWrite (10, LOW);

        ledPhase=0;
   }
}
void LED_2(){
  if (ledPhase==0)
   {
        digitalWrite (2,LOW);
        digitalWrite (4,LOW);
        digitalWrite (6,LOW);
        digitalWrite (8,LOW);
        digitalWrite (10,LOW);
        digitalWrite (11,HIGH);
        digitalWrite (3,HIGH);
        digitalWrite (5,HIGH);
        digitalWrite (7,HIGH);
        digitalWrite (9,HIGH);

        ledPhase=1;
   }
   else
   {
        digitalWrite (11, LOW);
        digitalWrite (3, LOW);
        digitalWrite (5, LOW);
        digitalWrite (7, LOW);
        digitalWrite (9, LOW);
        digitalWrite (2,HIGH);
        digitalWrite (4,HIGH);
        digitalWrite (6,HIGH);
        digitalWrite (8,HIGH);
        digitalWrite (10,HIGH);

        ledPhase=0;
   }
}
void LED_3(){
  if (ledPhase==0)
   {
        digitalWrite (3,LOW);
        digitalWrite (6,LOW);
        digitalWrite (9,LOW);
        digitalWrite (11,HIGH);
        digitalWrite (4,HIGH);
        digitalWrite (7,HIGH);
        digitalWrite (10,HIGH);

        ledPhase=1;
   }
   else if (ledPhase==1)
   {
        digitalWrite (11,LOW);
        digitalWrite (4,LOW);
        digitalWrite (7,LOW);
        digitalWrite (10,LOW);
        digitalWrite (2,HIGH);
        digitalWrite (5,HIGH);
        digitalWrite (8,HIGH);

        ledPhase=2;
   }
   else
   {
        digitalWrite (2,LOW);
        digitalWrite (5,LOW);
        digitalWrite (8,LOW);
        digitalWrite (3,HIGH);
        digitalWrite (6,HIGH);
        digitalWrite (9,HIGH);

        ledPhase=0;
   }    
}

void LED_1(int led){
  if (ledPhase==0)
   {
        digitalWrite (led,HIGH);
        ledPhase=1;
   }
   else
   {
        digitalWrite (led,LOW);
        ledPhase=0;
   }    
}

