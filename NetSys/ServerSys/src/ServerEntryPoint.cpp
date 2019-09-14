#include "Server.h"

#include <iostream>
#include <string>

int main()
{
	const int default_portNumber = 2573;
	std::cout << "Server entry point\n";
	NetSys::Server server(default_portNumber);
	server.run();

	std::string dummy_exit;
	std::getline(std::cin, dummy_exit);
	return 0;
}