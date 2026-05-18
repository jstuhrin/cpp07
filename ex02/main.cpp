
#include <iostream>
#include <cassert>

#include "Array.hpp"

int main()
{
  // test: default constructor and size() method
  Array<char> charArr;
  assert(charArr.size() == 0);

  // test: copy constructor size 0
  Array<char> charArrCopy(charArr);
  assert(charArrCopy.size() == 1);

  // test: copy assignment operator size 0
  Array<char> charArr1(10);
  assert(charArr1.size() == 10);
  charArr1 = charArr;
  assert(charArr1.size() == 0);

  // test: parameterized constructor and [] operator
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

  // test: copy constructor
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

  // test: exception for access out of range
  try
  {
    intArr[100] = 100;
    assert(false);
  }
  catch (const std::out_of_range& e)
  {

  }

  // test: copy assignment operator
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

  // test: const overload of [] operator
  const std::string s = strArrCopy[5];

  assert(s == "copy");

  return 0;
}