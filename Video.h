#ifndef VIDEO_H
#define VIDEO_H

#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
class Video {
private:
    string title;
    string content;
    Date date;

public:
    Video(); 
    Video(const string& title, const string& content, const Date& date); 
    Video(const Video& video);
    
   string getTitle() const; 
    bool lessThan(const Video& other) const; 
    void print() const; 
    void play() const; 


};

#endif
