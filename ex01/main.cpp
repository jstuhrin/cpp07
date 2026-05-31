
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

    iter(arr, 6, &incrementT<int>);

    iter(arr, 6, &printT<int>);

    std::cout << '\n';
  }

  {
    char array[] = {'a','b','c','d','e','f'};

    iter(array, 6, &printT<char>);

    std::cout << '\n';

    iter(array, 6, &incrementT<char>);

    iter(array, 6, &printT<char>);

    std::cout << '\n';

    iter(array, 6, &incrementT<char>);

    iter(array, 6, &printT<char>);

    std::cout << '\n';
  }

  {
    std::string strArr[] = {"first", "second", "third"};

    iter(strArr, 3, &printT<std::string>);

    std::cout << '\n';

    iter(strArr, 3, &incrementString);

    iter(strArr, 3, &printT<std::string>);

    std::cout << '\n';
  }

  {
    const double doubleArr[] = {0.0, 1.0, 2.1, 3.2, 4.3};

    iter(doubleArr, 5, &printT<const double>);

    std::cout << '\n';
  }

  return 0;
}