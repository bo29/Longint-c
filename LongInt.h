#ifndef LONGINT_H
#define LONGINT_H

#include <string>
#include "SLLLongIntList.h"
#include "ArrayLongIntList.h"
#include "DLLLongIntList.h"
#include "BSTLongIntList.h"

using std::string;

class LongInt {

private:
    LongIntList * list;

	bool isNegative;
	bool signChanged;

	void initialize();
	void setSign(const LongInt&);
	void setSign(bool sign);
	void setSignChanged(bool change);
	LongIntList* getList() const;

public:

    LongInt(const string&);
	LongInt();
    ~LongInt();
	
    void output();
	void printNodes();

    bool getSign() const;
	


    int getDigitCount() const;

    bool equalTo(const LongInt *) const;
    bool lessThan(const LongInt*) const;
    bool greaterThan(const LongInt*) const;

    LongInt* add(LongInt* const);//changed from const LongInt to LongInt const
    LongInt* subtract(LongInt* const);
    LongInt* multiply(LongInt* const);
    LongInt* power(const int pow);
};

#endif // LONGINTEGER_H
