int pin = A0;         //Pin εισόδου αισθητήρα Hall
int vcc = 5000;       //Τάση τροφοδοσίας αισθητήρα Hall σε mV
int green_pin = 3;

int value;            //Μεταβλητή τιμής στο εύρος 0-1023
int voltage;          //Μεταβλητή τάσης στο εύρος 0-Vcc
int field;            //Μεταβλητή τιμής πεδίου σε mT

void setup() {
  Serial.begin(9600); //Έναρξη σειριακής επικοινωνίας
  pinMode(green_pin, OUTPUT);
}

void loop() {
  value = analogRead(pin); //Ανάγνωση τιμής του αισθητήρα Hall
  voltage = value * (vcc / 1024.0); //Μετατροπή σε τιμή τάσης (mV)
  field = map(voltage, 1000, 4000, -100, 100); //Υπολογισμός μαγνητικού πεδίου (mT)
  field = field - 1;


  int brightness = map(abs(field), 0, 100, 0, 255);
  brightness = constrain(brightness, 0, 255); // ασφάλεια
  analogWrite(green_pin, brightness);



  //Εμφάνιση αποτελεσμάτων
  Serial.print("Value: ");
  Serial.print(value);
  Serial.print("\t");
  Serial.print(voltage);
  Serial.println(" mV");
  Serial.print("Magnetic Field: ");
  Serial.print(field);
  Serial.println(" mT");
  Serial.println("==========================");
  delay(100); //Λήψη νέας τιμής κάθε 0,1sec
}
