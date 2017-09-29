#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	virtual ~Base() = 0 {}
};

class Der :public Base
{
public:
	Der()
	{
		cout << "Der" << endl;
	}
	~Der()
	{
		cout << "~Der::~Base()" << endl;
	}
};

int main()
{
	Base* p = new Der;
	p->~Base();
	cout << sizeof(Base) << endl;
	system("pause");
	return 0;
}