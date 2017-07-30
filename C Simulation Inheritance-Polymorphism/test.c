#include <stdio.h>
#include <Windows.h>

typedef struct Base
{
	int _a;
	int _b;
}base;

typedef struct Dervice
{
	base c;
	int _d;
}der;

int main()
{
	printf("%d\n", sizeof(der));
	system("pause");
	return 0;
}

typedef void(*FUN)();
struct Base
{
	FUN _f;
};


struct Derived
{
	Base _b;
};


void FunB()
{
	printf("%s\n", "Base::fun()");
}
void FunD()
{
	printf("%s\n", "Derived::fun()");
}

void Test2()
{
	Base b;
	Derived d;

	b._f = FunB;
	d._b._f = FunD;

	Base *pb = &b;
	pb->_f();

	pb = (Base *)&d;
	pb->_f();

}