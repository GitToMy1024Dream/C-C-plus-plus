#include <iostream>
using namespace std;

////懒汉模式
//class Singletion
//{
//public:
//	static Singletion* GetInstance() //返回一个静态的对象指针
//	{
//		if (instance == NULL) //保证第一次创建对象成功
//		{
//			instance = new Singletion();
//			cout << "Obj create success for the first time." << endl;
//		}
//		else //保证全局仅有一个对象
//		{
//			cout << "Create failure" << endl;
//		}
//		return instance;
//	}
//private:
//	Singletion() //构造函数设为私有
//	{
//		cout << "Singletion()" << endl;
//	}
//	static Singletion* instance;
//};
//Singletion* Singletion::instance = NULL; //静态成员对象必须初始化

//双重检查机制
class Singletion
{
public:
	static Singletion* GetInstance() //返回一个静态的对象指针
	{
		//第一次检查实例是否存在
		if (instance == NULL)
		{
			Lock(mutex);//加锁
			//第二次检查实例是否存在
			if (instance == NULL)
			{
				instance = new Singletion();
				cout << "Obj create success for the first time." << endl;
			}
			else //保证全局仅有一个对象
			{
				cout << "Create failure" << endl;
			}
			Unlock(mutex);//解锁
		}
		return instance;
	}
private:
	Singletion() //构造函数设为私有
	{
		cout << "Singletion()" << endl;
	}
	 static Singletion*  instance;
	 static mutex _mtx; //互斥锁
};
Singletion* Singletion::instance = NULL; //静态成员对象必须初始化
mutex Singletion::_mtx; //初始化互斥锁
int main()
{
	Singletion* _s1 = Singletion::GetInstance();
	Singletion* _s2 = Singletion::GetInstance();
	cout << _s1 << endl;
	cout << _s2 << endl;
	system("pause");
	return 0;
}


