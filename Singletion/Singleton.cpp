#include <iostream>
using namespace std;
//恶汉单例
class Singleton
{
public:
	static Singleton* GetInstance() //返回一个静态的对象指针
	{
		return instance;
	}
	static void DestroyInstance() //销毁对象
	{
		delete instance;
		instance = NULL;
	}
private:
	Singleton() //构造函数设为私有
	{
		cout << "Singleton()" << endl;
	}
	static Singleton* instance;//静态成员，指向Singleton对象的指针
};
Singleton* Singleton::instance = new Singleton(); //静态成员对象必须初始化
int main()
{
	cout << "main run..." << endl; //验证静态对象的创建在main之前
	Singleton* _s1 = Singleton::GetInstance();
	Singleton* _s2 = Singleton::GetInstance();
	cout << _s1 << endl;
	cout << _s2 << endl;
	system("pause");
	return 0;
}