#include<stdio.h>
int main()
{
	int num1=0,num2=0,MidAgent=0,Blog_Text1=0,Blog_Text2=0,Temp;
	printf("please input num1,num2(�м��ÿո����):");
	scanf("%d %d",&num1,&num2);
	printf("num1=%d,num2=%d\n",num1,num2); 
	if(num1<num2)
	{
		MidAgent=num2;
		num2=num1;
		num1=MidAgent;
	}
	Blog_Text1=num1;
	Blog_Text2=num2;
	while(Blog_Text2!=0)
	{
	    Temp=Blog_Text1%Blog_Text2;
		Blog_Text1=Blog_Text2;
		Blog_Text2=Temp;
	}
	printf("���Լ��=%d",Blog_Text1);
	return 0;
 } 
