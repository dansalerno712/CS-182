#include "Dungeon.hh"

void Dungeon::unvisit()
{
    for(int i = 0; i < R; i++)
	visited[i] = false;
}
