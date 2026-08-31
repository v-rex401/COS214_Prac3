#include "EventUnit.h"

EventUnit::EventUnit(std::string name){
    this->name = name;
    this->parent = nullptr;

}

void EventUnit::update(){
    if(this->parent != nullptr){
        EventNotice newev = this->parent->getNotice();
        this->currentNotice = newev;

    }
}

void EventUnit::add(EventComponent* cmp){

}

void EventUnit::remove(EventComponent* cmp){

}

void EventUnit::setParent(EventSubject* par){
    if(par != nullptr){
        this->parent = par;
    }
}

