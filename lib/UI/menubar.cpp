#include "menubar.hpp"
#include "button.hpp"
#include <SFML/Graphics/Color.hpp>
#include <memory>

ui::MenuBar::MenuBar(){
    this->area = Panel();
}

void ui::MenuBar::draw(){
    ui::UiElement::draw();
    this->area.draw();
    for (auto &i: buttons)
    {
        i->draw();
    }
}
void ui::MenuBar::addButton(std::string name,std::function<void()> callback){
    std::shared_ptr<Button> btn = std::make_shared<Button>(callback);
    btn->setWindow(window);
    btn->setSize(10,this->sizeY/(0.01 * this->window->getSize().y));
    btn->setPosition(this->x + 10 * 0.01 * this->window->getSize().x * buttons.size(),0);
    btn->setName(name);
    // btn->setBackground(this->fgColor);
    this->buttons.push_back(btn);
        std::cout << "Button" << name <<": PosX" << this->sizeX << "  PosY: "<< this->sizeY << std::endl;


}
void ui::MenuBar::setWindow(sf::RenderWindow * window){
    UiElement::setWindow(window);
    area.setWindow(window);
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->setWindow(window);
    }
}
void ui::MenuBar::setPosition(float x, float y){
    UiElement::setPosition(x, y);
    this->area.setPosition(x,y);
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->setSize(10,this->sizeY/(0.01 * this->window->getSize().y));
        buttons[i]->setPosition(this->x + 10 * 0.01 * this->window->getSize().x *buttons.size(),this->y);
    }
}
void ui::MenuBar::setSize(float width, float height){
    UiElement::setSize(width, height);
    this->area.setSize(width,this->sizeY/(0.01 * this->window->getSize().y));
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->setSize(10,this->sizeY/(0.01 * this->window->getSize().y));
        buttons[i]->setPosition(this->x + 11 * buttons.size(),this->y);
    }

}

void ui::MenuBar::setBackground(sf::Color color){
    this->area.setBackground(color);
}
void ui::MenuBar::setForeground(sf::Color color){
    for (int i = 0; i < buttons.size(); i++){
        // buttons[i]->setBackground(color);
    }
}
void ui::MenuBar::update() {
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->update();
    }
}
