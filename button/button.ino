#define led 4
#define btn 3

int btnStateDown = 0;
int btnStateUp = 0;

void setState(){
    if(digitalRead(led) == HIGH){
        digitalWrite(led, LOW);
    } else {
        digitalWrite(led, HIGH);
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