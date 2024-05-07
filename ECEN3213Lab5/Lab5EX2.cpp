// Lab 5, Exercise 2
// g++ -std=c++14 Lab5EX2.cpp -o Lab5EX2 -lwiringPi
// Code by Mariia Shevchenko and Henry Le

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>
#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
/* Complete the code: include the file lab_util.cpp  */
#include "lab_util.cpp"

using namespace std::chrono;
using namespace std;


/* Complete the code: Set button pin */
int BUTTON = 27;

// State enum definition
enum State {
	STOPPED,
	RUNNING,
	RESET
};

// Global variables
State state;
high_resolution_clock::time_point begin_time;
high_resolution_clock::time_point hit_time;
unsigned int counter;

/* Complete the code, implement the timer */
void press_button() {
	string string_timestamp;

    // Get hit time, increment counter
    if (state == STOPPED){
		begin_time = high_resolution_clock::now();
		state=RUNNING;
		}

    else if (state==RUNNING) {
		counter=counter+1;
		hit_time = high_resolution_clock::now();
		string_timestamp = formatTime(begin_time, hit_time);
        if (counter == 1 || counter == 21){
			cout << counter << " : "<< counter << "st place:" <<string_timestamp<<endl;
			}
		else if(counter == 2|| counter == 22){
			cout << counter << " : "<< counter << "nd place:" <<string_timestamp<<endl;
			}
		else if (counter == 3|| counter == 23){
			cout << counter << " : "<< counter << "rd place:" <<string_timestamp<<endl;
			}
		else {
			cout << counter << " : "<< counter << "th place:" <<string_timestamp<<endl;
			}
	}		
	else if (state = RESET) {
	state = STOPPED;
	counter = 0;
    } 
}


int main(){
	double sleep_duration =0.1;
	int reset_counter =0;
	int counter_max =4;
    // Set up WiringPi
    if (wiringPiSetup () == -1) exit (1);

    state = STOPPED;
    counter = 0;
    unsigned int button_time = 0;
    
    pinMode(27, INPUT);

    cout << "Holding for long time to reset" << endl;


    /* Complete the code to implement the timer  */

    wiringPiISR(BUTTON, INT_EDGE_RISING, &press_button);
    /*while(true){
		//cout << counter;
		if (digitalRead(BUTTON)==1){
		usleep(sleep_duration*1000*1000);
		reset_counter=reset_counter+1;
		cout<<reset_counter<<endl;
		if(reset_counter >= counter_max){
			state =STOPPED;
			cout<<state<<endl;
			break;
			}
		}
	
    }*/
    int button_time = 0;
        while(true){
		if (state == STOPPED) {
			// Do nothing
		} else if (state == RUNNING) {
			// Reset check
			if (digitalRead(BUTTON) == HIGH) {
				// If button is held, increment button_time
				button_time++;

				// Set state to RESET if button has been held for at least 4 seconds
				if (button_time >= 4) {
                    cout<< "Reset" << endl;
					state = RESET;
				}
				cout << "button_time: " << button_time << endl;
			} else {
				// else set to 0
				button_time = 0;
			}

			// 1 second delay
			delay(1000);
		} else if (state == RESET) {
			// Reset variables
			counter = 0;
			button_time = 0;

			// Set state back to STOPPED
			state = STOPPED;

		}
    }
    /*
    Tips:
    1) Set digital pins to input, Use pinMode(PIN, MODE)
    2) Use wiringPiISR() to get the interupt
    3) Read the state of pin: digitalRead(PIN)
    4) Use delay() to set a delay
    5) Define the state for the timer
    6) Use the formatTime() in lab_util.cpp
    */


    return 0;
}
