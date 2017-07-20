#include <iostream>
using namespace std;

//POD:基本类型，指C++中与C兼容的类型

struct _TrueType
{
	bool Get()
	{
		return true;
	}
};

struct _FalseType
{
	bool Get()
	{
		return false;
	}
};

template<class _Tp>
struct TypeTraits
{
	typedef _FalseType _IsPODType;//如果不是内置类型，则IsPODType是FalseType 
};

//1.0
template<>
struct TypeTraits<bool>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//2.0
template<>
struct TypeTraits<char>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//3.0
template<>
struct TypeTraits<unsigned char>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//4.0
template<>
struct TypeTraits<short>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//5.0
template<>
struct TypeTraits<unsigned short>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//6.0
template<>
struct TypeTraits<int>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//7.0
template<>
struct TypeTraits<unsigned int>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//8.0
template<>
struct TypeTraits<long>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//9.0
template<>
struct TypeTraits<unsigned long>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//10.0
template<>
struct TypeTraits<long long>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//11.0
template<>
struct TypeTraits<unsigned long long>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//12.0
template<>
struct TypeTraits<float>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//13.0
template<>
struct TypeTraits<double>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};
//14.0
template<>
struct TypeTraits<long double>
{
	typedef _TrueType _IsPODType; //如果是内置类型则IsPODType是TrueType  
};

//使用参数推导的萃取处理
template<class T>
void Copy(const T* src, T* dst, size_t size, _FalseType)
{
	cout << "_FalseType:" << typeid(T).name() << endl;
	for(size_t i = 0;i < size;++i)
	{
		dst[i] = src[i];
	}
}

template<class T>
void Copy(const T* src, T* dst, size_t size, _TrueType)
{
	cout << "_TrueType:" << typeid(T).name() << endl;
	memcpy(dst, src, sizeof(T)*size);
}
//使用萃取判断类型的Get函数判断是否是POD类型来处理

template<class T>
void Copy(const T* src, T* dst, size_t size)
{
	cout << "_TrueType:" << typeid(T).name() << endl;
	//内置类型，使用memcpy或for都可以拷贝
	if (TypeTraits<T>::_IsPODType().Get())
	{
		memcpy(dst, src, size * sizeof(T));
	}
	else
	{
		//用户自定义类型，采用for循环拷贝
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
//测试
void Test()
{
	string s1[10] = { "1","2","3","4444444444444" };
	string s2[10] = { "11","22","33" };
	Copy(s1, s2, 10, TypeTraits<string>::_IsPODType());
	Copy(s1, s2, 10);
	int a1[10] = { 1,2,3 };
	int a2[10] = { 0 };
	Copy(a1, a2, 10, TypeTraits<int>::_IsPODType());
	Copy(a1, a2, 10);
}

int main()
{
	Test();
	system("pause");
	return 0;
}