#pragma once

#include <boost/asio.hpp>

namespace NetSys {
	class Server {
	public:
		explicit Server(unsigned int port);

		int run() const;
	protected:
		unsigned int m_portNumber;
	};
}