#include "Client.h"

#include <iostream>
#include <string>

int main()
{
	std::cout << "Client entry point\n";

	const unsigned int port = 2573;

	NetSys::Client client(port);
	client.run();

	std::string dummy_exit;
	std::getline(std::cin, dummy_exit);
	return 0;
}