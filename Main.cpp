#include <iostream>
#include "stdio.h"
#include "SLLLongIntList.h"
#include "ArrayLongIntList.h"
#include "LongInt.h"
#include "UtilityOperations.h"
#include <time.h>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
void output(map<char, LongInt*>& map, vector<char>& vector) {
	for (auto &i : vector) {
		cout << i << ": ";
		map[i]->output();
		cout << "Nodes: ";
		map[i]->printNodes();
		cout << "Number of digits: " << map[i]->getDigitCount() << endl;
		cout << "isNegative: ";
		map[i]->getSign() ? printf("true") : printf("false");
		cout << '\n' << endl;
	}
}
void printUtils(const unsigned int& t) {
	cout << "LongIntUtils for " << t << endl;
	cout << "overflow: " << overflow(t) << endl;
	cout << "underflow: " << underflow(t) << endl;
	cout << "upperHalf: " << upperHalf(t) << endl;
	cout << "lowerHalf: " << lowerHalf(t) << endl;
	cout << "digits: " << digits(t);
	cout << '\n' << endl;
}
void compare(map<char, LongInt*>& map, vector<char>& vector) {
	cout << "equalTo\t\t\tlessThan\t\tgreaterThan" << endl;
	cout << "-----------------------------------------------------------" << endl;
	for (auto &i : vector) {
		for (auto &j : vector) {
			cout << i << '=' << j << ": ";
			map[i]->equalTo(map[j]) ? printf("true") : printf("false");
			cout << "\t\t";
			cout << i << '<' << j << ": ";
			map[i]->lessThan(map[j]) ? printf("true") : printf("false");
			cout << "\t\t";
			cout << i << '>' << j << ": ";
			map[i]->greaterThan(map[j]) ? printf("true") : printf("false");
			cout << endl;
		}
		cout << endl;
	}
	cout << '\n' << endl;
}
void addition(map<char, LongInt*>& map, vector<char>& vector) {
	cout << "Addition\n--------" << endl;
	for (auto &i : vector) {
		for (auto &j : vector) {
			cout << i << '+' << j << ": ";
			map[i]->add(map[j])->output();
		}
		cout << endl;
	}
}
void subtraction(map<char, LongInt*>& map, vector<char>& vector) {
	cout << "Subtraction\n-----------" << endl;
	for (auto &i : vector) {
		for (auto &j : vector) {
			cout << i << '-' << j << ": ";
			map[i]->subtract(map[j])->output();
		}
		cout << endl;
	}
}
void multiplication(map<char, LongInt*>& map, vector<char>& vector) {
	cout << "Multiplication\n--------------" << endl;
	for (auto &i : vector) {
		for (auto &j : vector) {
			cout << i << '*' << j << ": ";
			map[i]->multiply(map[j])->output();
		}
		cout << endl;
	}
}
void powers(map<char, LongInt*>& map, vector<char>& vector) {
	cout << "Power\n-----" << endl;
	for (auto &i : vector) {
		cout << i << "^5: ";
		map[i]->power(5)->output();
		cout << i << "^10: ";
		map[i]->power(10)->output();
		cout << i << "^20: ";
		map[i]->power(20)->output();
		cout << endl;
	}
}
int main(){
	map<char, LongInt*> map;
	vector<char> vector;
	clock_t t;
	t = clock();
	size_t size = 100000;
	LongInt* A = new LongInt("2222");
	LongInt* B = new LongInt("99999999");
	LongInt* C = new LongInt("-246813575732");
	LongInt* D = new LongInt("180270361023456789");
	LongInt* E = new LongInt("1423550000000010056810000054593452907711568359");
	LongInt* F = new LongInt("-350003274594847454317890");
	LongInt* G = new LongInt("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	LongInt* H = new LongInt("-98534342983742987342987339234098230498203894209928374662342342342356723423423");
	LongInt* I = new LongInt("8436413168438618351351684694835434894364351846843435168484351684684315384684313846813153843135138413513843813513813138438435153454154515151513141592654543515316848613242587561516511233246174561276521672162416274123076527612");
	LongInt* J = B->add(C);
	LongInt* K = C->add(D);
	LongInt* L = I->add(I);
	LongInt* M = A->add(I);
	LongInt* N = B->add(K);
	LongInt* O = A->subtract(D);
	LongInt* P = C->subtract(D);
	LongInt* Q = D->subtract(C);
	LongInt* R = L->subtract(L);
	LongInt* S = P->subtract(O);
	LongInt* T = N->subtract(Q);
	LongInt* U = A->multiply(D);
	LongInt* V = B->multiply(C);
	LongInt* W = D->multiply(D);
	LongInt* X = O->multiply(I);
	LongInt* Y = J->multiply(P);
	LongInt* Z = M->multiply(N);
	map['A']=A;
	vector.push_back('A');
	map['B'] = B;
	vector.push_back('B');
	map['C'] = C;
	vector.push_back('C');
	map['D'] = D;
	vector.push_back('D');
	map['E'] = E;
	vector.push_back('E');
	map['F'] = F;
	vector.push_back('F');
	map['G'] = G;
	vector.push_back('G');
	map['H'] = H;
	vector.push_back('H');
	map['I'] = I;
	vector.push_back('I');
	output(map, vector);
	printUtils(2222);
	printUtils(99999999);
	compare(map, vector);
	addition(map, vector);
	subtraction(map, vector);
	multiplication(map, vector);
	powers(map, vector);
	cout << "J=B+C: ";
	J->output();
	cout << "K=C+D: ";
	K->output();
	cout << "L=I+I: ";
	L->output();
	cout << "M=A+I: ";
	M->output();
	cout << "N=B+K: ";
	N->output();
	cout << "O=A-D: ";
	O->output();
	cout << "P=C-D: ";
	P->output();
	cout << "Q=D-C: ";
	Q->output();
	cout << "R=L-L: ";
	R->output();
	cout << "S=P-O: ";
	S->output();
	cout << "T=N-Q: ";
	T->output();
	cout << "U=A*D: ";
	U->output();
	cout << "V=B*C: ";
	V->output();
	cout << "W=D*D: ";
	W->output();
	cout << "X=O*I: ";
	X->output();
	cout << "Y=J*P: ";
	Y->output();
	cout << "Z=M*N: ";
	Z->output();
	t = clock() - t;
	cout << "time: " << (double) t / 1000 << " seconds" << endl;
	cout << "end" << endl;
	cin.get();
	return 0;
}