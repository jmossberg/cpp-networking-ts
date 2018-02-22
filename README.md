# cpp-networking-ts
Examples using experimental version of C++ networking ts

The examples in this repository is based on the [talk by Michael Caisse on CppCon 2017](https://www.youtube.com/watch?v=2UC6_rfJuAw)

## Where to find information in the talk

* The stream example (networking-ts-stream.cpp) is based on information starting at 4:59 in the talk
* The synchronous example (networking-ts-sync.cpp) is based on information starting at 10:20 in the talk
* The asynchronous example (networking-ts-async.cpp) is based on information starting at 26:57 in the talk

## Clone Networking TS draft implementation

```
cd ~
mkdir git
cd git
git clone https://github.com/chriskohlhoff/networking-ts-impl.git
```

## How to build examples

`make build`

## How to run examples

`make run`

## How to view output from examples

`cat <example name>.o.output.txt`

Example:
`cat networking-ts-stream.o.output.txt`

## Links

* Networking TS Implementation - [https://github.com/chriskohlhoff/networking-ts-impl.git](https://github.com/chriskohlhoff/networking-ts-impl.git)
* Boost Overivew - [http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/overview.html](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/overview.html)
* Boost Async Example - [http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/example/cpp11/chat/chat_client.cpp](http://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/example/cpp11/chat/chat_client.cpp)
