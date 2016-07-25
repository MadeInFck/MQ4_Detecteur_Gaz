#include <EEPROM.h>

int val=0;
unsigned long temps;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(13,OUTPUT);
Serial.println("");
Serial.println("Initialisation du MQ-4");
temps=millis();
}

void loop() {
  

  if ((millis()-temps) < 5000) {
    if (val > 600) {
      digitalWrite(8,HIGH);
      digitalWrite(13,HIGH);
      //Serial.println("Détection haute");
    } else if (val < 400) {
      digitalWrite(8,LOW);
      digitalWrite(13,LOW);
      //Serial.println("Détection basse");
    }
  } else {
    val=analogRead(A0);
    EEPROM.write(0,val);
    Serial.println(val);
    temps=millis();
  }
  
}
