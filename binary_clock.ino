int hourLEDs_tens[] = {1,2};
int hourLEDs_ones[] = {3,4,5,6};

int minuteLEDs_tens[] = {7,8,9};
int minuteLEDs_ones[] = {10,11,12,13};

void setup() {
  for(int i = 1; i <= 13; i++) {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  cycleTime(1000);
}

void cycleTime(int _delay) {
 for(int hourT = 0; hourT <= 1; hourT++) {
    for(int hourO = 1; hourO <= 9; hourO++) {
      for(int minuteT = 0; minuteT <= 5; minuteT++) {
        for(int minuteO = 0; minuteO <= 9; minuteO++) {
          // need to find a way to reset after 12:59
          if(hourT == 1 && hourO == 2 && minuteT == 5 && minuteO == 9) {
           return; 
          }
          setTime(hourT, hourO, minuteT, minuteO);
          delay(_delay); // delay(1000*60) doesn't work?
        }
      }
    }
  } 
}

void setTime(int hourT, int hourO, int minuteT, int minuteO) {
 setHourTens(hourT);
 setHourOnes(hourO);
 setMinuteTens(minuteT);
 setMinuteOnes(minuteO); 
}

// methods below (modified) from
// http://www.multiwingspan.co.uk/arduino.php?page=led5
void setHourTens(byte numToShow)
{
  for (int i =0;i<2;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(hourLEDs_tens[i], HIGH); 
    }
    else
    {
      digitalWrite(hourLEDs_tens[i], LOW); 
    }
  }
}

void setHourOnes(byte numToShow)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(hourLEDs_ones[i], HIGH); 
    }
    else
    {
      digitalWrite(hourLEDs_ones[i], LOW); 
    }
  }
}

void setMinuteTens(byte numToShow)
{
  for (int i =0;i<3;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(minuteLEDs_tens[i], HIGH); 
    }
    else
    {
      digitalWrite(minuteLEDs_tens[i], LOW); 
    }
  }
}

void setMinuteOnes(byte numToShow)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(minuteLEDs_ones[i], HIGH); 
    }
    else
    {
      digitalWrite(minuteLEDs_ones[i], LOW); 
    }
  }
}

