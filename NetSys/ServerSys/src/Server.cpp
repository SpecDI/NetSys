#include "Server.h"

#include <boost/asio.hpp>

#include <iostream>

using tcp = boost::asio::ip::tcp;

namespace NetSys {
	Server::Server(unsigned int port)
		: m_portNumber(port)
	{
		std::cout << "Server constructed and listening on port " << m_portNumber << std::endl;
	}

	int Server::run() const
	{
		boost::asio::io_service io_service;
		tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), m_portNumber));
		tcp::socket socket_(io_service);

		// Wait for connection
		acceptor_.accept(socket_);

		return 0;
	}
}