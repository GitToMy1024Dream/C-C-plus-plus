#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class ScopedArray
{
public:
	ScopedArray(T* ptr = NULL);
	~ScopedArray();
	T& operator[](size_t index);
private:
	ScopedArray(const ScopedArray<T>& ap);
	ScopedArray<T>& operator=(const ScopedArray<T>& ap);
	T* _ptr;
};

template<class T>//构造函数
ScopedArray<T>::ScopedArray(T* ptr)
	:_ptr(ptr)
{}

template<class T>//析构函数
ScopedArray<T>::~ScopedArray()
{
	if (this->_ptr)
	{
		delete[] this->_ptr;
		_ptr = NULL;
	}
}
template<class T>
T& ScopedArray<T>::operator[](size_t index)
{
	assert(index);
	return _ptr[index];
}
int main()
{
	ScopedArray<int> p(new int[10]);
	system("pause");
	return 0;
}
