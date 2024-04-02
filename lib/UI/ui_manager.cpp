#include "ui_manager.hpp"

ui::UiElement::UiElement(){
    this->window = nullptr;
    this->visible = true;
    this->fgColor = sf::Color::White;
    this->bgColor = sf::Color::Black;
    this->x = 0;
    this->y = 0;
    this->sixeX = 64;
    this->sizeY = 64;
}

bool ui::UiElement::mouseOn(){ return false;}
bool ui::UiElement::actionPerformed(){return false;}
bool ui::UiElement::isVisible(){return visible;}
void ui::UiElement::draw(){}
void ui::UiElement::setWindow(sf::RenderWindow * window){this->window = window;}


void setSize(float width , float height);

void setPosition(float x, float y);

ui::UiManager::UiManager(sf::RenderWindow * window){
    this->window = window;
}

void ui::UiManager::draw(){
    for (auto i : this->elements){
        i->draw();
    }
}
void ui::UiManager::addElement(std::shared_ptr<UiElement> element){
    element->setWindow(this->window);
    elements.push_back(element);

}
