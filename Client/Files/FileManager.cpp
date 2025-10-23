//
// Created by Shaked Pollak on 9/23/2025.
//

#include "FileManager.h"

#include <filesystem>
#include <fstream>
#include <iostream>

const std::string serverInfoPath ="..\\server.info";
const std::string meInfoPath ="..\\me.info";

std::string FileManager::readServerInfo() {
    try {
        std::ifstream file(serverInfoPath);

        constexpr int MAX_PORT_LENGTH = 5;
        constexpr int MAX_IP_LENGTH = 15;

        int bufferLength = MAX_IP_LENGTH + 1 + MAX_PORT_LENGTH; // (1 for : )
        std::string buffer;
        file.read(buffer.data(), bufferLength);
        return buffer;
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cerr << "A filesystem related error has Occurred: " << e.what() << std::endl;
    }
    return "";
}

void FileManager::saveToMeInfo() {

}

bool FileManager::doesMeInfoExists() {
    if (std::filesystem::exists(meInfoPath)) {
        std::cerr << "me.info file already exists, can't register" << std::endl;
        return false;
    }
    return true;
}