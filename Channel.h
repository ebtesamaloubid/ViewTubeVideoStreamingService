#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include "VideoList.h" 

using namespace std;

class Channel {
public:
    // Constructors
    Channel(const string& title, const string& owner);
    Channel(const Channel& other);

    // Destructor
    ~Channel();

    // Member functions
    string getTitle() const;
    string getOwner() const;
    bool lessThan(const Channel& other) const;
    bool addVideo(const string& title, const string& content, const Date& date);
    bool removeVideo(int index);
    int getNumVideos() const;
    void print() const;
    void printVideos() const;
    void playVideo(int index) const;

private:
    string title;
    string owner;
    VideoList videos; 
};

#endif
