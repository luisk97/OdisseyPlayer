#ifndef VIDEOHANDLER_H
#define VIDEOHANDLER_H


#include <iostream>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <fstream>
#include <dirent.h>
#include "singleton.h"

typedef unsigned char byte;

class VideoHandler {
public:
    static std::string sendVideo(std::string pathFile);

    static int sendDirectory(std::string pathDirectory);

    static std::string getVideo(std::string fileName);
};

#endif // VIDEOHANDLER_H
