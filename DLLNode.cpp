#include "DLLNode.h"

DLLNode::DLLNode(int value) : Position(value) {
	this->value = value;
}

void DLLNode::setNext(DLLNode* next) {
	this->next = next;
}

void DLLNode::setPrev(DLLNode* prev) {
	this->prev = prev;
}

DLLNode* DLLNode::getNext() {
	return next;
}

DLLNode* DLLNode::getPrev() {
	return prev;
}