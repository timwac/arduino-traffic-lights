
#include "TrafficLight.h"
TrafficLight lights1(3, 4, 5);
TrafficLight lights2(6, 7, 8);

#define PRED 9
#define PGREEN 10
#define BTNPRS 11

void setup() {
  pinMode(PRED, OUTPUT);
  pinMode(PGREEN, OUTPUT);
  pinMode(BTNPRS, INPUT);

  digitalWrite(PRED, HIGH);
  digitalWrite(PGREEN, LOW);

}

unsigned long toggledTime = 0;
int counter = 0;
bool isPedestrianWaiting = false;

void allowPedestrianCrossing(){
  //TODO Refactor out delays
   delay(1000);
    digitalWrite(PGREEN, HIGH);
    digitalWrite(PRED, LOW);
    delay(3000);
    digitalWrite(PGREEN, LOW);
    digitalWrite(PRED, HIGH);
    delay(1000);
    isPedestrianWaiting = false;
}
void loop() {

  if (digitalRead(BTNPRS) == HIGH) {
    isPedestrianWaiting = true
    ;
  }
  unsigned long timeElapsedSinceLastToggle = millis() - toggledTime;
  Serial.print(counter);
  if (timeElapsedSinceLastToggle > 1000) {
    switch (counter % 8) {
      case 0:
        lights1.goingRedAmber();
        counter++;
        toggledTime = millis(); 
        break;
      case 1:
        lights1.goingGreen();
        counter++;
        toggledTime = millis(); 
        break;
      case 2:
        lights1.stoppingAmber();
        counter++;
        toggledTime = millis(); 
        break;
      case 3:
        lights1.stoppingRed();
        counter++;
        toggledTime = millis(); 
        break;
      case 4:
        lights2.goingRedAmber();
        counter++;
        toggledTime = millis(); 
        break;
      case 5:
        lights2.goingGreen();
        counter++;
        toggledTime = millis(); 
        break;
      case 6:
        lights2.stoppingAmber();
        counter++;
        toggledTime = millis(); 
        break;
      case 7:
        lights2.stoppingRed();
        if (isPedestrianWaiting == true){
             allowPedestrianCrossing();
          }
        counter++;
        toggledTime = 0; 
        break;
      default:
        // statements
        break;
    }

  }
}
