#ifndef DLLLONGINTLIST_H
#define DLLLONGINTLIST_H

#include "LongIntList.h"
#include "DLLNode.h"

class DLLLongIntList : public LongIntList {
private:
	DLLNode* head;
	DLLNode* tail;
	int links;
public:
	DLLLongIntList();
	~DLLLongIntList();

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