#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[10]={0},i=1;
flag:	printf("Please Enter PSW(you have three choices):\n");
		scanf("%s",input);
		if(strcmp(input,"root")==0)
		{
			printf("ÄúÒÑµÇÂ¼³É¹¦£¬»¶Ó­Äú£¡");
		}
		else if(i<3)
		{
			i++;
			goto flag;	
			
		} 		 
		return 0;
 } 
