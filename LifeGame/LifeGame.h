#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define MAXROW 10 //�������
#define MAXCOL 10 //�������
#define DEAD 0  //��ϸ��
#define ALIVE 1 //��ϸ��
int cell[MAXROW][MAXCOL];	 //��ǰ״̬
int tempcell[MAXROW][MAXCOL]; //ת������ʱ״̬
void Init();//��ʼ��ϸ������
int BorderSum(int,int);//ͳ�Ƶ�ǰϸ����Χ��ϸ����
int AliveSum();//ͳ����ϸ��������
void Output();//���ϸ��״̬