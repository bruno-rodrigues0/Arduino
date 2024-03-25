#define led 8
int key;

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(9600);
  	Serial.println("aperte Space para ligar o led");
}

void loop() {

    if(Serial.available())
    {
        key = Serial.read();
        if (key == 86)
        {
            digitalWrite(led, HIGH);
        }
        if (key == 88)
        {
            digitalWrite(led, LOW);
        }
        
    }
}