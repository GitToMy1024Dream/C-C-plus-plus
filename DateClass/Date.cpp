#include "Date.h"
//判断闰年
int Date::IsLeap()
{
	if((_year % 4 == 0 && _year % 100 != 0)||(_year % 400 == 0))
		return 1;
	return 0;
}
//获取某年某月的天数
int Date::GetMonthDay(int year,int month)
{
	int arr[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	int day;
	if((!IsLeap())&& (month == 2))//非闰年
		_day = arr[month] - 1;
	day = arr[month];//闰年
	return day;
}
//赋值=重载
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
//重载+ 加上指定天数
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
//重载- 减天数
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
		//获取上一月的天数
		tmp._day += GetMonthDay(tmp._year,tmp._month);
	}
	return tmp;
}
//重载- 两个日期相隔的天数

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
//重载前置++
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
//后置++
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

//重载前置--
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
//重载后置--
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
//重载！=
bool Date::operator!=(const Date& d)
{
	return (!(*this==d));
}
//重载>
bool Date::operator>(const Date& d)
{
	return (_year>d._year)||(_year==d._year)&&(_month>d._month)||(_month==d._month)&&(_day>d._day)||(_day==d._day);
}
//重载<
bool Date::operator<(const Date& d)
{
	return (_year<d._year) || (_year == d._year)&&(_month < d._month) || (_month == d._month)&&(_day < d._day) || (_day == d._day);
}
//重载==
bool Date::operator==(const Date& d)
{
	return (_year == d._year)&&(_month == d._month)&&(_day == d._day);
}
//重载<=
bool Date::operator<=(const Date& d)
{
	return (*this == d)||(*this < d);
}
//重载输出<<
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
	return _cout;
}
//重载输入>>
istream& operator>>(istream& _cin, Date& d)
{
	_cin>>d._year;
	_cin>>d._month;
	_cin>>d._day;
	return _cin;
}