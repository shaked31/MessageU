//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef MENU_H
#define MENU_H
#include <cstdint>
#include <string>
#include <vector>


class Menu {
private:
    struct MenuItem {
        uint16_t code;
        std::string description;
    };
    std::vector<MenuItem> _menuList;
public:
    Menu();
    void showMenu() const;
    friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
    uint16_t getUserChoice() const;
    void handleMenu(uint16_t code);

private:
    void registerReq();
};



#endif //MENU_H
