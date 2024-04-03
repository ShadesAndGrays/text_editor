#include "button.hpp"
#include "panel.hpp"
#include "ui_manager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

ui::Button::Button(){
    this->panel = std::make_unique<Panel>();
    this->callback = [](){};
    font.loadFromFile("./font/SpaceMono-Italic.tff");
    txt = sf::Text("Hello",font,30);
    txt.setFillColor(sf::Color::Red);
}
ui::Button::Button(std::function<void()> callback){
    this->panel = std::make_unique<Panel>();
    font.loadFromFile("./font/SpaceMono-Italic.ttf");
    txt = sf::Text("Hello",font,30);
    txt.setFillColor(sf::Color::Red);
    this->callback = callback;
}

void ui::Button::setName(std::string name){
    this->name = name;
    txt.setString(name);
}

void ui::Button::draw(){
    this->panel->draw();
    this->panel->setVisible(isVisible());
    window->draw(txt);

}


void ui::Button::update(){

    if (this->actionPerformed()){
        panel->setBackground(fgColor);
        this->callback();
    }
    else{
        if (this->mouseOn()){
            panel->setBackground(sf::Color::Green);
        }
        else
        panel->setBackground(bgColor);
    }
    txt.setPosition(x,y);

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
