//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef LISTCLIENTSREQUEST_H
#define LISTCLIENTSREQUEST_H
#include "Request.h"
#include "../../Network/Protocols.h"

class ListClientsRequest : public Request {
public:
    ListClientsRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::GET_LIST_CLIENTS, const uint32_t payloadSize)
    : Request(clientId, version, code, payloadSize) {}
    std::vector<uint8_t> buildPayload() const override {
        return {};
    };
    ~ListClientsRequest() override = default;
};



#endif //LISTCLIENTSREQUEST_H
