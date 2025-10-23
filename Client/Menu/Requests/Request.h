//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <cstdint>
#include <string>
#include <vector>
#include "../../Network/Protocols.h"

class Request {
protected:
    std::string _clientId;
    uint8_t _version;
    RequestCodeToServer _code;
    uint32_t _payloadSize;
public:
    Request(const std::string& clientId, const uint8_t version, const RequestCodeToServer code, const uint32_t payloadSize);
    virtual std::vector<uint8_t> buildPayload() const = 0 ;
    virtual std::vector<uint8_t> buildHeader() const;
    virtual ~Request() = default;
};



#endif //REQUEST_H
