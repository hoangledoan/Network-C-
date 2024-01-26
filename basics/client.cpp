#include <boost/asio.hpp>
#include <iostream>
#include <string>
int main()
{
    // Ip and Port of the Client
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    // Store error information
    boost::system::error_code ec;

    boost::asio::ip::address ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);

    if (ec.value() != 0)
    {
        std::cout << "Failed to parse  the IP Address. Error code: " << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }

    // Create a client endpoint
    boost::asio::ip::tcp::endpoint ep(ip_address, port_num);

    return 0;
}