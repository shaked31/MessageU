//
// Created by Shaked Pollak on 9/23/2025.
//

#include "Request.h"

#include <stdexcept>

Request::Request(const std::string& clientId, const uint8_t version, const RequestCode code, const uint32_t payloadSize)
    : _version(version), _code(code), _payloadSize(payloadSize) {
    if (clientId.length() > 16) {
        throw std::invalid_argument("clientID is larger than expected");
    }
    _clientId = clientId;
}


std::vector<uint8_t> Request::buildHeader() const {
    std::vector<uint8_t> header;

    header.insert(header.end(), _clientId.begin(), _clientId.end());

    header.push_back(_version);

    header.push_back(static_cast<uint16_t>(_code) & 0xFF);
    header.push_back((static_cast<uint16_t>(_code) >> 8) & 0xFF);

    header.push_back(_payloadSize & 0xFF);
    header.push_back((_payloadSize >> 8) & 0xFF);
    header.push_back((_payloadSize >> 16) & 0xFF);
    header.push_back((_payloadSize >> 24) & 0xFF);

    return header;
}