#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_coefficient, double Ki_coefficient, double Kd_coefficient) {
    Kp = Kp_coefficient;
    Ki = Ki_coefficient;
    Kd = Kd_coefficient;

    p_error = 1.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte) {
    i_error += cte;
    d_error = (cte - p_error);
    p_error = cte;
}

double PID::TotalError() {
    return -(Kp * p_error + Ki * i_error + Kd * d_error);
}

