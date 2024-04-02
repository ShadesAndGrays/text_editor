#include "ui_manager.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

ui::UiElement::UiElement(){
    this->window = nullptr;
    this->visible = true;
    this->fgColor = sf::Color::White;
    this->bgColor = sf::Color::Black;
}

bool ui::UiElement::mouseOn(){
    const sf::Vector2 mousePos = sf::Mouse::getPosition(*(this->window));

    return this->region.contains(static_cast<sf::Vector2f>(mousePos));

    /* if (mousePos.x > this->x && mousePos.x < (this->x + this->sizeX)){
    if (mousePos.y > this->y && mousePos.y < (this->y + this->sizeY)){

        return true;
    }
    }
    return false; */
}
bool ui::UiElement::actionPerformed(){return false;}
bool ui::UiElement::isVisible(){return visible;}
void ui::UiElement::draw(){}
void ui::UiElement::update(){}
void ui::UiElement::setWindow(sf::RenderWindow * window){this->window = window;}


void ui::UiElement::setSize(float width , float height){
    std::cout<< width <<" "<<  0.01 << " "<< this->window->getSize().x << " : " << this->sizeX<<std::endl;
    if (width > 100)
        width = 100;
    else if (width < 0)
        width = 0;
    if (height > 100)
        height = 100;
    else if (height < 0)
        height = 0;

    this->sizeX = width * 0.01 * this->window->getSize().x;
    this->sizeY = height * 0.01 * this->window->getSize().y;
    this->region.width = width * 0.01 * this->window->getSize().x;
    this->region.height = height * 0.01 * this->window->getSize().y;

    std::cout << "Size: " << this->sizeX << " " << this->sizeY << std::endl;
}



void ui::UiElement::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    this->region.left = this->x;
    this->region.top = this->y;

}

void ui::UiElement::setBackground(sf::Color color){
    bgColor = color;
}
void ui::UiElement::setForeground(sf::Color color){
    fgColor =color;
}

void ui::UiElement::setVisible(bool visible){
    this->visible = visible;
}










ui::UiManager::UiManager(sf::RenderWindow * window){
    this->window = window;
}

void ui::UiManager::draw(){
    for (auto i : this->elements){
        i->draw();
    }
}

void ui::UiManager::update(){
    for (auto &i : this->elements){
        i->update();
    }
}

void ui::UiManager::addElement(std::shared_ptr<UiElement> element){
    element->setWindow(this->window);
    elements.push_back(element);
}
