#include <iostream>
using namespace std;
//1.0
class Base
{
public:
	static Base* GetInstance()
	{
		return new Base();
	}
	static void Delete(Base* pInstance)
	{
		delete pInstance;
	}
private:
	Base()
	{}
	~Base()
	{}
};
class Dervice :public Base
{
public:
	Dervice()
	{}
	~Dervice()
	{}
};

//2.0
template<typename T >
class _Base
{
public:
	friend T;
private:
	_Base()
	{}
	~_Base()
	{}
};
class _Dervice :virtual public _Base<_Dervice>
{
public:
	_Dervice()
	{}
	~_Dervice()
	{}
};
class Try: public _Dervice
{
public:
	Try()
	{}
	~Try()
	{}
};

int main()
{
	system("pause");
	return 0;
}