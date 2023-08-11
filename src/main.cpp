#include <iostream>
#include "SFML/Graphics.hpp"
#include "page.hpp"
#include <vector>
#include "SFML/Window/Keyboard.hpp"
// #include "SFML/System/Clock.hpp"

int main()
{
    page Page;
    sf::Clock Timer;
    sf::Time prev_time(sf::seconds(0.0));
    sf::Time current_time = Timer.getElapsedTime();

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "My window");
    window.setPosition(sf::Vector2i(500.0, 50.0));

    sf::Text Text;
    Text.setFillColor(sf::Color::Black);
    Text.setPosition(sf::Vector2f(0.0, 0.0));
    sf::Font Font;
    Font.loadFromFile("font/ARIAL.TTF");
    Text.setFont(Font);
    std::string inputText = "";
    Text.setString(inputText);

    sf::Text info_text;
    info_text.setFillColor(sf::Color::Black);
    info_text.setPosition(sf::Vector2f(650.0, 580.0));
    info_text.setFont(Font);
    info_text.setScale(sf::Vector2f(0.3, 0.3));

    bool is_cusor_moving = false;

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !is_cusor_moving)
        {
            Page.move_up();
            //   printf("up");
            is_cusor_moving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !is_cusor_moving)
        {
            Page.move_down();
            //    printf("down");
            is_cusor_moving = true;
        }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !is_cusor_moving)
        {
            Page.move_left();
            //   printf("up");
            is_cusor_moving = true;
        }
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !is_cusor_moving)
        {
            Page.move_right();
            //    printf("down");
            is_cusor_moving = true;
        }

        current_time = Timer.getElapsedTime();

        //  time delay CALLS
        if (current_time - prev_time >= sf::seconds(0.45))
        {
            // std::cout << current_time.asSeconds() << std::endl;
            prev_time = current_time;

            is_cusor_moving = false;
        }

        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered)
            {

                switch (event.text.unicode)
                {
                case 8: // Delete
                {

                    Page.delete_char();
                }
                break;
                case 13: // Enter
                {
                    Page.add_newline();
                }

                break;
                default:
                    // ELSE
                    {
                        Page.add_char(static_cast<char>(event.text.unicode));
                        //*(Page.get_current_text()) += /* std::to_string(event.text.unicode) + */ static_cast<char>(event.text.unicode);
                    }
                    break;
                }

                Text.setString(Page.get_text());
            }
                std::string info =  "Ln: " + std::to_string(Page.get_current_line()) + ", Col: " + std::to_string(Page.get_col())  ;
                info_text.setString(sf::String(info));
        }

        window.clear(sf::Color::White);


        window.draw(Text);
        window.draw(info_text);
        window.display();
    }
}