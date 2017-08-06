#include "Date.h"
void FunTest()
{
	Date date1(2015,3,31);
	Date date2(date1);
	Date date3(2017,12,1);
	Date date4(date3);
	Date date5(2012,2,2);
	Date date6(date5);
	Date date7(2017,2,19);
	Date date8(1995,10,24);
	Date date9;
	/*cout<<"date1:"<<date1<<endl;
	cout<<"date2:"<<date2<<endl;
	cout<<"date3:"<<date3<<endl;
	cout<<"date4:"<<date4<<endl;
	cout<<"date5:"<<date5<<endl;
	cout<<"date6:"<<date6<<endl;
	cout<<"date7:"<<date7<<endl;
	cout<<"date8:"<<date8<<endl;
	cout<<"date9:"<<date9<<endl;*/
	cout<<"前置++："<<++date1<<endl;
	cout<<"后置++："<<date2++<<endl;
	cout<<"前置--："<<--date3<<endl;
	cout<<"后置--："<<date4--<<endl;
	cout<<"加指定天数："<<date5+24<<endl;
	cout<<"减指定天数："<<date6-5<<endl;
	cout<<"两个日期相差的天数："<<date7 - date8<<endl;
	//cin>>date9;
}
int main()
{
	FunTest();
	system("pause");
	return 0;
}