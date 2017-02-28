#include "Dungeon.hh"
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream ifs("dungeon.dat");
    if (!ifs)
	return 2;

    int numRooms;
    int numHalls;
    int numHeroes;

    ifs >> numRooms;
    ifs >> numHalls;
    ifs >> numHeroes;

    Dungeon dungeon(numRooms, numHeroes);

    string name;
    string monster;
    uint strength;
    uint treasure;

    for (int i = 0; i < numRooms; ++i)
    {
	ifs >> name;
	ifs >> monster;
	ifs >> strength;
	ifs >> treasure;

	dungeon.addRoom(name, monster, strength, treasure);
    }

    uint src;
    uint dst;
    uint cap;

    for (int i = 0; i < numHalls; ++i)
    {
	ifs >> src;
	ifs >> dst;
	ifs >> cap;

	dungeon.setHall(src, dst, cap);
    }

    uint hp;

    for (int i = 0; i < numHeroes; ++i)
    {
	ifs >> name;
	ifs >> strength;
	ifs >> hp;

	dungeon.addHero(name, strength, hp);
    }

    int choice = 1;
    uint start;
    uint end;
    uint budget;
    while (choice != 0)
    {
	dungeon.showOptions();
	cout << "Enter choice" << endl;
	cin >> choice;

	while (!cin)
	{
	    cout << "Invalid input" << endl;
	    cin.clear();
	    cin.ignore();
	    cin >> choice;
	}

	switch (choice)
	{
	case 1:
	    dungeon.depthRooms();
	    break;
	case 2:
	    dungeon.breadthRooms();
	    break;
	case 3:
	    dungeon.showHalls();
	    break;
	case 4:
	    dungeon.showHeroes();
	    break;
	case 5:
	    dungeon.mst();
	    break;
	case 6:
	    dungeon.listRooms();
	    cout << "Enter room to start from" << endl;
	    cin >> start;

	    while (!cin)
	    {
		cout << "Invalid input: Not an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> start;
	    }
	    
	    dungeon.lucrativePath(start);
	    break;
	case 7:
	    dungeon.lucrativePaths();
	    break;
	case 8:
	    dungeon.listRooms();
	    cout << "Enter room to start from" << endl;
	    cin >> start;

	     while (!cin)
	    {
		cout << "Invalid input: Not an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> start;
	    }
	     
	    dungeon.listRooms();
	    cout << "Enter a room to end at" << endl;
	    cin >> end;

	     while (!cin)
	    {
		cout << "Invalid input: Not an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> end;
	    }
	     
	    cout << "Enter budget" << endl;
	    cin >> budget;

	     while (!cin)
	    {
		cout << "Invalid input: Not an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> budget;
	    }
	     
	    cout << dungeon.pizzaParty(start, end, budget) << " pizzas can be delivered" << endl;
	    break;
	case 9:
	    dungeon.listRooms();
	    cout << "Enter a room to start from" << endl;
	    cin >> start;

	     while (!cin)
	    {
		cout << "Invalid input: Not an integer" << endl;
		cin.clear();
		cin.ignore();
		cin >> start;
	    }
	     
	    dungeon.raid(start);
	    break;
	case 0:
	    cout << "Exiting" << endl;
	    break;
	default:
	    cout << "Invalid choice" << endl;
	}
    }
}
