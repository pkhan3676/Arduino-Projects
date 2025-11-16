// --- Global Constants and Variables ---

// Define the digital pin number used for input
int pin = 8;
// Variable to store the current digital reading (either HIGH or LOW)
int value = 0;
// Time delay in milliseconds between readings
int deltatime = 100;

// --- Setup Function: Runs once when the sketch starts ---

void setup() {
  // Initialize serial communication at 9600 bits per second (baud rate)
  Serial.begin(9600);
  
  // Set the specified pin (pin 8) as a digital input
  // This is where a sensor or switch will be connected
  pinMode(pin, INPUT);
}

// --- Loop Function: Runs repeatedly forever ---

void loop() {
  // 1. Read Input
  // Read the current digital state of the input pin (either 1/HIGH or 0/LOW)
  value = digitalRead(pin);
  
  // 2. Output Data
  // Print the value (0 or 1) to the Serial Monitor
  Serial.println(value);
  
  // 3. Pause
  // Wait for the duration defined by 'deltatime' (100 milliseconds) before looping again
  delay(deltatime);
}