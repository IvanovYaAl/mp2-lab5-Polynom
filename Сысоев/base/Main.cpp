
#include "Polynom.h"

int main() {
	Polynom p1;
	Polynom p2;
	int choice;
	do {
		cout << "1 - Build a polynomial\n";
		cout << "2 - Multiply by number\n";
		cout << "3 - Polynomial derivative\n";
		cout << "4 - Integral from polynomial\n";
		cout << "5 - Add to another polynomial \n";
		cout << "6 - Subtract another polynomial \n";
		cout << "7 - Find out the value at a point \n";
		cout << "8 - Exit\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter the number of monomials: " << endl;
			int k;
			cin >> k;
			while (k != 0) {
				cout << "Enter in monom: " << endl;
				Monom l;
				l.ReadMonom();
				p1.add(l);
				k--;
			}
			p1.WritePolynom();
			cout << endl;
			break;
		};
		case 2:
		{
			double c;
			cout << "Multiply a polynomial by: ";
			cin >> c;
			p1.MultByNum(c);
			p1.WritePolynom();
			break;
		};
		case 3:
		{
			cout << "Derived Polynomial: " << endl;
			p1.Proizvod();
			p1.WritePolynom();
			break;
		};
		case 4:
		{
			cout << " Undefined polynomial integral" << endl;
			p1.Integral();
			p1.WritePolynom();
			break;
		}

		case 5:
		{
			Polynom* p3 = new Polynom();
			cout << "Enter the polynomial with which we will add" << endl;
			cout << "Enter the number of monomials:" << endl;
			int k;
			cin >> k;
			while (k != 0) {
				cout << "Enter in monom:" << endl;
				Monom u;
				u.ReadMonom();
				p3->add(u);
				k--;
			}
			p2.WritePolynom();
			cout << "Amount: " << endl;
			(p1.Sum(p3))->WritePolynom();
			break;
		}

		case 6:
		{
			Polynom* p4 = new Polynom();
			cout << "Enter the polynomial to be subtracted" << endl;
			cout << "Enter the number of monomials: " << endl;
			int k;
			cin >> k;
			while (k != 0) {
				cout << "Enter in monom: " << endl;
				Monom q;
				q.ReadMonom();
				p4->add(q);
				k--;
			}
			cout << "Difference" << endl;
			(p1.Sub(p4))->WritePolynom();
			break;
		}
		case 7:
		{
			p1.FindResult();
			break;
		};

		default:
			cout << "Wrong input\n";
		}
	} while (choice != 8);
	return 0;
}