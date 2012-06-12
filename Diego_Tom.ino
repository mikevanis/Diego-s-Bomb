#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 2);

int x = 0;

int countdown[] = {9, 4, 6, 7, 2, 8, 0, 0, 0, 0} ;
int test[] = {2, 2, 8, 8, 8, 8, 8, 8, 8, 8};

void setup() {
  for (int m = 0; m < 2; m++) {
    lc.shutdown(m, false);
    lc.setIntensity(m, 15);
    lc.clearDisplay(m);
  } 
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop() {
  //iterateCountdown(9);
  
  for(int i=0; i<10; i++) {
    if(i>7) {
      printNumber(1, i-8, countdown[i]);
    }
    else {
      printNumber(0, i, countdown[i]);
    }
  }
  
  // Flick relay and wait
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  delay(900);

}

void iterateCountdown(int pos) {
  if(countdown[pos]>0) {
    countdown[pos]--;
  }
  else {
    countdown[pos] = 9;
    iterateCountdown(pos-1);
  }
}

void printNumber(int m, int d, int n) {  
  // get the segment data for this number
  int data[8];
  getNumberData(n,data);

  // set the segments
  for (int i = 0; i < 7; i++) {
    if (data[i] == 1) {
      lc.setLed(m,d,i,true);  
    } 
    else {
      lc.setLed(m,d,i,false);
    }
  }
}

void getNumberData(int n, int *data) {
  switch (n) {
  case 0:
    data[0] = 0;
    data[1] = 1;
    data[2] = 1;
    data[3] = 1;
    data[4] = 0;
    data[5] = 1;
    data[6] = 1;
    data[7] = 1;
    break; 
  case 1:
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 1;
    data[4] = 0;
    data[5] = 1;
    data[6] = 0;
    data[7] = 0;
    break; 
  case 2:
    data[0] = 0;
    data[1] = 0;
    data[2] = 1;
    data[3] = 1;
    data[4] = 1;
    data[5] = 0;
    data[6] = 1;
    data[7] = 1;
    break; 
  case 3:
    data[0] = 0;
    data[1] = 0;
    data[2] = 1;
    data[3] = 1;
    data[4] = 1;
    data[5] = 1;
    data[6] = 1;
    data[7] = 0;
    break; 
  case 4:
    data[0] = 0;
    data[1] = 1;
    data[2] = 0;
    data[3] = 1;
    data[4] = 1;
    data[5] = 1;
    data[6] = 0;
    data[7] = 0;
    break; 
  case 5:
    data[0] = 0;
    data[1] = 1;
    data[2] = 1;
    data[3] = 0;
    data[4] = 1;
    data[5] = 1;
    data[6] = 1;
    data[7] = 0;
    break; 
  case 6:
    data[0] = 0;
    data[1] = 1;
    data[2] = 1;
    data[3] = 0;
    data[4] = 1;
    data[5] = 1;
    data[6] = 1;
    data[7] = 1;
    break; 
  case 7:
    data[0] = 0;
    data[1] = 0;
    data[2] = 1;
    data[3] = 1;
    data[4] = 0;
    data[5] = 1;
    data[6] = 0;
    data[7] = 0;
    break; 
  case 8:
    data[0] = 1;
    data[1] = 1;
    data[2] = 1;
    data[3] = 1;
    data[4] = 1;
    data[5] = 1;
    data[6] = 1;
    data[7] = 1;
    break; 
  case 9:  
    data[0] = 0;
    data[1] = 1;
    data[2] = 1;
    data[3] = 1;
    data[4] = 1;
    data[5] = 1;
    data[6] = 1;
    data[7] = 0;
    break; 
  }
}



