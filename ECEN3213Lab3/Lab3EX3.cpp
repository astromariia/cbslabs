//In this exercise, you will be measuring the analog
//voltages of a compounded circuit.

//Use your code from previous exercises to perform this.

//Print the values to the terminal screen.

//Thoroughly comment your code and demonstrate to the
//lab instructor.

//Use g++ -std=c++11 -o Lab3EX3 Lab3EX3.cpp -lwiringPi
//Code by Mariia Shevchenko and Henry Le from group 11

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;


int adc;
int ratio;
void stop(int);
int adcVal();

int main(){
	//Initialize the wiringPi Library.
	double voltage,digitalvoltage; // double declaration of variables to account for the floats
    signal(SIGINT, stop);
	wiringPiSetup();

	//Set mode of digital pins.
	pinMode(6,OUTPUT); //Pin 25
	pinMode(5,OUTPUT); //Pin 24
	pinMode(4,OUTPUT); //Pin 23
	pinMode(1,OUTPUT); //Pin 18
	while(true){
		
		//Place the values for 0 - 15 here.
			digitalWrite(6,0);
			digitalWrite(5,0);
			digitalWrite(4,0);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096; //Calculating actual voltage
			cout << "The converted analog voltage for the binary input " <<"0000" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,0);
			digitalWrite(5,0);
			digitalWrite(4,0);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0001" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,0);
			digitalWrite(4,1);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0010" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,0);
			digitalWrite(4,1);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0011" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,1);
			digitalWrite(4,0);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0100" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,1);
			digitalWrite(4,0);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0101" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,1);
			digitalWrite(4,1);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0110" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);	
			digitalWrite(6,0);
			digitalWrite(5,1);
			digitalWrite(4,1);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"0111" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,0);
			digitalWrite(4,0);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1000" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,0);
			digitalWrite(4,0);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1001" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,0);
			digitalWrite(4,1);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1010" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,0);
			digitalWrite(4,1);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1011" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,1);
			digitalWrite(4,0);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1100" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,1);
			digitalWrite(4,0);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1101" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,1);
			digitalWrite(4,1);
			digitalWrite(1,0);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1110" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);
			digitalWrite(6,1);
			digitalWrite(5,1);
			digitalWrite(4,1);
			digitalWrite(1,1);
			digitalvoltage = adcVal();
			voltage = (digitalvoltage/2047)*4.096;
			cout << "The converted analog voltage for the binary input " <<"1111" << " to R-2R ladder is " << voltage << " volts"<<endl; 
			usleep(1000000);		
				
	}
}


//This function is used to read data from ADS1015
int adcVal(){

	uint16_t low, high, value;
    // Refer to the supplemental documents to find the parameters.
	adc = wiringPiI2CSetup(0x48);
	wiringPiI2CWriteReg16(adc, 0x01, 0xC583);
	usleep(1000);
    uint16_t data = wiringPiI2CReadReg16(adc, 0x00);


    low = (data & 0xFF00) >> 8;
    high = (data & 0x00FF) << 8;
    value = (high | low)>>4;
	if (value > 0x07FF)
        {
            value |= 0xF000;
        }
	return (int16_t) value;
}

void stop(int sig){exit(1);}
