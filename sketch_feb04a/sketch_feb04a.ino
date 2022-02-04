void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 4095; //15624 * 3 / 10 ~=4096 - 1
  TCCR1B = TCCR1B | (1 << WGM12);
  TCCR1B = TCCR1B | (1 << CS12) | (1 << CS10);
  TIMSK1 = TIMSK1 | (1 << OCIE1A);
  sei();
}
  
ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void loop() {
  // put your main code here, to run repeatedly:

}
