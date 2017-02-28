#ifndef _MySBBST_H_
#define _MySBBST_H_
#include "student.hh"
#include <iostream>
using namespace std;
/* 
 * I pledge my honor that I have abided by the Stevens Honor System
 *
 * Dan Salerno
 */
/* Elem and key are both either an int, character, or student object
 * Comp is the comparator to compare 2 ints, 2 chars, 2 students, or an unsigned int and a student
 */
template <class Elem, class Key, class EEComp, class KEComp>
/* 
 * This is a class that implements an AVL tree with add, remove, search, and prinout methods
 * using either ints or chars
 *
 * Author: Dan Salerno
 */
class MySBBST
{
private:
    class MySBBSTNode
    {
    public:
	MySBBSTNode *lc;
	MySBBSTNode *rc;
	Elem data;
	unsigned int height;
	MySBBSTNode(Elem el){lc = NULL, rc = NULL, data = el, height = 1;}
    };
    MySBBSTNode *root;
    Elem zero;
    Elem search(MySBBSTNode *, Key);
    Elem remove(MySBBSTNode *&, Key);
    Elem removeMin(MySBBSTNode *&);
    bool add(MySBBSTNode *&, Elem);
    void inOrder(MySBBSTNode *);
    void rotateLeft(MySBBSTNode *&);
    void rotateRight(MySBBSTNode *&);
    void balance(MySBBSTNode *&);
    unsigned int getHeight(MySBBSTNode *);
    int getOrder(MySBBSTNode *);
    void fixHeight(MySBBSTNode *&);
public:
    /*
     * Constructor
     * Preconditions: user supplies an Elem zero, which is the Elem returned when search or remove fails
     * Postconditions: creates the AVL tree with supplied zero
     */
    MySBBST(Elem z){root = NULL, zero = z;}
    bool add(Elem);
    Elem search(Key);
    Elem remove(Key);
    void printout();
};
/*
 * Used as comparator for ints
 * Author: Dan Salerno
 */
class intintCompare
{
public:
    static bool lt(int, int);
    static bool gt(int, int);
    static bool eq(int, int);
};
/*
 * Used as comparator for chars
 * Author: Dan Salerno
 */
class charcharCompare
{
public:
    static bool lt(char, char);
    static bool gt(char, char);
    static bool eq(char, char);
};
    
#endif
