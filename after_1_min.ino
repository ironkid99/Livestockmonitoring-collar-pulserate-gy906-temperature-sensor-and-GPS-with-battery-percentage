const int heartRatePin = 26; 
volatile unsigned int pulseCount = 0;
volatile boolean pulseDetected = false;
unsigned long lastPulseTime = 0;
const unsigned long debounceInterval = 770;  

void handlePulse() {
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime > debounceInterval) {
    pulseCount++;
    pulseDetected = true;
    lastPulseTime = currentTime;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(heartRatePin, INPUT);
  attachInterrupt(digitalPinToInterrupt(heartRatePin), handlePulse, RISING);
}

void loop() {
  delay(60000); 

  detachInterrupt(digitalPinToInterrupt(heartRatePin));  // Disable interrupts
  unsigned int pulseCountCopy = pulseCount;
  pulseCount = 0;
  attachInterrupt(digitalPinToInterrupt(heartRatePin), handlePulse, RISING);  
  
  // Serial.print("Analog Signal Value: ");
  // Serial.println(analogRead(heartRatePin));

  Serial.print("Pulses per minute: ");
  Serial.println(pulseCountCopy);
}
