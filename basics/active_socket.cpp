#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
    // An instance of 'io_service' class is required by socket constructor.
    asio::io_service ios;

    // Creating an object of 'tcp' class representing
    // a TCP protocol with IPv4 as underlying protocol.
    asio::ip::tcp protocol = asio::ip::tcp::v4();

    // Instantiating an active TCP socket object.
    asio::ip::tcp::socket sock(ios);

    // Used to store information about error that happens
    // while opening the socket.
    boost::system::error_code ec;

    // Opening the socket.
    sock.open(protocol, ec);

    if (ec.value() != 0)
    {
        // Failed to open the socket.
        std::cout
            << "Failed to open the socket! Error code = "
            << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }

    return 0;
}