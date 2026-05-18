
#include <iostream>

#include "Array.hpp"

int main()
{
  Array<int> arr(10);

  for (std::size_t i = 0; i < 10; ++i)
  {
    arr[i] = i;
  }

  for (std::size_t i = 0; i < 10; ++i)
  {
    std::cout << arr[i] << ' ';
  }

  std::cout << '\n';

  return 0;
}