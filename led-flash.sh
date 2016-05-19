#!/bin/sh

# Demonstration of LED flashing using a shell script

# Disable trigger

echo "none" > /sys/class/leds/beaglebone:green:heartbeat/trigger
echo "none" > /sys/class/leds/beaglebone:green:mmc0/trigger
echo "none" > /sys/class/leds/beaglebone:green:usr2/trigger
echo "none" > /sys/class/leds/beaglebone:green:usr3/trigger

while true; do
	echo 255 > /sys/class/leds/beaglebone:green:heartbeat/brightness
	usleep 500000
	echo 0 > /sys/class/leds/beaglebone:green:heartbeat/brightness
	usleep 500000
done
