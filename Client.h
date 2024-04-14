#ifndef CLIENT_H
#define CLIENT_H

#include "Channel.h"
#include <iostream>
#include <string>
class ViewTube;
class Client {
private:
    std::string name;
    Channel* channel;

public:
    Client(const std::string& name);
    ~Client();

    bool download(ViewTube& viewTube, int index);
    void print() const;
    void printChannel() const;
    void play(int index) const;
};

#endif 
