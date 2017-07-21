#include <iostream>
using namespace std;

////����ģʽ
//class Singletion
//{
//public:
//	static Singletion* GetInstance() //����һ����̬�Ķ���ָ��
//	{
//		if (instance == NULL) //��֤��һ�δ�������ɹ�
//		{
//			instance = new Singletion();
//			cout << "Obj create success for the first time." << endl;
//		}
//		else //��֤ȫ�ֽ���һ������
//		{
//			cout << "Create failure" << endl;
//		}
//		return instance;
//	}
//private:
//	Singletion() //���캯����Ϊ˽��
//	{
//		cout << "Singletion()" << endl;
//	}
//	static Singletion* instance;
//};
//Singletion* Singletion::instance = NULL; //��̬��Ա��������ʼ��

//˫�ؼ�����
class Singletion
{
public:
	static Singletion* GetInstance() //����һ����̬�Ķ���ָ��
	{
		//��һ�μ��ʵ���Ƿ����
		if (instance == NULL)
		{
			Lock(mutex);//����
			//�ڶ��μ��ʵ���Ƿ����
			if (instance == NULL)
			{
				instance = new Singletion();
				cout << "Obj create success for the first time." << endl;
			}
			else //��֤ȫ�ֽ���һ������
			{
				cout << "Create failure" << endl;
			}
			Unlock(mutex);//����
		}
		return instance;
	}
private:
	Singletion() //���캯����Ϊ˽��
	{
		cout << "Singletion()" << endl;
	}
	 static Singletion*  instance;
	 static mutex _mtx; //������
};
Singletion* Singletion::instance = NULL; //��̬��Ա��������ʼ��
mutex Singletion::_mtx; //��ʼ��������
int main()
{
	Singletion* _s1 = Singletion::GetInstance();
	Singletion* _s2 = Singletion::GetInstance();
	cout << _s1 << endl;
	cout << _s2 << endl;
	system("pause");
	return 0;
}


