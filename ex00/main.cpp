
#include <cassert>
#include <string>

#include "whatever.hpp"

int main()
{
  // testing swap
  int one = 1;
  int two = 2;

  swap(one, two);
  assert(one == 2 && two == 1);

  swap(one, two);
  assert(one == 1 && two == 2);

  char a = 'a';
  char b = 'b';

  swap(a, b);
  assert(a == 'b' && b == 'a');

  swap(a, b);
  assert(a == 'a' && b == 'b');

  std::string less = "less";
  std::string more = "more";

  swap(less, more);
  assert(less == "more" && more == "less");

  swap(less, more);
  assert(less == "less" && more == "more");

  // testing min and max
  assert(min(one, two) == 1);
  assert(min(one, one) == 1);
  assert(min(two, one) == 1);

  assert(max(one, two) == 2);
  assert(max(two, two) == 2);
  assert(max(two, one) == 2);

  assert(min(a, b) == 'a');
  assert(min(a, a) == 'a');
  assert(min(b, a) == 'a');

  assert(max(a, b) == 'b');
  assert(max(b, b) == 'b');
  assert(max(b, a) == 'b');

  assert(min(less, more) == "less");
  assert(min(less, less) == "less");
  assert(min(more, less) == "less");

  assert(max(less, more) == "more");
  assert(max(more, more) == "more");
  assert(max(more, less) == "more");

  // testing min and max with const parameters
  assert(min(1, 2) == 1);
  assert(min(1, 1) == 1);
  assert(min(2, 1) == 1);

  assert(min('a', 'b') == 'a');
  assert(min('a', 'a') == 'a');
  assert(min('b', 'a') == 'a');

  assert(max(1, 2) == 2);
  assert(max(2, 2) == 2);
  assert(max(2, 1) == 2);

  assert(max('a', 'b') == 'b');
  assert(max('b', 'b') == 'b');
  assert(max('b', 'a') == 'b');

  return 0;
}