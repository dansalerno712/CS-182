#include "MySBBST.h"
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
  return x == y;
}
bool charcharCompare::lt(char x, char y)
{
    return x < y;
}
bool charcharCompare::gt(char x, char y)
{
    return x > y;
}
bool charcharCompare::eq(char x, char y)
{
    return x == y;
}
