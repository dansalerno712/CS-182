#ifndef _DUNGEON_HH_
#define _DUNGEON_HH_
#include <iostream>
#include "sorting.hh"
typedef unsigned int uint;
/* 
 * I pledge my honor that I have abided by the Stevens Honor System
 *
 * Dan Salerno
 */
/*
 * This is a class that implements a graph Dungeon with ability to add Rooms(Vertices), Heroes, and Halls(Edges)
 * and can print all Heroes, Halls, Rooms, as well as perform DFS and BFS on the Rooms and creating a 
 * maximum capacity spanning tree. Uses adjacency matrix.
 *
 * Author: Dan Salerno
 */
class Dungeon
{
private:
    class Room
    {
    public:
	std::string name;
	std::string monster;
	uint strength;
	uint treasure;
	
	Room(){name = "", monster = "", strength = 0; treasure = 0;}
	Room(std::string n, std::string m, uint s, uint t){name = n, monster = m, strength = s, treasure = t;}
    };
    class Hero
    {
    public:
	std::string name;
	uint strength;
	uint hp;
	static uint cash; 
	Hero(){name = "", strength = 0; hp = 0;}
	Hero(std::string n, uint s, uint h);
    };
    Room* rooms; //stores rooms
    Hero* heroes;//stores heroes
    uint** halls;//stores halls as adjacency matrix
    uint R; //max rooms
    uint HE; //max heroes
    uint numR; //current # of rooms
    uint numH; //current # of halls
    uint numHE; //current # of heroes
    bool* visited;
    static const uint INF = -1;
    void unvisit();
    uint nextNeighbor(uint v, uint w);
    uint nextNeighbor(uint v, uint w, uint** adjmatrix);
    void dfs(uint s);
    void bfs(uint s);
    int MSTMaxIndex(uint *D);
    int getLR(uint room);
    uint findAP(uint curr, uint dst, uint flow, uint** resnet);
    int* LP(uint start); //does exactly what lucrativePath(uint start) does, but return the array L
    uint clearRooms(uint start); //runs simulation of room clearing by heros
    int firstAliveHero; //keeps track of index of first alive hero
public:
    Dungeon();   
    Dungeon(uint r, uint h);
    int addRoom(std::string n, std::string m, uint s, uint t);
    bool setHall(uint src, uint dst, uint cap);
    bool addHero(std::string n, uint s, uint hp);
    void showHeroes();
    void listRooms();
    void showHalls();
    void depthRooms();
    void breadthRooms();
    void mst();
    void lucrativePath(uint start);
    void lucrativePaths();
    uint pizzaParty(uint start, uint target, uint budget);
    void raid(uint start);
    void showOptions();
    /*
     * A class used to compare two heros for sorting, based on strength
     * Author: Dan Salerno
     */
    class HeroHeroComp
    {
    public:
	static bool lt(Hero, Hero);
	static bool gt(Hero, Hero);
	static bool eq(Hero, Hero);
    };
};
#endif
	
