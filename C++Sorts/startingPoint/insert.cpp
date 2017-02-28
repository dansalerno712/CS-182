#include "sorting.hh"

template void Sortings<int, intintCompare>::insert(int*, unsigned int, unsigned int);
template void Sortings<char*, strstrCompare>::insert(char**, unsigned int, unsigned int);

template <class Elem, class Comp>
void Sortings<Elem, Comp>::insert(Elem *arr, unsigned int incr, unsigned int n)
{
    if (arr != NULL && n > 1)
    {
	for (int i = 0; i < n; i += incr)
	{
	    for (int j = i; j > 0 && Comp::lt(arr[j], arr[j - incr]); j -= incr)
	    {
		swap(arr, j, j - incr);
	    }
	}
    }
}

template void Sortings<int, intintCompare>::insert(int*, unsigned int);
template void Sortings<char*, strstrCompare>::insert(char**, unsigned int);
template void Sortings<Dungeon::Hero*, Dungeon::HeroHeroComp>::insert(Dungeon::Hero*, unsigned int);

template <class Elem, class Comp>
/*
 * Preconditions: Non-null Array of type Elem
 *                int n: the number of elements of arr you would like sorted (n > 1 and n < length of arr)
 *
 * Postconditions: arr is stably sorted in ascending order
 */
void Sortings<Elem, Comp>::insert(Elem *arr, unsigned int n)
{
    if (arr != NULL && n > 1)
    {
	for (int i = 1; i < n; i++)
	{
	    for (int j = i; j > 0 && Comp::lt(arr[j], arr[j - 1]); j--)
	    {
		swap(arr, j, j - 1);
	    }
	}
    }
    else
    {
	std::cout << "Cant sort that" << endl;
    }
}
