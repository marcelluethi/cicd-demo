d // server_tests.cpp
#include "hello_world_server.h"
#include <gtest/gtest.h>
#include <httplib.h>
#include <thread>

// Test Fixture for the Server class
class ServerTest : public ::testing::Test {
protected:
    Server *server;
    std::thread server_thread;

    // Set up the server before each test
    void SetUp() override {
        server = new Server("127.0.0.1", 8080);
        server_thread = std::thread([this]() { server->start(); });
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Give the server time to start
    }

    // Tear down the server after each test
    void TearDown() override {
        server->stop();
        server_thread.join();
        delete server;
    }
};

// Test case for the "/hello" endpoint
TEST_F(ServerTest, HelloEndpointReturnsWorld) {
    httplib::Client client("127.0.0.1", 8080);

    // Perform a GET request to the /hello endpoint
    auto res = client.Get("/hello");

    // Check that the response is valid and has the correct content
    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->status, 200);
    EXPECT_EQ(res->body, "world");
}

// Test case for an unknown endpoint
TEST_F(ServerTest, UnknownEndpointReturns404) {
    httplib::Client client("127.0.0.1", 8080);

    // Perform a GET request to an unknown endpoint
    auto res = client.Get("/unknown");

    // Check that the response is a 404 Not Found
    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->status, 404);
}

// Test case for a POST request (should return 404 since only GET is defined)
TEST_F(ServerTest, PostRequestReturns404) {
    httplib::Client client("127.0.0.1", 8080);

    // Perform a POST request to the /hello endpoint
    auto res = client.Post("/hello", "data", "text/plain");

    // Check that the response is a 404 Not Found
    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->status, 404);
}
