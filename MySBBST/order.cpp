#include "MySBBST.h"
#include "student.hh"
template int MySBBST<int, int, intintCompare, intintCompare>::getOrder(MySBBSTNode *);
template int MySBBST<char, char, charcharCompare, charcharCompare>::getOrder(MySBBSTNode *);
template void MySBBST<int, int, intintCompare, intintCompare>::rotateLeft(MySBBSTNode *&);
template void MySBBST<char, char, charcharCompare, charcharCompare>::rotateLeft(MySBBSTNode *&);
template void MySBBST<int, int, intintCompare, intintCompare>::rotateRight(MySBBSTNode *&);
template void MySBBST<char, char, charcharCompare, charcharCompare>::rotateRight(MySBBSTNode *&);
template void MySBBST<int, int, intintCompare, intintCompare>::balance(MySBBSTNode *&);
template void MySBBST<char, char, charcharCompare, charcharCompare>::balance(MySBBSTNode *&);
template int MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::getOrder(MySBBSTNode *);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::rotateLeft(MySBBSTNode *&);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::rotateRight(MySBBSTNode *&);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::balance(MySBBSTNode *&);


template <class Elem, class Key, class EEComp, class KEComp>
int MySBBST<Elem, Key, EEComp, KEComp>::getOrder(MySBBSTNode *n)
{
    return getHeight(n -> rc) - getHeight(n -> lc);
}

template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::rotateLeft(MySBBSTNode *&n)
{
    MySBBSTNode *temp = n -> rc;
    n -> rc = temp -> lc;
    temp -> lc = n;
    fixHeight(n);
    fixHeight(temp);
    n = temp;
}

template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::rotateRight(MySBBSTNode *&n)
{
    MySBBSTNode *temp = n -> lc;
    n -> lc = temp -> rc;
    temp -> rc = n;
    fixHeight(n);
    fixHeight(temp);
    n = temp;
}
    
template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::balance(MySBBSTNode *&n)
{
    if (n == NULL)
    {
	return;
    }
    else
    {
	fixHeight(n);
	if (getOrder(n) == 2)
	{
	    if (getOrder(n -> rc) < 0)
	    {
		rotateRight(n -> rc);
	    }
	    rotateLeft(n);	
	}
	if (getOrder(n) == -2)
	{
	    if (getOrder(n -> lc) > 0)
		rotateLeft(n -> lc);	
	    rotateRight(n);
	}
    }
}
