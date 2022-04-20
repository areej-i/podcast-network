#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode{

    public:
        //constructers
        Episode(const string& podcast, int number, const string& name,const string& content);
        Episode();

        void play();
        void print();
    
    private:
        string name;
        string content;
        string podcast;
        int number;
};
#endif