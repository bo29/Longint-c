#include "SLLNode.h"

SLLNode::SLLNode(int value) : Position(value) {
	this->value = value;
}

void SLLNode::setNext(SLLNode* next) {
	this->next = next;
}

SLLNode* SLLNode::getNext() {
	return next;
}