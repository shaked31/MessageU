//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <cstdint>
#include <string>
#include <vector>
#include "boost/asio.hpp"

using namespace boost::asio;

class NetworkManager {
private:
    struct ServerInfo {
        std::string IP;
        int port;
    };
    ip::tcp::socket _sock;
    io_context _io_ctx;

public:
    NetworkManager(const std::string& ip, const std::string& port);
    bool sendRequestToServer(const std::vector<uint8_t>& request);
    std::vector<uint8_t> receiveResponse();
    ~NetworkManager();
};



#endif //NETWORKMANAGER_H
