#pragma once

#include <SFML/Window/Event.hpp>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class page
{
private:
    // Individual lines on the screen
    std::vector<std::string> lines;
    int current_line;
    int col;
    void fix_position();
    void handleEvent(sf::Event event);

    sf::Clock Timer;
    sf::Text Text;
    sf::Font Font;
    sf::Time prev_time;
    sf::Time current_time;
    std::string inputText;
    sf::Text info_text;
    bool is_cusor_moving;


public:
    page();
    // text info
    int get_current_line();
    int get_col();
    void set_current_line(int line_number);

    // retrival
    std::string get_current_text();
    std::string get_text();

    // insertion and deletioin
    void add_newline();
    void add_char(char txt);
    void delete_char();
    void delete_current_line();

    // navigation
    void move_up();
    void move_down();
    void move_left();
    void move_right();

    void draw(sf::RenderWindow &window);

void updatePage();


};
