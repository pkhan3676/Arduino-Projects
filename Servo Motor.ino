// Motor A pins
const int enA = 6;  // Enable pin for Motor A (PWM)
const int in1 = 7;   // Direction pin 1
const int in2 = 8;   // Direction pin 2

// Motor B pins
const int enB = 5;   // Enable pin for Motor B (PWM)
const int in3 = 2;   // Direction pin 3
const int in4 = 4;   // Direction pin 4

// Speed variable (0-255)
int motorSpeed = 150; // Adjust speed here

void setup() {
  // Set all pins as OUTPUT
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize motors OFF
  stopMotors();
}

void loop() {
  // Drive forward
  driveForward(motorSpeed);
  delay(2000); // Run forward for 2 seconds

  // Drive backward
  driveBackward(motorSpeed);
  delay(2000); // Run backward for 2 seconds

  // Stop motors
  stopMotors();
  delay(1000);
}

// Function to drive forward
void driveForward(int speed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

// Function to drive backward
void driveBackward(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

// Function to stop motors
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}