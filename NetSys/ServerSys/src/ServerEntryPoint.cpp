#include "Server.h"

#include <iostream>
#include <string>

int main()
{
	std::cout << "Server entry point\n";
	NetSys::Server server;

	std::string dummy_exit;
	std::getline(std::cin, dummy_exit);
	return 0;
}