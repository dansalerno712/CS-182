#include "sorting.hh"
template void Sortings<int, intintCompare>::merge(int*, unsigned int);
template void Sortings<int, intintCompare>::mergeRecurse(int*, int[], unsigned int, unsigned int);
template void Sortings<char*, strstrCompare>::merge(char**, unsigned int);
template void Sortings<char*, strstrCompare>::mergeRecurse(char**, char*[], unsigned int, unsigned int);
template void Sortings<Dungeon::Hero*, Dungeon::HeroHeroComp>::merge(Dungeon::Hero*, unsigned int);
template void Sortings<Dungeon::Hero*, Dungeon::HeroHeroComp>::mergeRecurse(Dungeon::Hero*, Dungeon::Hero[], unsigned int, unsigned int);

template <class Elem, class Comp>
/*
 * Preconditions: Non-null Array of type Elem
 *                int n: the number of elements of arr you would like sorted (n > 1 and n < length of arr)
 *
 * Postconditions: arr is stably sorted in ascending order
 */
void Sortings<Elem, Comp>::merge(Elem *arr, unsigned int n)
{
    if (arr != NULL && n > 1)
    {
	if (n < THRESHOLD)
	{
	    insert(arr, n);
	}
	else
	{
	    Elem temp[n];
	    mergeRecurse(arr, temp, 0, n - 1);
	}
    }
    else
    {
	std::cout << "Cant sort that" << endl;
    }
}

template <class Elem, class Comp>
void Sortings<Elem, Comp>::mergeRecurse(Elem *arr, Elem tmp[], unsigned int l, unsigned int r)
{
    int m, i, j, k;
    if (l < r)
    {
	m = l + (r - l) / 2;
	mergeRecurse(arr, tmp, l, m);
	mergeRecurse(arr, tmp, m + 1, r);

	for (i = l; i < m + 1; i++)
	    tmp[i] = arr[i];
	for (j = r; i <= r; i++, j--)
	    tmp[j] = arr[i];
	for (i = l, j = r, k = l; k <= r; k++)
	{
	    if (!(Comp::gt(tmp[i], tmp[j])))
	    {
		arr[k] = tmp[i];
		i++;
	    }
	    else
	    {
		arr[k] = tmp[j];
		j--;
	    }
	}
    }
}


