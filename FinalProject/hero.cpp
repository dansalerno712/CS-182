#include "Dungeon.hh"
using namespace std;
Dungeon::Hero::Hero(string n, uint s, uint h)
{
    name = n;
    strength = s;
    hp = h;
}
uint Dungeon::Hero::cash = 0;
