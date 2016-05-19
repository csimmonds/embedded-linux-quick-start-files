/*
 Demonstrate how to flash one of the user LEDs on the BeagelBone Black 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define LED0_PATH "/sys/class/leds/beaglebone:green:heartbeat/brightness"

int main(int argc, char *argv[])
{
	int fd_led0;
	char str_on[] = "255";
	char str_off[] = "0";
	int ret;

	printf("LED flasher v1.0\n");
	fd_led0 = open(LED0_PATH, O_WRONLY);
	if (fd_led0 == -1) {
		printf("Cannot open %s: %s\n",
			LED0_PATH, strerror(errno));
		return 1;
	}

	while(1) {
		ret = write(fd_led0, str_off, sizeof(str_off));
		if (ret == -1) {
			printf("Error writing to %s: %s\n",
				LED0_PATH, strerror(errno));
			break;
		}
		usleep(500000);
		ret = write(fd_led0, str_on, sizeof(str_on));
		if (ret == -1) {
			printf("Error writing to %s: %s\n",
				LED0_PATH, strerror(errno));
			break;
		}
		usleep(500000);
	}
	return 0;
}
