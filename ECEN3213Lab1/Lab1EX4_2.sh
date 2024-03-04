#!/bin/bash
#Complete the code in Lab1EX4_2.sh so that it scans the state of the 
#button to control the LED. When the button is pressed, the terminal 
#will display “The button is pressed” and the LED will turn on. 
#If not, the terminal will display “The button is not pressed” and the LED will turn off.



# Complete Code: Exports the LED and switch pins to userspace 
echo 18 > /sys/class/gpio/export
echo 23 > /sys/class/gpio/export



# Complete Code: Sets the two pins as an input and output
echo "in" > /sys/class/gpio/gpio23/direction
echo "out" > /sys/class/gpio/gpio18/direction


while [ : ]; do

    # Complete Code: read the button status, and assign /sys/class/gpio/gpioXX/value to a variable
    vari=$(cat /sys/class/gpio/gpio23/value)
    if [ $vari -eq 1 ]
    then 
        # Complete Code: turn on the led
        # Display “The button is pressed” on the terminal
		echo 1 > /sys/class/gpio/gpio18/value
		echo 'The button is pressed'
    else
        # Complete Code: turn off the led
        echo 0 > /sys/class/gpio/gpio18/value
        # Display “The button is not pressed” on the terminal
        echo 'The button is not pressed'
    fi

done

# Complete Code: Unexports the pins 
echo 18 > /sys/class/gpio/unexport
echo 23 > /sys/class/gpio/unexport
