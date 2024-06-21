const int sensorPin = A0;         // Analog pin connected to the smoke sensor
const float VCC = 5.0;            // Arduino supply voltage
const float R_LOAD = 10.0;        // Resistance of load resistor in kilo-ohms
const float RO_CLEAN_AIR = 9.83;  // Resistance of sensor in clean air in kilo-ohms
const float SMOKE_THRESHOLD = 0.1;  // Threshold smoke concentration in PPM
const int ledPin = 13;            // Pin connected to the LED

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  // Read analog value from smoke sensor
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (VCC / 1023.0);
  float RS = ((VCC - voltage) * R_LOAD) / voltage;
  float ratio = RS / RO_CLEAN_AIR;
  float ppm = pow(10, ((log10(ratio) - 0.3624) / -0.3657));

  // Print smoke concentration to serial monitor
  Serial.print("Smoke Concentration (PPM): ");
  Serial.println(ppm);

  // Check if smoke concentration exceeds threshold
  if (ppm >= SMOKE_THRESHOLD) {
    Serial.println("Smoke Detected!");
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    Serial.println("Smoke Not Detected");
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  delay(1000); // Delay for stability
}
