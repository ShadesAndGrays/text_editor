#include "panel.hpp"
#include <SFML/Window/Mouse.hpp>

ui::Panel::Panel(){
}

void ui::Panel::draw(){

    ui::UiElement::draw();

    this->rect.setPosition(this->x,this->y);
    this->rect.setSize(sf::Vector2(this->sizeX,this->sizeY));
    this->rect.setFillColor(this->bgColor);

    if (this->window == nullptr){
        return;
    }
    if (!this->visible){
        return;
    }
    this->window->draw(this->rect);
}

bool ui::Panel::actionPerformed(){

    return false;
}
