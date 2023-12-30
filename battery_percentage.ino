const int batteryPin = 34;  // Analog pin connected to the battery voltage divider

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the raw analog value
  int rawValue = analogRead(batteryPin);

  // Convert the raw value to voltage (assuming 5V reference for Arduino Uno)
  float voltage = rawValue * (5.0 / 1023.0);
	//float voltage = (rawValue / 4095.0) * 3.7 * 2;
  // Calculate the battery percentage based on the battery characteristics
  int batteryPercentage = map(voltage, 1.7, 4.0 , 0, 100);
  batteryPercentage = constrain(batteryPercentage, 0, 100);  // Ensure the value is within 0-100 range

  // Print the results
  Serial.print("Battery Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Battery Percentage: ");
  Serial.print(batteryPercentage);
  Serial.println(" %");

  delay(5000);  // Delay for 5 seconds before the next reading
}