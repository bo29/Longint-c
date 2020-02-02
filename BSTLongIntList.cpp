#include "BSTLongIntList.h"
#include <math.h>
#include <algorithm>
using namespace std;

BSTLongIntList::BSTLongIntList()
{
	this->root = nullptr;
	this->links = 0;
}

BSTLongIntList::~BSTLongIntList()
{
	if (root != nullptr)
	{
		inorder(root);
		delete root;
	}
}

void BSTLongIntList::inorder(BSTNode* root)
{
	if (root != nullptr)
	{
		inorder(root->getLeftChild());
		delete(root);
		inorder(root->getRightChild());
		delete(root);
	}
}

bool BSTLongIntList::isEmpty()
{
	return root == nullptr;
}

int BSTLongIntList::size()
{
	return links;
}

BSTNode* BSTLongIntList::rotateWithLeftChild(BSTNode* k2)
{
	BSTNode* k1 = k2->getLeftChild();
	k2->setLeftChild(k1->getRightChild());
	k1->setRightChild(k2);
	k2->setHeight(max(k2->getLeftChild()->getHeight(), k2->getRightChild()->getHeight()) + 1);
	k1->setHeight(max(k1->getLeftChild()->getHeight(), k2->getHeight()) + 1);
	return k1;
}

BSTNode* BSTLongIntList::rotateWithRightChild(BSTNode* k1)
{
	BSTNode* k2 = k1->getRightChild();
	k1->setRightChild(k2->getLeftChild());
	k2->setLeftChild(k1);
	k1->setHeight(max(k1->getLeftChild()->getHeight(), k1->getRightChild()->getHeight()) + 1);
	k2->setHeight(max(k2->getRightChild()->getHeight(), k1->getHeight()) + 1);
	return k2;
}

BSTNode* BSTLongIntList::doubleWithLeftChild(BSTNode* k3)
{
	k3->setLeftChild(rotateWithRightChild(k3->getLeftChild()));
	return rotateWithLeftChild(k3);
}

BSTNode* BSTLongIntList::doubleWithRightChild(BSTNode* k1)
{
	k1->setRightChild(rotateWithLeftChild(k1->getRightChild()));
	return rotateWithRightChild(k1);
}

void BSTLongIntList::insertFirst(int value)
{
	root = insert(value, root);
}

void BSTLongIntList::insertLast(int value)
{
	root = insert(value, root);
}

BSTNode* BSTLongIntList::insert(int value, BSTNode* temp)
{
	if (temp == nullptr)
	{
		temp = new BSTNode(value);
	}
	else if (value < temp->getValue())
	{
		temp->setLeftChild(insert(value, temp->getLeftChild()));
		if (temp->getLeftChild()->getHeight() - temp->getRightChild()->getHeight() == 2)
		{
			if (value < temp->getLeftChild()->getValue())
			{
				temp = rotateWithLeftChild(temp);
			}
			else
			{
				temp = doubleWithLeftChild(temp);
			}
		}
	}
	else if (value > temp->getValue())
	{
		temp->setRightChild(insert(value, temp->getRightChild()));
		if (temp->getRightChild()->getHeight() - temp->getLeftChild()->getHeight() == 2)
		{
			if (value > temp->getRightChild()->getValue())
			{
				temp = rotateWithRightChild(temp);
			}
			else
			{
				temp = doubleWithRightChild(temp);
			}
		}
	}
	temp->setHeight(max(temp->getLeftChild()->getHeight(), temp->getRightChild()->getHeight() + 1));
	links++;
	return temp;
}

Position* BSTLongIntList::after(Position* p)
{
	BSTNode* node = dynamic_cast<BSTNode*>(p);
	if (root == nullptr)
	{
		return nullptr;
	}
	if (node->getLeftChild() != nullptr)
	{
		if (node->getLeftChild()->isExternal())
		{
			return node->getLeftChild();
		}
		else
		{
			BSTNode* temp = node->getLeftChild();
			while (temp->getRightChild() != nullptr)
			{
				temp = temp->getRightChild();
			}
			return temp;
		}
	}
	return nullptr;
}

Position* BSTLongIntList::before(Position* p)
{
	BSTNode* node = dynamic_cast<BSTNode*>(p);
	if (root == nullptr)
	{
		return nullptr;
	}
	if (node->isExternal())
	{
		BSTNode* temp = root;
		if (temp->getValue() < node->getValue())
		{
			while()
		}
	}
	if (node->getRightChild() != nullptr)
	{
		if (node->getRightChild()->isExternal())
		{
			return node->getRightChild();
		}
		else
		{
			BSTNode* temp = node->getRightChild();
			while (temp->getLeftChild() != nullptr)
			{
				temp = temp->getLeftChild();
			}
			return temp;
		}
	}
	return nullptr;
}

Position* BSTLongIntList::first()
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (links == 1)
	{
		return root;
	}
	BSTNode* temp = root;
	while (temp->getRightChild() != nullptr)
	{
		temp = temp->getRightChild();
	}
	return temp;
}

Position* BSTLongIntList::last()
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (links == 1)
	{
		return root;
	}
	BSTNode* temp = root;
	while (temp->getLeftChild() != nullptr)
	{
		temp = temp->getLeftChild();
	}
	return temp;
}

bool BSTLongIntList::isFirst(Position* p)
{
	BSTNode* node = dynamic_cast<BSTNode*>(p);
	if (root == nullptr)
	{
		return nullptr;
	}
	if (links == 1)
	{
		return root;
	}
	BSTNode* temp = root;
	while (temp->getRightChild() != nullptr)
	{
		temp = temp->getRightChild();
	}
	return node == temp;
}

bool BSTLongIntList::isLast(Position* p)
{
	BSTNode* node = dynamic_cast<BSTNode*>(p);
	if (root == nullptr)
	{
		return nullptr;
	}
	if (links == 1)
	{
		return root;
	}
	BSTNode* temp = root;
	while (temp->getLeftChild() != nullptr)
	{
		temp = temp->getLeftChild();
	}
	return node == temp;
}