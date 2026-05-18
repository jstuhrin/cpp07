
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
  public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);
    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;

    unsigned int size() const;

  private:
    T* arr_;
    unsigned int n_;
};

#include "Array.tpp"

#endif