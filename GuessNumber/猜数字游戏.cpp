/*#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{ 
    printf("\n"); 
    printf("\n"); 
	printf("                                                史上最难游戏猜数字\n");
    printf("\n"); 
	printf("\n"); 
	printf("                                      请选择：   1-->立即体验    0-->无聊不玩");
	printf("\n"); 
	printf("\n"); 
}
void game()
{
	int num=rand()%100;
	printf("%d\n",num);
	
}
int main()
{        
     int input=0;
     menu();
     srand((unsigned int)time(NULL));
	do{
	 printf("Please chooce 0 or 1:");
	 scanf("%d",&input);	
	 switch(input)
	 {
	 	case 1:
	 		game();
	 		break;
	    case 0:
	    	break;
	    	default:
	    		printf("选择无效");
	    		break;
	 }
		
	}while(input);
 } */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{ 
    printf("\n"); 
    printf("\n"); 
	printf("                                                史上最难游戏猜数字\n");
    printf("\n"); 
	printf("\n"); 
	printf("                                      请选择：   1-->立即体验    0-->无聊不玩");
	printf("\n"); 
	printf("\n"); 
}
void game()
{
	int num=rand()%100;
	int input=0;
	while(1)
	{
		printf("请输入猜的数字：");
		scanf("%d",&input);
		if(input>num)
		{
			printf("猜大了\n");
			
		
		}
		else if(input<num)
		{
			printf("猜小了\n");
			
	
		}
		else{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
	
}
int main()
{        
     int input=0;
     menu();
     srand((unsigned int)time(NULL));
	do{
	 printf("Please chooce 0 or 1:");
	 scanf("%d",&input);	
	 switch(input)
	 {
	 	case 1:
	 		game();
	 		break;
	    case 0:
	    	break;
	    	default:
	    		printf("选择无效\n");
	    		break;
	 }
		
	}while(input);
	return 0;
 } 
