 #include "Channel.h"

Channel::Channel(const string& title, const string& owner){
    this->title=title;
    this->owner=owner;
}


Channel::Channel(const Channel& other) : title(other.title), owner(other.owner), videos(other.videos) {}


Channel::~Channel() {}

// Getters
string Channel::getTitle() const {
    return title;
}

string Channel::getOwner() const {
    return owner;
}


bool Channel::lessThan(const Channel& other) const {
    bool check =title < other.title;
    return check;
}


bool Channel::addVideo(const string& title, const string& content, const Date& date) {
    Video* video = new Video(title, content, date);
    bool thereIsVideo = videos.addVideo(video);
    if (!thereIsVideo) {
        delete video; 
    }
    return thereIsVideo;
}


bool Channel::removeVideo(int index) {
    if (index < 0 || index >= videos.size()) {
        return false;
    }
    Video* removedVideo = videos.removeVideo(index);

    if (removedVideo) {

        return true; 
    } else {
        return false; 
    }
}


int Channel::getNumVideos() const {
    return videos.size();
}

void Channel::print() const {
    printVideos();
}

void Channel::printVideos() const {
    cout << "Channel Title: " << title << "\n" << "Owner: " << owner << "\n\n";

    if (videos.size() == 0) {
        cout << "No videos\n";
        return;
    }

    // Print all videos in the list
    for (int i = 0; i < videos.size(); ++i) {
        cout << i <<endl;
        Video* video = videos.getVideo(i); 
        if (video) {
            video->print();
            cout << "\n"<<endl;
        }
    }
}

void Channel::playVideo(int index) const {
    Video* video = videos.getVideo(index);
    if (video) {
        video->play();
    } else {
        cout << "Error found" << endl;
    }
}