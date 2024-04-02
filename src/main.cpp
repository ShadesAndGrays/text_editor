#include "keyboard_input_observer.hpp"
#include "page.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ui.hpp>

int main()
{

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "My window");
    window.setPosition(sf::Vector2i(500.0, 50.0));
    page Page;
    
    ui::UiManager myUi(&window);
    myUi.addElement(std::make_shared<ui::Panel>());

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
        }


        window.clear(sf::Color::White);
        Page.draw(window);
        myUi.draw();
        window.display();
    }
}
