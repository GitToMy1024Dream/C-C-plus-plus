#include "complex.h"
void FunTest()
{
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3 = c1*c2;
	Complex c4 = ++c1;
	Complex c5 = c2++;
	Complex c6 = c2/c1;
	cout<<c3<<endl;
	cout<<c4<<endl;
	cout<<c5<<endl;
	cout<<c6<<endl;
}
int main()
{
	FunTest();
	system("pause");
	return 0;
}