#include "MySBBST.h"
#include "student.hh"
template int MySBBST<int, int, intintCompare, intintCompare>::remove(int);
template char MySBBST<char, char, charcharCompare, charcharCompare>::remove(char);
template int MySBBST<int, int, intintCompare, intintCompare>::remove(MySBBSTNode *&, int);
template char MySBBST<char, char, charcharCompare, charcharCompare>::remove(MySBBSTNode *&, char);
template int MySBBST<int, int, intintCompare, intintCompare>::removeMin(MySBBSTNode *&);
template char MySBBST<char, char, charcharCompare, charcharCompare>::removeMin(MySBBSTNode *&);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::remove(MySBBSTNode *&, unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::remove(unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::removeMin(MySBBSTNode *&);


template <class Elem, class Key, class EEComp, class KEComp>
/*
 * Preconditions: User provides a valid Key k and k != zero
 * Postconditions: The first node that matches key k is removed from the AVL tree, and the tree
 *                 follows all AVL tree rules after the removal. The "data" data member of the removed
 *                 node is returned, zero is returned if no matches are found for k or if k is invalid
 */
Elem MySBBST<Elem, Key, EEComp, KEComp>::remove(Key k)
{
    if (KEComp::eq(k, zero))
    {
	cout << "Invalid input" << endl;
	return zero;
    }
    else
    return remove(root, k);
}

template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::remove(MySBBSTNode *&sr, Key k)
{
    Elem temp;
    MySBBSTNode *deleteMe = NULL;

    if (sr == NULL)
	return zero;
    if (KEComp::eq(k, sr -> data))
    {
	temp = sr -> data;
	if (sr -> lc != NULL && sr -> rc != NULL)
	{
	    sr -> data = removeMin(sr -> rc);
	}
	else
	{
	    deleteMe = sr;
	    if (sr -> lc == NULL)
		sr = sr -> rc;
	    else
		sr = sr -> lc;
	    delete deleteMe;
	    balance(sr);
	}
    }
    else
    {
	if (KEComp::lt(k, sr -> data))
	    temp =  remove(sr -> lc, k);
	else
	    temp = remove(sr -> rc, k);
	balance(sr);
    }
    return temp;
}

template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::removeMin(MySBBSTNode *&sr)
{
    Elem temp;
    MySBBSTNode *deleteMe;
    if (sr == NULL)
	return zero;
    if (sr -> lc == NULL)
    {
	temp = sr -> data;
	deleteMe = sr;
	sr = sr -> rc;
	delete deleteMe;
    }
    else
	temp = removeMin(sr -> lc);
    balance(sr);
    return temp;
}
