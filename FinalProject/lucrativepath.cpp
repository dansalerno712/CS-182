#include "Dungeon.hh"
#include <climits>
using namespace std;

int Dungeon::getLR(uint room)
{
    return rooms[room].treasure - rooms[room].strength;
}
/*
 * Preconditions: User supplies a valid index for a room to start with
 * Postconditions: Prints the most lucrative path from input room to all other rooms. The most lucrative
 *                 path is the path in with the sum of lucrative ratios (difference between treasure 
 *                 minus strength of monster) is as high as possible. If a room has a loot ratio of
 *                 -INF, the room is not reachable.
 */
void Dungeon::lucrativePath(uint start)
{
    if (start >= numR)
	cout << "Invalid room choice" << endl;
    else
    {
	int L[numR]; //array that holds lucrative value
	unvisit();

	for (int i = 0; i < numR; i++)
	{
	    L[i] = INT_MIN; //initiallizes all to -inf, since we need to find max, so this will always
	                    //be overwritten
	}

	L[start] = 0; //allows start to go first

	for (int i = 0; i < numR - 1; i++)
	{
	    //finds index of max value in L
	    int max = INT_MIN;
	    int maxIndex;

	    for (int i = 0; i < numR; i++)
	    {
		if (!visited[i] && L[i] >= max)
		{
		    max = L[i];
		    maxIndex = i;
		}
	    }

	    if (L[maxIndex] == INT_MIN)
		break;
	    
	    visited[maxIndex] = true;
	    //if the room at maxIndex can be used to create a better lucrative path, L is updated
	    //with the better lucrative path
	    for (int i = 0; i < numR; i++)
	    {
		if (halls[maxIndex][i] != 0 && !visited[i] && (L[maxIndex] + getLR(i) >= L[i]))
		    L[i] = L[maxIndex] + getLR(i);
	    }
	}
	//prints output
	cout << "Starting from " << rooms[start].name << endl;
	for (int i = 0; i < numR; i++)
	{
	    if (i == start)
	    {
	    }
	    else if (L[i] == INT_MIN)
		cout << rooms[i].name << " would have a loot ratio of unreachable" << endl;
	    else
		cout << rooms[i].name << " would have a loot ratio of " << L[i] << endl;
	}
    }
}

int* Dungeon::LP(uint start)
{
    int* L = new int[numR]; //array that holds lucrative value
    unvisit();

    for (int i = 0; i < numR; i++)
    {
	L[i] = INT_MIN; //initiallizes all to -inf, since we need to find max, so this will always
	//be overwritten
    }

    L[start] = 0; //allows start to go first

    for (int i = 0; i < numR - 1; i++)
    {
	//finds index of max value in L
	int max = INT_MIN;
	int maxIndex;

	for (int i = 0; i < numR; i++)
	{
	    if (!visited[i] && L[i] >= max)
	    {
		max = L[i];
		maxIndex = i;
	    }
	}
	if (L[maxIndex] == INT_MIN)
	    break;
	visited[maxIndex] = true;
	//if the room at maxIndex can be used to create a better lucrative path, L is updated
	//with the better lucrative path
	for (int i = 0; i < numR; i++)
	{
	    if (halls[maxIndex][i] != 0 && !visited[i] && L[maxIndex] + getLR(i) > L[i])
		L[i] = L[maxIndex] + getLR(i);
	}
    }
    return L;
}
/*
 * Preconditions: None
 * Postconditions: Prints a matrix that shows the most lucrative path from all rooms to all other rooms
 *                 The most lucrative  path is the path in with the sum of lucrative ratios (difference between
 *                 treasure minus strength of monster) is as high as possible. If the room has a LR of
 *                 C.R., the rooms is not reachable.
 */
void Dungeon::lucrativePaths()
{
    if (numR == 0)
	cout << "No rooms in the dungeon, so no lucrative paths can be found" << endl;
    else
    {
	int** L = new int*[numR];
	for (int i = 0; i < numR; i++)
	    L[i] = new int[numR];

	for(int i = 0; i < numR; i++)
	{
	    L[i] = LP(i);
	}
	cout << "C.R. means room can not be reached" << endl;
	for (int i = 0; i < numR; i++)
	{
	    for (int j = 0; j < numR; j++)
	    {
		if (L[i][j] == INT_MIN)
		    cout << "C.R." << "\t\t";
		else
		    cout << L[i][j] << "\t\t";
	    }
	    cout << endl << endl;
	}

	for (int i = 0; i < numR; i++)
	    delete L[i];
	delete L;
    }
}
    
