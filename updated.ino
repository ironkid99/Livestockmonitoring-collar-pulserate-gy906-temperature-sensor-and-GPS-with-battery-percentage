#include <Wire.h>
#include <Adafruit_MLX90614.h>
//#include <WireKinetis.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Wire.setSCL(20);  
//Wire.setSDA(21);

double temp_amb;
double temp_obj;

#define SDA_PIN 20
#define SCL_PIN 21
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mlx.begin();
  
  Wire.begin(SDA_PIN , SCL_PIN);
  //Wire.begin(SDA_PIN , SCL_PIN);

  Serial.println("Temperature Sensor MLX90614");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
}
void loop() {
  // put your main code here, to run repeatedly:
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();

  Serial.print("Room Temp = ");
  Serial.println(temp_amb);
  Serial.print("Object temp = ");
  Serial.println(temp_obj);
  
  delay(1000);
}
.