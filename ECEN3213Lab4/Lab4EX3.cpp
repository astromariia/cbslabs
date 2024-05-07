//Code by Mariia Shevchenko and Henry Le from group 11
// Lab 4, Exercise 3
// g++ -std=c++14 Lab4EX3.cpp -o Lab4EX3 -lwiringPi
// Reference: http://wiringpi.com/reference/i2c-library/


#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>
#include <iostream>

/* Complete the code: include the file lab_util.cpp  */
#include "lcd.cpp"

using namespace std;

/* Complete the code:Set button pin wPi26 */
int BUTTON = 26;


int button_state = LOW;
bool changed = false;

void press_button(){
	if (digitalRead(BUTTON) == 1){
			button_state = HIGH;
			changed=true;
			write(0,0,"PRESSED    ");
			//clear();
			//delay(50);
			}
	else {
			button_state = LOW;
			changed=false;
			write(0,0,"NOT PRESSED");
			//clear();
			//delay(50);
			}		
}

int main(){

    // Set up WiringPi
    if (wiringPiSetup () == -1) exit (1);    
    
    // Init I2C, assign a buffer handler to variable fd
    fd = wiringPiI2CSetup(LCDAddr);

    /* Complete the code: in the init function*/
    init();


    print_info();

    /* Complete here to print "PRESSED" or "NOT PRESSED"
      to the LCD screen using a hardware interrupt */
	 pinMode(26,INPUT);
    /*
    Tips:
    1) Set digital pins to input, Use pinMode(PIN, MODE);
    2) Read the state of pin digitalRead(PIN);
    3) Implement interrupt: wiringPiISR() and define callback function;
    4) Fill the code in function init() , write(), clear(), write_word()
    5) Use write() to display the messages
    */
    wiringPiISR(BUTTON,INT_EDGE_BOTH,&press_button);

    while(true) {
		  }
		  

    return 0;
}
