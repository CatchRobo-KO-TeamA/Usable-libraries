#include "Motor.h"

Motor::Motor(DigitalOut &_dir, PwmOut &_pulse, float _motor_ratio = 1,
             bool _isInvert = false)
    : dir(_dir),
      pulse(_pulse),
      motor_ratio(_motor_ratio),
      isInvert(_isInvert) {}

void Motor::run(float speed) {
  current_speed = speed;
  if (speed < -1.0) {
    speed = -1.0;
  } else if (speed > 1.0) {
    speed = 1.0;
  }

  if (speed > 0) {
    dir = isInvert;
    pulse = speed * motor_ratio;
  } else if (speed < 0) {
    dir = !isInvert;
    pulse = speed * motor_ratio;
  } else {
    pulse = 0;
  }
}

int Motor::get_speed() { return current_speed; }