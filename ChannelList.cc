#include "ChannelList.h"
#include <iostream>

ChannelList::ChannelList(){
   numChannels = 0;
    channels = new Channel*[MAX_CHANNELS];

}

ChannelList::~ChannelList() {
    for (int i = 0; i < numChannels; ++i) {
        delete channels[i];
    }
    delete[] channels;
}

bool ChannelList::addChannel(Channel* p) {
    if (isFull()) {
        return false;
    }
    channels[numChannels++] = p;
    return true;
}

Channel* ChannelList::getChannel(const std::string& title) const {
    for (int i = 0; i < numChannels; ++i) {
        if (title == channels[i]->getTitle()) {
            return channels[i];
        }
    }
    return nullptr;
}

Channel* ChannelList::getChannel(int index) const {
    if (index < 0 || index >= numChannels) return nullptr;
    return channels[index];
}

Channel* ChannelList::removeChannel(const std::string& title) {
    for (int i = 0; i < numChannels; ++i) {
        if (title == channels[i]->getTitle()) {
            Channel* goner = channels[i];
            for (int j = i; j < numChannels - 1; ++j) {
                channels[j] = channels[j + 1];
            }
            channels[--numChannels] = nullptr;
            return goner;
        }
    }
    return nullptr;
}

Channel* ChannelList::removeChannel(int index) {
    if (index < 0 || index >= numChannels) return nullptr;
    Channel* goner = channels[index];

    std::cout << "Channel deleted:\n";
    std::cout << "Title: " << goner->getTitle() << "\n";
    std::cout << "Owner: " << goner->getOwner() << "\n";

    for (int i = index; i < numChannels - 1; ++i) {
        channels[i] = channels[i + 1];
    }
    channels[--numChannels] = nullptr;
    return goner;
}

int ChannelList::size() const {
    return numChannels;
}

void ChannelList::print() const {
    for (int i = 0; i < numChannels; ++i) {
        channels[i]->print();
    }
}

bool ChannelList::isFull() const {
    return numChannels == MAX_CHANNELS;
}