// page.cpp
#include "keyboard_input_observer.hpp"
#include "page.hpp"
#include "file_loader.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <iostream>

page::page()
{
    // Text coordinates
    current_line = -1;
    col = 0;
    add_newline();


    file File;

    prev_time = current_time = Timer.getElapsedTime();

    std::string inputText = "";
    sf::Text info_text;
    bool is_cusor_moving = "";


    Text.setFillColor(sf::Color::Black);
    Text.setPosition(sf::Vector2f(0.0, 0.0));
    Font.loadFromFile("font/SpaceMono-Regular.ttf");
    Text.setFont(Font);
    Text.setString(inputText);

    info_text.setFillColor(sf::Color::Black);
    info_text.setPosition(sf::Vector2f(650.0, 580.0));
    info_text.setFont(Font);
    info_text.setScale(sf::Vector2f(0.3, 0.3));

    KeyboardInputObserver::getInstance()->subscribe(
            std::function<void(sf::Event event)>([&](sf::Event event){this->handleEvent(event);}));
}
// void (MyEntity::*handleEventCallback)(const sf::Event&)
int page::get_current_line()
{
    return current_line;
}
int page::get_col()
{
    return col;
}

void page::set_current_line(int line_number)
{
    if (line_number < 0)
        return;
    if (line_number >= lines.size())
        return;
    current_line = line_number;
}

std::string page::get_current_text()
{
    return lines[current_line];
}

std::string page::get_text()
{
    std::string text = "";
    for (auto i : lines)
    {
        text += i + '\n';
    }
    return text;
}

void page::add_newline()
{
    col = 0;
    current_line += 1;
    lines.push_back(std::string());
}

void page::delete_current_line()
{
    if (current_line <= 0)
        return;
    // delete lines[current_line];
    lines.erase(lines.begin() + current_line);
    current_line -= 1;
    col = lines[current_line].size();
}

void page::fix_position()
{
    if (current_line < 0)
        current_line = 0;
    else if (current_line > lines.size())
        current_line = lines.size();
    if (col < 0)
        col = 0;
    else if (col > lines[current_line].size())
        col = lines[current_line].size();
}
void page::move_up()
{
    if (current_line <= 0)
        return;
    current_line--;
    fix_position();
}

void page::move_down()
{
    if (current_line >= lines.size() - 1)
        return;
    current_line++;
    fix_position();
}

void page::move_left()
{
    if (col <= 0)
    {
        if (current_line > 0)
        {
            move_up();
            col = lines[current_line].size();
            return;
        }
        col = 0;
        return;
    }
    col--;
}
void page::move_right()
{
    // std::cout << lines[current_line].size();
    if (col >= lines[current_line].size())
    {
        if (lines.size()-1 > current_line)
        {
            //std::cout << lines.size()-1 << "   and   " << current_line;
            move_down();
            col = 0;
            return;
        }
        col = lines[current_line].size();
        return;
    }
    col++;
}
void page::add_char(char txt)
{
    if (col < 0 || col > lines[current_line].size())
    {
        std::cerr << "text is OUT OF BOUNDS" << std::endl;
        return;
    }
    lines[current_line].insert(col, 1, txt);
    move_right();
    
}

void page::delete_char()
{
    if (lines[current_line].empty())
    {
        delete_current_line();
        col = lines[current_line].size();
        return;
    }
    if (col == 0)
    {
        if (current_line == 0)
            return;
        std::string temp = lines[current_line];
        delete_current_line();
        lines[current_line] += temp;
        return;
    }

    move_left();
    lines[current_line].erase(col, 1);
    return;
}
void page::updatePage(){

        current_time = Timer.getElapsedTime();
        bool moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8);

        if (!is_cusor_moving)
        {
            if (moveUp)
            {
                this->move_up();
                   printf("up");
                is_cusor_moving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
            {
                this->move_down();
                    printf("down");
                is_cusor_moving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                this->move_left();
                //   printf("up");
                is_cusor_moving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                this->move_right();
                //    printf("down");
                is_cusor_moving = true;
            }
        }
        else
        {
            //  time delay CALLS
            if (current_time - prev_time >= sf::seconds(0.75))
            {
                // std::cout << current_time.asSeconds() << std::endl;
                prev_time = current_time;

                is_cusor_moving = false;
                printf("\nTime reset");
            }
        }

        // check all the window's events that were triggered since the last iteration of the loop
}

void page::handleEvent(sf::Event event){

    if (event.type == sf::Event::KeyPressed)
    {

        if (event.key.code == sf::Keyboard::Key::S && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        {
            //File.save_file(Page);
            std::cout << "Ctrl + S pressed!" << std::endl;
        }
    }

    else if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode > 128)
            return;

        switch (event.text.unicode)
        { case 8: // Delete
                {

                   this->delete_char();
                }
                break;
            case 13: // Enter
                {
                    this->add_newline();
                }

                break;
            default:
                // ELSE
                {
                    this->add_char(static_cast<char>(event.text.unicode));
                    //*(Page.get_current_text()) += /* std::to_string(event.text.unicode) + */ static_cast<char>(event.text.unicode);
                }
                break;
        }
    }
    Text.setString(this->get_text());
    std::string info = "Ln: " + std::to_string(this->get_current_line()) + ", Col: " + std::to_string(this->get_col());
    info_text.setString(sf::String(info));
}

void page::draw(sf::RenderWindow &window){
    window.draw(this->Text);

}
