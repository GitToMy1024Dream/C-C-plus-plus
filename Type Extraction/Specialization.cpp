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
//特化标志
//template<>
//class Specialization<int, float>  //全特化
//{
//public:
//	void FuncTest(int _x, float _y)
//	{
//		cout << "_x:" << _x << endl;
//		cout << "_y:" << _y << endl;
//	}
//};

//偏特化
template<typename T>
class Specialization<int, T> //类型部分未明确，偏特化
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