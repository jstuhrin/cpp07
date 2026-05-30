
#include <cassert>
#include <iostream>

#include "iter.hpp"

namespace
{
  void printInt(const int& i)
  {
    std::cout << i << ' ';
  }

  void incrementInt(int& i)
  {
    ++i;
  }

  template <typename T>
  void printT(const T& t)
  {
    std::cout << t << ' ';
  }

  template <typename T>
  void incrementT(T& t)
  {
    ++t;
  }

  void incrementString(std::string& s)
  {
    for (std::size_t i = 0; i < s.size(); ++i)
    {
      incrementT(s[i]);
    }
  }
}

int main()
{
  {
    int arr[] = {0,1,2,3,4,5};

    iter(arr, 6, &printInt);

    std::cout << '\n';

    iter(arr, 6, &incrementInt);

    iter(arr, 6, &printInt);

    std::cout << '\n';

    iter(arr, 6, static_cast<void (*)(int&)>(&incrementT)); // explicitly instantiate the function pointer, otherwise the compiler does not know which overload to choose

    iter(arr, 6, static_cast<void (*)(const int&)>(&printT));

    std::cout << '\n';
  }

  {
    char array[] = {'a','b','c','d','e','f'};

    iter(array, 6, static_cast<void (*)(const char&)>(&printT));

    std::cout << '\n';

    iter(array, 6, static_cast<void (*)(char&)>(&incrementT));

    iter(array, 6, static_cast<void (*)(const char&)>(&printT));

    std::cout << '\n';

    iter(array, 6, static_cast<void (*)(char&)>(&incrementT));

    iter(array, 6, static_cast<void (*)(const char&)>(&printT));

    std::cout << '\n';
  }

  {
    std::string strArr[] = {"first", "second", "third"};

    iter(strArr, 3, static_cast<void (*)(const std::string&)>(&printT));

    std::cout << '\n';

    iter(strArr, 3, &incrementString);

    iter(strArr, 3, static_cast<void (*)(const std::string&)>(&printT));

    std::cout << '\n';
  }

  {
    const double doubleArr[] = {0.0, 1.0, 2.1, 3.2, 4.3};

    iter(doubleArr, 5, static_cast<void (*)(const double&)>(&printT));

    std::cout << '\n';
  }

  return 0;
}