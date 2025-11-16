/*
  HC-SR04 Ultrasonic Sensor Distance Reader with Proximity Alert
  "Ultrasonic" refers to sound waves that have a frequency higher than the upper limit of human hearing, which is typically around 20 kilohertz (kHz)
  
  Reads distance in millimeters (mm) and prints an alert 
  if an object is closer than 45 mm (4.5 cm).

  Wiring Connections:
  HC-SR04 VCC -> Arduino 5V
  HC-SR04 Gnd -> Arduino GND
  HC-SR04 Trig -> Arduino Digital Pin 9
  HC-SR04 Echo -> Arduino Digital Pin 10
*/

// --- Pin Definitions ---
const int trigPin = 9;  // Trigger Pin (OUTPUT) Trigger Pin (OUTPUT) // trigger is the sound wave which emitts from the US Sensor
const int echoPin = 10; // Echo Pin (INPUT) Echo is the receiver of the sensor which receives the sound waves receiving after hitting the object

// --- Global Variables ---
long duration;          // Duration of the sound wave travel in microseconds (µs).
long distanceMm;        // Calculated distance in millimeters (mm).
const int ALERT_DISTANCE_MM = 45; // Set the alert threshold to 45 mm (4.5 cm).

void setup() {
  // --- Pin Configuration ---
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  
  // --- Serial Communication Setup ---
  Serial.begin(9600); // Baud Rate for communication
  Serial.println("--- HC-SR04 Sensor Running with 45 mm Alert ---");
}

void loop() {
  // --- 1. Sensor Triggering Sequence ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // this is the time which are used to set the signal LOW for stablizing the signal

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // this is the time which are used to set the signal HIGH for emit Sound Waves
  digitalWrite(trigPin, LOW);

  // --- 2. Measure the Echo Time ---
  duration = pulseIn(echoPin, HIGH);

  // --- 3. Calculate the Distance in Millimeters (mm) ---
  
  // First, calculate distance in centimeters: distanceCm = duration / 58
  // Then, multiply by 10 to get millimeters: distanceMm = (duration / 58) * 10
  // Simplified: The speed of sound is approx. 343 m/s or 0.343 mm/µs.
  // The conversion factor becomes: (1 / 0.343) * 2 ≈ 5.8 
  // We use the integer calculation for simplicity and efficiency:
  distanceMm = (duration * 10) / 58; // 58 is the calculated value when we calculate the speed of sound in round trip
  // Alternatively, you can use floating-point math for slightly higher accuracy:
  // float distanceFloat = duration * 0.1715; // 34300 cm/s -> 0.0343 cm/µs. Speed of sound is 0.0343 * 10 = 0.343 mm/µs.
  // distanceMm = distanceFloat;

  // --- 4. Output the Result ---
  Serial.print("Distance: ");
  Serial.print(distanceMm);
  Serial.print(" mm");

  // --- 5. Conditional Alert Check ---
  // If the measured distance is LESS THAN the defined threshold...
  if (distanceMm < ALERT_DISTANCE_MM) {
    // ...print the warning message on the same line.
    Serial.println(" *** DANGER! OBSTACLE TOO CLOSE! ***");
    // Optionally, you can add code here to trigger an LED or buzzer.
  } else {
    // ...otherwise, just print a standard newline.
    Serial.println();
  }

  // --- 6. Delay for Next Reading ---
  delay(500); 
}
