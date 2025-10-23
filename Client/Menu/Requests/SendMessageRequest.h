//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef SENDTOCLIENTREQUEST_H
#define SENDTOCLIENTREQUEST_H
#include <cstdint>
#include <string>
#include <vector>

#include "Request.h"
#include "../../Network/Protocols.h"


class SendMessageRequest : public Request {
private:
    std::string _targetClientId;
    MessageType _messageType;
    uint32_t _contentSize;
    std::string _messageContent;
public:
    SendMessageRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::SEND_MESSAGE, const uint32_t payloadSize,
    const std::string& targetClientId, const MessageType messageType, const uint32_t contentSize, const std::string& messageContent);
    std::vector<uint8_t> buildPayload() const override;
    ~SendMessageRequest() override = default;
};



#endif //SENDTOCLIENTREQUEST_H