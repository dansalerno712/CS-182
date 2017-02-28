#include "MySBBST.h"
#include "student.hh"
#include <iostream>

template void MySBBST<int, int, intintCompare, intintCompare>::printout();
template void MySBBST<char, char, charcharCompare, charcharCompare>::printout();
template void MySBBST<int, int, intintCompare, intintCompare>::inOrder(MySBBSTNode *);
template void MySBBST<char, char, charcharCompare, charcharCompare>::inOrder(MySBBSTNode *);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::inOrder(MySBBSTNode *);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::printout();


template <class Elem, class Key, class EEComp, class KEComp>
/*
 * Preconditions: None
 * Postconditions: Prints out an inorder traversal of the AVL tree, with '(' indicating that
 *                 you have gone down a level, and ')' indicating you have gone up a level
 */
void MySBBST<Elem, Key, EEComp, KEComp>::printout()
{
    return inOrder(root);
}

template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::inOrder(MySBBSTNode *sr)
{
    if (sr != NULL)
    {
	std::cout << "(";
	inOrder(sr -> lc);
	std::cout << sr -> data << ": " << getOrder(sr);
	inOrder(sr -> rc);
	std::cout << ")";
    }
}
