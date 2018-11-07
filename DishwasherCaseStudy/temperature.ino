#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
int ser=1;// To find Overflow
int out=10;// To perform blink operation
int sense=0;
int mot=12;// For the motor indicator
int motorPin = 9;

void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  pinMode(out, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.println("Arduino Digital Temperature // Serial Monitor Version"); //Print a message
  sensors.begin();
}

void loop(void)
{ 
    
  if(analogRead(ser)) // To find if the water level touches the very end 
  {
    digitalWrite(out,HIGH);
  sensors.requestTemperatures();  
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));// Prints the temperature of the water
  delay(100);
  if(sensors.getTempCByIndex(0)>32)
    {
      int speed=70;
       analogWrite(motorPin, speed); // Makes the motor to rotate
       digitalWrite(mot,HIGH);
    }
  }
  else
  {
    sensors.requestTemperatures();  
     Serial.print("Temperature is: ");
    Serial.println(sensors.getTempCByIndex(0));// Prints the temperature of the water
    digitalWrite(out,LOW);
    delay(100);
    if(sensors.getTempCByIndex(0)>32)
    {
      int speed=70;
       analogWrite(motorPin, speed);// Makes the motor to rotate
       digitalWrite(mot,HIGH);
    }
  }
  
}
