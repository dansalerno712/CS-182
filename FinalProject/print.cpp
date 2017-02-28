#include "Dungeon.hh"
using namespace std;
/*
 * Preconditions: None
 * Postconditions: Prints out the info of every hero, one per line. Prints cash once
 */
void Dungeon::showHeroes()
{
    if (numHE == 0)
	cout << "No heroes in the dungeon" << endl;
    else
    {
	for(uint i = 0; i < numHE; i++)
	{
	    cout << "Name: " << heroes[i].name << " Strength:" << heroes[i].strength
		 << " HP: " << heroes[i].hp << endl;
	}
	cout << "Cash: " << heroes[0].cash;
	cout << endl;
    }
}
/*
 * Preconditions: None
 * Postconditions: Prints the index and the name of each room
 */
void Dungeon::listRooms()
{
    if (numR == 0)
	cout << "No rooms in the dungeon" << endl;
    else
    {
	for(uint i = 0; i < numR; i++)
	{
	    cout << "Index : " << i << " Name: " << rooms[i].name << endl;
	}
	cout << endl;
    }
}
/* Preconditions: None
 * Postconditions: Prints the adjacency matrix
 */
void Dungeon::showHalls()
{
    if (numR == 0)
	cout << "No rooms in the dungeon, so no halls exist" << endl;
    else
    {
	for(uint i = 0; i < numR; i++)
	{
	    for(uint j = 0; j < numR; j++)
	    {
		if (halls[i][j] == INF)
		    cout << "INF" << "     ";
		else
		    cout << halls[i][j]<< "     ";
	    }
	    cout << endl;
	}
	cout << endl;
    }
}
/* Preconditions: None
 * Postconditions: Prints out all options for the menu
 */
void Dungeon::showOptions()
{
    cout << "=================================================================================" << endl;
    cout << "1) Depth" << endl;
    cout << "2) Breadth" << endl;
    cout << "3) Halls" << endl;
    cout << "4) Heroes" << endl;
    cout << "5) Most Safe Pizza Sharing" << endl;
    cout << "6) Lucrative Path" << endl;
    cout << "7) Lucrative Paths" << endl;
    cout << "8) Pizza Party" << endl;
    cout << "9 RAID!" << endl;
    cout << "0) Exit" << endl;
}
