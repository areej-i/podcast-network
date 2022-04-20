#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "PodArray.h"
#include "Subscriber.h"
#include "defs.h"

using namespace std;

class Network{

    public:
        //constructers
        //Network(const string& name, PodArray *ptr, Subscriber *subArr, int numSubs);
        Network(const string& name);
        ~Network();

        //getters
        bool getPodcast(const string& pod, Podcast** podcast);
        bool getSubscriber(const string& name, Subscriber** sub);
        
        bool addPodcast(const string& podcast, const string& host);
        bool removePodcast(const string& podcast);
        bool addEpisode(const string& podcast, const string& title, const string& content);
        bool addSubscriber(const string& name, const string& creditCard);
        bool download(const string& subscriber, const string& pod, Podcast ** podcast);
        bool stream(const string& subscriber, const string& pod, int episode, Episode ** ep);
        bool hasSubscriber(const string& sub);
        void print();
    
    private:
        string name;
        PodArray *ptr;
        Subscriber* subArr[MAX_SUBS];
        int numSubs;
};
#endif