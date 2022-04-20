#include "Podcast.h"
#include "defs.h"

Podcast::Podcast(const string& title, const string& host){
    this->title = title;
    this->host = host;
    epArr = new Episode*[MAX_EPS];
    numEps = 0;
}

Podcast::Podcast(Podcast &pod){
    title = pod.title;
    host = pod.host;
    epArr = new Episode*[MAX_EPS];
    for (int i =0; i < MAX_PODS;i++){
        epArr[i] = new Episode(*pod.epArr[i]);
    }
    //epArr = new Episode*(*pod.epArr);
    numEps = pod.numEps;
}

Podcast::~Podcast(){
    for(int j = 0; j < numEps; j++){
        delete epArr[j];
    }
    delete [] epArr;
}
string Podcast::getTitle(){
    return title;
}
string Podcast::getHost(){
    return host;
}
int Podcast::getNumEpisodes(){
    return numEps;
}

bool Podcast::addEpisode(string t,string content){
    if (numEps < MAX_EPS){
        Episode *ep = new Episode(title, numEps+1,t,content);
        //number = numEps + 1;
        epArr[numEps] = ep;
        numEps++;
        return true;
    }
    return false;
}

bool Podcast::getEpisode(int index, Episode ** ep){
    if (index <= numEps){
        *ep = epArr[index];
        return true;
    }
    return false;
}
bool Podcast::lessThan(Podcast& pod){
    if(this->title.compare(pod.title) > 0){
        return true;
    }
    return false;
}
void Podcast::print(){
    cout << endl << "Podcast: " << title;
    cout << endl << "Host: "<< host;
    cout <<endl << "Number of episodes: " <<numEps <<endl;
    // for (int i = 0; i < numEps; i++){
    //     epArr[i]->print();
    // }
}