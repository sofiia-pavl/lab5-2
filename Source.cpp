#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

class Empty { };

class Error
{
	string message;
public:
	Error(string m) : message(m) {}
	string What() { return message; }
};

class MyException : public exception
{
	string message;
public:
	MyException(string m) : message(m) {}
	string What() { return message; }
};

double D1(double x1, double y1, double a, double b, double c)
{
	if (a == 0 && b == 0)
		throw 1;
	return (a*x1 + b*y1 + c)/(sqrt(pow(a, 2) + pow(b, 2)));
}

double D2(double x1, double y1, double a, double b, double c) throw()
{
	if (a == 0 && b == 0)
		throw 2.1;
	return (a * x1 + b * y1 + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D3(double x1, double y1, double a, double b, double c) throw(char)
{
	if (a == 0 && b == 0)
		throw '3';
	return (a * x1 + b * y1 + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D4(double x1, double y1, double a, double b, double c) throw(Empty)
{
	if (a == 0 && b == 0)
		throw Empty();
	return (a * x1 + b * y1 + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D5(double x1, double y1, double a, double b, double c) throw(Error)
{
	if (a == 0 && b==0)
		throw Error(" a = b = 0");
	return (a * x1 + b * y1 + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

double D6(double x1, double y1, double a, double b, double c) throw(int)
{
	if (a == 0 && b == 0)
		throw MyException(" a = b = 0");
	return (a * x1 + b * y1 + c) / (sqrt(pow(a, 2) + pow(b, 2)));
}

void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main()
{
	set_unexpected(FU);
	//set_terminate(FT);

	double x1, y1, a, b, c;
	cout << " x1 = "; cin >> x1;
	cout << " y1 = "; cin >> y1;
	cout << " a = "; cin >> a;
	cout << " b = "; cin >> b;
	cout << " c = "; cin >> c;
	cout << " P1(" << x1 << "," << y1 << ") , " << endl << a << "x + " << b << "y + " << c << " = 0 " << endl;

	try
	{
		cout << " D = " << D1(x1, y1, a,b,c) << endl;
		//cout << " D = " << D2(x1, y1, a,b,c) << endl;
		//cout << " D = " << D3(x1, y1, a,b,c) << endl;
		//cout << " D = " << D4(x1, y1, a,b,c) << endl;
		//cout << " D = " << D5(x1, y1, a,b,c) << endl;
		//cout << " D = " << D6(x1, y1, a,b,c) << endl;
	}
	catch (int i)
	{
		cout << " catch (int) <= D1() : " << i << endl;
	}
	catch (double d)
	{
		cout << " catch (double) <= D2() : " << d << endl;
	}
	catch (char c)
	{
		cout << " catch (char) <= D3() : " << c << endl;
	}
	catch (Empty)
	{
		cout << " catch (Empty) <= D4()" << endl;
	}
	catch (Error e)
	{
		cout << " catch (Error) <= D5() : " << e.What() << endl;
	}
	catch (MyException q)
	{
		cout << " catch (MyException) <= D6() : " << q.What() << endl;
	}
	catch (bad_exception)
	{
		cout << " catch (bad_exception) " << endl;
	}

	return 0;
}