#include "BSTNode.h"

BSTNode::BSTNode(int value) : Position(value)
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->height = 0;
	this->value = value;
}

BSTNode::~BSTNode()
{
	delete left;
	delete right;
}

void BSTNode::setParent(BSTNode* parent)
{
	this->parent = parent;
}

BSTNode* BSTNode::getParent()
{
	return parent;
}

void BSTNode::setLeftChild(BSTNode* left)
{
	this->left = left;
}

BSTNode* BSTNode::getLeftChild()
{
	return left;
}

void BSTNode::setRightChild(BSTNode* right)
{
	this->right = right;
}

BSTNode* BSTNode::getRightChild()
{
	return right;
}

bool BSTNode::isExternal()
{
	if ((this->left == nullptr && this->right == nullptr) || this == nullptr)
	{
		return true;
	}
	return false;
}

bool BSTNode::isInternal()
{
	if (this->right != nullptr || this->left != nullptr)
	{
		return true;
	}
	return false;
}

void BSTNode::setHeight(int height)
{
	this->height = height;
}

int BSTNode::getHeight()
{
	return this == nullptr ? -1 : height;
}