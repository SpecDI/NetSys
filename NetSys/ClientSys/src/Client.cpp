#include "Client.h"

#include <boost/asio.hpp>
#include <boost/exception/all.hpp>

#include <iostream>
#include <string_view>
#include <exception>
#include <sstream>

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

	int Client::connect()
	{
		// Create socket and reference via stored 
		if (m_socketPtr == nullptr) {
			m_socketPtr = std::make_unique<tcp::socket>(m_io_service);
		}

		boost::system::error_code error;
		m_socketPtr->connect(tcp::endpoint(boost::asio::ip::address::from_string(m_address), m_portNumber), error);

		return error.value();
	}

	std::string Client::send_request(std::string_view request)
	{
		std::string request_message(request);
		request_message += "\n";

		boost::system::error_code error;

		if (!m_socketPtr->is_open()) {
			int status = connect();
			if (status) {
				std::stringstream stream;
				stream << "Connection failed with status: " << status;
				return stream.str();
			}
		}

		boost::asio::write(*(m_socketPtr.get()), boost::asio::buffer(request_message), error);

		boost::asio::streambuf receive_buffer;
		boost::asio::read(*(m_socketPtr.get()), receive_buffer, boost::asio::transfer_all(), error);
		return boost::asio::buffer_cast<const char*>(receive_buffer.data());
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