/*#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{ 
    printf("\n"); 
    printf("\n"); 
	printf("                                                ʷ��������Ϸ������\n");
    printf("\n"); 
	printf("\n"); 
	printf("                                      ��ѡ��   1-->��������    0-->���Ĳ���");
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
	    		printf("ѡ����Ч");
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
	printf("                                                ʷ��������Ϸ������\n");
    printf("\n"); 
	printf("\n"); 
	printf("                                      ��ѡ��   1-->��������    0-->���Ĳ���");
	printf("\n"); 
	printf("\n"); 
}
void game()
{
	int num=rand()%100;
	int input=0;
	while(1)
	{
		printf("������µ����֣�");
		scanf("%d",&input);
		if(input>num)
		{
			printf("�´���\n");
			
		
		}
		else if(input<num)
		{
			printf("��С��\n");
			
	
		}
		else{
			printf("��ϲ�㣬�¶��ˣ�\n");
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
	    		printf("ѡ����Ч\n");
	    		break;
	 }
		
	}while(input);
	return 0;
 } 
