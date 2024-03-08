#define led_red 8
#define led_yel 9
#define led_gre 10

void setup()
{
    pinMode(led_red, OUTPUT);
    pinMode(led_yel, OUTPUT);
    pinMode(led_gre, OUTPUT);
}

void closed(int timer){
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yel, LOW);
    digitalWrite(led_gre, LOW);
    delay(timer * 1000);
    return;
}

void open(int timer){
    digitalWrite(led_red, LOW);
    digitalWrite(led_yel, LOW);
    digitalWrite(led_gre, HIGH);
    delay(timer * 1000);
    return;
}

void attention(int timer){
    digitalWrite(led_red, LOW);
    digitalWrite(led_yel, HIGH);
    digitalWrite(led_gre, LOW);
    delay(timer * 1000);
    return;
}

void loop()
{
    closed(7);
    open(9);
    attention(3);
}