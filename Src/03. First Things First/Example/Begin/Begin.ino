#define STATUS_LED  13

void setup() {
  pinMode(STATUS_LED, OUTPUT);
}

void loop() {
  
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
  
  digitalWrite(STATUS_LED, LOW);
  delay(1000);
  
}
