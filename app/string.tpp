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
    os << (other._data != nullptr ? other._data : "");
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

  string& string::append(size_t n, char c)
  {
    if (n != 0)
    {
      string temp;
      temp._size = _size + n;
      temp._data = new char[temp._size + 1];
      std::memcpy(temp._data, _data, _size);
      std::memset(temp._data + _size, c, n);
      temp._data[temp._size] = 0;
      *this = std::move(temp);
    }

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

  string& string::assign(const string& str, size_t subpos, size_t sublen)
  {
    if (subpos >= str._size)
    {
      sublen = 0;
    }

    if (sublen && (subpos + sublen > str._size || subpos + sublen < subpos))
    {
      sublen = str._size - subpos;
    }

    delete[] _data;

    _size = sublen;
    _data = new char[_size + 1];
    std::memcpy(_data, str._data + subpos, sublen);
    _data[_size] = 0;

    return *this;
  }

  string& string::assign(const string& str)
  {
    *this = str;
    return *this;
  }

  string& string::assign(const char* s, size_t n)
  {
    size_t sublen = std::strlen(s);
    if (sublen > n)
      sublen = n;

    delete[] _data;

    _size = sublen;
    _data = new char[_size + 1];
    std::memcpy(_data, s, sublen);
    _data[_size] = 0;

    return *this;
  }

  string& string::assign(size_t n, char c)
  {
    delete[] _data;

    _size = n;
    _data = new char[_size + 1];
    std::memset(_data, c, _size);
    _data[_size] = 0;

    return *this;
  }

  string& string::insert(size_t pos, const string& str)
  {
    if (pos > _size)
      pos = _size;

    string temp;
    temp._size = _size + str._size;
    temp._data = new char[_size + 1];
    std::memcpy(temp._data, _data, pos);
    std::memcpy(temp._data + pos, str._data, str._size);
    std::memcpy(temp._data + pos + str._size, _data + pos, _size - pos);
    temp._data[temp._size] = 0;
    *this = std::move(temp);

    return *this;
  }

  string& string::erase(size_t pos, size_t len)
  {
    if (pos >= _size)
      return *this;

    if (pos + len > _size || pos + len < pos)
      len = _size - pos;

    string temp;
    temp._size = _size - len;
    temp._data = new char[temp._size + 1];
    std::memcpy(temp._data, _data, pos);
    std::memcpy(temp._data + pos, _data + pos + len, _size - len - pos);
    temp._data[temp._size] = 0;

    *this = std::move(temp);
    return *this;
  }

  string& string::replace(size_t pos, size_t len, const string& str)
  {
    erase(pos, len);
    insert(pos, str);
    return *this;
  }

  void string::swap(string& str)
  {
    string temp = std::move(*this);
    *this = std::move(str);
    str = std::move(temp);
  }

  void string::pop_back()
  {
    if (_size == 0)
      return;

    string temp;
    temp._size = _size - 1;
    temp._data = new char[_size + 1];
    std::memcpy(temp._data, _data, temp._size);
    temp._data[temp._size] = 0;
    *this = std::move(temp);
  }

  const char* string::c_str() const noexcept
  {
    return _data;
  }

  const char* string::data() const noexcept
  {
    return _data;
  }
} // namespace zeklib