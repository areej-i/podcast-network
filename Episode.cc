#include "Episode.h"

Episode::Episode(){
    podcast = "n/a";
    number = 0;
    name = "n/a";
    content = "n/a";
}

Episode::Episode(const string& podcast, int number, const string& name,const string& content){
    this->podcast = podcast;
    this->number = number;
    this->name = name;
    this->content = content;
}

void Episode::play(){
    cout << endl << "Episode " << number <<": " <<name <<endl;
    cout << "Podcast: " << podcast <<endl;
    cout <<"Content: " << content <<endl;
}

void Episode::print(){
    play();
}