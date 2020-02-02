#ifndef BSTLONGINTLIST_H
#define BSTLONGINGLIST_H
#include "LongIntList.h"
#include "BSTNode.h"

class BSTLongIntList : public LongIntList
{
private:
	BSTNode* root;
	int links;
	BSTNode* rotateWithLeftChild(BSTNode*);
	BSTNode* rotateWithRightChild(BSTNode*);
	BSTNode* doubleWithLeftChild(BSTNode*);
	BSTNode* doubleWithRightChild(BSTNode*);
	BSTNode* insert(int, BSTNode*);
	BSTNode* search(BSTNode*);
	void inorder(BSTNode*);


public:
	BSTLongIntList();
	~BSTLongIntList();
	void insertFirst(int);
	void insertLast(int);
	Position* first();
	Position* last();
	Position* after(Position*);
	Position* before(Position*);
	bool isFirst(Position*);
	bool isLast(Position*);
	bool isEmpty();
	int size();

};

#endif