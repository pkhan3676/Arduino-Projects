
void setup() {
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
  int inputState = digitalRead(4);
  Serial.println(inputState);  // Use println, not print
  delay(100);
}
