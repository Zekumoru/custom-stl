# zkl STL Reimplementation

## Overview

`zkl` (zekumoru library) is a C++ library that offers custom implementations of two fundamental components of the Standard Template Library (STL): `std::vector` and `std::string`. These classes, `zkl::vector` and `zkl::string`, are designed to mimic the functionality and interface of their STL counterparts, providing an educational tool for understanding dynamic data structures and string manipulation in C++.

## Features

### `zkl::vector`
- **Dynamic Array**: Implements a resizable array similar to `std::vector`.
- **Template-Based**: Supports various data types through templating.
- **Core Functionalities**:
  - `push_back(const T& value)`: Adds an element to the end.
  - `pop_back()`: Removes the last element.
  - `at(size_t index)`: Accesses elements with bounds checking.
  - `operator[](size_t index)`: Accesses elements without bounds checking.
  - `size() const`: Returns the number of elements.
  - `capacity() const`: Returns the current capacity.
  - `empty() const`: Checks if the vector is empty.
  - `clear() const`: Removes all elements without altering capacity.
  - `reserve(size_t newCapacity)`: Reserves storage.
  
### `zkl::string`
- **Custom String Class**: Provides functionality akin to `std::string`.
- **Comprehensive Methods**:
  - **Constructors & Destructor**:
    - Default, C-string, copy, move constructors, and destructor.
  - **Assignment Operators**:
    - Copy and move assignment.
  - **Access Operators**:
    - `operator[]`, `at()`, `front()`, `back()`.
  - **Modification Methods**:
    - `append()`, `assign()`, `insert()`, `erase()`, `replace()`, `push_back()`, `pop_back()`.
  - **Concatenation Operators**:
    - `operator+=` and `operator+` for strings and characters.
  - **Search Methods**:
    - `find()`, `rfind()`, `find_first_of()`, `find_last_of()`, `find_first_not_of()`, `find_last_not_of()`.
  - **Utility Methods**:
    - `size()`, `length()`, `clear()`, `empty()`, `c_str()`, `data()`, `copy()`, `substr()`, `compare()`.
  - **Stream Operators**:
    - `operator<<`, `operator>>`, and `getline()` for input/output operations.
