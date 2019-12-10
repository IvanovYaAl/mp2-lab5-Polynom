
#pragma once
#include <iostream> 
#include "Monom.h"
#include <string>

using namespace std;

class Polynom
{
private:
	Monom key;
	Polynom* next;
public:
	Polynom();
	Polynom(Monom a);
	void add(Monom a);
	Monom ReturnMonom();
	bool isEmpty();
	int Count();
	Polynom* Sum(Polynom* pol);
	Polynom* Sub(Polynom* pol);
	void FindResult();
	string FirndResultToString(double, double, double);
	Polynom* MultByNum(double num);
	Polynom* Proizvod();
	Polynom* Integral();
	void WritePolynom();
	bool operator ==(Polynom* h);
protected:
};
