#include "keyboard_input_observer.hpp"
#include "page.hpp"
#include "panel.hpp"
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
    std::shared_ptr<ui::Panel> pan = std::make_shared<ui::Panel>();
    std::shared_ptr<ui::Button> btn = std::make_shared<ui::Button>();
    myUi.addElement(pan);
    myUi.addElement(btn);
    pan->setSize(100,100);
    pan->setPosition(0,0);
    pan->setBackground(sf::Color(133,183,140));

    btn->setPosition(0, 0);
    btn->setSize(100,10);
    btn->setForeground(sf::Color::Yellow);
    btn->setBackground(sf::Color::Magenta);
    pan->setVisible(false);

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
