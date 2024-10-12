#include "app/zeklib.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
  zeklib::string line = "Hello";
  std::cout << (line + " world!") << std::endl;
  return 0;
}
