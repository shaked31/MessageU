//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef GETPUBLICKEYREQUEST_H
#define GETPUBLICKEYREQUEST_H
#include "Request.h"
#include "../../Network/Protocols.h"

class GetPublicKeyRequest : public Request{
private:
    std::string _targetClientId;
public:
    GetPublicKeyRequest(const std::string& clientId, const uint8_t version, const RequestCode code = RequestCode::GET_PUBLIC_KEY,
        const uint32_t payloadSize, const std::string& targetClientId);
    std::vector<uint8_t> buildPayload() const override;
    ~GetPublicKeyRequest() override = default;

};



#endif //GETPUBLICKEYREQUEST_H
