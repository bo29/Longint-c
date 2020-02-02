#ifndef BSTNODE_H
#define BSTNODE_H

#include "Position.h"

class BSTNode : public Position
{
private:
	int height;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

public:
	BSTNode(int n);
	~BSTNode();
	int value;
	int getHeight();
	void setHeight(int);
	BSTNode* getParent();
	BSTNode* getLeftChild();
	BSTNode* getRightChild();
	void setParent(BSTNode*);
	void setLeftChild(BSTNode*);
	void setRightChild(BSTNode*);
	bool isExternal();
	bool isInternal();
};
#endif