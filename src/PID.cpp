#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    p_error = 0;
	i_error = 0;
	d_error = 0;
	
}


void PID::UpdateError(double cte_) {
	prev_cte = cte;
	cte = cte_;
	int_cte = int_cte + cte;

	p_error = Kp* cte;
	i_error = Ki * int_cte;
	d_error = Kd* (cte-prev_cte);
}

double PID::TotalError() {

	total_error= p_error + d_error + i_error;

	return total_error;
}

