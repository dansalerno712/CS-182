#include "sorting.hh"
#include "Dungeon.hh"


template void Sortings<Dungeon::Hero, Dungeon::HeroHeroComp>::insert(Dungeon::Hero*, unsigned int);

template <class Elem, class Comp>
/*
 * Preconditions: Non-null Array of type Elem
 *                int n: the number of elements of arr you would like sorted (n > 1 and n < length of arr)
 *
 * Postconditions: arr is stably sorted in descending order
 */
void Sortings<Elem, Comp>::insert(Elem *arr, unsigned int n)
{
    if (arr != NULL && n > 1)
    {
	for (int i = 1; i < n; i++)
	{
	    for (int j = i; j > 0 && Comp::gt(arr[j], arr[j - 1]); j--)
	    {
		swap(arr, j, j - 1);
	    }
	}
    }
}
