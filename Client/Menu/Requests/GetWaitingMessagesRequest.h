//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef GETWAITINGMESSAGESREQUEST_H
#define GETWAITINGMESSAGESREQUEST_H
#include "../../Network/Protocols.h"


class GetWaitingMessagesRequest : public Request {
public:
    GetWaitingMessagesRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::GET_WAITING_MESSAGES, const uint32_t payloadSize)
    : Request(clientId, version, code, payloadSize) {}
    std::vector<uint8_t> buildPayload() const override {
        return {};
    };
    ~GetWaitingMessagesRequest() override = default;
};


#endif //GETWAITINGMESSAGESREQUEST_H
