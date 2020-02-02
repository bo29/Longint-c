#include "ArrayLongIntList.h"
#include "ArrayEntry.h"
#include <iostream>

// STEP 3 CODE

ArrayLongIntList::ArrayLongIntList() {
	this->n = 0;
	this->arraySize = 10; // TODO: What should be the initial size?
	lindex = arraySize / 2;
	rindex = arraySize / 2;
	entries = new ArrayEntry*[arraySize];
	// TODO: Initialize the array.
}

ArrayLongIntList::~ArrayLongIntList() {
	delete[] entries;
}

void ArrayLongIntList::insertFirst(int value) {
	if (n == 0) {
		entries[lindex] = new ArrayEntry(value);
		entries[lindex]->setIndex(0);
		lindex--;
		rindex++;
		n++;
	}
	else if (lindex > -1) {
		entries[lindex] = new ArrayEntry(value);
		n++;
		for (int i = lindex, j = 0; i < rindex; i++, j++) {
			entries[i]->setIndex(j);
		}
		lindex--;
	}
	else if (lindex <= -1) {
		newArray(true);
		entries[lindex + 1] = new ArrayEntry(value);
		entries[lindex + 1]->setIndex(0);
	}
}

void ArrayLongIntList::insertLast(int value) {
	if (n == 0) {
		entries[rindex] = new ArrayEntry(value);
		entries[rindex]->setIndex(0);
		lindex--;
		rindex++;
		n++;
	}
	else if (rindex < arraySize) {
		entries[rindex] = new ArrayEntry(value);
		entries[rindex]->setIndex(n);
		rindex++;
		n++;
	}
	else if (rindex >= arraySize) {
		newArray(false);
		entries[rindex - 1] = new ArrayEntry(value);
		entries[rindex - 1]->setIndex(n - 1);
	}
}

void ArrayLongIntList::newArray(bool addOne) {
	n++;
	arraySize = n * 3;
	int index = lindex + 1;
	ArrayEntry** newEntries = new ArrayEntry*[arraySize];
	for (int i = n + addOne; i <= 2 * (n - 1) + addOne; i++, index++) {
		newEntries[i] = entries[index];
		newEntries[i]->setIndex(entries[index]->getIndex() + addOne);
	}
	delete[] entries;
	entries = new ArrayEntry*[arraySize];
	for (int i = n; i < n * 2; i++) {
		entries[i] = newEntries[i];
	}
	delete[] newEntries;
	lindex = n - 1;
	rindex = n * 2;
}

Position* ArrayLongIntList::first() {
	return entries[lindex + 1];
}

Position* ArrayLongIntList::last() {
	return entries[rindex - 1];
}

Position* ArrayLongIntList::before(Position * p) {
    ArrayEntry * entry = dynamic_cast<ArrayEntry*>(p);
	if (entries[lindex + 1] == p) {
		throw "ArrayIndexOutOfBoundsException: -1";
	}
	return entries[(entry->getIndex() + lindex)];
}

Position* ArrayLongIntList::after(Position * p) {
    ArrayEntry * entry = dynamic_cast<ArrayEntry*>(p);
	if (entries[rindex - 1] == p) {
		throw "ArrayIndexOutOfBoundsException";
	}
	return entries[(entry->getIndex()) + lindex + 2];
}

bool ArrayLongIntList::isFirst(Position * p) {
    ArrayEntry * entry = dynamic_cast<ArrayEntry*>(p);
	return entries[lindex + 1] == p;
}

bool ArrayLongIntList::isLast(Position * p) {
    ArrayEntry * entry = dynamic_cast<ArrayEntry*>(p);
	return entries[rindex - 1] == p;
}

bool ArrayLongIntList::isEmpty() {
	return n == 0;
}

int ArrayLongIntList::size() {
	return n;
}