#pragma once

#include <boost/asio.hpp>

#include <string>
#include <string_view>

namespace NetSys {
	using tcp = boost::asio::ip::tcp;

	class Client {
	public:
		explicit Client(unsigned int port);
		Client(unsigned int port, std::string_view address);

		void run() const;
	protected:
		unsigned int m_portNumber;
		std::string m_address;
	};
}