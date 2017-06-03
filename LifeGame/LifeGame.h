#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define MAXROW 10 //最大行数
#define MAXCOL 10 //最大列数
#define DEAD 0  //死细胞
#define ALIVE 1 //活细胞
int cell[MAXROW][MAXCOL];	 //当前状态
int tempcell[MAXROW][MAXCOL]; //转换的临时状态
void Init();//初始化细胞数组
int BorderSum(int,int);//统计当前细胞周围的细胞数
int AliveSum();//统计生细胞的数量
void Output();//输出细胞状态