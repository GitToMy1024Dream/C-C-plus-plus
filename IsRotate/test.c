#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char str_str(char *str1,char *str2)
{
	int len = strlen(str1);
	int i = 0;
	int j = 0;
	char tmp = 0;
	assert(str1);
	assert(str2);
	for(i = 0;i < len;i++)
	{
		tmp = str1[0];
		for(j = 0;j < len - 1;j++)
		{
			str1[j] = str1[j+1];
		}
		str1[len-1] = tmp; 
		if(strcmp(str1,str2) == 0)
	{
		printf("1\n");
		return 0;
	}	
	}
	printf("0\n");
	return 0;
	
	
}
int main()
{
	char arr1[] = "ABCDEF";
	char arr2[] = "BCDEFA";
	str_str(arr1,arr2);
	system("pause");
	return 0;
}