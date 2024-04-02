#include "button.hpp"
#include "panel.hpp"
#include "ui_manager.hpp"
#include <memory>

ui::Button::Button(){
    this->panel = std::make_unique<Panel>();
}

void ui::Button::draw(){
    this->panel->draw();
    this->panel->setVisible(isVisible());
}


void ui::Button::update(){

    if (this->actionPerformed()){
        panel->setBackground(fgColor);
    }
    else{
        if (this->mouseOn()){
            panel->setBackground(sf::Color::Green);
        }
        else
        panel->setBackground(bgColor);
    }
}

bool ui::Button::actionPerformed(){

    if (this->mouseOn() && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        return true;

    }

    return false;
}

void ui::Button::setWindow(sf::RenderWindow * window){
    UiElement::setWindow(window);
    panel->setWindow(window);
}

void ui::Button::setPosition(float x, float y){
    UiElement::setPosition(x, y);
    this->panel->setPosition(x,y);
}
void ui::Button::setSize(float width, float height){
    UiElement::setSize(width, height);
    this->panel->setSize(width,height);

}
