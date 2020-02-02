#include "DLLLongIntList.h"


DLLLongIntList::DLLLongIntList() {
	head = nullptr;
	tail = nullptr;
	links = 0;
}

DLLLongIntList::~DLLLongIntList() {
	DLLNode* current = head;
	while (current != 0) {
		DLLNode* next = current->getNext();
		delete current;
		current = next;
	}
	head = 0;
	tail = 0;
	links = 0;
}

void DLLLongIntList::insertFirst(int value) {
	DLLNode* insert = new DLLNode(value);
	if (this->isEmpty()) {
		head = insert;
		tail = insert;
	}
	else {
		insert->setNext(head);
		head->setPrev(insert);
		head = head->getPrev();
	}
	links++;
}

void DLLLongIntList::insertLast(int value) {
	DLLNode* insert = new DLLNode(value);
	if (this->isEmpty()) {
		head = insert;
		tail = insert;
	}
	else {
		insert->setPrev(tail);
		tail->setNext(insert);
		tail = tail->getNext();
	}
	links++;
}

Position* DLLLongIntList::first() {
	return head;
}

Position* DLLLongIntList::last() {
	return tail;
}


Position* DLLLongIntList::before(Position* p) {
	DLLNode* node = dynamic_cast<DLLNode*>(p);
	return node->getPrev();
}
Position* DLLLongIntList::after(Position* p) {
	DLLNode* node = dynamic_cast<DLLNode*>(p);
	return node->getNext();
}

bool DLLLongIntList::isFirst(Position* p) {
	DLLNode* node = dynamic_cast<DLLNode*>(p);
	if (links == 0) {
		throw "LongInt has not been initialized";
	}
	else if (node == head) {
		return true;
	}
	return false;
}

bool DLLLongIntList::isLast(Position* p) {
	DLLNode* node = dynamic_cast<DLLNode*>(p);
	if (links == 0) {
		throw "LongInt has not been initialized";
	}
	else if (node == tail) {
		return true;
	}
	return false;
}

bool DLLLongIntList::isEmpty() {
	if (head == 0) {
		return true;
	}
	return false;
}

int DLLLongIntList::size() {
	return links;
}