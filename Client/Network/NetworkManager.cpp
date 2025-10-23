//
// Created by Shaked Pollak on 9/23/2025.
//

#include "NetworkManager.h"
// #include "../include/asio.hpp"
#include "boost/asio.hpp"
using namespace boost::asio;
using ip::tcp;


NetworkManager::NetworkManager(const std::string &ip, const std::string &port) : _sock(_io_ctx) {
    tcp::resolver res(_io_ctx);
    connect(_sock, res.resolve(ip, port));
}

NetworkManager::~NetworkManager() {
    _sock.close();
}
