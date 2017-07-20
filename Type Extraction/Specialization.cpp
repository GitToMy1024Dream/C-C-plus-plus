#include <iostream>
using namespace std;

template<typename T1,typename T2>
class Specialization
{
public:
	void FuncTest(T1 _x, T2 _y)
	{
		cout << "_x:" << _x << endl;
		cout << "_y:" << _y << endl;
	}
};
//�ػ���־
//template<>
//class Specialization<int, float>  //ȫ�ػ�
//{
//public:
//	void FuncTest(int _x, float _y)
//	{
//		cout << "_x:" << _x << endl;
//		cout << "_y:" << _y << endl;
//	}
//};

//ƫ�ػ�
template<typename T>
class Specialization<int, T> //���Ͳ���δ��ȷ��ƫ�ػ�
{
public:
	void FuncTest(int _x, T _y)
	{
		cout << "_x:" << _x << endl;
		cout << "_y:" << _y << endl;
	}
};
int main()
{
	Specialization<int, char> _s;
	_s.FuncTest(3, 'x');
	system("pause");
	return 0;
}