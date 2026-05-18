
#include <iostream>
#include <cassert>

#include "Array.hpp"

int main()
{
  // testing default constructor and size() method
  Array<char> charArr;
  assert(charArr.size() == 0);

  // testing parameterized constructor and [] operator
  Array<int> intArr(10);
  assert(intArr.size() == 10);
  for (int i = 0; i < 10; ++i)
  {
    intArr[i] = i;
  }
  for (int i = 0; i < 10; ++i)
  {
    assert(intArr[i] == i);
  }

  // testing copy constructor
  Array<int> copy(intArr);
  assert(copy.size() == 10);
  for (int i = 0; i < 10; ++i)
  {
    assert(copy[i] == intArr[i]);
  }
  for (int i = 0; i < 10; ++i)
  {
    intArr[i] = intArr[i] + 10;
  }
  for (int i = 0; i < 10; ++i)
  {
    assert(copy[i] != intArr[i]);
  }

  // testing exception for access out of range
  try
  {
    intArr[100] = 100;
    assert(false);
  }
  catch (std::out_of_range e)
  {

  }

  // testing copy assignment operator
  Array<std::string> strArr(10);
  assert(strArr.size() == 10);

  for (int i = 0; i < 10; ++i)
  {
    strArr[i] = "original";
  }

  Array<std::string> strArrCopy;
  assert(strArrCopy.size() == 0);

  strArrCopy = strArr;
  assert(strArrCopy.size() == 10);

  for (int i = 0; i < 10; ++i)
  {
    assert(strArrCopy[i] == "original");
  }

  for (int i = 0; i < 10; ++i)
  {
    strArrCopy[i] = "copy";
  }

  for (int i = 0; i < 10; ++i)
  {
    assert(strArr[i] == "original");
    assert(strArrCopy[i] == "copy");
  }

  // testing const overload of [] operator
  const std::string s = strArrCopy[5];

  assert(s == "copy");

  return 0;
}