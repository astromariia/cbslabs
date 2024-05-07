//Code by Mariia Shevchenko and Henry Le from group 11
// Lab 4, Exercise 1
// g++ -std=c++14 Lab4EX1.cpp -o Lab4EX1 -lwiringPi
// Reference: http://wiringpi.com/reference/i2c-library/


#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>
#include <iostream>

/* Complete the code: include the file lab_util.cpp  */
#include "lcd.cpp"

using namespace std;

int main(){

    // Set up WiringPi
    if (wiringPiSetup () == -1) exit (1);   

    // Init I2C, assign a buffer handler to variable fd
    fd = wiringPiI2CSetup(LCDAddr);

    /* Complete the code: in the init function*/
    init();

    print_info();
    
    write(0,0,"Hello world!");
    write(0,1,"I am Henry and Mariia.");

    /* Complete the code here to print on the LCD screen “Hello world!” and “I am xxx” in two lines.
     (xxx is your first name) */

    /*
    Tips:
    1) Fill the code in function init() , write(), write_word()
    2) Use write() to display the messages
    */


    return 0;
}
