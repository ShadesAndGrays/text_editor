#include "keyboard_input_observer.hpp"
#include <SFML/Window/Event.hpp>

KeyboardInputObserver *  KeyboardInputObserver::keyboardInputObserverInstance = nullptr;


Subsriber::Subsriber(unsigned id, std::function<void(sf::Event event)> callback): id(id), callback(callback){}

KeyboardInputObserver::KeyboardInputObserver(){}

KeyboardInputObserver* KeyboardInputObserver::getInstance(){
    if (keyboardInputObserverInstance == nullptr){
        keyboardInputObserverInstance = new KeyboardInputObserver;
    }
    return  keyboardInputObserverInstance;
}

unsigned KeyboardInputObserver::subscribe(std::function<void(sf::Event event)> callback){
    auto sub = Subsriber(mainId,callback);
    subscribers.push_back(sub);
    return mainId++;
}
void KeyboardInputObserver::listen(sf::Event event){
    for (Subsriber &i: subscribers){
        i.callback(event);
    }

}
