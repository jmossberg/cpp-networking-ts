#include <experimental/net>
#include <iostream>
#include <string>

namespace net = std::experimental::net;
using namespace std::literals::string_literals;

int main()
{
    net::io_context io_context;
    net::ip::tcp::socket socket(io_context);
    net::ip::tcp::resolver resolver(io_context);

    std::cout << "networking ts sync example" << std::endl;
    
    net::connect(socket, resolver.resolve("ipecho.net", "http"));

    for(auto v : { "GET /plain HTTP/1.0\r\n"s
                 , "Host: ipecho.net\r\n"s
                 , "Accept: */*\r\n"s
                 , "Connection: close\r\n\r\n"s } )
    {
        net::write(socket, net::buffer(v));
    }

    std::string header;
    net::read(socket, net::dynamic_buffer(header),
              [&header](auto ec, auto n) -> std::size_t
              {
                 if(ec ||
                    (   header.size() > 3
                     && header.compare(header.size()-4, 4,
                                       "\r\n\r\n") == 0 ))
                 {
                     return 0;
                 }
                 return 1;
              }
              );

    std::cout << "header: " << header << std::endl;
    
    std::string body;
    std::error_code e;
    net::read(socket, net::dynamic_buffer(body),
              [](auto ec, auto n) -> std::size_t
              {
                 if(ec) { return 0; }
                 return 1;
              },
              e
              );

    if(e == net::error::eof){
        // Connection closed by peer
        // http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/tutorial/tutdaytime1/src.html
    }else if(e){
        std::cout << "body error: " << e << std::endl;
    }

    std::cout << "body: " << body << std::endl;
}

