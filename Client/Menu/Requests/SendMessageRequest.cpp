//
// Created by Shaked Pollak on 9/23/2025.
//

#include "SendMessageRequest.h"

#include <stdexcept>

SendMessageRequest::SendMessageRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::SEND_MESSAGE, const uint32_t payloadSize,
    const std::string& targetClientId, const MessageType messageType, const uint32_t contentSize, const std::string& messageContent)
        : Request(clientId, version, code, payloadSize), _messageType(messageType) {
    if (targetClientId.length() > 16) {
        throw std::invalid_argument("clientID is larger than expected");
    }
    _targetClientId = targetClientId;

    if (messageType == MessageType::REQUEST_SYMMETRIC_KEY) {
        _contentSize = 0;
        _messageContent = "";
    }
    else {
        _contentSize = contentSize;
        _messageContent = messageContent;
    }
}

std::vector<uint8_t> SendMessageRequest::buildPayload() const override {
    std::vector<uint8_t> buffer;

    buffer.insert(buffer.end(), _targetClientId.begin(), _targetClientId.end());

    buffer.push_back(static_cast<uint8_t>(_messageType));

    buffer.push_back(_contentSize & 0xFF);
    buffer.push_back((_contentSize >> 8) & 0xFF);
    buffer.push_back((_contentSize >> 16) & 0xFF);
    buffer.push_back((_contentSize >> 24) & 0xFF);

    buffer.insert(buffer.end(), _messageContent.begin(), _messageContent.end());

    return buffer;
}