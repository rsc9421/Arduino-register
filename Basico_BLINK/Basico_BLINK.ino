void setup() {
DDRB|=0b00100000;//pb5 como salida(led pin arduino uno)
//pinMode(13,OUTPUT);
}

void loop() {

PORTB|=0b00100000;
delay(500);
PORTB&=~(0b00100000);
delay(500);

/*
digitalWrite(13,HIGH);
delay(400);
digitalWrite(13,LOW);
delay(400);
*/
}
