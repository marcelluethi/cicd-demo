// hello_world_server.cpp
#include "hello_world_server.h"
#include <iostream>

// Constructor initializes the host and port
Server::Server(const std::string &host, int port) : host_(host), port_(port) {
    // Define the /hello endpoint that responds with "world"
    svr_.Get("/hello", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello SE Students", "text/plain");
    });
}

// Destructor (if needed for cleanup)
Server::~Server() {
    stop();  // Ensure the server is stopped
}

// Start the server on the specified host and port
void Server::start() {
    std::cout << "Server started at http://" << host_ << ":" << port_ << "\n";
    svr_.listen(host_.c_str(), port_);
}

// Stop the server gracefully
void Server::stop() {
    svr_.stop();
    std::cout << "Server stopped.\n";
}
