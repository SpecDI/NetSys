#include "Server.h"

#include <boost/asio.hpp>

#include <iostream>

namespace NetSys {
	Server::Server(unsigned int port)
		: m_portNumber(port)
	{
		std::cout << "Server constructed and listening on port " << m_portNumber << std::endl;
	}

	int Server::run() const
	{
		// Create an I/O service to register requests
		boost::asio::io_service io_service;
		// Create an acceptor that intercepts connections
		tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), m_portNumber));
		// Socket used to transmit data to client over port
		tcp::socket socket_(io_service);

		// Wait for connection
		acceptor_.accept(socket_);

		// Intercept and send messages
		std::string message = read_message(socket_);
		std::cout << "Message: " << message << std::endl;

		message = "Hello from server";
		send_message(socket_, message);

		return 0;
	}

	std::string Server::read_message(tcp::socket& socket) const
	{
		// Create buffer to read data in
		boost::asio::streambuf buffer;
		boost::asio::read_until(socket, buffer, "\n");
		// Return read message
		return boost::asio::buffer_cast<const char*>(buffer.data());
	}

	void Server::send_message(tcp::socket& socket, const std::string& message) const
	{
		// Write message through socket into buffer
		boost::asio::write(socket, boost::asio::buffer(message + "\n"));
	}
}