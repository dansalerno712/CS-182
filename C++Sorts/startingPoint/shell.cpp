#include "sorting.hh"

template void Sortings<int, intintCompare>::shell(int*, unsigned int);
template void Sortings<char*, strstrCompare>::shell(char**, unsigned int);

template <class Elem, class Comp>
/*
 * Preconditions: Non-null Array of type Elem
 *                int n: the number of elements of arr you would like sorted (n > 1 and n < length of arr)
 *
 * Postconditions: arr is sorted in ascending order
 */
void Sortings<Elem, Comp>::shell(Elem *arr, unsigned int n)
{
    if (arr != NULL && n > 1)
    {
	for (int incr = n / 2; incr > THRESHOLD; incr /= 2)
	{
	    for (int s = 0; s < incr; s++)
	    {
		insert(&arr[s], incr, n - s);
	    }
	}
	insert(arr, 1, n);
    }
    else
    {
	std::cout << "Cant sort that" << endl;
    }
}
