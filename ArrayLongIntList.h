#ifndef ARRAYLONGINTLIST_H
#define ARRAYLONGINTLIST_H

#include "LongIntList.h"
#include "ArrayEntry.h"

// STEP 3 CODE

class ArrayLongIntList : public LongIntList {

private:

	ArrayEntry ** entries;
	
	int arraySize;
	
	int n;

	int lindex;
	int rindex;

	void newArray(bool addOne);

public:
    ArrayLongIntList();
    ~ArrayLongIntList();

    void insertFirst(int);
    void insertLast(int);

    Position* first();
    Position* last();

    Position* before(Position*);
    Position* after(Position*);

    bool isFirst(Position*);
    bool isLast(Position*);

    bool isEmpty();

    int size();
};

#endif
