#include <iostream>
#include <Windows.h>
using namespace std;


template<class T>
class Greate
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<class T>
class Less
{
	bool operator()(const T&left, const T& right)
	{
		return left < right;
	}
};

template<class T,class Compare>
void BubbleSort(T* _array, int size)
{	
	int flag = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (Compare(_array[j], _array[j + 1]))
			{
				flag = 1;
				std::swap(_array[j], _array[j + 1]);
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

int main()
{
	int _array[10] = { 2,1,7,6,4,10,3,9,8,0 };
	BubbleSort<int,Greate<int>>(_array, sizeof(_array) / sizeof(_array[0]));
	system("pause");
	return 0;
}