#pragma once
#include <mbed.h>

class Motor {
 public:
  Motor(DigitalOut &_dir, PwmOut &_pulse, float _motor_ratio);
  void run(int speed);

  int get_speed();

 private:
  DigitalOut &dir;
  PwmOut &pulse;
  bool isInvert;
  float motor_ratio;
  int current_speed;
};
