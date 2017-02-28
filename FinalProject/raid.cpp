#include "Dungeon.hh"
#include "sorting.hh"
using namespace std;
uint Dungeon::clearRooms(uint start)
{
    uint v;
    uint lastVisited;
    if (start < numR && !visited[start])
    {
	if (firstAliveHero >= numHE)
	    return numR;
	visited[start] = true;
	lastVisited = start;
	cout << "Entering room: " << rooms[start].name << endl;
	//simulation
	while (rooms[start].strength > 0 && firstAliveHero < numHE)
	{
	    if (rooms[start].strength >= heroes[firstAliveHero].hp && heroes[firstAliveHero].strength
		>= rooms[start].strength)
	    {
		rooms[start].strength = 0;
		heroes[firstAliveHero].hp = 0;
		cout << heroes[firstAliveHero].name << " killed " << rooms[start].monster
		     << " in " << rooms[start].name << endl;
		cout << heroes[firstAliveHero].name << " died fighting " << rooms[start].monster
		     << " in " << rooms[start].name << endl;
		firstAliveHero++;
		cout << rooms[start].treasure << " pizza vouchers were looted from room: "
		     << rooms[start].name << endl;
		heroes[0].cash += rooms[start].treasure;
		rooms[start].treasure = 0;
	    }
	    else if (rooms[start].strength >= heroes[firstAliveHero].hp)
	    {
		rooms[start].strength -= heroes[firstAliveHero].strength;
		heroes[firstAliveHero].hp = 0;
		cout << heroes[firstAliveHero].name << " died fighting " << rooms[start].monster
		     << " in " << rooms[start].name << endl;
		cout << rooms[start].monster << "'s strength was lowered to " << rooms[start].strength << endl;
		firstAliveHero++;
	    }
	    else if (heroes[firstAliveHero].strength >= rooms[start].strength)
	    {
		heroes[firstAliveHero].hp -= rooms[start].strength;
		rooms[start].strength = 0;
		cout << heroes[firstAliveHero].name << " killed " << rooms[start].monster
		     << " in " << rooms[start].name << endl;
		cout << heroes[firstAliveHero].name << "'s HP was lowered to " << heroes[firstAliveHero].hp
		     << endl;
		cout << rooms[start].treasure << " pizza vouchers were looted from room: "
		     << rooms[start].name << endl;
		heroes[0].cash += rooms[start].treasure;
		rooms[start].treasure = 0;
	    }
	    else
	    {
		heroes[firstAliveHero].hp -= rooms[start].strength;
		rooms[start].strength -= heroes[firstAliveHero].strength;
		cout << heroes[firstAliveHero].name << " attacked " << rooms[start].monster
		     << " lowering its strength to " << rooms[start].strength << endl;
		cout << rooms[start].monster << " attacked " << heroes[firstAliveHero].name
		     << " lowering its hp to " << heroes[firstAliveHero].hp << endl;
	    }	    
	}
	if (firstAliveHero >= numHE)
	    return numR; 
	for (v = nextNeighbor(start, numR); v < numR; v = nextNeighbor(start, v))
	{	
	    if (!visited[v])
	    {	   
		lastVisited = clearRooms(v);
	    }
	}
	return lastVisited;
    }
    return numR;
}
/*
 * Preconditions: User supplies a valid starting room index
 * Postconditions: Heroes do a dfs traversal of rooms and fight all monsters in each room and collect loot. 
 *                 after clearing all rooms, raid prints the amount of pizzas that the heros can order.
 *                If all heroes die or are already dead, no pizzas are ordered.
 */
void Dungeon::raid(uint start)
{
    if (start >= numR)
    {
	cout << "Invald room selection" << endl;
	return;
    }
    else
    {
	unvisit();
	if (numHE == 0)
	    cout << "No heros are in the dungeon, so no pizzas are ordered" << endl;
	else if (numR == 0)
	    cout << "There are no rooms in the dugeon, so no pizzas are ordered" << endl;
	else
	{
	    firstAliveHero = -1;
	    for (int i = 0; i < numHE; i++)
	    {
		if (heroes[i].hp != 0)
		{
		    firstAliveHero = i;
		    break;
		}
	    }
	    if (firstAliveHero == -1)
	    {
		cout << "All heroes are dead, so no pizza is ordered" << endl;
		return;
	    }
	    else
	    {
		Sortings<Hero, HeroHeroComp>::merge(heroes, numHE);
		uint finish = clearRooms(start); //clearRooms() returns the last room the monsters killed something in
		if (finish == numR)
		{
		    cout << "All heroes died in combat, so no pizzas are ordered" << endl;
		    return;
		}
		uint pizzas = pizzaParty(start, finish, heroes[0].cash);
		cout << pizzas << " pizzas are ordered and delivered to room " << rooms[finish].name << endl;
	    }
	}
    }
}
