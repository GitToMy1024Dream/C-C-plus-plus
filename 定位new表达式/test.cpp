#include <iostream>
using namespace std;


class A
{
public:
	A(int a = 2)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	void show()
	{
		cout << _a << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	/*A *pa = (A*)malloc(sizeof(A));
	new(pa) A(1); //���ù��캯��
	pa->~A(); // ������������
	free(pa);*/

	//����10��A���͵Ŀռ�
	A* pa = (A*)malloc(sizeof(A) * 10);
	for (int i = 0; i < 10; ++i)
	{
		new(pa + i) A(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		(pa + i)->~A();
	}
	free(pa);
	system("pause");
	return 0;
}