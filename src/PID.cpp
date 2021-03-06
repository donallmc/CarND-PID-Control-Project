#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
  d_error_ = 0;
  p_error_ = 0;
  i_error_ = 0;
}

void PID::UpdateError(double cte) {
  d_error_ = cte - p_error_;  
  p_error_ = cte;
  i_error_ += cte;
}

double PID::getSteeringAngle() {
  return - (Kp_ * p_error_) - (Kd_ * d_error_) - (Ki_ * i_error_);
}
