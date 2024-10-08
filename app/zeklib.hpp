#pragma once

#include <cstddef>

namespace zeklib
{
  template <typename T>
  class vector
  {
  private:
    T *_array;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t newCapacity);

  public:
    vector();
    vector(size_t initialCapacity);
    ~vector();

    void push_back(const T &value);
    void pop_back();
    T &at(size_t index);
    const T &at(size_t index) const;
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void clear() const;
    void reserve(size_t newCapacity);
  };
}

#include "vector.tpp"
