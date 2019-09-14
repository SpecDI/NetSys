#include "Client.h"

#include <iostream>
#include <string>

int main()
{
	std::cout << "Client entry point\n";

	NetSys::Client client;

	std::string dummy_exit;
	std::getline(std::cin, dummy_exit);
	return 0;
}