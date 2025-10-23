//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef REGISTERREQUEST_H
#define REGISTERREQUEST_H
#include <iostream>
#include <string>
#include "../../Network/Protocols.h"
#include "Request.h"



class RegisterRequest : public Request {
private:
    std::string _name;
    std::string _publicKey;
public:
    RegisterRequest(const std::string& clientId, uint8_t version, uint32_t payloadSize,
        const std::string& name, const std::string& publicKey);
    std::vector<uint8_t> buildPayload() const override;
    ~RegisterRequest() override = default;
};



#endif //REGISTERREQUEST_H
