cmake_minimum_required(VERSION 3.31)
project(Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cryptopp CONFIG REQUIRED)

set(SOURCES
        main.cpp

        Menu/menu.cpp
        Menu/Requests/GetPublicKeyRequest.cpp
        Menu/Requests/GetWaitingMessagesRequest.cpp
        Menu/Requests/ListClientsRequest.cpp
        Menu/Requests/RegisterRequest.cpp
        Menu/Requests/Request.cpp
        Menu/Requests/SendMessageRequest.cpp

        Crypto/AESWrapper.cpp
        Crypto/RSAWrapper.cpp
        Crypto/Base64Wrapper.cpp

        Files/FileManager.cpp

        Network/NetworkManager.cpp
)

add_executable(Client ${SOURCES})

if (WIN32)
    target_link_libraries(Client ws2_32 cryptopp::cryptopp)
endif()