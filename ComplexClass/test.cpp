#include "complex.h"
//=
Complex& Complex::operator=(const Complex& t)
{
	if(this != &t)
	{
		_real = t._real;
		_imag = t._imag;
	}
	return *this;
}
bool Complex::operator==(const Complex& t)
{
	if(_imag != 0 || t._imag != 0)
	{
		cout<<"虚部不为0，无法比较!"<<endl;
		return false;
	}
	return (_real == t._real)&&(_imag == t._imag);
}
bool Complex::operator!=(const Complex& t)
{
	return !(*this == t);
}
bool Complex::operator>(const Complex& t)
{
	if(_imag != 0 || t._imag != 0)
	{
		cout<<"虚部不为0，无法比较大小！"<<endl;
		return false;
	}
	else
	{
		if(_real > t._real)
			return true;
		return false;
	}
}
bool Complex::operator<(const Complex& t)
{
	if(_imag != 0 || t._imag != 0)
	{
		cout<<"虚部不为0，无法比较大小！"<<endl;
		return false;
	}
	return !(*this >= t);
}
bool Complex::operator>=(const Complex& t)
{
	if(_imag != 0 || t._imag != 0)
	{
		cout<<"虚部不为0，无法比较大小！"<<endl;
		return false;
	}
	return (*this == t)||(*this > t);
}
bool Complex::operator<=(const Complex& t)
{
	if(_imag != 0 || t._imag != 0)
	{
		cout<<"虚部不为0，无法比较大小!"<<endl;
		return false;
	}
	return (*this == t)||(*this < t);
}
Complex& Complex::operator+=(const Complex& t)
{
	_real += t._real;
	_imag += t._imag;
	return *this;
}
Complex& Complex::operator-=(const Complex& t)
{
	_real -= t._real;
	_imag -= t._imag;
	return *this;
}
Complex Complex::operator+(const Complex& t)
{
	Complex temp(*this);
	temp._real += t._real;
	temp._imag += t._imag;
	return temp;
}
Complex Complex::operator-(const Complex& t)
{
	Complex temp(*this);
	temp._real -= t._real;
	temp._imag -= t._imag;
	return temp;
}
Complex Complex::operator*(const Complex& t)//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
{
	Complex temp(*this);
	temp._real = this->_real*t._real - this->_imag*t._imag;
	temp._imag = this->_imag*t._real + this->_real*t._imag;
	return temp;
}
Complex Complex::operator/(const Complex& t)//(a+bi)(c-di)/(c+di)(c-di)
{
	Complex temp(*this);
	temp._real = (this->_real*t._real+this->_imag*t._imag)/(t._real*t._real+t._imag*t._imag)\
		+(this->_imag*t._real - this->_real*t._imag)/((t._real*t._real+t._imag*t._imag));
	return temp;
}
Complex Complex::operator++()
{
	++_real;
	++_imag;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex temp(*this);
	_real++;
	_imag++;
	return temp;
}
ostream& operator<<(ostream& _cout,const Complex& t)
{
	_cout<<t._real<<"+"<<t._imag<<"i"<<endl;
	return _cout;
}