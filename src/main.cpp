#include <iostream>
#include <iterator>
#include <algorithm>
#include<boost/asio.hpp>
#include<spdlog/spdlog.h>
#include<boost/signals2.hpp>
#include <boost/lambda/lambda.hpp>
#include<boost/serialization/array.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>



void SignalSlotFunc()
{
    // Define a signal with one std::string parameter and no return value
    boost::signals2::signal<void(const uint16_t,const std::string&)> signalMessage;

    // Connect the slot to the signal
    signalMessage.connect([=](const uint16_t var,const std::string& message){
        std::cout<<var << "---- Slot received: " << message<<std::endl;
    });

    // Emit the signal
    signalMessage(2,"Hello from Boost.Signals2!");
}
void SimpleTcpClient()
{
    try {
        boost::asio::io_context io_context;

        // Resolve the server address and port
        boost::asio::ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("192.168.0.103", "9090");

        // Create and connect the socket
        boost::asio::ip::tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::cout << "Connected to server." << std::endl;

        // Send message
        std::string msg = "Hello from Boost TCP client!";
        boost::asio::write(socket, boost::asio::buffer(msg));

        // Receive response
        char reply[1024] = {};
        size_t reply_length = socket.read_some(boost::asio::buffer(reply));
        std::cout << "Reply from server: ";
        std::cout.write(reply, reply_length);
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cin.get();
}
void spdLogFunc()
{
    // Create a console logger (stdout)
    auto console = spdlog::stdout_color_mt("console");

    console->info("This is an info message");
    console->warn("This is a warning message");
    console->error("This is an error message");

    // You can also use the default logger directly:
    spdlog::info("Logging directly with spdlog::info()");
}
int main()
{
    SignalSlotFunc();
    spdLogFunc();
    SimpleTcpClient();
    return 0;
}
