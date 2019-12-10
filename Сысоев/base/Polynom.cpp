
#include "Polynom.h"
#include "Monom.h"

using namespace std;

Polynom::Polynom()
{
	Monom lo;
	key = lo;
	next = NULL;
}

Polynom::Polynom(Monom a)
{
	key = a;
	next = NULL;
}

void Polynom::add(Monom a)
{
	if (isEmpty())
	{
		key = a;
	}
	else
	{
		Polynom* p = this;
		while (p->next != NULL) {
			p = p->next;
		}
		Polynom* p1 = new Polynom(a);
		p->next = p1;
		p1->next = NULL;
	}
}
Monom Polynom::ReturnMonom() {
	return key;
}

bool Polynom::isEmpty()
{
	Polynom* p = this;
	Monom lo;
	while (p != NULL)
	{
		if (p->key != lo)
			return false;
		p = p->next;
	}
	return true;
}

int Polynom::Count() {
	int coun = 0;
	Polynom* p = this;
	while (p != NULL)
	{
		coun++;
		p = p->next;
	}
	return coun;
}

Polynom* Polynom::Sum(Polynom* pol) {
	Polynom* res = new Polynom();
	Polynom* p1 = this;
	Polynom* p2 = pol;
	Monom po;
	int first = 0, second = 0;
	first = p1->Count();
	second = p2->Count();
	for (int i = 0; i < first; i++) {
		Polynom* p2 = pol;
		int f = -1;
		for (int j = 0; j < second; j++) {
			if (p1->key == p2->key) {
				p1->key = p1->key + p2->key;
				p2->key = po;
			}
			p2 = p2->next;
		}
		res->add(p1->key);
		p1 = p1->next;
	}
	Polynom* p3 = p2;
	for (int i = 0; i < second; i++) {
		if (p3->key == po) { p3 = p3->next; }
		else {
			res->add(p3->key);
			p3 = p3->next;
		}
	}
	return res;
}

Polynom* Polynom::Sub(Polynom* pol) {
	Polynom* res = new Polynom();
	Polynom* p1 = this;
	Polynom* p2 = pol;
	Monom po;
	int first = 0, second = 0;
	first = p1->Count();
	second = p2->Count();
	for (int i = 0; i < first; i++) {
		Polynom* p2 = pol;
		int f = -1;
		for (int j = 0; j < second; j++) {
			if (p1->key == p2->key) {
				p1->key = p1->key - p2->key;
				p2->key = po;
			}
			p2 = p2->next;
		}
		res->add(p1->key);
		p1 = p1->next;
	}
	Polynom* p3 = p2;
	for (int i = 0; i < second; i++) {
		if (p3->key == po) { p3 = p3->next; }
		else {
			p3->key.RetFactor(p3->key.GetFactor() * -1);
			res->add(p3->key);
			p3 = p3->next;
		}
	}
	return res;
}

void Polynom::FindResult() {
	cout << "Enter coordinates (x, y, z): " << endl;
	double X, Y, Z;
	cin >> X >> Y >> Z;
	long long RESULT = 0;
	Polynom* p = this;
	int u = p->Count();
	for (int i = 0; i < u; i++) {
		RESULT += p->key.GetFactor() * (pow(X, p->key.GetPowerX())) * (pow(Y, p->key.GetPowerY())) * (pow(Z, p->key.GetPowerZ()));
		p = p->next;
	}
	cout << "Value at point x = " << X << ", y = " << Y << ", z = " << Z << " equal: " << RESULT << endl;
}
Polynom* Polynom::MultByNum(double num)
{
	Polynom* p = this;
	while (p != NULL)
	{
		p->key.RetFactor(p->key.GetFactor() * num);
		p = p->next;
	}
	return p;
}

Polynom* Polynom::Proizvod() {
	int numb = 0;
	char lil;
	cout << "Enter which variable to take the derivative x, y or z : " << endl;
	cin >> lil;
	if (lil == 'x' || lil == 'X')
		numb = 1;
	if (lil == 'y' || lil == 'Y')
		numb = 2;
	if (lil == 'z' || lil == 'Z')
		numb = 3;
	Monom lo;
	Polynom* p = this;
	Polynom* q = this;
	switch (numb) {
	case 1:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() * p->key.GetPowerX(), p->key.GetPowerX() - 1, p->key.GetPowerY(), p->key.GetPowerZ());
			p->key = lo;
			p = p->next;
		}
		break;
	case 2:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() * p->key.GetPowerY(), p->key.GetPowerX(), p->key.GetPowerY() - 1, p->key.GetPowerZ());
			p->key = lo;
			p = p->next;
		}
		break;
	case 3:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() * p->key.GetPowerZ(), p->key.GetPowerX(), p->key.GetPowerY(), p->key.GetPowerZ() - 1);
			p->key = lo;
			p = p->next;
		}
		break;
	default:
		break;
	}
	return p;
}

Polynom* Polynom::Integral() {
	int numb = 0;
	char lil;
	cout << "Enter which variable to take the integral x, y or z : " << endl;
	cin >> lil;
	if (lil == 'x' || lil == 'X')
		numb = 1;
	if (lil == 'y' || lil == 'Y')
		numb = 2;
	if (lil == 'z' || lil == 'Z')
		numb = 3;
	Monom lo;
	Polynom* p = this;
	Polynom* q = this;
	switch (numb) {
	case 1:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() / p->key.GetPowerX(), p->key.GetPowerX() + 1, p->key.GetPowerY(), p->key.GetPowerZ());
			p->key = lo;
			p = p->next;
		}
		break;
	case 2:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() / p->key.GetPowerY(), p->key.GetPowerX(), p->key.GetPowerY() + 1, p->key.GetPowerZ());
			p->key = lo;
			p = p->next;
		}
		break;
	case 3:
		for (int i = 0; i < q->Count(); i++) {
			lo.GetMonom(p->key.GetFactor() / p->key.GetPowerZ(), p->key.GetPowerX(), p->key.GetPowerY(), p->key.GetPowerZ() + 1);
			p->key = lo;
			p = p->next;
		}
		break;
	default:
		break;
	}
	return p;
}

void Polynom::WritePolynom() {
	Monom po;
	Polynom* ret = this;
	Polynom* ret1 = this;
	for (int i = 0; i < ret1->Count(); i++) {
		if (ret->key == po) { ret->next; }
		else {
			if (i == 0) {
				if (ret->key.GetFactor() == 1) {
					cout << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
				}
				else {
					cout << ret->key.GetFactor() << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
				}
			}
			else if (ret->key.GetFactor() > 0) {
				if (ret->key.GetFactor() == 1) {
					cout << "+" << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
				}
				else {
					cout << "+" << ret->key.GetFactor() << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
				}
			}
			else {
				if (ret->key.GetFactor() == 0) {
					cout << "+(" << ret->key.GetFactor() << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ() << ")";
				}
				else {
					if (ret->key.GetFactor() == -1) {
						cout << "-" << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
					}
					else {
						cout << ret->key.GetFactor() << "x^" << ret->key.GetPowerX() << "y^" << ret->key.GetPowerY() << "z^" << ret->key.GetPowerZ();
					}
				}
			}
		}
		ret = ret->next;
	}
	cout << endl;
}
bool Polynom::operator ==(Polynom* h) {
	Polynom* p1 = this;
	Polynom* p2 = h;
	if (p1->Count() != p2->Count()) {
		return false;
	}
	else {
		while (p1 != NULL) {
			if (p1->key != p2->key) {
				return false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return true;
}


string Polynom::FirndResultToString(double _x, double _y, double _z) {
	double X = _x, Y = _y, Z = _z;
	int RESULT = 0;
	Polynom* p = this;
	int u = p->Count();
	for (int i = 0; i < u; i++) {
		RESULT += p->key.GetFactor() * (pow(X, p->key.GetPowerX())) * (pow(Y, p->key.GetPowerY())) * (pow(Z, p->key.GetPowerZ()));
		p = p->next;
	}
	string polo = "";
	polo = polo + to_string(RESULT);
	return polo;
}