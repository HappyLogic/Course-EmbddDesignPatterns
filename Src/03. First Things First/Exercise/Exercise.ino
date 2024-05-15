#define MOTOR_SWITCH       4
#define MOTOR_DRIVE        5


void setup()
{
  pinMode(MOTOR_SWITCH, INPUT);
  pinMode(MOTOR_DRIVE, OUTPUT);
}

void loop()
{
  
  if (digitalRead(MOTOR_SWITCH))
  {
    digitalWrite(MOTOR_DRIVE, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_DRIVE, LOW);
  }
  
  delay(100);
}
