#include "bulb.h"

#include <malloc.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdio.h>


static const int LED_GATEWAY_PORT = 8899;

static int _send_packet(const LEDBulb *bulb, char packet[]) {
	sendto(bulb->socket, packet, 3, 0,  (struct sockaddr *)&bulb->remote, sizeof(struct sockaddr_in));
	close(bulb->socket);

	return 0;
}



/* Create a new LED bulb object given IP address */
LEDBulb* init_led_bulb(const char *ip_address) {

	LEDBulb *bulb = malloc(sizeof(LEDBulb));
	if(bulb == NULL) {
		return NULL;
	}


	
	bulb->socket = socket(AF_INET,SOCK_DGRAM,0);
	bulb->remote.sin_family = AF_INET;
	bulb->remote.sin_addr.s_addr = inet_addr(ip_address);
	bulb->remote.sin_port = htons(LED_GATEWAY_PORT);
	bulb->is_connected = 1;

	return bulb;

}


int led_bulb_set_white(const LEDBulb *bulb){
	
	char packet[] = {0xc2,0x00,0x55};
	_send_packet(bulb,packet);
	return 0;
	

}

// int led_bulb_off(LEDBulb *bulb);
// int led_bulb_on(LEDBulb *bulb);
int led_bulb_set_color(const LEDBulb *bulb, const int color) {
	char test[] = {0x40,color,0x55};
	_send_packet(bulb,test);
	return 0;
}
