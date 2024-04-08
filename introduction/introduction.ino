#include <hcsr04.h>
#include <SoftwareSerial.h>

SoftwareSerial btn_serial (11, 12);


#define TRIG_P 2
#define ECHO_P 3
#define btn 7

int leds[] = {8, 9, 10, 11};
int registry = 4;

int btnStateDown = 0;
int btnStateUp = 0;


HCSR04 hcsr04(TRIG_P, ECHO_P, 20, 4000);

void setup(){   
    for(int i = 0; i < 4; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
    pinMode(btn, INPUT);
    pinMode(registry, OUTPUT);
    Serial.begin(9600);
}

void  checkDistance(float distance){
   
    if (distance < 100){
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], LOW);
    } else if(distance > 1000 && distance < 2000){
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], LOW);
    } else if(distance > 2000 && distance < 3000){
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], LOW);
    } else if(distance > 3000 && distance < 3900){
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], LOW);
     } else if(distance > 3900){
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
     }
}

void setRegistry(float distance){
  btnStateDown = 0;
  btnStateUp = 0;
  Serial.print(distance);
  Serial.println(" milimetros.");
  delay(400);
}

void loop(){

    float dist = hcsr04.distanceInMillimeters();

    checkDistance(dist);

    if(digitalRead(btn) == HIGH){
      btnStateDown = 1;
      btnStateUp = 0;
      digitalWrite(registry, HIGH);
        
    } else {
      btnStateUp = 1;
      digitalWrite(registry, LOW);
    }

    if(btnStateDown == 1 && btnStateUp == 1){
      setRegistry(dist);
    }

    delay(10);
}

