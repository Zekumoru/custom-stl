#pragma once

#include "zkl.hpp"
#include <cctype>
#include <cstring>
#include <stdexcept>

namespace zkl
{
  string::string() : _data(nullptr), _size(0)
  {
  }

  string::string(const char* string)
  {
    _size = std::strlen(string);
    _data = new char[_size + 1];
    std::strcpy(_data, string);
  }

  string::string(const string& other)
  {
    _size = other._size;
    _data = new char[_size + 1];
    std::strcpy(_data, other._data);
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
      std::strcpy(_data, other._data);
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

  std::istream& operator>>(std::istream& is, string& str)
  {
    str.clear();
    int c;

    // skip leading whitespace
    while (c = is.get())
    {
      if (!std::isspace(c))
      {
        str.push_back(c);
        break;
      }
    }

    if (is.eof())
      return is;

    // read until newline
    while (c = is.get())
    {
      if (std::isspace(c))
        break;
      str.push_back(c);
    }

    return is;
  }

  std::ostream& operator<<(std::ostream& os, const string& other)
  {
    os << (other._data != nullptr ? other._data : "");
    return os;
  }

  std::istream& getline(std::istream& is, string& str)
  {
    str.clear();
    int c;

    // skip leading whitespace
    while (c = is.get())
    {
      if (!std::isspace(c))
      {
        str.push_back(c);
        break;
      }
    }

    if (is.eof())
      return is;

    // read until newline
    while (c = is.get())
    {
      if (c == '\n' || c == '\r')
        break;
      str.push_back(c);
    }

    return is;
  }

  std::istream& getline(std::istream& is, string& str, char delim)
  {
    str.clear();
    int c;

    // skip leading whitespace
    while (c = is.get())
    {
      if (!std::isspace(c))
      {
        str.push_back(c);
        break;
      }
    }

    if (is.eof())
      return is;

    // read until delim
    while (c = is.get())
    {
      if (c == delim)
        break;
      str.push_back(c);
    }

    return is;
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
    temp._data = new char[temp._size + 1];
    std::memcpy(temp._data, _data, pos);
    std::memcpy(temp._data + pos, str._data, str._size);
    std::memcpy(temp._data + pos + str._size, _data + pos, _size - pos);
    temp._data[temp._size] = 0;
    *this = std::move(temp);

    return *this;
  }

  string& string::insert(size_t pos, const char* str)
  {
    size_t len = std::strlen(str);
    if (len == 0)
      return *this;

    if (pos > _size)
      pos = _size;

    string temp;
    temp._size = _size + len;
    temp._data = new char[temp._size + 1];
    std::memcpy(temp._data, _data, pos);
    std::memcpy(temp._data + pos, str, len);
    std::memcpy(temp._data + pos + len, _data + pos, _size - pos);
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

  string& string::replace(size_t pos, size_t len, const char* str)
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
    temp._data = new char[temp._size + 1];
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

  size_t string::copy(char* s, size_t len, size_t pos)
  {
    if (pos >= _size)
      return 0;

    if (pos + len > _size || pos + len < pos)
      len = _size - pos;

    // if s doesn't have enough space, will cause undefined behavior
    std::memcpy(s, _data + pos, len);
    return len;
  }

  size_t string::find(const string& str, size_t pos) const noexcept
  {
    // si = string index, fi = find index
    for (size_t si = pos; si < _size; si++)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0; fi++)
      {
        if (_data[si + fi] != str._data[fi])
          break;
      }
      if (fi == str._size) // string found
        return si;
    }

    return npos;
  }

  size_t string::find(char c, size_t pos) const noexcept
  {
    for (size_t i = pos; i < _size; i++)
    {
      if (c == _data[i])
        return i;
    }

    return npos;
  }

  size_t string::find(const string& str, size_t pos, size_t n) const noexcept
  {
    // si = string index, fi = find index
    for (size_t si = pos; si < _size; si++)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0 && fi != n; fi++)
      {
        if (_data[si + fi] != str._data[fi])
          break;
      }
      if (fi == str._size || fi == n) // string found
        return si;
    }

    return npos;
  }

  size_t string::rfind(const string& str, size_t pos) const noexcept
  {
    if (pos >= _size)
      pos = _size - 1;

    // si = string index, fi = find index
    for (size_t si = pos; si != npos; si--)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0; fi++)
      {
        if (_data[si + fi] != str._data[fi])
          break;
      }
      if (fi == str._size) // string found
        return si;
    }

    return npos;
  }

  size_t string::rfind(char c, size_t pos) const noexcept
  {
    if (pos >= _size)
      pos = _size - 1;

    for (size_t i = pos; i != npos; i--)
    {
      if (c == _data[i])
        return i;
    }

    return npos;
  }

  size_t string::find_first_of(const string& str, size_t pos) const
  {
    // si = string index, fi = find index
    for (size_t si = pos; si < _size; si++)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0; fi++)
      {
        if (_data[si] == str._data[fi])
          return si; // match found
      }
    }

    return npos;
  }

  size_t string::find_first_of(char c, size_t pos) const
  {
    for (size_t i = pos; i < _size; i++)
    {
      if (_data[i] == c)
        return i; // match found
    }

    return npos;
  }

  size_t string::find_last_of(const string& str, size_t pos) const
  {
    if (pos >= _size)
      pos = _size - 1;

    // si = string index, fi = find index
    for (size_t si = pos; si != npos; si--)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0; fi++)
      {
        if (_data[si] == str._data[fi])
          return si; // match found
      }
    }

    return npos;
  }

  size_t string::find_last_of(char c, size_t pos) const
  {
    if (pos >= _size)
      pos = _size - 1;

    for (size_t i = pos; i != npos; i--)
    {
      if (_data[i] == c)
        return i; // match found
    }

    return npos;
  }

  size_t string::find_first_not_of(const string& str, size_t pos) const
  {
    // si = string index, fi = find index
    for (size_t si = pos; si < _size; si++)
    {
      size_t fi;
      for (fi = 0; str._data[fi] != 0; fi++)
      {
        if (_data[si] == str._data[fi])
          break;
      }
      if (fi == str._size)
        return si; // match found
    }

    return npos;
  }

  size_t string::find_first_not_of(char c, size_t pos) const
  {
    for (size_t i = pos; i < _size; i++)
    {
      if (_data[i] != c)
        return i; // match found
    }

    return npos;
  }

  size_t string::find_last_not_of(const string& str, size_t pos) const
  {
    if (pos >= _size)
      pos = _size - 1;

    // si = string index, fi = find index
    for (size_t si = pos; si != -1; si--)
    {
      size_t fi;
      for (fi = 0; fi < str._size; fi++)
      {
        if (_data[si] == str._data[fi])
          break;
      }
      if (fi == str._size)
        return si; // match found
    }

    return npos;
  }

  size_t string::find_last_not_of(char c, size_t pos) const
  {
    if (pos >= _size)
      pos = _size - 1;

    for (size_t i = pos; i != -1; i--)
    {
      if (_data[i] != c)
        return i;
    }

    return npos;
  }

  string string::substr(size_t pos, size_t len) const
  {
    // the logic below has been recurring somewhere in the code above and
    // honestly there's a need to explain if I ever forget what the logic does
    // basically the logic will match the length to the maximum _data length so
    // that it won't memory copy over the _data array.
    // pos + len > _size checks if the pos + len goes beyond the _data array
    // pos + len < pos checks if an addition with a negative (a very big number)
    // occurs (negative like -1 but size_t doesn't have negatives)
    if (pos + len > _size || pos + len < pos)
      len = _size - pos;

    string str; // Won't create a copy since the compiler will do a NRVO

    str._size = len;
    str._data = new char[str._size + 1];
    std::memcpy(str._data, _data + pos, len);
    str._data[str._size] = 0;

    return str;
  }

  int string::compare(const string& str) const noexcept
  {
    for (size_t i = 0; i < _size && i < str._size; i++)
    {
      const int diff = _data[i] - str._data[i];
      if (diff != 0)
        return diff;
    }

    if (_size > str._size)
      return 1;
    if (_size < str._size)
      return -1;
    return 0; // seems silly but needed for when both strings are empty
  }

  int string::compare(size_t pos, size_t len, const string& str) const noexcept
  {
    if (pos > _size)
    {
      throw std::out_of_range("Position out of range");
    }

    // ti = this' data index, si = str's data index
    size_t ti;
    size_t si;
    for (ti = pos, si = 0; ti < _size && si < str._size && si < len; ti++, si++)
    {
      const int diff = _data[ti] - str._data[si];
      if (diff != 0)
        return diff;
    }

    // case: all matches except len is bigger than str's size
    // return remaining length (negative size_t) which is capped by str's size
    if (len > si)
      return (pos + len > _size ? _size - pos - si : len - si);

    // case: all matches except len is shorter than str's size
    // return missing length (positive size_t)
    if (len < str._size)
      return len - str._size;

    return 0;
  }

  bool operator==(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) == 0;
  }

  bool operator!=(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) != 0;
  }

  bool operator<(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) < 0;
  }

  bool operator<=(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) <= 0;
  }

  bool operator>(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) > 0;
  }

  bool operator>=(const string& lhs, const string& rhs) noexcept
  {
    return lhs.compare(rhs) >= 0;
  }

  void swap(string& x, string& y)
  {
    x.swap(y);
  }
} // namespace zkl