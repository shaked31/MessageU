//
// Created by Shaked Pollak on 9/23/2025.
//

#include "RegisterRequest.h"
#include "../../Network/Protocols.h"

RegisterRequest::RegisterRequest(const std::string& clientId, const uint8_t version, const uint32_t payloadSize,
        const std::string& name, const std::string& publicKey) : Request(clientId, version, RequestCode::REGISTER, payloadSize) {
    if (name.length() > 254) {
        throw std::invalid_argument("Name property is to large");
    }
    if (publicKey.length() > 160) {
        throw std::invalid_argument("public key property is to large");
    }
    _name = name;
    _publicKey = publicKey;
}

std::vector<uint8_t> RegisterRequest::buildPayload() {
    std::vector<uint8_t> buffer;
    buffer.insert(buffer.end(), _name.begin(), _name.end());

    buffer.push_back(0x00);

    buffer.insert(buffer.end(), _publicKey.begin(), _publicKey.end());

    return buffer;
}