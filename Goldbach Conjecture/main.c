
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
#include <stdio.h>
#include <Windows.h>
#include <math.h>
int isPrime(int n)
{
	int j = 0;
	if(n <= 1)
		return 0;
	if(n == 2)
		return 1;
	if(!(n%2))
		return 0;
	for(j = 3;j <= sqrt(n);j += 2)//3到根号下n之间判断是否有因子
		if((n%j))
			return 0;
		return 1;
}
int main()
{
	int i = 0;
	int n = 0;
	int count = 0;
	for(i = 4;i <= 2000; i += 2)
	{
		for(n = 2;n < i;n++) //将偶数i分解为两个整数
		{
			if(isPrime(n))	//判断第一个数是否为素数
				if(isPrime(i-n)) //判断另一个数是否为素数
				{
					printf("%d=%d+%d  ",i,n,i-n);//两者均为素数
					break;
				}
		}
	}
	system("pause");
	return 0;
}