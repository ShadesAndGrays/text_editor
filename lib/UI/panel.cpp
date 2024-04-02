#include "panel.hpp"

ui::Panel::Panel(){

}

void ui::Panel::draw(){

    ui::UiElement::draw();
    std::cout << "Hello" << std::endl;

    this->rect.setPosition(this->x,this->y);
    this->rect.setSize(sf::Vector2(this->sixeX,this->sizeY));
    this->rect.setFillColor(this->bgColor);

    if (this->window == nullptr){
        std::cout << "window not set" << std::endl;
        return;
    }
    if (!this->visible){

        std::cout << "element is not visible" << std::endl;
        return;
    }
    this->window->draw(this->rect);
}

bool ui::Panel::mouseOn() {

    return  false;
}
bool ui::Panel::actionPerformed(){

    return false;
}
