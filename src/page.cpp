// page.cpp

#include "page.hpp"
#include "iostream"

page::page()
{
    current_line = -1;
    col = 0;
    add_newline();
}

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
        if (lines.size() > current_line)
        {
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