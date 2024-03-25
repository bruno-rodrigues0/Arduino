#define r 1
#define g 2
#define b 3
#define btn 4
#define max 4

int ciclo = 0;

int btnStateDown = 0;
int btnStateUp = 0;

void setup(){
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(btn, INPUT);
}

void red(){
    digitalWrite(r, 1);
    digitalWrite(g, 0);
    digitalWrite(b, 0);
}

void green(){
    digitalWrite(r, 0);
    digitalWrite(g, 1);
    digitalWrite(b, 0);
}

void blue(){
    digitalWrite(r, 0);
    digitalWrite(g, 0);
    digitalWrite(b, 1);
}

void white(){
    digitalWrite(r, 1);
    digitalWrite(g, 1);
    digitalWrite(b, 1);
}

void setLed(){
    switch (ciclo)
    {
        case 0:
            red();
            break;
        
        case 1:
            green();
            break;
        
        case 2:
            blue();
            break;

        default:
            white();
            break;

    }

    ciclo++;
    if(ciclo == max){
        ciclo = 0;
    }

    btnStateDown = 0;
    btnStateUp = 0;
}

void verifyBtn(){
    if(digitalRead(btn) == HIGH){
        btnStateDown = 1;
        btnStateUp = 0;
    } else {
        btnStateUp = 1;
    }

    if(btnStateDown == 1 && btnStateUp == 1){
        btnStateDown = 0;
        btnStateUp = 0;
        setLed();
    }
}

void loop(){
    verifyBtn();
}
