#include "Subscriber.h"

Subscriber::Subscriber(const string& name, const string& creditCard){
    this->name = name;
    this->creditCard = creditCard;
}

bool Subscriber::matches(const string& n)
{
    if (n == name)
    {
        return true;
    }
    return false;
}

void Subscriber::print(){
    cout << "Name: " << name << " Credit card: " <<creditCard;
}