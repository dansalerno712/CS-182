#include "Dungeon.hh"
using namespace std;
uint Dungeon::findAP(uint curr, uint dst, uint flow, uint** resnet)
{
    visited[curr] = true;
    if (curr == dst)
	return flow;
    else
    {
	for (uint v = nextNeighbor(curr, numR, resnet); v < numR; v = nextNeighbor(curr, v, resnet))
	{
	    uint min;
	    if (!visited[v])
	    {
		if(flow < resnet[curr][v])
		    min = flow;
		else
		    min = resnet[curr][v];
	    
		if((min = findAP(v, dst, min, resnet)) > 0)
		{
		    resnet[curr][v] -= min;
		    resnet[v][curr] += min;		  
		    return min;
		}
	    }
	}
    }
    return 0;
}
/*
 * Preconditions: User supplies valid uint index of starting room and target room,
 *                as well as the budget for pizza
 * Postconditions: Returns the number of pizzas that can be delivered, which is either the 
 *                 max flow (if budget > maxflow) or the budget (if the budget < maxflow)
 *                 If room input is invalid, returns INF.
 */	    
uint Dungeon::pizzaParty(uint start, uint target, uint budget)
{
    if (start >= numR || target >= numR)
    {
	cout << "Invalid room selection, disregard amount of pizzas that can be delivered" << endl;
	return INF;
    }
    else
    {
	//if start = target, you are trying to move pizzas from one room to the same room, so infinite pizzas
	//can be moved. Therefore, budget is always returned
	if (start == target)
	    return budget;
	
	uint** resnet = new uint*[numR];
	for (int i = 0; i < numR; i++)
	    resnet[i] = new uint[numR];

	for (int i = 0; i < numR; i++)
	    for (int j = 0; j < numR; j++)
		resnet[i][j] = halls[j][i];
	do
	{
	    unvisit();
	} while (findAP(target, start, INF, resnet));

	uint maxflow = 0;
	for (int i = 0; i < numR; i++)
	{
	    if (i != target)
	    {
		maxflow += resnet[i][target];
	    }
	}

	for (int i = 0; i < numR; i++)
	    delete resnet[i];
	delete resnet;
	
	if (maxflow > budget)
	    return budget;
	else
	    return maxflow;
    }
}
