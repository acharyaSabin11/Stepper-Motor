// Define pin connections & motor's steps per revolution
const int dirPin = 18;
const int stepPin = 5; 
const int fullRev = 800;
const int inputPin = 2;
const int ledPin = 21;
const int switchPin = 19;
int analogIn = 0;

void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(115200);
  delay(1000);
}
void loop()
{
  int switchState = digitalRead(switchPin);
  // Serial.println(switchState);
  if(switchState)
  {
  digitalWrite(ledPin, HIGH);
    // Set motor direction counter-clockwise
	digitalWrite(dirPin, LOW);

	// Spin motor slowly
	for(int x = 0; x < fullRev; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(2000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(2000);
    analogIn = analogRead(inputPin);
    Serial.print((90.0/800) * (x+1));
    Serial.print(", ");
    Serial.println(analogIn);
	}

  digitalWrite(dirPin, HIGH);

	// Spin motor slowly
	for(int x = 0; x < fullRev; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(2000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(2000);
    analogIn = analogRead(inputPin);
    Serial.print(90-(90.0/800) * (x+1));
    Serial.print(", ");
    Serial.println(analogIn);
	}
  digitalWrite(ledPin, LOW);
  }

}