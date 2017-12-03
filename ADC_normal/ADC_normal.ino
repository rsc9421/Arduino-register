void setup() {
/*
UCSR0B=0;UCSR0A=0;UCSR0C=0;
UCSR0B|=0b00011000;
UCSR0C|=0b00000110;
UBRR0=8;
*/
Serial.begin(115200);
ADCSRA=0;ADMUX=0;
ADMUX|=0b01000000;//canal=ADC0, Vref=AVcc
ADCSRA|=0b10000111;//ADC enable, prescaler=128
}

void loop() {
ADCSRA|=0b01000000;
while(ADCSRA&0b01000000);
Serial.println(ADC);
delay(500);
}
