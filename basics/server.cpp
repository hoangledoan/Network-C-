#include <boost/asio.hpp>
#include <iostream>

int main()
{
    unsigned short port_num = 3333;

    // Create IPv6 Address in host
    boost::asio::ip::address ip_address = boost::asio::ip::address_v6::any();

    boost::asio::ip::tcp::endpoint ep(ip_address, port_num);

    return 0;
}