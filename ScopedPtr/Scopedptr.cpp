#include <iostream>
using namespace std;

template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr = NULL);
	~ScopedPtr();
	T& operator*();
	T& operator*()const;
	T* operator->();
	T* operator->()const;
private:
	ScopedPtr(const ScopedPtr<T>& ap);
	ScopedPtr<T>& operator=(const ScopedPtr<T>& ap);
	T* _ptr;
};

template<class T>//构造函数
ScopedPtr<T>::ScopedPtr(T* ptr)
	:_ptr(ptr)
{}

template<class T>//析构函数
ScopedPtr<T>::~ScopedPtr()
{
	if (this->_ptr)
	{
		delete this->_ptr;
		_ptr = NULL;
	}
}

template<class T>//重载*
T& ScopedPtr<T>::operator*()
{
	return *(this->_ptr);
}
template<class T>
T& ScopedPtr<T>::operator*()const
{
	return *(this->_ptr);
}

template<class T>//重载->
T* ScopedPtr<T>::operator->()
{
	return this->_ptr;
}
template<class T>//重载->
T* ScopedPtr<T>::operator->()const
{
	return this->_ptr;
}

int main()
{
	ScopedPtr<int> p(new int(1));
	system("pause");
	return 0;
}
