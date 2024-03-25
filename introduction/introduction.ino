int led=10;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  digitalWrite(led, HIGH);
  delay(7000);
  digitalWrite(led, LOW);
  delay(2000);
}