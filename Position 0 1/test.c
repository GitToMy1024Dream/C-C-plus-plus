#include <stdio.h>
#include <Windows.h>
#include <assert.h>
void bit_set(unsigned int *p_date,unsigned int pos,int flag)
{
	if(pos <= 1 || pos >= 8)
	{
		printf("input error!");
	}
	else
	{
		if(flag == 1)
		{
			*p_date |= (1 << (pos - 1));
			printf("%d\n",*p_date);
		}
		else if(flag == 0)
		{
			*p_date &= ~((1 << (pos - 1)));
			printf("%d\n",*p_date);
		}
	}
}
int main()
{
	unsigned int p_date = 0;
	unsigned int pos = 0;
	int flag = 0;
	printf("Please enter p_date pos flag:");
	scanf("%d %d %d",&p_date,&pos,&flag);
	bit_set(&p_date,pos,flag);
	system("pause");
	return 0;
}