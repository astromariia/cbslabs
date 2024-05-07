#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// code by Mariia Shevchenko and Henry Le
// g++ -std=c++14 Lab6EX2.cpp -o Lab6EX2 -lwiringPi
int button1State = LOW;
int speed = 0;
int dir = 1;

void button1Interrupt() {
    delay(200);
    if(!digitalRead(1)) return;
    button1State = (button1State == LOW) ? HIGH : LOW;
    cout << "Button status: "<<button1State <<endl;
} 

void button2Interrupt() {
	delay(200);
	if(!digitalRead(4)) return;
    if (speed <= 0) {
        dir = 1;
    }
    else if (speed >= 1000) {
        dir = -1;
    }
    speed = speed + (100*dir);
 
    cout <<  "speed: "<<speed <<endl;
}

int main(void){
    
    wiringPiSetup();

    /* 1. set mode for the pins, the pin mode of the PWM pin should be PWM_OUTPUT */
	pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(1, INPUT);
    pinMode(4, INPUT);
    pinMode(23, PWM_OUTPUT);

    /* 2. use pulling or interrupt to control the motor.*/
	pwmWrite(PWMpin, speed);
	
	wiringPiISR(1, INT_EDGE_BOTH, &button1Interrupt);
    wiringPiISR(4, INT_EDGE_BOTH, &button2Interrupt);
    while (true) {    
        if (button1State == HIGH){
        digitalWrite(2, 1);
        digitalWrite(3, 0); 
        pwmWrite(23, speed);
        }
        else {
            digitalWrite(2, 0);
            digitalWrite(3, 0);
        }
        
        delay (500);
    }

    return 0;
}

