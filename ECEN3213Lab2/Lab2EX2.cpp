//In this exercise, you will make an LED counter which will
//Count in binary from 0 to 15, or from 0000 to 1111.

//Use the digital I/O pins on the Raspberry Pi to send
//power to the LED. Complete the circuit as listed in
//the lab document.

//Thoroughly comment your code and demonstrate to the lab inststructor.


//Use g++ -std=c++11 -o Lab2_2 Lab2EX2.cpp -lwiringPi

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

	//Set digital pins to output.
	//Use pinMode(PIN, MODE);
	pinMode(4,OUTPUT); //23
	pinMode(5,OUTPUT); //24
	pinMode(6,OUTPUT);     //25
	pinMode(1,OUTPUT); //18

	//Create each sequence and count from 0 to 15.
	//Use digitalWrite(PIN, Value);
		digitalWrite(1,1);
		digitalWrite(4,1);
		digitalWrite(5,1);//To turn off the LED the digitalWrite() a high value
		digitalWrite(6,1); // Number 0000 
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,1);
		digitalWrite(5,1);
		digitalWrite(6,0); //Number 0001
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,1);
		digitalWrite(5,0);
		digitalWrite(6,1); //Number 0010
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,1);
		digitalWrite(5,0);
		digitalWrite(6,0); //Number 0011
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,0);
		digitalWrite(5,1);
		digitalWrite(6,1); //Number 0100
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,0);
		digitalWrite(5,1);
		digitalWrite(6,0); //Number 0101
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,0);
		digitalWrite(5,0);
		digitalWrite(6,1); //Number 0110
		usleep(1000000);
		digitalWrite(1,1);
		digitalWrite(4,0);
		digitalWrite(5,0);
		digitalWrite(6,0); //Number 0111
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,1);
		digitalWrite(5,1);
		digitalWrite(6,1); //Number 1000
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,1);
		digitalWrite(5,1);
		digitalWrite(6,0); //Number 1001
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,1);
		digitalWrite(5,0);
		digitalWrite(6,1); //Number 1010
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,1);
		digitalWrite(5,0);
		digitalWrite(6,0); //Number 1011
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,0);
		digitalWrite(5,1);
		digitalWrite(6,1); //Number 1100
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,0);
		digitalWrite(5,1);
		digitalWrite(6,0); //Number 1101
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,0);
		digitalWrite(5,0);
		digitalWrite(6,1); //Number 1110
		usleep(1000000);
		digitalWrite(1,0);
		digitalWrite(4,0);
		digitalWrite(5,0);
		digitalWrite(6,0); //Number 1111
	//Create a 1 second delay after each sequence.
	//Use usleep(us) for the delay.
}

void stop(int sig){exit(1);}
