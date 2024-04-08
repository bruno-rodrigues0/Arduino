#include <hcsr04.h>

#define TRIG_P 2
#define ECHO_P 3
#define led 7

int registry = 4;

HCSR04 hcsr04(TRIG_P, ECHO_P, 20, 4000);

void setup(){   
    pinMode(led, OUTPUT);
    pinMode(registry, OUTPUT);
    Serial.begin(9600);
}

void loop(){

    float dist = hcsr04.distanceInMillimeters();
    
    Serial.println(dist);

    digitalWrite(led, HIGH);
    delay(80);
    digitalWrite(led, LOW);
    delay(300);
}

