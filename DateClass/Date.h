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
			cout<<"�Ƿ�����"<<endl;
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
	//���������
	Date& operator=(const Date& d);  //=
	Date operator+(int days); //������
	Date operator-(int days);  //������
	int operator-(const Date& d); //�����������������
	Date& operator++();  //ǰ��++
	Date operator++(int);  //����++
	Date& operator--();   //ǰ��--
	Date operator--(int);  //����--
	bool operator>(const Date& d);//>
	bool operator<(const Date& d);// <
	bool operator<=(const Date& d);//<=
	bool operator!=(const Date& d); // !=
	bool operator==(const Date& d); //==
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
	int IsLeap();  //�ж�����
	int GetMonthDay(int year,int month);//�ж�һ�����ж�����
private:
	int _year;
	int _month;
	int _day;
};



