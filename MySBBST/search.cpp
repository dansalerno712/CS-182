#include "MySBBST.h"
#include "student.hh"
template int MySBBST<int, int, intintCompare, intintCompare>::search(int);
template char MySBBST<char, char, charcharCompare, charcharCompare>::search(char);
template int MySBBST<int, int, intintCompare, intintCompare>::search(MySBBSTNode *, int);
template char MySBBST<char, char, charcharCompare, charcharCompare>::search(MySBBSTNode *, char);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::search(MySBBSTNode *, unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::search(unsigned int);


template <class Elem, class Key, class EEComp, class KEComp>
/*
 * Preconditions: The user provides a valid key k and k != zero
 * Postconditions: search returns the "data" data member of the first node in the AVL tree
 *                 that matches the key provided, and returns zero if k is not matched or k is invalid
 */
Elem MySBBST<Elem, Key, EEComp, KEComp>::search(Key k)
{
    if (KEComp::eq(k, zero))
    {
	cout << "Invalid input" << endl;
	return zero;
    }
    else
    return search(root, k);
}

template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::search(MySBBSTNode *sr, Key k)
{
    if (sr == NULL)
	return zero;
    if (KEComp::eq(k, sr -> data))
	return sr -> data;
    if (KEComp::lt(k, sr -> data))
	return search(sr -> lc, k);
    return search(sr -> rc, k);
}
