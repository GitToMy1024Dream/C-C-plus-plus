#include <iostream>
#include <Windows.h>
#pragma warning (disable:4996)
class String
{
public:
	String(const char* pStr = "") //���캯��
		:_pStr(new char[strlen(pStr) + 4 + 1])//+4�ഴ�����ĸ��ֽ��������浱ǰ��ַ�м�������
	{
		if(NULL == pStr)
		{
			*((int*)_pStr) = 1;//ǰ4���ֽ���������
			_pStr += 4;//���ƫ��4���ֽ�
			*_pStr = '\0';
		}
		else
		{
			*((int *)_pStr) = 1;//ǰ4���ֽ���������
			_pStr += 4;//���ƫ��4���ֽ�
			strcpy(_pStr,pStr);//�����ַ���
		}
	}
	String(const String& s)//�������캯��
		:_pStr(s._pStr)
	{
		++(*(int*)(_pStr - 4));//��ǰƫ��4���ֽڽ�����+1
	}
	~String()//��������
	{
		if(NULL == _pStr)
		{
			return;
		}
		else
		{
			if(--(*(int*)(_pStr - 4)) == 0)
			{
				delete[] (_pStr - 4);
				_pStr = NULL;
			}
		}
	}
	//���ظ�ֵ�����=
	String& operator=(const String& s)
	{
		if(_pStr != s._pStr)
		{
			if(--(*(int*)(_pStr - 4)) == 0)//�ͷžɿռ�
			{
				delete[] (_pStr - 4);
				_pStr = NULL;
			}
			_pStr = s._pStr;//ָ���¿ռ�
			++(*(int*)(_pStr - 4));//����+1
		}
		return *this;
	}
	//�����±���ʲ�����
	char& operator[](size_t t)
	{
		if(t >= 0 && t < strlen(_pStr))//�±�Ƿ��ж�
		{
			if((*(int*)(_pStr - 4)) > 1)//�������ָ��ͬһ��ռ�
			{
				char *pTemp = new char[strlen(_pStr) + 4 + 1];//������ʱ�ռ�
				pTemp += 4;//���ƫ��4���ֽ�
				strcpy(pTemp,_pStr);//�����ַ���
				--(*(int*)(_pStr - 4));//����-1
				_pStr = pTemp;//����ǰ�Ķ���ָ����ʱ�ռ�
				*((int*)(_pStr - 4)) = 1;//���¿ռ�ļ�����Ϊ1
			}
			return _pStr[t];
		}							   
	}
private:
	char *_pStr;
};
void FunTest()
{
	String s1("Hello world");
	String s2(s1);
	String s3 = s2;
	s3[3] = 'm';
}
int main()
{
	FunTest();
	system("pause");
	return 0;
}