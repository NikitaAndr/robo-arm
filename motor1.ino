// ВТЫКАЙ ВО ВТОРОЙ ПОРТ!!!

#define stp 9
#define dir 8
#define EN  7

char user_input;
int x;
int y;
int n=100;  //н=1000 - примерно оборот
int state;

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins(); //Set pins to default states
  digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
  StepForwardDefault()
  ReverseStepDefault();
  ForwardBackwardStep();
  resetEDPins();
}

void loop() {
      // digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
      // StepForwardDefault();
      // ReverseStepDefault();
      // ForwardBackwardStep();
      // resetEDPins();
}

//Reset Easy Driver pins to default states
void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(EN, HIGH);
}

//Default microstep mode function
void StepForwardDefault()
{
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 0; x<n; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}

//Reverse default microstep mode function
void ReverseStepDefault()
{
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 0; x<n; x++)  //Loop the stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}

//Forward/reverse stepping function
void ForwardBackwardStep()
{
  for(x= 1; x<n; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(dir);
    if(state == HIGH)
    {
      digitalWrite(dir, LOW);
    }
    else if(state ==LOW)
    {
      digitalWrite(dir,HIGH);
    }
    
    for(y=0; y<n; y++)
    {
      digitalWrite(stp,HIGH); //Trigger one step
      delay(1);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
  }
}
