#include <experimental/net>
#include <iostream>
#include <string>
#include <chrono>

namespace net = std::experimental::net;
using namespace std::chrono_literals;

int main()
{
    std::cout << "networking ts stream example" << std::endl;

    net::ip::tcp::iostream s;

    s.expires_after(5s);
    s.connect("ipecho.net", "http");

    if(!s) {
        std::cout << "error: " << s.error().message() << std::endl;
        return -1;
    }

    s << "GET /plain HTTP/1.0\r\n";
    s << "Host: ipecho.net\r\n";
    s << "Accept: */*\r\n";
    s << "Connection: close\r\n\r\n";

    std::string header;
    while(s && std::getline(s, header) && header != "\r")
        std::cout << header << "\n";

    std::cout << s.rdbuf();
    std::cout << std::endl;
}
