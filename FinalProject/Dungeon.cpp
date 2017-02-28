#include "Dungeon.hh"
/*
 * Default Constructor
 * Preconditions: None
 * Postcondition: Creates a dungeon with Room and Hero capacity of 5. Halls from a room to itself
 *                have infinite capacity.
 */
Dungeon::Dungeon()
{
    rooms = new Room[5];
    heroes = new Hero[5];
    halls = new uint*[5];
    for (int i = 0; i < 5; i++)
	halls[i] = new uint[5];
    for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
	{
	    if (i == j)
		halls[i][j] = INF;
	    else
		halls[i][j] = 0;
	}
    R = 5;
    HE = 5;
    //H = R * R;
    numR = 0;
    numH = 0;
    numHE = 0;
    visited = new bool[5];
}
/*
 * Constructor
 * Preconditions: User supplies capactiy for rooms and heroes
 * Postconditions: Creates a dungeon with specified capacities. Halls from a room to itself
 *                 have infinite capacity.
 */
Dungeon::Dungeon(uint r, uint h)
{
    if (r < 5)
    {
	rooms = new Room[5];
	halls = new uint*[5];
	for (int i = 0; i < 5; i++)
	    halls[i] = new uint[5];
	for(int i = 0; i < 5; i++)
	{
	    for (int j = 0; j < 5; j++)
	    {
		if (i == j)
		    halls[i][j] = INF;
		else
		    halls[i][j] = 0;
	    }
	}
	R = 5;
    }
    else
    {
	rooms = new Room[r];
	halls = new uint*[r];
	for (int i = 0; i < r; i++)
	    halls[i] = new uint[r];
	for(int i = 0; i < r; i++)
	{
	    for (int j = 0; j < r; j++)
	    {
		if (i == j)
		    halls[i][j] = INF;
		else
		    halls[i][j] = 0;
	    }
	}
	R = r;
    }
    if (h < 5)
    {
	heroes = new Hero[5];
	HE = 5;
    }
    else
    {
	heroes = new Hero[h];
	HE = h;
    }
    //H = R * R;
    numR = 0;
    numH = 0;
    numHE = 0;
    visited = new bool[5];
}

