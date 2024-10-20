// ВТЫКАЙ ВО ВТОРОЙ ПОРТ!!!

#define dir1 9
#define stp1 8
#define dir2 7
#define stp2 6
#define dir3 5
#define stp3 4


char user_input;
int x;
int y;
int n=2000;  //н=1000 - примерно оборот
int state;

void setup() {
  test(stp1, dir1);
  test(stp2, dir2);
  test(stp3, dir3);
}


void test(int stp, int dir){
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  resetEDPins(stp, dir); //Set pins to default states
  StepForwardDefault(stp, dir);
  resetEDPins(stp, dir);
}

void loop() {
      // StepForwardDefault();
      // ReverseStepDefault();
      // ForwardBackwardStep();
      // resetEDPins();
}

//Reset Easy Driver pins to default states
void resetEDPins(int stp, int dir)
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
}

//Default microstep mode function
void StepForwardDefault(int stp, int dir)
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
void ReverseStepDefault(int stp, int dir)
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
void ForwardBackwardStep(int stp, int dir)
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
