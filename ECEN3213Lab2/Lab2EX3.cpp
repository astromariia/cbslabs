//In this exercise, you will toggle an LED using a button switch.

//Use the digital I/O pins on the Raspberry Pi to read the state
//of the switch, and send the corresponding signal to the LED.

//Thoroughly comment your code and demonstrate to the lab instructor.


//Use g++ -std=c++11 -o Lab2_3 Lab2EX3.cpp -lwiringPi

//code by Henry Le and Mariia Shevchenko

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

void stop(int);

int main(){
	//Initialize the wiringPi library.
	signal(SIGINT, stop);
	wiringPiSetup();

	//Set the state of the digital pins.
	pinMode(4,INPUT); //23
	pinMode(1,OUTPUT); //18

	while(true){
		//If there is a change in the state of the
		//switch, the state of the LED must also change.
		//The code reads the value of the button from pin 23
		if (digitalRead(4) == 0){
			digitalWrite(1,0);
		}
		else{
			digitalWrite(1,1);
		}				
	}
}

void stop(int sig){exit(1);}
