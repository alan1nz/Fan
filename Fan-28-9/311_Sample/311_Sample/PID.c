/*
 * PID.c
 *
 * Created: 9/26/2017 12:37:58 PM
 *  Author: peng
 */ 


#include "PID.h"


void pid(int error, int sum_error, int pre_error){
	


	int p_term = error * p_coefficient; //Calculate P term


	double i_term = sum_error + error*i_coefficient; //Sum the integral term

	int pid_output = i_term; //Add all terms





	if (pid_output > 267){ //Place a limit on PID output
		pid_output = 267;
	}else if (pid_output < 0){
		pid_output = 0 ;
	}
		
						char y[5] = {0};
						sprintf(y,"%d",i_term);
						uart_transmit(y[0]);
						uart_transmit(y[1]);
						uart_transmit(y[2]);
						uart_transmit(y[3]);
						uart_transmit(' ');

	OCR1B = pid_output;
}

