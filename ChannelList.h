#ifndef CHANNELLIST_H
#define CHANNELLIST_H

#include "Channel.h"

class ChannelList {
private:
    int numChannels;
    Channel** channels; // Pointer to an array of Channel pointers

public:
    ChannelList();
    ~ChannelList();

    bool addChannel(Channel* p);
    Channel* getChannel(const std::string& title) const;
    Channel* getChannel(int index) const;
    Channel* removeChannel(const std::string& title);
    Channel* removeChannel(int index);
    int size() const;
    void print() const;
    bool isFull() const;
};

#endif 
