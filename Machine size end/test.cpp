//#include <iostream>
//using namespace std;
//int main()
//{
//	int x = 1;
//	if (*(char*)&x == 1)
//	{
//		cout << "С��ģʽ"<<endl;
//	}
//	else
//	{
//		cout << "���ģʽ" << endl;
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
		cout << "С��ģʽ"<<endl;
	else
		cout << "���ģʽ" << endl;
	system("pause");
	return 0;
}