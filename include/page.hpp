#pragma once

#include <vector>
#include <string>

class page
{
private:
    std::vector<std::string> lines;
    int current_line;
    int col;
    void fix_position();

public:
    page();
    int get_current_line();
    int get_col();
    void set_current_line(int line_number);
    std::string get_current_text();
    std::string get_text();
    void add_newline();
    void add_char(char txt);
    void delete_char();
    void delete_current_line();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
};
