#ifndef NETDRIVER_H
#define NETDRIVER_H
#include <enet/enet.h>
#include <iostream>

class netDriver {
	public:
		ENetHost *host;
		ENetAddress address;
		netDriver(bool isServer);
		void createServer();
		void createClient();
};


#endif
