#include <iostream>
#include "SFML/Graphics.hpp"
int main(){ 
 
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "My window");
   
    sf::Text Text;
        Text.setFillColor(sf::Color::Black);
        //Text.setPosition(sf::Vector2f(0.0,0.0));
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

/* #include <SFML/Graphics.hpp>
#include <string>

int main()
{
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Text Editor");

    sf::Font font;
    if (!font.loadFromFile("font/ARIAL.TTF"))
    {
        // Replace "arial.ttf" with the path to a font file on your system
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    

    std::string inputText;
    for (int i = 31; i < 128; i++){
        if (i %10 == 0)
           inputText += '\n';
    inputText += std::to_string(i)+":"+ static_cast<char>(i) +" ";
    }
    text.setString(inputText);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 && !inputText.empty())
                    {
                        // Backspace was pressed, remove the last character
                        inputText.pop_back();
                    }
                    else if (event.text.unicode == 13)
                    {
                        // Enter key was pressed, add a newline character
                        inputText += '\n';
                    }
                    else
                    {
                        // Add the typed character to the text
                        inputText += static_cast<char>(event.text.unicode);
                    }

                    // Update the text displayed on the screen
                    text.setString(inputText+"_");
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}
 */