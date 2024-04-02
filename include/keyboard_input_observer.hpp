#pragma once
#include <SFML/Window/Event.hpp>
#include <functional>
#include <vector>
class Subsriber{
    private:
        unsigned id;
    public:
        std::function<void(sf::Event event)> callback;
        Subsriber(unsigned id, std::function<void(sf::Event event)> callback);


};
class KeyboardInputObserver{
    private:
        static KeyboardInputObserver * keyboardInputObserverInstance ;
        KeyboardInputObserver();
        unsigned mainId;
        std::vector<Subsriber> subscribers;
    public:
        static KeyboardInputObserver * getInstance();
        unsigned subscribe(std::function<void(sf::Event event)> callback);
        void listen(sf::Event event);


};


