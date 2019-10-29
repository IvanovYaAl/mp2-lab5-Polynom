#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <iostream>
#include <string>
#include "stack.h"


using namespace std;

class TPostfix
{
	int CountNumber;
	string infix;
	string postfix;
public:
	TPostfix();
	TPostfix(string str);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	string DelPostfix();
	int Priority(char a, char b);
	bool Eqution();
	bool Check();
	bool Operation(char op);
	int CountNum();
	double Calculate(double* ); // Ввод переменных, вычисление по постфиксной форме
};

#endif
