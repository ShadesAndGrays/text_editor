#include "../include/file_loader.hpp"
#include <iostream>
/*  std::string load_file(std::string path);
   void save_file();
   void save_file(std::string path);
*/

void file::save_file(page Page)
{
   try
   {
      File.open("Untitled.txt", std::ios::out);
      if (!File.is_open())
         throw std::runtime_error("Failed to open file");
      File << Page.get_text();
      
      File.close();
   }
   catch (const std::exception& e)
   {
      std::cerr << "Exception: " << e.what() << std::endl;
   }
}
