//Code by Mariia Shevchenko and Henry Le from group 11
// Lab 4, Exercise 2
// g++ -std=c++14 Lab4EX2.cpp -o Lab4EX2 -lwiringPi
// Reference: http://wiringpi.com/reference/i2c-library/


#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>
#include <iostream>

/* Complete the code: include the file lab_util.cpp  */
#include "lcd.cpp"

using namespace std;

/* Complete the code:Set button pin wPi 26 */
int BUTTON = 26;

int button_state = LOW;

int main(){

    // Set up WiringPi
    if (wiringPiSetup () == -1) exit (1);
    // Init I2C, assign a buffer handler to variable fd
    fd = wiringPiI2CSetup(LCDAddr);

    /* Complete the code: in the init function*/
    init();


    print_info();
    pinMode(26,OUTPUT);
    
	while(true){
		//If there is a change in the state of the
		//switch, the state of the LED must also change.
		if (digitalRead(BUTTON) == 0){
			write(0,0,"NOT PRESSED");
			delay(50);
			clear();
		}
		else{
			write(0,0,"PRESSED");
			delay(50);
			clear();
		}				
	}

    /* Complete here to detect state of Button pin
      and write "PRESSED" or "NOT PRESSED" to screen */
	
    /*
    Tips:
    1) Set digital pins to input, Use pinMode(PIN, MODE);
    2) Read the state of pin: digitalRead(PIN);
    3) Fill the code in function init() , write(), clear(), write_word()
    4) Use write() to display the messages
    */

    return 0;
}
