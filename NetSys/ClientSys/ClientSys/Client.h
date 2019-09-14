#pragma once

#include "boost/asio.hpp"

namespace NetSys {
	using tcp = boost::asio::ip::tcp;

	class Client {
	public:
		explicit Client(unsigned int port);

		void run() const;
	protected:
		unsigned int m_portNumber;
	};
}