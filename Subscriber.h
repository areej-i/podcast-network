#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;

class Subscriber{

    public:
        //constructor
        Subscriber(const string& name, const string& creditCard);

        bool matches(const string& name);
        void print();
    
    private:
        string name;
        string creditCard;
};
#endif