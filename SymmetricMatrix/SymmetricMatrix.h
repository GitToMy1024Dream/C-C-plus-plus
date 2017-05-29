#pragma once
#include <iostream>  
using namespace std;
template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(int *a, size_t N) //���캯��
		:_pData(new T[N*(N + 1) / 2])
		,_N(N)
	{
		size_t idx = 0;
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				//��������������  
				if (i >= j)
				{
					_pData[idx] = a[i*N + j];
					++idx;
				}
				else
					break;
			}
		}
	}
	~SymmetricMatrix()//��������  
	{
		delete[] _pData;
		_pData = NULL;
		_N = 0;
	}
	//������������
	template<class T>
	friend ostream& operator<<(ostream& _cout, SymmetricMatrix<T>& s)
	{
		for (size_t i = 0; i < _N; ++i)
		{
			for (size_t j = 0; j < _N; ++j)
			{
				_cout << s.Access(i, j) << " ";
			}
			_cout << endl;
		}
		return _cout;
	}
	void Display()//��ӡ����  
	{
		for (size_t i = 0; i < _N; ++i)
		{
			for (size_t j = 0; j < _N; ++j)
			{
				cout << Access(i, j) << " ";
			}
			cout << endl;
		}
	}
	T& Access(size_t i, size_t j)
	{
		//������תΪת������ 
		if (i < j)
			swap(i, j);
		return _pData[i*(i + 1) / 2 + j];
	}
	const T& Access(size_t i, size_t j) const 
	{
		//������Ԫ��ת������ 
		if (i < j)
			swap(i, j);
		return _pData[i*(i + 1) / 2 + j];
	}
protected:
	T* _pData;//ѹ���洢��һά����  
	size_t _N;//N*N�ľ���  
};