#pragma once

#include <fstream>
#include "page.hpp"

class file
{

private:
    std::string file_path;
    std::fstream File;

public:
    std::string load_file(std::string path);
    void save_file(page Page);
    void save_file(page Page, std::string path);
};