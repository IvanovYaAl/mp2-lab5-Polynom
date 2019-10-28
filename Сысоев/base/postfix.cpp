#include "postfix.h"
#include "stack.h"

TPostfix::TPostfix() {
	infix = "a+b";
}

TPostfix::TPostfix(string str) {
	infix = str;
}

bool TPostfix::Operation(char op) {
	if ((op == '+') || (op == '-') || (op == '*') || (op == '/'))
		return true;
	return false;
}

bool TPostfix::Check() {
	int num = 0, operat = 0;
	for (size_t i = 0; i < infix.size(); i++) {
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*')
			operat++;
		else if (!Operation(infix[i]) && infix[i] != ')' && infix[i] != '(')
		{
			while (infix[i]!='+'&& infix[i] != '-'&& infix[i] != '/'&& infix[i] != '*'){
				i++;
				if (i == infix.size())
					break;
			}
			i--;
			num++;
		}
	}
	CountNumber = num;
	if (num != operat + 1)
		return false;
	int LBracket = 0, RBracket = 0;
	for (size_t i = 0; i < infix.size(); i++) {
		if (infix[i] == '(')
			LBracket++;
		else if (infix[i] == ')')
			RBracket++;
	}
	if (LBracket != RBracket)
		return false;
	if (infix[0] == ')' || infix[0] == '/' || infix[0] == '*' || infix[0] == '-' || infix[0] == '+')
		return false;
	if (infix[infix.size()-1] == '(' || infix[infix.size() - 1] == '/' || infix[infix.size() - 1] == '*' || infix[infix.size() - 1] == '-' || infix[infix.size() - 1] == '+')
		return false;
	return true;
}

int TPostfix::CountNum() {
	return CountNumber;
}

int TPostfix::Priority(char a, char b) {
	if ((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 0;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if ((a == '+' || a == '-') && (b == '+' || b == '-'))
		return 0;
	throw "Error";
}

string TPostfix::ToPostfix()
{
	if (Check() == false) {
		throw "Error";	
	}
	TStack<char> ops(infix.size());
	postfix = "";
	for (size_t i = 0; i < infix.size(); i++)
	{
		if (isalpha(infix[i])) postfix += infix[i];
		else if (Operation(infix[i]) || (infix[i] == '(') || (infix[i] == ')')) {
		if (ops.IsEmpty())
			ops.Push(infix[i]);
		else if (ops.GetTop() == '(')
			ops.Push(infix[i]);
		else if (infix[i] == '(')
			ops.Push(infix[i]);
		else if (infix[i] == ')')
		{
			while (ops.GetTop() != '(')
			{
				postfix += ops.pop();
			}
			ops.pop();
		}
		else if (Priority(infix[i], ops.GetTop()) == 1)
			ops.Push(infix[i]);
		else
		{
			while ((ops.GetTop() != '('))
			{
				if (Priority(infix[i], ops.GetTop()) == 1)
					break;

				postfix += ops.pop();

				if (ops.IsEmpty())
					break;
			}
			ops.Push(infix[i]);
		}
		}
	}
	while (!ops.IsEmpty())
	{
		postfix += ops.pop();
		
	}
	return postfix;
}

string TPostfix::DelPostfix() {

	string newpost = infix;
	int newsize = newpost.size();
	for (int i = 0; i < newsize; i++) {
		if (newpost[i] == '+' || newpost[i] == '-' || newpost[i] == '*' || newpost[i] == '/' || newpost[i] == '(' || newpost[i] == ')') {
			for (int j = i; j < newsize-1; j++) {
				newpost[j] = newpost[j + 1];	
			}
			newsize--;
			i--;
		}
		
	}
	string op="";
	for (int i = 0; i < newsize; i++) {
		op += newpost[i];
	}
	return op;
}

bool TPostfix::Eqution() {
	string let = DelPostfix();
	for (int i = 0; i < DelPostfix().size(); i++) {
		for (int j = i + 1; j < let.size(); j++) {
			if (let[i] == let[j])
				return false;
		}
	}
	return true;
}

double TPostfix::Calculate(double* _val )
{
	TStack<double>stack(postfix.size());
	double num1, num2;
	
	cout << DelPostfix() << endl;
	string letter = DelPostfix();
	int hp = DelPostfix().size();
	double* newval;
	newval = new double[hp]();

	if (Eqution()) {
		for (int i = 0; i < hp; i++) {
			newval[i] = _val[i];
		}
	}
	else {
		int u = 0;
		for (int i = 0; i < hp-1; i++) {
			for (int j = i + 1; j < hp; j++) {
				if ((letter[i] == letter[j]) && letter[i] != ' ') {
					if (u == 0)
						newval[i] = _val[i];
					newval[j] = newval[i];
					letter[j] = ' ';
					u = 1;
				}
				u = 0;
			}
		}
	}
	int j = 0;
	for (size_t i = 0; i < postfix.size(); i++) {
		
		if (isalpha(postfix[i]))
		{
			stack.Push(newval[j]);
			j++;
		}
		else {
			num2 = stack.pop();
			num1 = stack.pop();		
			switch (postfix[i]) {
			case'+':
				stack.Push(num1 + num2);
				break;
			case'-':
				stack.Push(num1 - num2);
				break;
			case'*':
				stack.Push(num1 * num2);
				break;
			case'/':
				stack.Push(num1 / num2);
				break;
			default:
				break;
			}
		}
	}
	return stack.pop();
}
