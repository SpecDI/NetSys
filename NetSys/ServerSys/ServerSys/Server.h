#pragma once

#include <boost/asio.hpp>

#include <string>

namespace NetSys {
	using tcp = boost::asio::ip::tcp;

	class Server {
	public:
		explicit Server(unsigned int port);

		int run() const;
	protected:
		std::string read_message(tcp::socket& socket) const;
		void send_message(tcp::socket& socket, const std::string& message) const;

		unsigned int m_portNumber;
	};
}