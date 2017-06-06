#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>
void *my_memmove(void *dst,void *src,int count)
{
	char *_dst = (char*)dst;
	char *_src = (char*)src;
	char *ret = _dst;
	assert(dst&&src);
	//从后向前复制
	if(_src < _dst && _src + count > _dst)
	{
		char *_dst_end = _dst + count - 1;
		char *_src_end = _src + count - 1;
		while(count--)
		{
			*_dst_end-- = *_src_end--;
		}
	}
	else//从前往后复制
	{
		while(count--)
		{
			*_dst++ = *_src++;
		}
	}
	return ret;
 
}
int main()
{
	char src[32] = "I love u girl.";
	char dst[32];
	printf("%s\n",my_memmove(dst,src,strlen(src)+1));
	system("pause");
	return 0;
}