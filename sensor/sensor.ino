#include <hcsr04.h>

#define TRIG_P 2
#define ECHO_P 3
#define btn 7

int leds[] = {8, 9, 10, 11};
int registry = 4;


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

void loop(){

    float dist = hcsr04.distanceInMillimeters();
    
    Serial.println(dist);
    delay(300);
}

