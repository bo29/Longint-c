#include "LongInt.h"
#include "UtilityOperations.h"
#include <algorithm>
#include <math.h>
using namespace std;

LongIntList* list;
bool isNegative;
bool signChanged = false;
string s;
LongInt::LongInt() {
	s = "";
	list = this->list;
	isNegative = false;
	initialize();
}

LongInt::LongInt(const string& str) {
	s = str;
	isNegative = false;
	list = this->list;
	initialize();
}


LongInt::~LongInt() {
	delete list;
}

LongIntList* LongInt::getList() const {
	return list;
}

void LongInt::initialize() {
	// Do not change this line until Step 3
	//this->list = new SLLLongIntList();
	// Step 3 initialization
	this->list = new ArrayLongIntList();
	//this->list = new DLLLongIntList();
	unsigned int toInsert;
	if (!s.empty()) {
		if ((s.length() <= 8)) {
			if (s[0] == '-') {
				toInsert = abs(stoi(s.substr(1, s.length())));
				list->insertFirst(toInsert);
			}
			else {
				toInsert = abs(stoi(s.substr(0, s.length())));
				list->insertFirst(toInsert);
			}
		}
		else {
			int remainder = s.length() % 8;
			if (remainder == 1 && s[0] == '-') {
				toInsert = stoi(s.substr(1, 8));
				list->insertFirst(toInsert);
				remainder += 8;
			}
			else if (s[0] == '-') {
				toInsert = stoi(s.substr(1, remainder - 1));
				list->insertFirst(toInsert);
			}
			else if (remainder > 0) {
				toInsert = stoi(s.substr(0, remainder));
				list->insertFirst(toInsert);
			}
			for (int i = remainder, j = remainder + 8; j <= s.length(); i += 8, j += 8) {
				toInsert = stoi(s.substr(i, 8));
				list->insertFirst(toInsert);//removed j-1
			}
		}
		setSign(*this);
	}
}

void LongInt::output() {
	Position* p = list->last();
	if (this->getSign() == true)
		printf("-");
	while (p != list->first()) {
		if (p->getValue() == 0) {
			for (int i = 0; i < 7; ++i)
				printf("%d", 0);
		}
		else if ((digits(p->getValue()) < 8) && !list->isLast(p)) {
			for (int i = 0; i < 8 - digits(p->getValue()); i++) {
				printf("%d", 0);
			}
		}
		printf("%d", p->getValue());
		p = list->before(p);
	}
	if ((digits(p->getValue()) < 8) && !list->isLast(p)) {
		for (int i = 0; i < 8 - digits(p->getValue()); i++)
			printf("%d", 0);
	}
	printf("%d\n", p->getValue());
}

void LongInt::printNodes() {
	Position* p = list->last();
	if (this->getSign() == true) {
		printf("-");
	}
	while (p != list->first()) {
		printf("%d -> ", p->getValue());
		p = list->before(p);
	}
	printf("%d\n", p->getValue());
}

bool LongInt::getSign() const {
	return isNegative;
}

void LongInt::setSign(const LongInt&) {
	if (list->size() == 1 && !list->isEmpty()) {
		if (stoi(s) < 0)
			isNegative = true;
		else
			isNegative = false;
	}
	else if (s[0] != '-')
		isNegative = false;
	else
		isNegative = true;
}

void LongInt::setSign(bool sign) {
	isNegative = sign;
}

void LongInt::setSignChanged(bool change) {
	signChanged = change;
}

int LongInt::getDigitCount() const {
	Position* p = list->first();
	int count = 0;
	while (!list->isLast(p)) {
		count += digits(p->getValue());
		if (digits(p->getValue() < 8))
			count += 8 - digits(p->getValue());
		p = list->after(p);
	}
	return count += digits(p->getValue());
}

bool LongInt::equalTo(const LongInt* i) const {
	if ((getDigitCount() != i->getDigitCount()) || getSign() != i->getSign()) {
		return false;
	}
	LongIntList* list2 = i->getList();
	Position* p1 = list->first();
	Position* p2 = list2->first();
	while (!list->isLast(p1)) {
		if (p1->getValue() != p2->getValue())
			return false;
		p1 = list->after(p1);
		p2 = i->getList()->after(p2);
	}
	return p1->getValue() == p2->getValue();
}

bool LongInt::lessThan(const LongInt* i) const {
	if (equalTo(i))
		return false;
	if (getSign() != i->getSign()) {
		if (getSign() == true)
			return true;
		return false;
	}
	else if (getDigitCount() < i->getDigitCount()) {
		if (getSign() == true)
			return false;
		return true;
	}
	else if (getDigitCount() > i->getDigitCount()) {
		if (getSign() == true)
			return true;
		return false;
	}
	else {
		LongIntList* list2 = i->getList();
		Position* p1 = list->last();
		Position* p2 = list2->last();
		while (p1->getValue() == p2->getValue() && p1 != list->first()) {
			p1 = list->before(p1);
			p2 = list2->before(p2);
		}
		if (p1->getValue() < p2->getValue()) {
			if (getSign() == true)
				return false;
			return true;
		}
		else if (p1->getValue() > p2->getValue()) {
			if (getSign() == true)
				return true;
			return false;
		}
	}
}

bool LongInt::greaterThan(const LongInt* i) const {
	if (equalTo(i))
		return false;
	if (getSign() != i->getSign()) {
		if (getSign() == true)
			return false;
		return true;
	}
	else if (getDigitCount() < i->getDigitCount()) {
		if (getSign() == true)
			return true;
		return false;
	}
	else if (getDigitCount() > i->getDigitCount()) {
		if (getSign() == true)
			return false;
		return true;
	}
	else {
		LongIntList* list2 = i->getList();
		Position* p1 = list->last();
		Position* p2 = list2->last();
		while (p1->getValue() == p2->getValue() && p1 != list->first()) {
			p1 = list->before(p1);
			p2 = list2->before(p2);
		}
		if (p1->getValue() < p2->getValue()) {
			if (getSign() == true)
				return true;
			return false;
		}
		else {
			if (getSign() == true)
				return false;
			return true;
		}
	}
}

LongInt* LongInt::add(LongInt* const i) {
	LongInt* k = new LongInt();
	if (!this->getSign() && i->getSign()) {
		i->setSign(false);
		i->setSignChanged(true);
		return this->subtract(i);
	}
	else if (this->getSign() && !i->getSign()) {
		setSign(false);
		setSignChanged(true);
		return i->subtract(this);
	}
	Position* pi = i->getList()->first();
	Position* pj = this->getList()->first();
	const int minSize = min(i->getList()->size(), this->getList()->size());
	int counter = 0;
	int over = 0;
	while (counter < minSize) {
		int toAdd = pi->getValue() + pj->getValue() + over;
		int under = underflow(toAdd);
		over = overflow(toAdd);
		k->getList()->insertLast(under);
		counter++;
		if (counter == minSize) {
			break;
		}
		pi = i->getList()->after(pi);
		pj = this->getList()->after(pj);
	}
	if (i->getList()->size() == this->getList()->size()) {
		if ((overflow(pi->getValue() + pj->getValue())) > 0) {
			k->getList()->insertLast(overflow(pi->getValue() + pj->getValue()));
		}
	}
	else if (minSize == i->getList()->size()) {
		pj = this->getList()->after(pj);
		while (pj != this->getList()->last()) {
			if (over > 0) {
				k->getList()->insertLast(pj->getValue() + over);
				over = 0;
			}
			else {
				k->getList()->insertLast(pj->getValue());
			}
			pj = this->getList()->after(pj);
		}
		if (overflow > 0) {
			k->getList()->insertLast(pj->getValue() + over);
		}
		else {
			k->getList()->insertLast(pj->getValue());
		}
	}
	else if (minSize == this->getList()->size()) {
		pi = i->getList()->after(pi);
		while (pi != i->getList()->last()) {
			if (over > 0) {
				k->getList()->insertLast(pi->getValue() + over);
				over = 0;
			}
			else {
				k->getList()->insertLast(pi->getValue());
			}
			pi = i->getList()->after(pi);
		}
		if (overflow > 0) {
			k->getList()->insertLast(pi->getValue() + over);
		}
		else {
			k->getList()->insertLast(pi->getValue());
		}
	}
	if (!i->getSign() && !this->getSign()) {
		k->setSign(false);
	}
	else {
		k->setSign(true);
	}
	if (signChanged) {
		setSign(!getSign());
		setSignChanged(false);
	}
	if (i->signChanged) {
		i->setSign(!i->getSign());
		i->signChanged = false;
	}
	return k;
}

LongInt* LongInt::subtract(LongInt* const i) {
	LongInt* j = new LongInt();
	if (this->equalTo(i)) {
		LongInt* k = new LongInt();
		k->getList()->insertFirst(0);
		k->setSign(false);
		return k;
	}
	else if (!this->getSign() && i->getSign()) {
		i->setSign(false);
		i->setSignChanged(true);
		return this->add(i);
	}
	else if (this->getSign() && i->getSign()) {
		i->setSign(false);
		i->setSignChanged(true);
		setSign(false);
		setSignChanged(true);
		return i->subtract(this);
	}
	else if (getSign() && !i->getSign()) {
		j->setSign(true);
		setSign(false);
		setSignChanged(true);
		Position* pi = i->getList()->first();
		Position* pj = this->getList()->first();
		const int minSize = min(i->getList()->size(), this->getList()->size());
		int counter = 0;
		int over = 0;
		while (counter < minSize) {
			int toAdd = pi->getValue() + pj->getValue() + over;
			int under = underflow(toAdd);
			over = overflow(toAdd);
			j->getList()->insertLast(under);
			counter++;
			if (counter == minSize) {
				break;
			}
			pi = i->getList()->after(pi);
			pj = this->getList()->after(pj);
		}
		if (i->getList()->size() == this->getList()->size()) {
			if ((overflow(pi->getValue() + pj->getValue())) > 0) {
				j->getList()->insertLast(overflow(pi->getValue() + pj->getValue()));
			}
		}
		else if (minSize == i->getList()->size()) {
			pj = this->getList()->after(pj);
			while (pj != this->getList()->last()) {
				if (over > 0) {
					j->getList()->insertLast(pj->getValue() + over);
					over = 0;
				}
				else {
					j->getList()->insertLast(pj->getValue());
				}
				pj = this->getList()->after(pj);
			}
			if (overflow > 0) {
				j->getList()->insertLast(pj->getValue() + over);
			}
			else {
				j->getList()->insertLast(pj->getValue());
			}
		}
		else if (minSize == this->getList()->size()) {
			pi = i->getList()->after(pi);
			while (pi != i->getList()->last()) {
				if (over > 0) {
					j->getList()->insertLast(pi->getValue() + over);
					over = 0;
				}
				else {
					j->getList()->insertLast(pi->getValue());
				}
				pi = i->getList()->after(pi);
			}
			if (overflow > 0) {
				j->getList()->insertLast(pi->getValue() + over);
			}
			else {
				j->getList()->insertLast(pi->getValue());
			}
		}
		if (signChanged) {
			setSign(!getSign());
			setSignChanged(false);
		}
		if (i->signChanged) {
			i->setSign(!i->getSign());
			i->signChanged = false;
		}
		return j;
	}
	else if (getSign() == false && i->getSign() == false) {
		if (greaterThan(i)) {
			j->setSign(false);
		}
		else if (lessThan(i)) {
			j->setSign(true);
		}
		int minSize = min(list->size(), i->getList()->size());
		int k = 0;
		Position* p1;
		Position* p2;
		if (list->size() == i->getList()->size()) {
			p1 = list->last();
			p2 = i->getList()->last();
			while (p1->getValue() == p2->getValue()) {
				minSize--;
				p1 = list->before(p1);
				p2 = i->getList()->before(p2);
			}
		}
		p1 = list->first();
		p2 = i->getList()->first();
		int carry = 0;
		while (k < minSize) {
			int toSub;
			if (p1->getValue() < p2->getValue()) {
				if (!j->getSign()) {
					toSub = 100000000 - abs(p1->getValue() - p2->getValue()) - carry;
				}
				else {
					toSub = abs(p1->getValue() - p2->getValue()) - carry;
				}
			}
			else {
				if (!j->getSign()) {
					toSub = abs(p1->getValue() - p2->getValue()) - carry;
				}
				else {
					toSub = 100000000 - abs(p1->getValue() - p2->getValue()) - carry;
					if (toSub == 100000000) {
						toSub = 0;
					}
				}
			}
			carry = p1->getValue() - p2->getValue();
			if (carry == 0 && (p1 == list->last() || p2 == i->getList()->last())) {
				break;
			}
			if (carry < 0) {
				if (j->getSign() == false) {
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
			else if (carry > 0) {
				if (j->getSign() == false) {
					carry = 0;
				}
				else {
					carry = 1;
				}
			}
			if (list->size() == i->getList()->size() && (p1 == list->last() || k == minSize - 1)) {
				if (toSub == 0) {
					break;
				}
			}
			j->getList()->insertLast(toSub);
			k++;
			if (k == minSize) {
				break;
			}
			p1 = list->after(p1);
			p2 = i->getList()->after(p2);
		}
		if (list->size() == i->getList()->size()) {
			if (abs(overflow(p1->getValue() - p2->getValue())) > 0) {
				j->getList()->insertLast(abs(overflow(p1->getValue() - p2->getValue() - carry)));
			}
		}
		else if (minSize == list->size()) {
			int overflow = 0;
			p2 = i->getList()->after(p2);
			while (p2 != i->getList()->last()) {
				if (p2->getValue() - carry < 0) {
					j->getList()->insertLast(100000000 + (p2->getValue() - carry - overflow));
					overflow = abs(p2->getValue() - carry);
				}
				else {
					j->getList()->insertLast(p2->getValue() - carry - overflow);
					overflow = 0;
				}
				p2 = i->getList()->after(p2);
				carry = 0;
			}
			j->getList()->insertLast(p2->getValue() - carry - overflow);
		}
		else if (minSize == i->getList()->size()) {
			int overflow = 0;
			p1 = list->after(p1);
			while (p1 != list->last()) {
				if (p1->getValue() - carry < 0) {
					j->getList()->insertLast(100000000 + (p1->getValue() - carry - overflow));
					overflow = abs(p1->getValue() - carry);
				}
				else {
					j->getList()->insertLast(p1->getValue() - carry - overflow);
					overflow = 0;
				}
				p1 = list->after(p1);
				carry = 0;
			}
			j->getList()->insertLast(p1->getValue() - carry - overflow);
		}
	}
	if (signChanged) {
		setSign(!getSign());
		setSignChanged(false);
	}
	if (i->signChanged) {
		i->setSign(!i->getSign());
		i->signChanged = false;
	}
	return j;
}

LongInt* LongInt::multiply(LongInt* const i) {
	if (list->isEmpty() && i->getList()->isEmpty()) {
		throw "LongInts have no values";
	}
	else if (list->isEmpty()) {
		return i;
	}
	else if (i->getList()->isEmpty()) {
		return this;
	}
	LongInt* j = new LongInt();
	if ((!getSign() && !i->getSign()) || (getSign() && i->getSign())) {
		j->setSign(false);
	}
	else if ((getSign() && !i->getSign()) || (!getSign() && i->getSign())) {
		j->setSign(true);
	}
	if (list->size() == 1) {
		if (list->first()->getValue() == 0) {
			j->getList()->insertLast(0);
			j->setSign(false);
			return j;
		}
		else if (list->first()->getValue() == 1) {
			bool jSign = j->getSign();
			j = i;
			j->setSign(jSign);
			return j;
		}
	}
	if (i->list->size() == 1) {
		if (i->list->first()->getValue() == 0) {
			j->getList()->insertLast(0);
			j->setSign(false);
			return j;
		}
		else if (i->list->first()->getValue() == 1) {
			bool jSign = j->getSign();
			j = this;
			j->setSign(jSign);
			return j;
		}
	}
	Position* p1 = list->first();
	Position* p2 = i->getList()->first();
	int minSize = min(list->size(), i->getList()->size());
	int maxSize = max(list->size(), i->getList()->size());
	const int columns = list->size() + i->getList()->size();
	const int rows = list->size()*i->getList()->size();
	int count = columns;
	int k = maxSize - 1;
	int m = 0;
	int n = columns - 1;
	unsigned int** arrays = new unsigned int*[rows];
	for (int i = 0; i < rows; i++) {
		arrays[i] = new unsigned int[columns];
	}
	while (m < rows) {
		int z1 = upperHalf(p1->getValue())*upperHalf(p2->getValue());
		int z3 = lowerHalf(p1->getValue())*lowerHalf(p2->getValue());
		int z2 = (upperHalf(p1->getValue()) + lowerHalf(p1->getValue()))*
			(upperHalf(p2->getValue()) + lowerHalf(p2->getValue())) - z1 - z3;
		int v1 = z1 + upperHalf(z2);
		int v2 = (int)(z3 + lowerHalf(z2)*pow(10, 4));
		arrays[m][n] = v2;
		arrays[m][n - 1] = v1;
		m++; n--;
		if (k > 0) {
			if (i->getList()->size() == minSize) {
				p1 = list->after(p1);
			}
			else if (list->size() == minSize) {
				p2 = i->getList()->after(p2);
			}
			k--;
		}
		else if (k == 0) {
			if (i->getList()->size() == minSize && p2 != i->getList()->last()) {
				count--;
				n = count - 1;
				p2 = i->getList()->after(p2);
				p1 = list->first();
				k = maxSize - 1;
			}
			else if (list->size() == minSize && p1 != list->last()) {
				count--;
				n = count - 1;
				p1 = list->after(p1);
				p2 = i->getList()->first();
				k = maxSize - 1;
			}
		}
	}
	unsigned int over = 0;
	unsigned int toInsert;
	for (n = columns - 1; n >= 0; n--) {
		if (over > 0) {
			toInsert = over;
			over = 0;
		}
		else {
			toInsert = 0;
		}
		for (m = 0; m < rows; m++) {
			unsigned int current = arrays[m][n];
			if (current == 0 || current >= 3452816845) {
				continue;
			}
			over = over + overflow(toInsert + current);
			toInsert = underflow(toInsert + current);
		}
		if (n == 0 && underflow(toInsert) == 0) {
			continue;
		}
		j->getList()->insertLast(toInsert);
	}
	for (int i = 0; i < rows; i++) {
		delete[] arrays[i];
	}
	delete[] arrays;
	return j;
}

LongInt* LongInt::power(const int p) {
	if (list->isEmpty()) {
		throw "LongInt doesn't exist.";
	}
	if (p <= 0) {
		LongInt* one = new LongInt("1");
		return one;
	}
	else if (p == 1) {
		return this;
	}
	else if (p % 2 == 0) {
		return multiply(this)->power(p / 2);
	}
	else {
		return multiply(multiply(this)->power((p - 1) / 2));
	}
}