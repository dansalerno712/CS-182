#include "Dungeon.hh"
/* Preconditions: User supplies string name, string monster name, uint strength, uint treasure
 * Postconditions: A room is created with those parameters and placed into the dungeon. If the dungeon
 *                 is full, -1 is returned and the room is not added. Otherwise, the index of where the
 *                 room was added is returned.
 */
int Dungeon::addRoom(std::string n, std::string m, uint s, uint t)
{
    if (numR >= R)
	return -1;
    else
    {
	Room add(n, m, s, t);
	rooms[numR] = add;
	return numR++;
    }
}
/* Preconditions: User supplies uint source, uint destination, and uint capacity of the hall
 * Postconditions: A hall is created with those parameters. If the src and dst are valid, the hall
 *                 is added to the dungeon and true is returned. If invalid, it is not added and false
 *                 is returned.
 */
bool Dungeon::setHall(uint src, uint dst, uint cap)
{
    if (src >= numR || dst >= numR || src == dst)
	return false;
    else
    {
	if (cap == 0)
	{
	    halls[src][dst] = cap;
	    numH--;
	}
	else
	{
	    halls[src][dst] = cap;
	    numH++;
	}
	return true;
    }
}
/* Preconditions: User supplies string name, uint strength, and uint hp
 * Postconditions: A hero is created with those parameters. If the dungeon is full, false is returned
 *                 and the hero is not added. Otherwise, the hero is added and true is returned.
 */
bool Dungeon::addHero(std::string n, uint s, uint hp)
{
    if (numHE >= HE)
	return false;
    else
    {
	Hero add(n, s, hp);
	heroes[numHE] = add;
	numHE++;
	return true;
    }
}

	
