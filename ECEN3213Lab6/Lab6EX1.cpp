#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// code by Mariia Shevchenko and Henry Le

// g++ -std=c++14 Lab6EX1.cpp -o Lab6EX1 -lwiringPi
int BUTTON =1;
int count;
void direction(void){
	delay(.3);
	if (digitalRead(BUTTON) == HIGH){
		count=1-count;
		digitalWrite(2, 1);
		digitalWrite(3, 0);
		pwmWrite(26, 600);
		if (count== 0){
			digitalWrite(2,0);
			digitalWrite(3,1);
			pwmWrite(26, 600);
			}
		}
	}

int main(void){
    
    wiringPiSetup();

    /* 1. set mode for the pins, the pin mode of the PWM pin should be PWM_OUTPUT */
    pinMode(1, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(23, PWM_OUTPUT);


	/* 2. write HIGH or LOW to the two I/O pins to control the initial rotation direction */
	digitalWrite(2, 0);
	digitalWrite(3, 0);
	pwmWrite(23, 0);

    //wiringPiISR(BUTTON, INT_EDGE_RISING, &direction);
    /* 3. use function pwmWrite to control the initial motor speed. Refer to document pwm.pdf for more information. */
	while (true){
		if (digitalRead(BUTTON) == HIGH && count%2!=0){
		count++;
		digitalWrite(2, 1);
		digitalWrite(3, 0);
		pwmWrite(23, 600);
		}
		else if (digitalRead(BUTTON) == HIGH && count%2==0){
			count++;
			digitalWrite(2,0);
			digitalWrite(3,1);
			pwmWrite(23, 600);
			}
		else {
		}
		cout<<digitalRead(BUTTON)<<endl;
		
	}
    /* 4. use pulling or interrupt to control the direction toggling.*/


    //tips:	run the code using sudo ./Lab6EX1

    return 0;
}

