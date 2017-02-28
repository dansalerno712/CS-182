#include "sorting.hh"

template void Sortings<int, intintCompare>::quick(int*, unsigned int);
template void Sortings<int, intintCompare>::quickRecurse(int*, unsigned int, unsigned int);
template unsigned int Sortings<int, intintCompare>::findPivot(int*, unsigned int, unsigned int);
template unsigned int Sortings<int, intintCompare>::partition(int*, unsigned int, unsigned int);


template void Sortings<char*, strstrCompare>::quick(char**, unsigned int);
template void Sortings<char*, strstrCompare>::quickRecurse(char**, unsigned int, unsigned int);
template unsigned int Sortings<char*, strstrCompare>::findPivot(char**, unsigned int, unsigned int);
template unsigned int Sortings<char*, strstrCompare>::partition(char**, unsigned int, unsigned int);



template <class Elem, class Comp>
void Sortings<Elem, Comp>::quick(Elem *arr, unsigned int n)
{
}

template <class Elem, class Comp>
void Sortings<Elem, Comp>::quickRecurse(Elem *arr, unsigned int l, unsigned int r)
{

}

template <class Elem, class Comp>
unsigned int Sortings<Elem, Comp>::findPivot(Elem *arr, unsigned int l, unsigned int r)
{
}

template <class Elem, class Comp>
unsigned int Sortings<Elem, Comp>::partition(Elem *arr, unsigned int l, unsigned int r)
{

}
