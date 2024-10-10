// hello_world_server.h
#ifndef HELLO_WORLD_SERVER_H
#define HELLO_WORLD_SERVER_H

#include <httplib.h>
#include <string>

class Server {
public:
    Server(const std::string &host, int port);
    ~Server();

    // Method to start the server
    void start();

    // Method to stop the server
    void stop();

private:
    std::string host_;
    int port_;
    httplib::Server svr_;  // Internal HTTP server object
};

#endif  // HELLO_WORLD_SERVER_H
