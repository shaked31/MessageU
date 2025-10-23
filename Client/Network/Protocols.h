//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef PROTOCOLS_H
#define PROTOCOLS_H
#include <cstdint>

enum class RequestCodeFromClient : uint16_t {
    REGISTER = 110,
    GET_LIST_CLIENTS = 120,
    GET_PUBLIC_KEY = 130,
    GET_WAITING_MESSAGES = 140,
    SEND_MESSAGE = 150,
    GET_SYMMETRIC_KEY = 151,
    SEND_SYMMETRIC_KEY = 152,
    SEND_FILE = 153
};

enum class RequestCodeToServer : uint16_t {
    REGISTER = 600,
    GET_LIST_CLIENTS = 601,
    GET_PUBLIC_KEY = 602,
    SEND_MESSAGE = 603,
    GET_WAITING_MESSAGES = 604
};

enum class MessageType : uint8_t {
    REQUEST_SYMMETRIC_KEY = 1,
    SEND_SYMMETRIC_KEY = 2,
    SEND_TEXT_MESSAGE = 3,
    SEND_FILE = 4
};

#endif //PROTOCOLS_H