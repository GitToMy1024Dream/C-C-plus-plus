#include <iostream>
using namespace std;

//POD:�������ͣ�ָC++����C���ݵ�����

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
	typedef _FalseType _IsPODType;//��������������ͣ���IsPODType��FalseType 
};

//1.0
template<>
struct TypeTraits<bool>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//2.0
template<>
struct TypeTraits<char>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//3.0
template<>
struct TypeTraits<unsigned char>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//4.0
template<>
struct TypeTraits<short>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//5.0
template<>
struct TypeTraits<unsigned short>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//6.0
template<>
struct TypeTraits<int>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//7.0
template<>
struct TypeTraits<unsigned int>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//8.0
template<>
struct TypeTraits<long>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//9.0
template<>
struct TypeTraits<unsigned long>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//10.0
template<>
struct TypeTraits<long long>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//11.0
template<>
struct TypeTraits<unsigned long long>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//12.0
template<>
struct TypeTraits<float>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//13.0
template<>
struct TypeTraits<double>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};
//14.0
template<>
struct TypeTraits<long double>
{
	typedef _TrueType _IsPODType; //���������������IsPODType��TrueType  
};

//ʹ�ò����Ƶ�����ȡ����
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
//ʹ����ȡ�ж����͵�Get�����ж��Ƿ���POD����������

template<class T>
void Copy(const T* src, T* dst, size_t size)
{
	cout << "_TrueType:" << typeid(T).name() << endl;
	//�������ͣ�ʹ��memcpy��for�����Կ���
	if (TypeTraits<T>::_IsPODType().Get())
	{
		memcpy(dst, src, size * sizeof(T));
	}
	else
	{
		//�û��Զ������ͣ�����forѭ������
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
//����
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