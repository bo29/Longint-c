#ifndef DLLNODE_H
#define DLLNODE_H

#include "Position.h"

class DLLNode : public Position {

private:
	DLLNode* next;
	DLLNode* prev;

public:
	DLLNode(int);

	void setNext(DLLNode*);
	void setPrev(DLLNode*);
	DLLNode* getNext();
	DLLNode* getPrev();

};

#endif