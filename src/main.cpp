#include <iostream>
#include "SFML/Graphics.hpp"
#include "page.hpp"
#include "file_loader.hpp"
#include <vector>
#include "SFML/Window/Keyboard.hpp"
// #include "SFML/System/Clock.hpp"

int main()
{

    file File;
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

    sf::CircleShape circ = sf::CircleShape(5);
    circ.setPosition(sf::Vector2f(500.0, 500.0));
    circ.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        if (is_cusor_moving)

            circ.setFillColor(sf::Color::Red);
        else
            circ.setFillColor(sf::Color::Blue);

        current_time = Timer.getElapsedTime();

        if (!is_cusor_moving)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                Page.move_up();
                //   printf("up");
                is_cusor_moving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                Page.move_down();
                //    printf("down");
                is_cusor_moving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                Page.move_left();
                //   printf("up");
                is_cusor_moving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                Page.move_right();
                //    printf("down");
                is_cusor_moving = true;
            }
        }
        else
        {
            //  time delay CALLS
            if (current_time - prev_time >= sf::seconds(0.45))
            {
                // std::cout << current_time.asSeconds() << std::endl;
                prev_time = current_time;

                is_cusor_moving = false;
                printf("\nTime reset");
            }
        }

        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;
        while (window.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {

                if (event.key.code == sf::Keyboard::Key::S && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    File.save_file(Page);
                    std::cout << "Ctrl + S pressed!" << std::endl;
                               }
            }

            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode > 128)
                    continue;

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
            }
            Text.setString(Page.get_text());
            std::string info = "Ln: " + std::to_string(Page.get_current_line()) + ", Col: " + std::to_string(Page.get_col());
            info_text.setString(sf::String(info));
        }

        window.clear(sf::Color::White);
        window.draw(circ);
        window.draw(Text);
        window.draw(info_text);
        window.display();
    }
}