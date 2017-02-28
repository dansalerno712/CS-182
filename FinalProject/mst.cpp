#include "Dungeon.hh"
using namespace std;
int Dungeon::MSTMaxIndex(uint *D)
{
    uint max = 0;
    int maxIndex;

    for (int i = 0; i < numR; i++)
    {
	if (visited[i] == false && D[i] >= max)
	{
	    max = D[i];
	    maxIndex = i;
	}
    }
    return maxIndex;
}
/* Preconditions: mst() is called on a connected graph
 * Postconditions: mst() prints out the halls and their corresponding capacities that would be 
 *                 included in a maximal capacity spanning tree. Undirected edges are formed by summing 
 *                 both directed edges. If mst() is called on a not connected graph, the closest possible
 *                 mst is made and rooms that are unreachable are shown as well.
 */
void Dungeon::mst()
{
    if (numR == 0)
	cout << "No rooms in the dungeon, so no mst can be made" << endl;
    else
    {
	uint C[numR]; //array that holds the current max capacity that that reaches each vertex
	int parent[numR]; //used to simulate the tree structure and keep track of which edges connect where
	unvisit(); //clears visited array

	for (int i = 0; i < numR; i++)
	    C[i] = 0;

	C[0] = INF; //makes sure that room at index 0 is starting  point
	parent[0] = -1;

	for (int i = 0; i < numR - 1; i++)
	{
	    int maxIndex = MSTMaxIndex(C); //gets index of max value in D
	    visited[maxIndex] = true; //adds rooms to mst
	    //loop that checks if the newly added room can help reach any other rooms for a higher
	    //capacity than is already known
	    if (C[maxIndex] == 0)
		break;
	    for (int n = 0; n < numR; n++)
	    {
		if ((halls[maxIndex][n] != 0 || halls[n][maxIndex] != 0) && visited[n] == false
		    && ((halls[maxIndex][n] + halls[n][maxIndex]) > C[n]))
		{
		    parent[n] = maxIndex;
		    C[n] = halls[maxIndex][n] + halls[n][maxIndex];
		}
	    }
	}
	//prints out mst
	cout << "If any rooms have a weight of Unreachable, the graph was not connected and a proper MST could "
	     << "not be made. The closest possible MST is shown, with rooms that are unreachable displayed" << endl;
	cout << "Hall                    Weight" << endl;
	for (int i = 1; i < numR; i++)
	{
	    if (C[i] == 0)
		cout << rooms[i].name << "                    " << "Unreachable" << endl;
	    else
		cout << rooms[parent[i]].name << " - " << rooms[i].name << "                    "
		     << (halls[i][parent[i]] + halls[parent[i]][i]) << endl;
	}
    }
}
						      
