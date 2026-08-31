#include "EventSubject.h"

void EventSubject::attach(EventObserver* x){
    bool duplicate = false;

    if(x != nullptr){
        for(EventObserver* obs : observerList){
            if(obs == x){
            duplicate = true;
            }
        }

    }

    if(!duplicate){
        observerList.push_back(x);
    }
}

void EventSubject::detach(EventObserver* y){
    
    if(y != nullptr){
        for(int i = 0; i< this->observerList.size(); i++){
            if(this->observerList[i] == y){
                observerList.erase(this->observerList.begin() +i);
                break;
            }
        }

    }

}

void EventSubject::notify(){
    for(EventObserver* obs : observerList){
        obs->update();
    }
}