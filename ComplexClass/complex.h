#include <iostream>
#include <Windows.h>
using namespace std;
class Complex
{
public:
	Complex(double real,double imag)
		:_real(real)
		,_imag(imag)
	{}
	Complex(const Complex& t)
	{
		_real = t._real;
		_imag = t._imag;
	}
	~Complex()
	{}
	//ÔËËã·ûµÄÖØÔØ
	Complex& operator=(const Complex& t);
	bool operator==(const Complex& t);
	bool operator>(const Complex& t);
	bool operator<(const Complex& t);
	bool operator!=(const Complex& t);
	bool operator>=(const Complex& t);
	bool operator<=(const Complex& t);
	Complex operator++();
	Complex operator++(int);
	Complex& operator+=(const Complex& t);
	Complex& operator-=(const Complex& t);
	Complex operator+(const Complex& t);
	Complex operator-(const Complex& t);
	Complex operator*(const Complex& t);
	Complex operator/(const Complex& t);
	friend ostream& operator<<(ostream& _cout,const Complex& c);
private:
	double _real;
	double _imag;
};