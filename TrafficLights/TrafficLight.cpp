#include "Arduino.h"
#include "TrafficLight.h"
// British style traffic light sequence: 
//RED -> RED + AMBER -> GREEN -> AMBER -> RED

//TODO Refactor such that the traffic light knows its state and
//ensure the lights can't be activated in an incorrect sequence

TrafficLight::TrafficLight(int red, int amber, int green)

{
  pinMode(red, OUTPUT);
  pinMode(amber, OUTPUT);
  pinMode(green, OUTPUT);
  _red = red;
  _amber = amber;
  _green = green;

  digitalWrite(_red, HIGH);
  digitalWrite(_amber, LOW);
  digitalWrite(_green, LOW);
}

void TrafficLight::goingRedAmber()
{
  digitalWrite(_amber, HIGH);
}

void TrafficLight::goingGreen()
{
  digitalWrite(_red, LOW);
  digitalWrite(_amber, LOW);
  digitalWrite(_green, HIGH);
}

void TrafficLight::stoppingAmber()
{
  digitalWrite(_green, LOW);
  digitalWrite(_amber, HIGH);
}

void TrafficLight::stoppingRed()
{
  digitalWrite(_amber, LOW);
  digitalWrite(_red, HIGH);
}
