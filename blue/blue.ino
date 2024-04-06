// direções possivel (como o bluetooth so retorna um char, associei os valores a nomes para ficar mais facil de ler)
#define right a 
#define left d 
#define down s 
#define up w 

int gates[4] = {3, 4, 7, 8}; // portas a serem controladas pelo bluetooth
int motores[4] = {5, 6, 9, 10}; // motores

void setup(){

    // output pinMode
    for(int i = 0; i < 4; i++){
        pinMode(gates[i], OUTPUT);
        pinMode(motores[i], OUTPUT);
    }

    // input pinMode
    // for(int i = 0; i < 3; i++){
    //     pinMode(gates[i], INPUT);
    // }

    Serial.begin(9600); 
}

void virarEsquerda(){
    digitalWrite(motores[/* motores da direita */]);
}
void acelerar(){
    for(int i = 0; i < 4; i++){
        digitalWrite(motores[i]); /* todos os motores */ 
    }
}
void virarDireita(){
    digitalWrite(motores[/* motores da esquerda */]);
}
void re(){
    digitalWrite(motores[/* como q faz o motor girar pra tras????????? */]);
}

void loop(){
    
    if(Serial.read()){ // Se a porta serial estiver recebendo um valor
        char value = Serial.read(); // recebe a entrada de valor do bluetooth
       
        do {
            switch (value)
            {
            case up:
                acelerar();
                break;
            
            case down:
                re();
                break;

            case left:
                virarEsquerda();
                break;

            case right: 
                virarDireita();
                break;
                
            default: // caso esteja tudo configurado, nem vai cair no default
                break;
            } 
        } while (value);
    };
}


