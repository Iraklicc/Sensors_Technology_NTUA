/*
  parakato einai o kwdikas gia na anavei to S-O-S 
  sto led tou Arduino me kwdika Mors

  Exei 2 sinartiseis gia to gramma S kai gia 
  to gramma O antistoixa, oi opoies kalountai 
  sximatizontas tin zitoumeni leksi.  
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// gramma S
void S() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  delay(1000);
}

// gramma O
void O() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  delay(1000);
}

void loop() {
  S();
  O();
  S();
  delay(2000); // ena delay gia na diaxwrizetai kathe fora h leksi
}
