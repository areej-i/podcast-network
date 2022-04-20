#include "Client.h"

Client::Client(const string& name){
    this->name = name;
    ptr = new PodArray();
}

Client::~Client(){
    delete ptr;
}

void Client::download(Network *network, const string& podcast){
    if (ptr->isFull())
        cout << "unable to download podcast from Network -- In Client";
    else
    {
        Podcast* p1 = new Podcast(podcast,podcast);
        network->getPodcast(podcast,&p1);    
        ptr->addPodcast(p1);
    }    
}

void Client::stream(Network *network, const string& podcast, int episode){

    Podcast * p1 = new Podcast(podcast,podcast);
    if (network->getPodcast(podcast,&p1))
    {
        Episode * e1 = new Episode();
        p1->getEpisode(episode,&e1);
        e1->play();
        delete e1;
    }

    delete p1;
}

void Client::playLocal(const string& podcast, int episode){
    Podcast * p1 = new Podcast(podcast,podcast);
    if (ptr->getPodcast(podcast,&p1))
    {
        Episode * e1 = new Episode();
        p1->getEpisode(episode,&e1);
        e1->play();
        //delete e1;
    }
    else
    {
        cout << endl << "unable to play locally.";
    }

    //delete p1;
}

void Client::print(){
    cout << "name: " <<name;
    ptr->print();
}