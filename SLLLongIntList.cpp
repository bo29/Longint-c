#include "SLLLongIntList.h"


SLLLongIntList::SLLLongIntList() {
	head = nullptr;
	tail = nullptr;
	links = 0;
}

SLLLongIntList::~SLLLongIntList() {
	SLLNode* current = head;
	while (current != 0) {
		SLLNode* next = current->getNext();
		delete current;
		current = next;
	}
	head = 0;
	tail = 0;
	links = 0;
}

void SLLLongIntList::insertFirst(int value) {
	SLLNode* insert = new SLLNode(value);
	if (this->isEmpty()) {
		head = insert;
		tail = insert;
	}
	else {
		insert->setNext(head);
		head = insert;
	}
	++links;
}

void SLLLongIntList::insertLast(int value) {
	SLLNode* insert = new SLLNode(value);
	if (this->isEmpty()) {
		head = insert;
		tail = insert;
	}
	else {
		tail->setNext(insert);
		tail = tail->getNext();
	}
	++links;
}

Position* SLLLongIntList::first() {
	return head;
}

Position* SLLLongIntList::last() {
	return tail;
}

Position* SLLLongIntList::before(Position * p) {
    SLLNode * node = dynamic_cast<SLLNode*>(p);
	if (head == nullptr)
		throw "Empty list.";
	if (head == node)
		throw "Cannot attempt to access anything before beginning of list";
	SLLNode* temp = head;
	while (temp->getNext() != nullptr){
		if (temp->getNext() == node)
			return temp;
		temp = temp->getNext();
	}
	throw "Something went horribly, horribly wrong.";
}

Position* SLLLongIntList::after(Position * p) {
    SLLNode * node = dynamic_cast<SLLNode*>(p);
	if (head == nullptr)
		throw "Empty list.";
	if (tail == node)
		throw "Cannot attempt to access anything after end of list";
	return node->getNext();
}

bool SLLLongIntList::isFirst(Position * p) {
    SLLNode * node = dynamic_cast<SLLNode*>(p);
	if (node == head)
		return true;
	return false;
}

bool SLLLongIntList::isLast(Position * p) {
    SLLNode * node = dynamic_cast<SLLNode*>(p);
	if (node == tail)
		return true;
	return false;
}

bool SLLLongIntList::isEmpty() {
	if (head == 0)
		return true;
	return false;
}

int SLLLongIntList::size() {
	return links;
}