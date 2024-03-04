//In this exercise, you will turn on the two LEDs.

//Use the digital I/O pins on the Raspberry Pi to send
//power to the LED. Complete the circuit as listed in
//the lab document.

//Thoroughly comment your code and demonstrate to the lab inststructor.

//Use g++ -std=c++11 -o Lab2_1 Lab2EX1.cpp -lwiringPi

//code by Henry Le and Mariia Shevchenko

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

int main(){
	//Initialize the wiringPi library.
	wiringPiSetup();			// Initialized to refer to pins by WiringPi number
	//wiringPiSetupGpio();		// Initialized to refer to pins by GPIO number (not recommended)

	//Set digital pins to output.
	//Use pinMode(PIN, MODE);
	pinMode(4, OUTPUT);
	pinMode(1, OUTPUT);
	// Write signal to I/O pins
	//Use digitalWrite(PIN, Value);
	digitalWrite(4, 0);
	digitalWrite(1, 1);

	return 0;
}

