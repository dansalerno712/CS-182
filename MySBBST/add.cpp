#include "MySBBST.h"
#include "student.hh"
template bool MySBBST<int, int, intintCompare, intintCompare>::add(int e);
template bool MySBBST<char, char, charcharCompare, charcharCompare>::add(char e);
template bool MySBBST<int, int, intintCompare, intintCompare>::add(MySBBSTNode *&sr, int e);
template bool MySBBST<char, char, charcharCompare, charcharCompare>::add(MySBBSTNode *&sr, char e);
template bool MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::add(MySBBSTNode *&sr, student s);
template bool MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::add(student s);

template <class Elem, class Key, class EEComp, class KEComp>
/*
 * Preconditions: User provides a valid Elem e and e != zero
 * Postconditions: Elem e is added to the AVL tree, and the tree follows all rules of AVL Trees
 *                 after the addition of e. True is returned if e was added successfully, false otherwise
 *
 */
bool MySBBST<Elem, Key, EEComp, KEComp>::add(Elem e)
{
    if (EEComp::eq(zero, e))
    {
	cout << "Invalid input" << endl;
	return false;
    }
    else    
    return add(root, e);
}


template <class Elem, class Key, class EEComp, class KEComp>
bool MySBBST<Elem, Key, EEComp, KEComp>::add(MySBBSTNode *&sr, Elem e)
{
    if (sr == NULL)
    {
	sr = new MySBBSTNode(e);
    }
    else
    {
	if (EEComp::lt(e, sr -> data))
	{
	    add(sr -> lc, e);
	}
	else
	{
	    add(sr -> rc, e);
	}
    }
    balance(sr);
    return true;
}
