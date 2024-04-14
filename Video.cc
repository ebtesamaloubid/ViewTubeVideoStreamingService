#include "Video.h"

Video::Video(){ 
    this->title=" no title";
    this ->content=" no content";
    this->date=Date();
    } 

Video::Video(const string& title, const string& content, const Date& date) {
    this->title = title;
    this->content = content;
    this->date = date;
}


Video::Video(const Video& video) {
    this->title = video.title;
    this->date = video.date;
    this->content = video.content;
}

string Video::getTitle() const {
    return title;
}


bool Video::lessThan(const Video& other) const {
    return date.lessThan(other.date);
}


void Video::print() const {
   cout << "Video:   " << title << "\nDate added: ";
    date.print();
    cout<< "\n" << endl;
}




void Video::play() const {
    cout << "Now watching" << endl;
    print(); 
    cout << content << endl; 
}
