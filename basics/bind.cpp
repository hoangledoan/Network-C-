#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
    unsigned short port_num = 3333;

    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
                               port_num);

    // Used by 'acceptor' class constructor.
    asio::io_service ios;

    // Creating and opening an acceptor socket.
    asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

    boost::system::error_code ec;

    acceptor.bind(ep, ec);

    // Handling errors if any.
    if (ec.value() != 0)
    {
        // Failed to bind the acceptor socket. Breaking
        // execution.
        std::cout << "Failed to bind the acceptor socket."
                  << "Error code = " << ec.value() << ". Message: "
                  << ec.message();

        return ec.value();
    }

    return 0;
}