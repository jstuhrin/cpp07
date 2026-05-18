
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* arr, const std::size_t size, void (*func)(T&))
{
  for (std::size_t i = 0; i < size; ++i)
  {
    func(arr[i]);
  }
}

#endif
