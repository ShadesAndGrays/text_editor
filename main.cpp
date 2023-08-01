#include <iostream>
#include "SFML/Graphics.hpp"
int main(){ 
 
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "My window");
   
    sf::Text Text;
        Text.setFillColor(sf::Color::Black);
        Text.setPosition(sf::Vector2f(0.0,0.0));
        sf::Font Font;
        Font.loadFromFile("font/ARIAL.TTF");
        Text.setFont(Font);
        std::string inputText = "";

        Text.setString(inputText);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 128)
                    continue;
                if (event.text.unicode  == 8 && !inputText.empty()){
                    inputText.pop_back();
                    }
                else if(event.text.unicode  == 13){inputText += '\n';}
                else                {
                    inputText += static_cast<char>(event.text.unicode);
                }
            Text.setString(inputText);
            }
        }
            window.clear(sf::Color::White);
            window.draw(Text);
            window.display();

    }
 
}