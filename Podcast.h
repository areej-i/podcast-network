#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class Podcast{

    public:
        //constructers
        Podcast(const string& title, const string& host);
        Podcast(Podcast&);
        ~Podcast();

        string getTitle();
        string getHost();
        int getNumEpisodes();
        bool addEpisode(string title,string content);
        bool getEpisode(int index, Episode ** ep);
        bool lessThan(Podcast& pod);
        void print();
    
    private:
        string title;
        string host;
        int numEps;
        Episode** epArr;
};
#endif