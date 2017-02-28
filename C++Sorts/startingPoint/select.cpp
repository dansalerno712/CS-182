#include "sorting.hh"

template void Sortings<int, intintCompare>::select(int*, unsigned int);
template void Sortings<char*, strstrCompare>::select(char**, unsigned int);

template <class Elem, class Comp>
void Sortings<Elem, Comp>::select(Elem *arr, unsigned int n)
{

}
