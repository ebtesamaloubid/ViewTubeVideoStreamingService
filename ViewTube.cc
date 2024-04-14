#include "ViewTube.h"

ViewTube::ViewTube() {}

ViewTube::~ViewTube() {
    for (Channel* channel : channelList) {
        delete channel;
    }
}

bool ViewTube::addChannel(const string& title, const string& owner) {
    Channel* newChannel = new Channel(title, owner);
    if (newChannel) {
        channelList.push_back(newChannel);
        return true;
    }
    return false;
}

bool ViewTube::deleteChannel(int index) {
    if (index < 0 || index >= channelList.size()) {
        cout << "Error: index not found" << endl;
        return false;
    }

    string title = channelList[index]->getTitle();
    string owner = channelList[index]->getOwner();

    delete channelList[index];

    for (int i = index; i < channelList.size() - 1; i++) {
        channelList[i] = channelList[i + 1];
    }

    channelList.pop_back();

    cout << "Channel deleted:\n" << "Title: " << title << "\n" << "Owner: " << owner << "\n";
    return true;
}

int ViewTube::getNumChannels() const {
    int size= channelList.size();
    return size;
}

bool ViewTube::addVideo(const string& channelTitle, const string& title, const string& content, const Date& date) {
    for (size_t i = 0; i < channelList.size(); ++i) {
        if (channelList[i]->getTitle() == channelTitle) {
            return channelList[i]->addVideo(title, content, date);
        }
    }
    cout << "Error: Channel with this title doesnt excit" << endl;
    return false;
}


bool ViewTube::deleteVideo(int channelIndex, int videoIndex) {
    if (channelIndex < 0 || channelIndex >= channelList.size()) {
        cout << "Error: Channel at this index doesnt exist " <<endl;
        return false;
    }
    bool check=channelList[channelIndex]->removeVideo(videoIndex);
    return check ;
}

bool ViewTube::download(int index, Channel** outChannel) {
    if (index < 0 || index >= channelList.size() || !outChannel) {
        return false;
    }
    *outChannel = channelList[index];
    return true;
}

void ViewTube::printChannels() const {
    std::cout << "\nViewTube\n========\n";
    for (size_t i = 0; i < channelList.size(); ++i) {
        cout << i << " Title: " << channelList[i]->getTitle() << "\nowner: " << channelList[i]->getOwner() <<"\n"<< endl;
    }
}

void ViewTube::printChannel(int index) const {
    if (index < 0 || index >= channelList.size()) {
       cout << "Error: Channel at this index doesnt exist " << endl;
        return;
    }
    channelList[index]->print();
}

void ViewTube::playVideo(int channelIndex, int videoIndex) const {
    if (channelIndex < 0 || channelIndex >= channelList.size()) {
        cout << "Error: Channel at this index doesnt exist"  << endl;
        return;
    }
    channelList[channelIndex]->playVideo(videoIndex);
}
