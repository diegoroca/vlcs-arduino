#define LED_PIN 13  // Pin del LED 
#define BLINK_FREQUENCY 1000  // Frecuencia de parpadeo en Hz (MAX 8MHz MIN 1Hz)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  setupBlinker1(BLINK_FREQUENCY);
}

void loop() {
  // Main loop vacío el LED es controlado por el timer de interrupcion}
}

void setupBlinker1(int frequency) {
  // Desabilitar las interrupciones globalmente
  cli();

  // Calcular el valor de comparación para lograr la frecuencia deseada
  int compareMatch = (16000000 / (2 * 8 * frequency)) - 1;

  // Resetear los registros de control
  TCCR1A = 0;
  TCCR1B = 0;

  // Establecer el valor de comparación
  OCR1A = compareMatch;

  // Establecer modo CTC (Clear Timer on Compare match)
  TCCR1B |= (1 << WGM12);

  // Establecer prescaler a 8
  TCCR1B |= (1 << CS11);

  // Habilitar el timer de interrupcion por comparacion
  TIMSK1 |= (1 << OCIE1A);

  // Habilitar las interrpciones globalmente
  sei();
}

// Rutina de servicion de interrupción por comparacion del Timer1  
ISR(TIMER1_COMPA_vect) {
  static bool ledState = LOW;

  // Conmutar el estado del LED
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
}
