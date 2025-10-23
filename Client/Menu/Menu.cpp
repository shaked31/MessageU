//
// Created by Shaked Pollak on 9/23/2025.
//

#include "Menu.h"

#include <algorithm>
#include <iostream>
#include <ranges>

#include "../Files/FileManager.h"
#include "../Network/Protocols.h"
#include "Requests/RegisterRequest.h"
#include "Requests/Request.h"

#define MAX_USERNAME_LENGTH 254
#define VERSION uint16_t(2)

void clearMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

Menu::Menu() {
    _menuList = {
        {110, "Register"},
        {120, "Request for clients list"},
        {130, "Request for public key"},
        {140, "Request for waiting messages"},
        {150, "Send a text message"},
        {151, "Send a request for symmetric key"},
        {152, "Send your symmetric key"},
        {153, "Send a file"},
        {0, "Exit"}
    };
}

std::ostream& operator<<(std::ostream& os, const Menu& menu) {
    for (const auto& [code, description] : menu._menuList) {
        os << code << ") " << description << std::endl;
    }
    os << "?";
    return os;
}

void Menu::showMenu() const {
    clearMenu();
    std::cout << *this << std::endl;
}

uint16_t Menu::getUserChoice() const {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        try {
            int codeChoice = std::stoi(input);
            auto it = std::ranges::find_if(_menuList,
               [codeChoice](const MenuItem& item) {
                   return item.code == codeChoice;
               });
            if (it != _menuList.end()) {
                return static_cast<uint16_t>(codeChoice);
            }
            std::cerr << "Invalid code choice" << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Enter a valid number" << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Number out of range" << std::endl;
        }
    }
}

void Menu::handleMenu(const uint16_t code) {
    Request* req;
    FileManager fm;
    switch (code) {
        case static_cast<uint16_t>(RequestCodeFromClient::REGISTER):
            if (fm.doesMeInfoExists()) {
            }
            clearMenu();
            std::string usernameInput;
            std::getline(std::cin, usernameInput);
            while (usernameInput.length() > MAX_USERNAME_LENGTH) {
                throw std::invalid_argument("Username is to long, the maximum is 254 chars");
            }
            req = new RegisterRequest("", VERSION, );
    }
}
