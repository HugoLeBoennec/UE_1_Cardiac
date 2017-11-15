
void Chenille(){
        digitalWrite (1, HIGH);
        delay (light_time);
        digitalWrite (1, LOW);
        
        digitalWrite (2, HIGH);
        delay (light_time);
        digitalWrite (2, LOW);
        
        digitalWrite (3, HIGH);
        delay (light_time);
        digitalWrite (3, LOW);
        
        digitalWrite (4, HIGH);
        delay (light_time);
        digitalWrite (4, LOW);
        
        digitalWrite (5, HIGH);
        delay (light_time);
        digitalWrite (5, LOW);
        
        digitalWrite (6, HIGH);
        delay (light_time);
        digitalWrite (6, LOW);
        
        digitalWrite (7, HIGH);
        delay (light_time);
        digitalWrite (7, LOW);
        
        digitalWrite (8, HIGH);
        delay (light_time);
        digitalWrite (8, LOW);
        
        digitalWrite (9, HIGH);
        delay (light_time);
        digitalWrite (9, LOW);
        
        digitalWrite (10, HIGH);
        delay (light_time);
        digitalWrite (10, LOW);
}
void Clignotement(){
        digitalWrite (1, HIGH);
        digitalWrite (2, HIGH);
        digitalWrite (3, HIGH);
        digitalWrite (4, HIGH);
        digitalWrite (5, HIGH);
        digitalWrite (6, HIGH);
        digitalWrite (7, HIGH);
        digitalWrite (8, HIGH);
        digitalWrite (9, HIGH);
        digitalWrite (10, HIGH);
        delay (light_time);
        digitalWrite (1, LOW);
        digitalWrite (2, LOW);
        digitalWrite (3, LOW);
        digitalWrite (4, LOW);
        digitalWrite (5, LOW);
        digitalWrite (6, LOW);
        digitalWrite (7, LOW);
        digitalWrite (8, LOW);
        digitalWrite (9, LOW);
        digitalWrite (10, LOW);
        delay (light_time);
}
void LED_2(){
          digitalWrite (1,HIGH);
        digitalWrite (3,HIGH);
        digitalWrite (5,HIGH);
        digitalWrite (7,HIGH);
        digitalWrite (9,HIGH);
        delay(light_time);
        digitalWrite (1, LOW);
        digitalWrite (3, LOW);
        digitalWrite (5, LOW);
        digitalWrite (7, LOW);
        digitalWrite (9, LOW);
        digitalWrite (2,HIGH);
        digitalWrite (4,HIGH);
        digitalWrite (6,HIGH);
        digitalWrite (8,HIGH);
        digitalWrite (10,HIGH);
        delay(light_time);
        digitalWrite (2,LOW);
        digitalWrite (4,LOW);
        digitalWrite (6,LOW);
        digitalWrite (8,LOW);
        digitalWrite (10,LOW);
}
void LED_3(){
          digitalWrite (1,HIGH);
        digitalWrite (4,HIGH);
        digitalWrite (7,HIGH);
        digitalWrite (10,HIGH);
        delay (light_time);
        digitalWrite (1,LOW);
        digitalWrite (4,LOW);
        digitalWrite (7,LOW);
        digitalWrite (10,LOW);
        digitalWrite (2,HIGH);
        digitalWrite (5,HIGH);
        digitalWrite (8,HIGH);
        delay (light_time);
        digitalWrite (2,LOW);
        digitalWrite (5,LOW);
        digitalWrite (8,LOW);
        digitalWrite (3,HIGH);
        digitalWrite (6,HIGH);
        digitalWrite (9,HIGH);
        delay(light_time);
        digitalWrite (3,LOW);
        digitalWrite (6,LOW);
        digitalWrite (9,LOW);
}

