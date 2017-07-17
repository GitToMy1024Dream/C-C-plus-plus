#include <iostream>
using namespace std;
//栈上的对象
//class Base
//{
//public:
//	Base()
//	{}
//	~Base()
//	{}
//private:
//	void* operator new(size_t);
//	void operator delete(void*);
//};
//堆上的对象
class _Base
{
public:
	static _Base* Create()
	{
		return new _Base();
	}
	void Delete()
	{
		delete this;
	}
private:
	_Base()
	{}
	~_Base()
	{}
};

int main()
{
	//Base* ptr = new Base();
	_Base* ptr = _Base::Create();
	ptr->Delete();
	system("pause");
	return 0;
}