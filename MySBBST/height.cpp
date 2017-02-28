#include "MySBBST.h"
#include "student.hh"
template unsigned int MySBBST<int, int, intintCompare, intintCompare>::getHeight(MySBBSTNode *);
template unsigned int MySBBST<char, char, charcharCompare, charcharCompare>::getHeight(MySBBSTNode *);
template void MySBBST<int, int, intintCompare, intintCompare>::fixHeight(MySBBSTNode *&);
template void MySBBST<char, char, charcharCompare, charcharCompare>::fixHeight(MySBBSTNode *&);
template unsigned int MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::getHeight(MySBBSTNode *);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::fixHeight(MySBBSTNode *&);

template <class Elem, class Key, class EEComp, class KEComp>
unsigned int MySBBST<Elem, Key, EEComp, KEComp>::getHeight(MySBBSTNode *n)
{
    if (n == NULL)
	return 0;
    return n -> height;
}

template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::fixHeight(MySBBSTNode *&n)
{
    int hLeft = getHeight(n -> lc);
    int hRight = getHeight(n -> rc);
    if (hLeft > hRight)
	n -> height = hLeft + 1;
    else
	n -> height = hRight + 1;
}
