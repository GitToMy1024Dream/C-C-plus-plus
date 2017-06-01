#include <iostream>
#include <Windows.h>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;
class String
{
public:
	String(const char *pStr = "")
	{
		if(pStr == NULL)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr) + 1];
			strcpy(_pStr,pStr);
		}
	}
	String(const String& s)
	{
		_pStr = new char[strlen(s._pStr) + 1];
		strcpy(_pStr,s._pStr);
	}
	~String()
	{
		if(_pStr)
		{
			delete[] _pStr;
			_pStr = NULL;
		}
	}
	size_t Size()const;//�ַ����Ĵ�С
	size_t Lengh()const;//�ַ����ĳ���
	char& operator[](const size_t index);//�±�綨��
	const char& operator[](size_t index)const;
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	void Copy(const String& s);
	String operator+(const String& s);
	bool strstr(const String& s);
	String& operator=(const String& s);
	String& operator+=(const String& s);
	friend ostream& operator<<(ostream& _cout,const String& s);
private:
	char *_pStr;
};