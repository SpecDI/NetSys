#pragma once

#include <boost/asio.hpp>

#include <string>
#include <string_view>
#include <memory>

namespace NetSys {
	using tcp = boost::asio::ip::tcp;

	class Client {
	public:
		explicit Client(unsigned int port);
		Client(unsigned int port, std::string_view address);

		void run() const;
		int connect();
	protected:
		unsigned int m_portNumber;
		std::string m_address;
		boost::asio::io_service m_io_service;
		std::unique_ptr<tcp::socket> m_socketPtr;
	};
}