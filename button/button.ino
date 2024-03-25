#define led 4
#define led2 2
#define led3 7

#define btn 3

int btnStateDown = 0;
int btnStateUp = 0;

void setState(){
    if(digitalRead(led) == HIGH){
        digitalWrite(led, LOW);
        delay(50);
        digitalWrite(led2, LOW);
        delay(50);
        digitalWrite(led3, LOW);

    } else {
        digitalWrite(led, HIGH);
        delay(50);
        digitalWrite(led2, HIGH);
        delay(50);
        digitalWrite(led3, HIGH);
    }

    return;
}

void keyUp(){
    if(btnStateDown == 1 && btnStateUp == 1){
        btnStateDown = 0;
        btnStateUp = 0;
        setState();
    }
}

void setup(){
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(btn, INPUT);
}

void loop(){
    if(digitalRead(btn) == HIGH){
        btnStateDown = 1;
        btnStateUp = 0;
    } else {
        btnStateUp = 1;
        keyUp();
    }
}