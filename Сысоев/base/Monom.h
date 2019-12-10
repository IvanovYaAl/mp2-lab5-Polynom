
#pragma once
#include <iostream>

using namespace std;

class Monom {
	double c;
	int q, w, e;	//powers of x, y, z
public:
	Monom() {
		c = 0.0;
		q = w = e = 0;
	}
	Monom(double _c, int _q, int _w, int _e) {
		c = _c;
		q = _q;
		w = _w;
		e = _e;
	}
	~Monom() {
		c = 0.0;
		q = w = e = 0;
	}
	double GetFactor() { return c; }
	int GetPowerX() { return q; }
	int GetPowerY() { return w; }
	int GetPowerZ() { return e; }

	void RetFactor(double a) { c = a; }

	void GetMonom(double _c, int _q, int _w, int _e) {
		c = _c;
		q = _q;
		w = _w;
		e = _e;
	}
	bool operator==(const Monom& h) {
		if (q == h.q && w == h.w && e == h.e)
			return true;
		else return false;
	}
	bool operator!=(const Monom& h) {
		if (q == h.q && w == h.w && e == h.e)
			return false;
		else return true;
	}
	Monom& operator = (const Monom& l) {
		c = l.c;
		q = l.q;
		w = l.w;
		e = l.e;
		return *this;
	}
	Monom* operator = (Monom* l) {
		c = l->c;
		q = l->q;
		w = l->w;
		e = l->e;
		return this;
	}

	Monom& operator +(const Monom& l) {
		c += l.c;
		return *this;
	}

	Monom& operator -(const Monom& l) {
		c = c - l.c;
		return *this;
	}

	void ReadMonom() {
		double c1;
		int q1, w1, e1;
		cout << "Coefficient: ";
		cin >> c1;
		cout << "Powers: ";
		cin >> q1 >> w1 >> e1;
		c = c1;
		q = q1;
		w = w1;
		e = e1;
	}
};