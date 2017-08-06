#include "Date.h"
//�ж�����
int Date::IsLeap()
{
	if((_year % 4 == 0 && _year % 100 != 0)||(_year % 400 == 0))
		return 1;
	return 0;
}
//��ȡĳ��ĳ�µ�����
int Date::GetMonthDay(int year,int month)
{
	int arr[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	int day;
	if((!IsLeap())&& (month == 2))//������
		_day = arr[month] - 1;
	day = arr[month];//����
	return day;
}
//��ֵ=����
Date& Date::operator=(const Date& d)
{
	if(this == &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//����+ ����ָ������
Date Date::operator+(int days)
{
	Date tmp(*this);
	if(days < 0)
		return tmp + days;
	tmp._day += days;
	while (tmp._day > GetMonthDay(tmp._year,tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year,tmp._month);
		if(_month == 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
		else
			tmp._month++;
	}
	return tmp;
}
//����- ������
Date Date::operator-(int days)
{
	Date tmp(*this);
	if(days < 0)
		return tmp - days;
	tmp._day -= days;
	while(tmp._day <= 0)
	{
		if(tmp._month == 1)
		{
			tmp._year--;
			tmp._month = 12;
		}
		else
		{
			--tmp._month;
		}
		//��ȡ��һ�µ�����
		tmp._day += GetMonthDay(tmp._year,tmp._month);
	}
	return tmp;
}
//����- �����������������

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date Max(*this);
	Date Min(d);
	if((*this) < d)
	{
		std::swap(Max,Min);
		flag = -1;
	}
	int days = 0;
	while(Max != Min)
	{
		--Max;
		++days;
	}
	return days*flag;
}
//����ǰ��++
Date& Date::operator++()     //2015/3/5
{
	_day++;
	if(_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year,_month);
		_month++;
		if(_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
//����++
Date Date::operator++(int)
{
	Date tmp(*this);
	_day++;
	if(_day > GetMonthDay(_year,_month))
	{
		_day = GetMonthDay(_year,_month) - _day;
		_month++;
		if(_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return tmp;
}

//����ǰ��--
Date& Date::operator--()
{
	_day--;
	if(_day < 1)
	{
		_month--;
		if(_month < 1)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year,_month);
	}
	return *this;
}
//���غ���--
Date Date::operator--(int)
{
	Date tmp(*this);
	_day--;
	if(_day < 1)
	{
		_month--;
		if(_month < 1)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year,_month);
	}
	return tmp;
}
//���أ�=
bool Date::operator!=(const Date& d)
{
	return (!(*this==d));
}
//����>
bool Date::operator>(const Date& d)
{
	return (_year>d._year)||(_year==d._year)&&(_month>d._month)||(_month==d._month)&&(_day>d._day)||(_day==d._day);
}
//����<
bool Date::operator<(const Date& d)
{
	return (_year<d._year) || (_year == d._year)&&(_month < d._month) || (_month == d._month)&&(_day < d._day) || (_day == d._day);
}
//����==
bool Date::operator==(const Date& d)
{
	return (_year == d._year)&&(_month == d._month)&&(_day == d._day);
}
//����<=
bool Date::operator<=(const Date& d)
{
	return (*this == d)||(*this < d);
}
//�������<<
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
	return _cout;
}
//��������>>
istream& operator>>(istream& _cin, Date& d)
{
	_cin>>d._year;
	_cin>>d._month;
	_cin>>d._day;
	return _cin;
}