#pragma once

#include "zeklib.hpp"
#include <cstring>
#include <stdexcept>

namespace zeklib
{
  string::string() : _data(nullptr), _size(0)
  {
  }

  string::string(const char* string)
  {
    _size = std::strlen(string);
    _data = new char[_size + 1];
    strcpy(_data, string);
  }

  string::string(const string& other)
  {
    _size = other._size;
    _data = new char[_size + 1];
    strcpy(_data, other._data);
  }

  string::string(string&& other) noexcept
  {
    _size = other._size;
    _data = other._data;

    other._data = nullptr;
  }

  string::~string()
  {
    delete[] _data;
  }

  string& string::operator=(const string& other)
  {
    if (this != &other)
    {
      delete[] _data;

      _size = other._size;
      _data = new char[_size + 1];
      strcpy(_data, other._data);
    }

    return *this;
  }

  string& string::operator=(string&& other) noexcept
  {
    if (this != &other)
    {
      delete[] _data;

      _size = other._size;
      _data = other._data;

      other._data = nullptr;
    }

    return *this;
  }

  std::ostream& operator<<(std::ostream& os, const string& other)
  {
    os << other._data;
    return os;
  }

  size_t string::size() const
  {
    return _size;
  }

  size_t string::length() const
  {
    return _size;
  }

  void string::clear()
  {
    _size = 0;
    delete[] _data;
    _data = nullptr;
  }

  bool string::empty() const
  {
    return _size == 0;
  }

  char& string::operator[](const size_t index)
  {
    return _data[index];
  }

  const char& string::operator[](const size_t index) const
  {
    return _data[index];
  }

  char& string::at(const size_t index)
  {
    if (index >= _size)
    {
      throw std::out_of_range("Index out of range");
    }

    return _data[index];
  }

  const char& string::at(const size_t index) const
  {
    if (index >= _size)
    {
      throw std::out_of_range("Index out of range");
    }

    return _data[index];
  }

  char& string::front()
  {
    return _data[0];
  }

  char& string::back()
  {
    return _data[_size - 1];
  }

  const char& string::front() const
  {
    return _data[0];
  }

  const char& string::back() const
  {
    return _data[_size - 1];
  }

  string& string::operator+=(const string& other)
  {
    string temp;
    temp._size = _size + other._size;
    temp._data = new char[temp._size + 1];

    memcpy(temp._data, _data, _size);
    memcpy(temp._data + _size, other._data, other._size);
    temp._data[temp._size] = 0;

    *this = std::move(temp);
    return *this;
  }

  string& string::operator+=(const char* str)
  {
    string temp;
    size_t strSize = std::strlen(str);
    temp._size = _size + strSize;
    temp._data = new char[temp._size + 1];

    memcpy(temp._data, _data, _size);
    memcpy(temp._data + _size, str, strSize);
    temp._data[temp._size] = 0;

    *this = std::move(temp);
    return *this;
  }

  string& string::operator+=(char c)
  {
    string temp;
    temp._size = _size + 1;
    temp._data = new char[temp._size + 1];

    memcpy(temp._data, _data, _size);
    temp._data[temp._size - 1] = c;
    temp._data[temp._size] = 0;

    *this = std::move(temp);
    return *this;
  }

  string operator+(const string& left, const string& right)
  {
    string str(left);
    str += right;
    return str;
  }

  string operator+(char left, const string& right)
  {
    string str;
    str._size = 1;
    str._data = new char[2];
    str[0] = left;
    str[1] = 0;

    str += right;
    return str;
  }

  string operator+(const string& left, char right)
  {
    string str(left);
    str += right;
    return str;
  }

  string& string::append(const string& str)
  {
    *this += str;
    return *this;
  }

  string& string::append(const string& str, size_t subpos, size_t sublen)
  {
    if (subpos >= str._size)
      return *this;

    if (subpos + sublen > str._size || subpos + sublen < subpos)
    {
      sublen = str._size - subpos;
    }

    if (sublen == 0)
      return *this;

    string temp;
    temp._size = _size + sublen;
    temp._data = new char[temp._size + 1];
    std::memcpy(temp._data, _data, _size);
    std::memcpy(temp._data + _size, str._data + subpos, sublen);
    temp._data[temp._size] = 0;
    *this = std::move(temp);

    return *this;
  }

  string& string::append(const char* str)
  {
    *this += str;
    return *this;
  }

  string& string::append(const char* str, size_t n)
  {
    size_t sublen = std::strlen(str);
    if (sublen > n)
      sublen = n;

    if (sublen == 0)
      return *this;

    string temp;
    temp._size = _size + sublen;
    temp._data = new char[temp._size + 1];
    std::memcpy(temp._data, _data, _size);
    std::memcpy(temp._data + _size, str, sublen);
    temp._data[temp._size] = 0;

    *this = std::move(temp);
    return *this;
  }

  string& string::push_back(char c)
  {
    *this += c;
    return *this;
  }

  string& string::assign(const char* str) // this is to prevent dangling reference with the other overloaded assign
  {
    *this = str;
    return *this;
  }

  string& string::assign(const string& str)
  {
    *this = str;
    return *this;
  }
} // namespace zeklib