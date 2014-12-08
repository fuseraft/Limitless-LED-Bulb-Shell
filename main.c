#include <stdio.h>
#include <stdlib.h>
#include "bulb.h"
#include "colors.h"


int main()
{
	printf("Starting.... newwww\n");
	LEDBulb *test = init_led_bulb("192.168.0.14");
	printf("is connected : %d\n",test->is_connected);
	//led_bulb_set_color(test, GREEN);
	//sleep(5000);
	led_bulb_set_white(test);




	return 0;

}