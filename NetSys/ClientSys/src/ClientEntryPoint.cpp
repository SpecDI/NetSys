#include "Client.h"

#include <iostream>
#include <string>

int main()
{
	std::cout << "Client entry point\n";

	const unsigned int port = 2573;

	NetSys::Client client(port);
	int connection_code = client.connect();
	if (connection_code) {
		std::cout << "Connection failed\n";
	}
	else {
		std::string respone = client.send_request("Pula");
		std::cout << respone << std::endl;
	}

	std::string dummy_exit;
	std::getline(std::cin, dummy_exit);
	return 0;
}