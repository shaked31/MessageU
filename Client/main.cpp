#include <iostream>
#include "Menu/Menu.h"
#include "Crypto/RSAWrapper.h"
int main() {

    const Menu m;

    m.showMenu();

    int requestCode = m.getUserChoice();


    return 0;
}