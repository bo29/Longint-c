#include "ArrayEntry.h"

ArrayEntry::ArrayEntry(int value) : Position(value) {
	this->value=value;
}

int ArrayEntry::getIndex() {
	return index;
}

void ArrayEntry::setIndex(int index) {
	this->index=index;
}