
#include <stdexcept>

template <typename T>
Array<T>::Array()
  : n_(0)
  , arr_(new T[0])
{}

template <typename T>
Array<T>::Array(unsigned int n)
  : n_(n)
  , arr_(new T[n])
{}

template <typename T>
Array<T>::Array(const Array<T>& other)
  : n_(other.n_)
  , arr_(new T[n_])
{
  for (unsigned int i = 0; i < n_; ++i)
  {
    arr_[i] = other.arr_[i];
  }
}

template <typename T>
Array<T>::~Array()
{
  delete[] arr_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
  if (this == &other)
  {
    return *this;
  }
  arr_ = new T[other.n_];
  delete[] arr_;
  n_ = other.n_;
  for (unsigned int i = 0; i < n_; ++i)
  {
    arr_[i] = other.arr_[i];
  }
  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
  if (i >= n_)
  {
    throw std::out_of_range("Array indes out of range");
  }
  return arr_[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
  if (i >= n_)
  {
    throw std::out_of_range("Array indes out of range");
  }
  return arr_[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
  return n_;
}
