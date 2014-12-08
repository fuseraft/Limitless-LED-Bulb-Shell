#ifndef BULB_H
#define BULB_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>



typedef struct LEDBulb {

	int is_connected;
	int socket;
	struct sockaddr_in remote;
} LEDBulb;



LEDBulb* init_led_bulb(const char *ip_address);
// int led_bulb_off(LEDBulb *bulb);
// int led_bulb_on(LEDBulb *bulb);
int led_bulb_set_white(const LEDBulb *bulb);
 int led_bulb_set_color(const LEDBulb *bulb, const int color);

#endif