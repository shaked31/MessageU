//
// Created by Shaked Pollak on 9/23/2025.
//

#include "GetPublicKeyRequest.h"

#include <stdexcept>

GetPublicKeyRequest::GetPublicKeyRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::GET_PUBLIC_KEY,
                                         const uint32_t payloadSize, const std::string& targetClientId)
            : Request(clientId, version, code, payloadSize) {
    if (targetClientId.length() > 16) {
        throw std::invalid_argument("clientID is larger than expected");
    }
    _targetClientId = targetClientId;
}


std::vector<uint8_t> GetPublicKeyRequest::buildPayload() const {
    std::vector<uint8_t> buffer;

    buffer.insert(buffer.end(), _targetClientId.begin(), _targetClientId.end());

    return buffer;
}
