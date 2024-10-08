// main.cpp
#include "app/zeklib.hpp"
#include <iostream>

int main()
{
  zeklib::vector<int> vec;

  // Adding elements
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  // Accessing elements
  std::cout << "Elements in vector:" << std::endl;
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  // Removing the last element
  vec.pop_back();

  // Checking size and capacity
  std::cout << "Size after pop: " << vec.size() << std::endl;
  std::cout << "Capacity: " << vec.capacity() << std::endl;

  // Using at() with bounds checking
  try
  {
    std::cout << "Element at index 1: " << vec.at(1) << std::endl;
    std::cout << "Element at index 5: " << vec.at(5) << std::endl; // This will throw
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
