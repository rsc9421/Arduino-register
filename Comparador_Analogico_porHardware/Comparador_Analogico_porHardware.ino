//cuando AIN0(pin 6) > AIN1(pin 7) => interrupcion
void setup() {
DDRB|=0b00100000;
ACSR|=0b00001000;//habilitamos interr. comparador
sei();
}

void loop() {
}

ISR(ANALOG_COMP_vect){
//chequeamos si por flanco de subida o bajada
 if (ACSR & (1<<ACO)) PORTB|=0b00100000;
  else PORTB&=~(0b00100000);;
}

