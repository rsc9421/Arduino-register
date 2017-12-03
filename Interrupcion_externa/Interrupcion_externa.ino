void setup() {
 DDRB|=0b00100000;//pb5 salida(led arduino uno)
 DDRD|=0b00000000;//pc0 entrada
 PORTD|=0b00000100;//habilita pull up en pc0
 EIMSK|=0b00000001;//habilita interrupcion en pin INT0
 sei();
}

void loop() {

}
ISR(INT0_vect){
PORTB^=0b00100000;
delay(1000);
  }
