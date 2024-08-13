const int inputPin = 2;  // Pin digital donde se leera el valor de entrada

void setup() {
  // Inicializar el pin como entrada
  pinMode(inputPin, INPUT);

  // Iniciar comunicacion serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del pin de entrada
  int inputValue = digitalRead(inputPin);

  // Imprimir el valor en el monitor serial
  Serial.println(inputValue);

  // Esperar un pequeño intervalo de tiempo para no saturar el monitor serial
  //delay(10);
}

