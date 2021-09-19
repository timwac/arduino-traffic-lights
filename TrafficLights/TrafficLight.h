/*
  TrafficLight.h - Library for a set of Traffic Lights.
*/
#ifndef TrafficLight_h
#define TrafficLight_h

#include "Arduino.h"

class TrafficLight
{
  public:
    TrafficLight(int red, int amber, int green);
    void goingRedAmber();
    void goingGreen();
    void stoppingAmber();
    void stoppingRed();
  private:
    int _red; int _amber; int _green;
};

#endif
