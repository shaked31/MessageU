//
// Created by Shaked Pollak on 9/23/2025.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>


class FileManager {
public:
    std::string readServerInfo();
    void saveToMeInfo();
    bool doesMeInfoExists();
};



#endif //FILEMANAGER_H
