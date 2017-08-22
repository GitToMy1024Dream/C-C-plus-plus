#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
class Timer{
public:
	Timer()
	{
		seconds = 0;
	}
	Timer(char *t)
	{
		seconds = atoi(t);
	}
	Timer(int t)
	{
		seconds = t;
	}
	Timer(int min,int sec)
	{
		seconds = min * 60 + sec;
	}
	int SetTime()
	{
		return seconds;
	}
private:
	int seconds;
};
int main()
{
	LARGE_INTEGER _start = { 0 }, _end = { 0 };
__asm{
    rdtsc
    mov dword ptr [_start.LowPart], eax
    mov dword ptr[_start.HighPart], edx
}
    Timer A;//your code here
	Timer B(10);
	Timer C("20");
	Timer D(1,10);
	cout<<"second1="<<A.SetTime()<<endl;
	cout<<"second2="<<B.SetTime()<<endl;
	cout<<"second3="<<C.SetTime()<<endl;
	cout<<"second4="<<D.SetTime()<<endl;
__asm{
    rdtsc
    mov dword ptr [_end.LowPart], eax
    mov dword ptr[_end.HighPart], edx
}
long interval = static_cast<long>(_end.QuadPart - _start.QuadPart);
    cout<<"Time:"<<interval<<endl;
	system("pause");
	return 0;
}



