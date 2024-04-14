#include "Client.h"
#include "ViewTube.h"

Client::Client(const std::string& name){
    this->name= name;
    this->channel= nullptr;
} 

Client::~Client() {
    delete channel;
}

bool Client::download(ViewTube& viewTube, int index) {
    Channel* newChannel;
    if (viewTube.download(index, &newChannel)) {
        delete channel; 
        channel = new Channel(*newChannel); 
        return true;
    } else {
        return false;
    }
}

void Client::print() const {
    cout << "Client: " << name << endl;
    if (channel) {
        channel->print();
    } else {
        cout << "No channel downloaded." << endl;
    }
}

void Client::printChannel() const {
    if (channel) {
        channel->printVideos();
    } else {
        cout << "No channel downloaded." << endl;
    }
}

void Client::play(int index) const {
    if (channel) {
        channel->playVideo(index);
    } else {
        cout << "No channel downloaded to play." << endl;
    }
}
