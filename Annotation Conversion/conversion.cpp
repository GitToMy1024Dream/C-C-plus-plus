#include "convert.h"
status_t gStatus = NORMAL_STATUS;
void doNormal(FILE *in,FILE *out)
{
	int first = fgetc(in);
	int second = 0;
	assert(in);
	assert(out);
	switch(first)
	{
	case '/':
		{
			second = fgetc(in);
			if(second == '*')
			{
				fputc('/',out);
				fputc('/',out);
				gStatus = C_STATUS;
			}
			else if (second == '/')
			{
				 fputc(first,out);
				 fputc(second,out);
				 gStatus = CPP_STATUS;
			}
			else
			{
				fputc(first,out);
				fputc(second,out);
			}
		}
		break;
	case EOF:
		gStatus = END_STATUS;
		break;
	default:
		fputc(first,out);
		break;
	}
}
void doCStatus(FILE *in,FILE *out)
{	 
	int first = fgetc(in);
	int second = 0;
	assert(in);
	assert(out);
	switch(first)
	{
	case '*':
		{
			second = fgetc(in);
			if(second == '/')
			{
				int third = fgetc(in);
				if(third == '\n')
				{
					fputc(third,out);
				}
				else 
				{
					ungetc(third,in);
					fputc('\n',out);
				}
				gStatus = NORMAL_STATUS;
			}
			else
			{
				fputc(first,out);
				ungetc(second,in);
			}
		}
		break;
	case '\n':
		fputc(first,out);
		fputc('/',out);
		fputc('/',out);
		break;
	case EOF:
		gStatus = END_STATUS;
		break;
	default:
		fputc(first,out);
		break;
	}
}
static void doCPPStatus(FILE *in, FILE *out)
{
	int first = fgetc(in);
	assert(in);
	assert(out);
	switch(first)
	{
	case '\n':
		fputc(first,out);
		gStatus = NORMAL_STATUS;
		break;
	case EOF:
		gStatus = END_STATUS;
		break;
	default:
		fputc(first,out);
		break;
	}
}
static void convertStatusMachine(FILE *in,FILE *out)
{
	assert(in);
	assert(out);
	while (gStatus != END_STATUS)
	{
		switch (gStatus)
		{
		case NORMAL_STATUS:
			doNormal(in,out);
			break;
		case C_STATUS:
			doCStatus(in,out);
			break;
		case CPP_STATUS:
			doCPPStatus(in,out);
			break;
		case END_STATUS:
			break;
		default:
			break;
		}
	}
}
void convertBegin()
{
	FILE *in = fopen (INPUT_FILE,"r"); 
	
	FILE *out = fopen(OUTPUT_FILE,"w");
	if(NULL == in )
	{
		perror("fopen");
		exit(1);
	}
	
	if(NULL == out)
	{
		perror("fopen");
		exit(2);
	}
	convertStatusMachine(in,out);
	fclose(in);
	fclose(out);
}
int main()
{
	printf("开始注释转换！\n");
	convertBegin();
	printf("convert done...\n");
	printf("转换完成。\n");
	system("pause");
	return 0;
}