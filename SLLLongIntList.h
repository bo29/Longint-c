
#ifndef SLLLONGINTLIST_H
#define SLLLONGINTLIST_H

#include "LongIntList.h"
#include "SLLNode.h"

class SLLLongIntList : public LongIntList {

private:
    SLLNode * head;
	SLLNode * tail;
	int links;
	
public:
    SLLLongIntList();
    ~SLLLongIntList();

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
