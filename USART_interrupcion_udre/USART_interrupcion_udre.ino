void putch(uint8_t ch){
while(!(UCSR0A&0b00100000));//listo para enviar nuevo dato?
UDR0=ch;  
}
void putstr(char* string){
   while (*string){
   putch(*string);
   string++;}
}
char* getstr(){
  char i;char r1[30];
  for(i=0;i<30;i++){
  while ( !(UCSR0A & (1<<RXC0)) );
    r1[i]=UDR0;
    if(r1[i]=='q'){r1[i]='\0';break;}
  }
  return* r1;}
uint8_t getch(){
while ( !(UCSR0A & (1<<RXC0)) );
return UDR0; 
  }
volatile char hay_algo=0;//variable global, volatile para interrupciones
void setup() {
UCSR0B=0;UCSR0A=0;UCSR0C=0;
UCSR0B|=0b10111000;//habilitar RX y TX
UCSR0C|=0b00000110;//modo asincrono, sin paridad,stop bit=1, data bit=8
UBRR0=3;//250000 baudios
//formula=>UBRR0=fosc/(16*baudios) si esta en modo asincrono
sei();
putstr("escribir a\n");
}

void loop() {

}
ISR(USART_RX_vect){
  hay_algo=UDR0;
  }
ISR(USART_UDRE_vect){
if(hay_algo=='a'){putstr("interrupcion en UDRE!\n hace practicamente lo mismo que interrupcion en TX\n usar esta preferentemente\n");hay_algo=0;}
  }
