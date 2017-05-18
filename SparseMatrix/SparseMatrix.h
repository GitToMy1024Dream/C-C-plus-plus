#pragma once
#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
template<class T>
//稀疏矩阵压缩存储
class SparseMatrix
{
	template<class T>
	struct Trituple
	{
		//三元组顺序表
		Trituple(size_t row, size_t col, const T& data)
			: _row(row)
			, _col(col)
			, _data(data)
		{}
		Trituple()
		{}
		size_t _row;
		size_t _col;
		T _data;
	};

public:

	// 稀疏矩阵的压缩存储
	SparseMatrix(int* array, size_t row, size_t col, const T& invalid)
		: _row(row)
		, _col(col)
		, _invalid(invalid)
	{
		for (size_t i = 0; i < row; ++i)
		{
			for (size_t j = 0; j < col; ++j)
			{
				if (array[i*col + j] != invalid)
				{
					_sm.push_back(Trituple<T>(i, j, array[i*col + j]));
				}
			}
		}
	}
	SparseMatrix()//不带参数的构造函数
	{}

	// 访问稀疏矩阵中row行col中的元素
	T& Access(int row, int col)
	{
		vector<Trituple<T>>::iterator it = _sm.begin();
		while (it != _sm.end())
		{
			if (it->_row == row && it->_col == col)
			{
				return it->_data;
			}
			it++;
		}
		return _invalid;
	}
	// 还原稀疏矩阵
	template<class T>
	friend ostream& operator<<(ostream& _cout, SparseMatrix<T>& s)
	{
		size_t index = 0;
		for (size_t i = 0; i < _row; ++i)
		{
			for (size_t j = 0; j < _col; ++j)
			{
				if (index < s._sm.size() && i == s._sm[index]._row
					&& j == s._sm[index]._col)
				{
					_cout << s._sm[index] << " ";
					++index;
				}
				else
					cout << s._invalid << " ";
			}
			_cout << endl;
		}
		return _cout;
	}
	//打印矩阵
	void Display()
	{
		size_t index = 0;
		for (size_t i = 0; i < _row; ++i)
		{
			for (size_t j = 0; j < _col; ++j)
			{
				if (index < _sm.size() && i == _sm[index]._row && j == _sm[index]._col)
				{
					cout << _sm[index]._data << "  ";
					++index;
				}
				else
				{
					cout << _invalid << "  ";
				}
			}
			cout << endl;
		}
	}
	// 实现稀疏矩阵的逆置，并给出时间复杂度,f(n)=O(M*N)
	SparseMatrix<T> Transprot()
	{
		SparseMatrix<T> sm;
		sm._row = _col;
		sm._col = _row;
		sm._invalid = _invalid;
		for (size_t i = 0; i < _col; ++i)
		{
			vector<Trituple<T>>::iterator it = _sm.begin();
			while (it != _sm.end())
			{
				if (i == it->_col)
				{
					sm._sm.push_back(Trituple<T>(it->_col, it->_row, it->_data));
				}
				it++;
			}
		}
		return sm;
	}

	// 实现稀疏矩阵的快速逆置，并给出时间复杂度 f(n) =0(M)+O(N)
	SparseMatrix<T> FastTransprot()
	{
		SparseMatrix<T> sm;
		sm._row = _col;
		sm._col = _row;
		sm._invalid = _invalid;
		sm._sm.resize(_sm.size());
		int *pRowCount = new int[_col];//原矩阵每一列的元素个数
		int *pRowStart = new int[_col];//原矩阵每一列的起始位置,即
		//当前矩阵每一行的起始位置
		memset(pRowCount, 0, sizeof(pRowCount)*_col);
		memset(pRowStart, 0, sizeof(pRowStart)*_col);
		//1.统计原矩阵每一列有效元素的个数(当前行的有效元素个数)
		for (size_t idx = 0; idx < _sm.size(); ++idx)
		{
			pRowCount[_sm[idx]._col]++;
		}
		//2.统计原矩阵每一列的起始位置(当前行的起始位置)
		for (size_t idx = 1; idx < _col; ++idx)
		{
			pRowStart[idx] = pRowStart[idx - 1] + pRowCount[idx - 1];
		}
		//3.存储数据
		for (size_t idx = 0; idx < _sm.size(); ++idx)
		{
			int& addr = pRowStart[_sm[idx]._col];
			sm._sm[addr] = Trituple<T>(_sm[idx]._col, _sm[idx]._row, _sm[idx]._data);
			addr++;
		}
		return sm;
	}

	// 实现稀疏矩阵的加法操作
	SparseMatrix<T> operator+(const SparseMatrix<T>& sp)
	{
		SparseMatrix<T> sm;
		sm._row = _row;
		sm._col = _col;
		if (sp._row != _row || sp._col != _col)
		{
			cout << "两个矩阵行列不一致" << endl;
			return sm;
		}
		int left = 0;
		int right = 0;
		int addr1 = 0;
		int addr2 = 0;
		while (left < _sm.size() && right < sp._sm.size())
		{
			addr1 = _sm[left]._row*_col + _sm[left]._col;
			addr2 = sp._sm[right]._row*sp._col + sp._sm[right]._col;
			if (addr1 == addr2)
			{
				sm._sm.push_back(Trituple<T>(_sm[left]._row, _sm[left]._col, _sm[left]._data + sp._sm[right]._data));
				++left;
				++right;
			}
			else if (addr1 < addr2)
			{
				sm._sm.push_back(Trituple<T>(_sm[left]._row, _sm[left]._col, _sm[left]._data));
				left++;
			}
			else
			{
				sm._sm.push_back(Trituple<T>(_sm[right]._row, _sm[right]._col, _sm[right]._data));
				right++;
			}
		}
		while (left < _sm.size())
		{
			sm._sm.push_back(Trituple<T>(_sm[left]._row, _sm[left]._col, _sm[left]._data));
			left++;
		}
		while (right < sp._sm.size())
		{
			sm._sm.push_back(Trituple<T>(_sm[right]._row, _sm[right]._col, _sm[right]._data));
			right++;
		}
		return sm;
	}

private:
	vector<Trituple<T>> _sm;
	size_t _row;
	size_t _col;
	T _invalid;//无效数据
};
