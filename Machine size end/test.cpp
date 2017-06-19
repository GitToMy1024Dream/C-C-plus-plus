//#include <iostream>
//using namespace std;
//int main()
//{
//	int x = 1;
//	if (*(char*)&x == 1)
//	{
//		cout << "小端模式"<<endl;
//	}
//	else
//	{
//		cout << "大端模式" << endl;
//	}
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;
typedef union
{
	char a;
	int b;
}Test;
int main() 
{
	Test u;
	u.b = 1;
	if (u.a == 1)
		cout << "小端模式"<<endl;
	else
		cout << "大端模式" << endl;
	system("pause");
	return 0;
}