#ifndef SLLNODE_H
#define SLLNODE_H

#include "Position.h"

class SLLNode : public Position {

private:
    SLLNode * next;

public:
    SLLNode(int);
	
	void setNext(SLLNode*);
	SLLNode* getNext();
};

#endif
