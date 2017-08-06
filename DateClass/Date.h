#include <Windows.h>
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900,int month = 1,int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if((year >= 1900) && (month >= 1 && month <= 12) && (day >= 1 && day <= GetMonthDay(year,month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else 
		{
			cout<<"非法日期"<<endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	Date(const Date& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
	}
	~Date()
	{
		;
	}
	//运算符重载
	Date& operator=(const Date& d);  //=
	Date operator+(int days); //加天数
	Date operator-(int days);  //减天数
	int operator-(const Date& d); //两个日期相隔的天数
	Date& operator++();  //前置++
	Date operator++(int);  //后置++
	Date& operator--();   //前置--
	Date operator--(int);  //后置--
	bool operator>(const Date& d);//>
	bool operator<(const Date& d);// <
	bool operator<=(const Date& d);//<=
	bool operator!=(const Date& d); // !=
	bool operator==(const Date& d); //==
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
	int IsLeap();  //判断闰年
	int GetMonthDay(int year,int month);//判断一个月有多少天
private:
	int _year;
	int _month;
	int _day;
};



