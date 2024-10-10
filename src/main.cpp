#include "hello_world_server.h"

int main() {
    // Create a server object with the desired host and port
    Server server("0.0.0.0", 8080);

    // Start the server
    server.start();

    return 0;
}