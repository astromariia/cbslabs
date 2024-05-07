//Code by Mariia Shevchenko and Henry Le from group 11
// Lab 4, Exercise 5
// g++ -std=c++14 Lab4EX5.cpp -o Lab4EX5 -lwiringPi
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
int counter=0;
char counter_string[20];

void press_button(){
	delay(100);
	if (digitalRead(BUTTON) == 1){
			button_state = HIGH;
			changed=true;
			write(0,0,"PRESSED    ");
			counter=counter+1;
			sprintf(counter_string,"Times: %d", counter);
			write(0,1,counter_string);
			}
	else {
			button_state = LOW;
			changed=false;
			write(0,0,"NOT PRESSED");
			}		
}

int main(){

    // Set up WiringPi
    if (wiringPiSetup () == -1) exit (1);    
    
    // Init I2C, assign a buffer handler to variable fd
    fd = wiringPiI2CSetup(LCDAddr);

    /* Complete the code: in the init function */
    init();


    print_info();

	pinMode(26,INPUT);
    /* Complete here to print "PRESSED" or "NOT PRESSED"
      to the LCD screen using a hardware interrupt */

    /*
    Tips:
    1) Set digital pins to input, Use pinMode(PIN, MODE);
    2) Read the state of pin digitalRead(PIN);
    3) Implement interrupt: wiringPiISR() and define callback function;
    4) Fill in the code in function init() , write(), clear(), write_word()
    5) Use write() to display the messages
    6) Function sprintf() coulb be used for generate the string of press times
    7) You can declare a variable like flag, and update the flag value(Using 1 or 0) in callback function, 
       and check the flag in the main function then display the relevant messages
    */

	wiringPiISR(BUTTON,INT_EDGE_BOTH,&press_button);
	
    while(true) {
        /* Check the flag status based on the Tip 7*/
        /* Display  "PRESSED and the press times " or Display  "NOT PRESSED" */
    }


    return 0;
}
