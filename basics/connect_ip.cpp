#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{

    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
               port_num);

        asio::io_service ios;

        // Creating and opening a socket.
        asio::ip::tcp::socket sock(ios, ep.protocol());

        // Connecting a socket.
        sock.connect(ep);

        // At this point socket 'sock' is connected to
        // the server application and can be used
        // to send data to or receive data from it.
    }
    // Overloads of asio::ip::address::from_string() and
    // asio::ip::tcp::socket::connect() used here throw
    // exceptions in case of error condition.
    catch (system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
}