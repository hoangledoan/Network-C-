#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
    std::string host = "samplehost.com";
    std::string port_num = "3333";
    asio::io_service ios;

    // This object represents a query to the DNS. It contains a DNS name to resolve,
    // a port number that will be used to construct an endpoint object after the DNS
    // name resolution and a set of flags controlling some specific aspects of resolution
    // process, represented as a bitmap. All these values are passed to the query class's
    // constructor. Because the service is specified as a protocol port number (in our case
    // , 3333) and not as a service name (for example, HTTP, FTP, and so on), we passed the
    // asio::ip::tcp::resolver::query::numeric_service flag to explicitly inform the query
    // object about that, so that it properly parses the port number value.
    asio::ip::tcp::resolver::query resolver_query(host,
                                                  port_num, asio::ip::tcp::resolver::query::numeric_service);

    // Creating a resolver.
    asio::ip::tcp::resolver resolver(ios);

    boost::system::error_code ec;

    // We create an instance of the asio::ip::tcp::resolver class. This class
    // provides the DNS name resolution functionality. To perform the resolution,
    // it requires services of the underlying operating system and it gets access
    // to them through the object of the asio::io_services class being passed to
    // its constructor as an argument.
    asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query, ec);

    // Handling errors if any.
    if (ec.value() != 0)
    {
        // Failed to resolve the DNS name. Breaking execution.
        std::cout << "Failed to resolve a DNS name."
                  << "Error code = " << ec.value()
                  << ". Message = " << ec.message();

        return ec.value();
    }

    asio::ip::tcp::resolver::iterator it =
        resolver.resolve(resolver_query, ec);

    asio::ip::tcp::resolver::iterator it_end;

    for (; it != it_end; ++it)
    {
        // Here we can access the endpoint like this.
        asio::ip::tcp::endpoint ep = it->endpoint();
    }

    return 0;
}