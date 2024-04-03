#include "button.hpp"
#include "keyboard_input_observer.hpp"
#include "menubar.hpp"
#include "page.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ui.hpp>

int main()
{

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "My window");
    window.setPosition(sf::Vector2i(500.0, 50.0));
    sf::View pageScene = window.getDefaultView();
    sf::View uiScene = window.getDefaultView();

    page Page;
    ui::UiManager myUi(&window);
    std::shared_ptr<ui::MenuBar> menu = std::make_shared<ui::MenuBar>();
    myUi.addElement(menu);

    menu->setSize(100,5);
    menu->setPosition(0,0);
    menu->setBackground(sf::Color(133,183,140));
    menu->setForeground(sf::Color::White);
    menu->addButton("close",[&](){window.close();});


    while (window.isOpen())
    {
        Page.updatePage();
        sf::Event event;
        while(window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else 
                KeyboardInputObserver::getInstance()->listen(event);
            myUi.update();
        }


        window.clear(sf::Color::White);
        Page.draw(window);
        myUi.draw();
        window.display();
        // std::cout << "Window posX: "<< window.getPosition().x <<"posY: "<<window.getPosition().y<<std::endl;
        // std::cout << "Mouse posX: "<< sf::Mouse::getPosition().x <<"posY: "<<sf::Mouse::getPosition().y<<std::endl;
        // std::cout << "Mouse posX: "<< sf::Mouse::getPosition().x -window.getPosition().x <<"posY: "<<sf::Mouse::getPosition().y - window.getPosition().y<<std::endl;
    }
}
