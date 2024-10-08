#pragma once

#include "zeklib.hpp"
#include <stdexcept>

namespace zeklib
{
  template <typename T>
  vector<T>::vector()
      : _array(nullptr), _size(0), _capacity(0)
  {
  }

  template <typename T>
  vector<T>::vector(size_t initialCapacity) : _array(nullptr), _size(0), _capacity(initialCapacity) {}

  template <typename T>
  vector<T>::~vector()
  {
    delete[] _array;
  }

  template <typename T>
  void vector<T>::reallocate(size_t newCapacity)
  {
    T *newArray = new T[newCapacity];

    for (size_t i = 0; i < _size; ++i)
    {
      newArray[i] = _array[i];
    }

    delete[] _array;

    _array = newArray;
    _capacity = newCapacity;
  }

  template <typename T>
  void vector<T>::push_back(const T &value)
  {
    if (_size >= _capacity)
    {
      size_t newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
      reallocate(newCapacity);
    }

    _array[_size] = value;
    _size++;
  }

  template <typename T>
  void vector<T>::pop_back()
  {
    if (_size == 0)
    {
      throw std::out_of_range("Vector is empty");
    }
    _size--;

    size_t halfCapacity = _capacity / 2;
    if (_size < halfCapacity && halfCapacity >= 1)
    {
      reallocate(halfCapacity);
    }
  }

  template <typename T>
  T &vector<T>::at(size_t index)
  {
    if (index >= _size)
    {
      throw std::out_of_range("Index out of range");
    }

    return _array[index];
  }

  template <typename T>
  const T &vector<T>::at(size_t index) const
  {
    return at(index);
  }

  template <typename T>
  T &vector<T>::operator[](size_t index)
  {
    return _array[index];
  }

  template <typename T>
  const T &vector<T>::operator[](size_t index) const
  {
    return _array[index];
  }

  template <typename T>
  size_t vector<T>::size() const
  {
    return _size;
  }

  template <typename T>
  size_t vector<T>::capacity() const
  {
    return _capacity;
  }

  template <typename T>
  bool vector<T>::empty() const
  {
    return _size == 0;
  }

  template <typename T>
  void vector<T>::clear() const
  {
    _size = 0;
    reallocate(0);
  }

  template <typename T>
  void vector<T>::reserve(size_t newCapacity)
  {
    if (capacity >= newCapacity)
      return;
    reallocate(newCapacity);
  }
}
