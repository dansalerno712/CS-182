#include "Dungeon.hh"

uint Dungeon::nextNeighbor(uint v, uint w)
{
    if(w == numR)
    {
	for(int i = 0; i < numR; i++)
	{
	    if(halls[v][i] != 0 && v != i)
		return i;
	}
    }
    else
    {
	for(int i = w + 1; i < numR; i++)
	{
	    if(halls[v][i] != 0 && v != i)
		return i;
	}
    }
    return R;
}

uint Dungeon::nextNeighbor(uint v, uint w, uint** adjmatrix)
{
    if(w == numR)
    {
	for(int i = 0; i < numR; i++)
	{
	    if(adjmatrix[v][i] != 0 && adjmatrix[v][i] != INF && v != i)
		return i;
	}
    }
    else
    {
	for(int i = w + 1; i < numR; i++)
	{
	    if(adjmatrix[v][i] != 0 && adjmatrix[v][i] != INF && v != i)
		return i;
	}
    }
    return numR;
}
