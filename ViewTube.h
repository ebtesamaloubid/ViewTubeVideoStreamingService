
#ifndef VIEWTUBE_H
#define VIEWTUBE_H

#include <iostream>
#include <vector>
#include "Channel.h"

class ViewTube {
private:
    vector<Channel*> channelList;

public:
    ViewTube();
    ~ViewTube();

    bool addChannel(const string& title, const string& owner);
    bool deleteChannel(int index);
    int getNumChannels() const;

    bool addVideo(const string& channel, const string& title, const string& content, const Date& date);
    bool deleteVideo(int channelIndex, int videoIndex);

    bool download(int index, Channel** outChannel);

    void printChannels() const;
    void printChannel(int index) const;
    void playVideo(int channelIndex, int videoIndex) const;
};

#endif 
