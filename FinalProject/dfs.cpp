#include "Dungeon.hh"
using namespace std;
void Dungeon::dfs(uint s)
{
    uint v;
    if (s < numR && !visited[s])
    {
	cout << rooms[s].name << " Monster: " << rooms[s].monster << " Strength: " << rooms[s].strength <<
	    " Treasure: " << rooms[s].treasure << endl;
	visited[s] = true;
	for (v = nextNeighbor(s, numR); v < numR; v = nextNeighbor(s, v))
	{
	    if (!visited[v])
		dfs(v);
	}
    }
}
/* Preconditions: None
 * Postconditions: Does a dfs of rooms, with a dashed line seperating disjoint groups
 */
void Dungeon::depthRooms()
{
    if (numR == 0)
	cout << "No rooms in the dungeon" << endl;
    else
    {
	uint v;
	unvisit();
	for (v = 0; v < numR; v++)
	{
	    if (!visited[v])
	    {
		dfs(v);
		cout << "-----------------------------------" << endl;
	    }
	}
	cout << endl;
    }
}
