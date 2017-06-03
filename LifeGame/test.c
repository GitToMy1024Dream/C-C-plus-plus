#include "LifeGame.h"
int main()
{
	int row,col,sum1;
	char again;
	Init();
	Output();
	printf("按任意键进行转换\n");
	getch();
	while(1)
	{
		for(row = 0;row < MAXROW;row++)
		{
			for(col = 0;col < MAXCOL;col++)
			{
				switch(BorderSum(row,col))
				{
				case 0:
				case 1:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					tempcell[row][col] = DEAD;
					break;
				case 2:
					tempcell[row][col] = cell[row][col];
					break;
				case 3:
					tempcell[row][col] = ALIVE;
					break;
				}
			}
		}
		for(row = 0;row < MAXROW;row++)
			for(col = 0;col < MAXCOL;col++)
				cell[row][col] = tempcell[row][col];
		sum1 = AliveSum();
		if(sum1 == 0)
			break;
		Output();
		printf("共有%d个活细胞。\n",sum1);
		printf("\n继续生成下一次细胞的状态(n退出)?");
		again = getch();
		if(again == 'N' || again == 'n')
			break;
	}
	getch();
	system("pause");
	return 0;
}