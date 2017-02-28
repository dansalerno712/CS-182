#include "exp.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int my_pow(int x, unsigned int y)
{
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  if (y % 2 == 0)
    return my_pow(x * x, y / 2);
  else
    return x * my_pow(x * x, (y - 1) / 2);
}

int main()
{
  int x = 0;
  unsigned int y = 0;
  string input = "";
  while (true) {
    cout << "Please enter x: ";
    getline(cin, input);

    stringstream myStream(input);
    if (myStream >> x)
      break;
    cout << "Invalid x. ";
  }
  while (true) {
    cout << "Please enter y: ";
    getline(cin, input);

    stringstream myStream(input);
    if (myStream >> y)
      break;
    cout << "Invalid y. ";
  }
    
  cout << my_pow(x, y);
}
