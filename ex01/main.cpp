
#include <cassert>
#include <iostream>

#include "iter.hpp"

namespace
{
  void printInt(int& i)
  {
    std::cout << i << ' ';
  }

  void incrementInt(int& i)
  {
    ++i;
  }

  template <typename T>
  void printT(T& t)
  {
    std::cout << t << ' ';
  }

  template <typename T>
  void incrementT(T& t)
  {
    ++t;
  }

  void toUpper(std::string& s)
  {
    for (std::size_t i = 0; i < s.size(); ++i)
    {
      s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
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

    iter(arr, 6, &incrementT);

    iter(arr, 6, &printT);

    std::cout << '\n';
  }

  {
    char array[] = {'a','b','c','d','e','f'};

    iter(array, 6, &printT);

    std::cout << '\n';

    iter(array, 6, &incrementT);

    iter(array, 6, &printT);

    std::cout << '\n';

    iter(array, 6, &incrementT);

    iter(array, 6, &printT);

    std::cout << '\n';
  }

  {
    std::string strArr[] = {"first", "second", "third"};

    iter(strArr, 3, &printT);

    std::cout << '\n';

    iter(strArr, 3, &toUpper);

    iter(strArr, 3, &printT);

    std::cout << '\n';
  }

  return 0;
}