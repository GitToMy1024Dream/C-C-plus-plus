#include <iostream>
#include <Windows.h>
#pragma warning (disable:4996)
class String
{
public:
	String(const char* pStr = "") //构造函数
		:_pStr(new char[strlen(pStr) + 4 + 1])//+4多创建的四个字节用来保存当前地址有几个对象
	{
		if(NULL == pStr)
		{
			*((int*)_pStr) = 1;//前4个字节用来计数
			_pStr += 4;//向后偏移4个字节
			*_pStr = '\0';
		}
		else
		{
			*((int *)_pStr) = 1;//前4个字节用来计数
			_pStr += 4;//向后偏移4个字节
			strcpy(_pStr,pStr);//拷贝字符串
		}
	}
	String(const String& s)//拷贝构造函数
		:_pStr(s._pStr)
	{
		++(*(int*)(_pStr - 4));//向前偏移4个字节将计数+1
	}
	~String()//析构函数
	{
		if(NULL == _pStr)
		{
			return;
		}
		else
		{
			if(--(*(int*)(_pStr - 4)) == 0)
			{
				delete[] (_pStr - 4);
				_pStr = NULL;
			}
		}
	}
	//重载赋值运算符=
	String& operator=(const String& s)
	{
		if(_pStr != s._pStr)
		{
			if(--(*(int*)(_pStr - 4)) == 0)//释放旧空间
			{
				delete[] (_pStr - 4);
				_pStr = NULL;
			}
			_pStr = s._pStr;//指向新空间
			++(*(int*)(_pStr - 4));//计数+1
		}
		return *this;
	}
	//重载下标访问操作符
	char& operator[](size_t t)
	{
		if(t >= 0 && t < strlen(_pStr))//下标非法判断
		{
			if((*(int*)(_pStr - 4)) > 1)//多个对象指向同一块空间
			{
				char *pTemp = new char[strlen(_pStr) + 4 + 1];//开辟临时空间
				pTemp += 4;//向后偏移4个字节
				strcpy(pTemp,_pStr);//拷贝字符串
				--(*(int*)(_pStr - 4));//计数-1
				_pStr = pTemp;//将当前的对象指向临时空间
				*((int*)(_pStr - 4)) = 1;//将新空间的计数置为1
			}
			return _pStr[t];
		}							   
	}
private:
	char *_pStr;
};
void FunTest()
{
	String s1("Hello world");
	String s2(s1);
	String s3 = s2;
	s3[3] = 'm';
}
int main()
{
	FunTest();
	system("pause");
	return 0;
}