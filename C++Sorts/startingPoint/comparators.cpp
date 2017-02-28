#include "sorting.hh"
/*
 * Preconditions: x and y are ints
 *
 * Postconditions: returns true if x < y
 */
bool intintCompare::lt(int x, int y)
{
  return x < y;
}
/*
 * Preconditions: x and y are ints
 *
 * Postconditions: returns true if x > y
 */
bool intintCompare::gt(int x, int y)
{
  return x > y;
}
/*
 * Preconditions: x and y are ints
 *
 * Postconditions: returns true if x = y
 */
bool intintCompare::eq(int x, int y)
{
  return x = y;
}
/*
 * Preconditions: s1 and s2 are strings
 *
 * Postcondition: returns if s1 comes alphabetically before s2
 */
bool strstrCompare::lt(char* s1, char* s2)
{
    return (strcmp(s1, s2) < 0);
}
/*
 * Preconditions: s1 and s2 are strings
 *
 * Postcondition: returns if s1 comes alphabetically after s2
 */
bool strstrCompare::gt(char* s1, char* s2)
{
  return (strcmp(s1, s2) > 0);
}
/*
 * Preconditions: s1 and s2 are strings
 *
 * Postcondition: returns if s1 and s2 are alphabetically equal
 */
bool strstrCompare::eq(char* s1, char* s2)
{
  return (strcmp(s1, s2) == 0);
}
/*
unsigned int intuival::uintVal(int n)
{
  if (n < 0)
    return n * -1;
  else
    return n;
}
*/
