#include "netDriver.h"

//#include <enet/enet.h>



netDriver::netDriver(bool isServer) {
	if (isServer) {
		this->createServer();
	} else {
		this->createClient();
	}
}

void netDriver::createServer() {
	address.host = ENET_HOST_ANY;
	address.port = 9999;

	std::max(1,2);
	host = enet_host_create(&address, 8, 2, 0, 0);

	if(host == NULL) {
		std::cout << "An error occurred while trying to create an ENet server host.\n";
		exit (EXIT_FAILURE);
	}
}

void netDriver::createClient() {

	host = enet_host_create(NULL, 1, 2, 0, 0);

	if(host == NULL) {
		std::cout << "An error occurred while trying to create an ENet client host.\n";
		exit (EXIT_FAILURE);
	}
}


