#include "Dungeon.hh"
#include <queue>
using namespace std;

void Dungeon::bfs(uint s)
{
    queue<uint> Q;
    if (s < numR && !visited[s])
    {
	Q.push(s);
	visited[s] = true;
	while(!Q.empty())
	{
	    uint v = Q.front();
	    Q.pop();
	    cout << rooms[v].name << " Monster: " << rooms[v].monster << " Strength: " << rooms[v].strength <<
	    " Treasure: " << rooms[v].treasure << endl;
	    
	    for (uint n = nextNeighbor(v, numR); n < numR; n = nextNeighbor(v, n))
	    {
		if (!visited[n])
		{
		    Q.push(n);
		    visited[n] = true;
		}
	    }
	}
    }
}
/* Preconditions: None
 * Postconditions: A bfs of the rooms is performed with a dashed line separating disjoint groups
 */
void Dungeon::breadthRooms()
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
		bfs(v);
		cout << "-----------------------------------" << endl;
	    }
	}
	cout << endl;
    }
}
