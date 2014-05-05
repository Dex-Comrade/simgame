#include <iostream>
#include <enet/enet.h>
#include "netDriver.h"

int main() {
	if (enet_initialize() != 0) {
		std::cout << "An error occurred while initializing ENet.\n";
		return EXIT_FAILURE;
	}

	char input;
	bool isServer;
	std::cout << "Is this a server? (y/n)";
	std::cin >> input;

	if(input == 'y') {
		isServer = false;
	} else {
		isServer = true;
	}

	netDriver driver = new netDriver(isServer);
	ENetHost *host = driver.host;
	ENetEvent event;

	while(enet_host_service(host, &event, 1000) > 0) {
		std::cout <<"Waiting on message...";
		switch(event.type) {
		case ENET_EVENT_TYPE_CONNECT:
			printf("A new client connected from %x:%u.\n", event.peer->address.host, event.peer->address.port);
			event.peer->data = "Client information";
			break;
		case ENET_EVENT_TYPE_RECEIVE:
			printf("A packet of length %u containing %s was received from %s on channel %u.\n"), event.packet->dataLength, event.packet->data, event.peer->data, event.channelID);

			enet_packet_destroy(event.packet);
			break;
		case ENET_EVENT_TYPE_DISCONNECT:
			printf("%s disconnected.\n", event.peer->data);
			event.peer->data = NULL;
		}
	}
	return 0;
}
