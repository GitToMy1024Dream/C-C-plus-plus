
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
	for(j = 3;j <= sqrt(n);j += 2)//3��������n֮���ж��Ƿ�������
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
		for(n = 2;n < i;n++) //��ż��i�ֽ�Ϊ��������
		{
			if(isPrime(n))	//�жϵ�һ�����Ƿ�Ϊ����
				if(isPrime(i-n)) //�ж���һ�����Ƿ�Ϊ����
				{
					printf("%d=%d+%d  ",i,n,i-n);//���߾�Ϊ����
					break;
				}
		}
	}
	system("pause");
	return 0;
}