#!/bin/bash
#  Please refer to the book "Exploring Raspberry Pi" chapter 6

# XX is the pin number, you need to replace it.

# Complete Code: Exports pin to userspace
echo 18 > /sys/class/gpio/export

# Complete Code: Set pin as an output
echo "out" > /sys/class/gpio/gpio18/direction
while [ : ]; do
    # Complete Code: turn on the LED
    echo 1 > /sys/class/gpio/gpio18/value

    # Compllet ete Code: delay for 100 ms
	sleep 1
    # Complete Code: turn off the LED
    echo 0 > /sys/class/gpio/gpio18/value

    # Complete Code: delay for 100 ms
	sleep 1
done

# Complete Code: Unexports pin to userspace
echo 18 > /sys/class/gpio/unexport
