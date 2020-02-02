#include "UtilityOperations.h"
#include <cmath>

int overflow(const unsigned int t) {
	if (digits(t) > 8)
		return t / (unsigned int)pow(10, 8);
	return 0;
}

int underflow(const unsigned int t) {
	if (t == 0)
		return 0;
	return t % (unsigned int)pow(10, 8);
}

int digits(const unsigned int t) {
	if (t == 0)
		return 1;
	else if (t < 0)
		return (unsigned int)log10(t) + 1;
	return (unsigned int)log10(t) + 1;
}

int upperHalf(const unsigned int t) {
	if (t == 0)
		return 0;
	return t / (unsigned int)pow(10, 4);
}

int lowerHalf(const unsigned int t) {
	if (t == 0)
		return 0;
	return t % (unsigned int)pow(10, 4);
}

