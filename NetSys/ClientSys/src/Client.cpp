#include "Client.h"

#include <boost/asio.hpp>

#include <iostream>
#include <string_view>

namespace NetSys {
	Client::Client(unsigned int port)
		: m_portNumber(port)
	{
		m_address = "127.0.0.1";
		std::cout << "Client created and sending data over port " << m_portNumber << " with address " << m_address << std::endl;
	}

	Client::Client(unsigned int port, std::string_view address)
		: m_portNumber(port), m_address(address)
	{
		std::cout << "Client created and sending data over port " << m_portNumber << " with address " << m_address << std::endl;
	}

	void Client::run() const
	{
		// Create I/O service handler
		boost::asio::io_service io_service;
		// Create socket to transmit/receive data
		tcp::socket socket(io_service);

		socket.connect(tcp::endpoint(boost::asio::ip::address::from_string(m_address), m_portNumber));

		std::string message = "Hello from Client\n";
		boost::system::error_code error;
		boost::asio::write(socket, boost::asio::buffer(message), error);

		boost::asio::streambuf receive_buffer;
		boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
		std::string server_message = boost::asio::buffer_cast<const char*>(receive_buffer.data());
		std::cout << server_message << std::endl;
	}
}