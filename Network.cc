#include "Network.h"

Network::Network(const string& n){
    name = n;
    //this->ptr = ptr;
    ptr = new PodArray();
    numSubs=0;
}
Network::~Network(){
    for (int i=0; i < numSubs; i++){
        delete subArr[i];
    }
    //delete [] subArr;
}
bool Network::getPodcast(const string& pod, Podcast** podcast){
    if (ptr->getPodcast(pod,podcast))
        return true;
    return false;
}

bool Network::addPodcast(const string& podcast, const string& host){
    if (ptr->isFull()){
        return false;
    }
    else
    {
        Podcast *p1 = new Podcast(podcast,host);
        ptr->addPodcast(p1);
        delete p1;
        return true;
    }
}
bool Network::removePodcast(const string& podcast){
    Podcast * p1 = new Podcast(podcast,podcast);
    ptr->removePodcast(podcast,&p1);
	return true;
}
bool Network::addEpisode(const string& podcast, const string& title, const string& content){
    Podcast * p1 = new Podcast(podcast,podcast);
    for (int i = 0; i < ptr->size(); i++)
    {
        if (ptr->getPodcast(podcast,&p1))
        {
            p1->addEpisode(title,content);
            return true;
        }
    }
    delete p1;
    return false;
}
bool Network::addSubscriber(const string& name, const string& creditCard){
    if (numSubs < MAX_SUBS){
        Subscriber *s1 = new Subscriber(name,creditCard);
        subArr[numSubs] = s1;
        numSubs++;
        //delete s1;
        return true;
    }
    return false;
}
bool Network::download(const string& subscriber, const string& pod, Podcast ** podcast){
    for (int i = 0; i < numSubs;i++){
        if (subArr[i]->matches(subscriber))
        {
            if(ptr->getPodcast(pod,podcast)){
                return true;
            }
            else
                cout << "no such podcast";
            return false;
        }
    }
    cout << "no such subscriber";
    return false;
}
bool Network::stream(const string& subscriber, const string& pod, int episode, Episode ** ep){
    
    for (int i = 0; i < numSubs;i++){
        if (subArr[i]->matches(subscriber))
        {
            Podcast * p1 = new Podcast(pod,pod);
            if (ptr->getPodcast(pod,&p1)){
                if (p1->getEpisode(episode,ep)){
                    return true;
                }
                else
                    cout <<endl<< "no such episode";
                return false;
            }
            else
                cout <<endl << "no such podcast";
            return false;
        }
    }
    cout <<endl << "no such subscriber";
    //delete p1;
    return false;
}
bool Network::hasSubscriber(const string& sub)
{
    for (int i = 0; i < numSubs; i++)
    {
        if (subArr[i]->matches(sub))
        {
            return true;
        }
    }
    return false;
}
void Network::print(){
    cout << endl << "Network: " <<name <<endl;
    if (numSubs > 0)
    {
        cout << endl << "Subscribers: " <<endl;
        for (int i=0; i < numSubs; i++){
            subArr[i]->print();
        }
    }
    ptr->print();

}