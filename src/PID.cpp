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


	// window size for cte running average 
	win_size_cte = 100000;
	
}


void PID::UpdateError(double cte_) {
	
	// calculate running average of cte
	hist_cte.push_back(cte_);
	
	if (hist_cte.size() > win_size_cte)
	{
		// remove first element
		hist_cte.erase(hist_cte.begin()+0);
	}
	
	double cte_sum = 0;
	for (int i = 0; i < hist_cte.size(); ++i)
	{
		cte_sum += hist_cte[i];
	}
	
	int_cte = cte_sum / hist_cte.size();

	prev_cte = cte;
	cte = cte_;

	p_error = Kp* cte;
	i_error = Ki * int_cte;
	d_error = Kd* (cte-prev_cte);
}

double PID::TotalError() {

	total_error= p_error + d_error + i_error;

	return total_error;
}
