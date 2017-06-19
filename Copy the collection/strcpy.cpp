#include <iostream>
#include <assert.h>
using namespace std;
char* my_strcpy(char *dst, const char* src)
{
	assert(src);
	char *ret = dst;
	while (*dst++ = *src++);
	return ret;

}
char* my_strncpy(char* dst, const char* src, int n)
{
	assert(src);
	char* ret = dst;
	while (n && (*dst++ = *src++))
		n--;
	if (n > 0)
	{
		while (--n)
			*dst++ = '\0';
	}
	return ret;
}
char* my_strcat(char *dst, char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return ret;
}
char* my_strncat(char* dst, char* src, int len)
{
	assert(dst && src && len > 0);
	char* ret = dst;
	while (*dst != '\0')
		dst++;
	while (len-- && *src!='\0')
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return ret;
}
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 > *str2)
			return 1;
		else
			return -1;
	}
	if (*str1 == '\0' && *str2 != '\0')
		return -1;
	else if (*str1 != '\0' && *str2 == '\0')
		return 1;
	return 0;
}
int my_strncmp(const char* str1, const char* str2,int n)
{
	assert(str1 && str2 && n > 0);
	while (n-- > 0 && *str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 > *str2)
			return 1;
		else
			return -1;
	}
	if (*str1 == '\0' || *str2 == '\0')
		return 0;
}
char* my_memcpy(char* dst, const char* src, int n)
{
	assert(src && n > 0);
	char* ret = dst;
	while (*dst != '\0')
		dst++;
	while (n-- > 0 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return ret;
}
char* my_memmove(char* dst, char* src, int n)
{
	char *_dst = dst;
	char *_src = src;
	char *ret = dst;
	if (_src < _dst && _src + n > _dst)
	{
		char* _dst_end = _dst + n - 1;
		char* _src_end = _src + n - 1;
		while (n--)
		{
			*_dst_end++ = *_src_end++;
		}
	}
	else
	{
		while (n--)
			*_dst++ = *_src;
	}
	return ret;
}
int main()
{
	const char *src = "my dream is bat.";
	char dst[32] = { 0 };
	//cout << my_strcpy(dst, src) << endl;
	//cout << my_strncpy(dst, src, 11) << endl;
	char str1[32] = "i am ";
	char str2[32] = "a student.";
	char *p1 = "i am you father";
	char *p2 = "i";
	char str3[32] = "abcde";
	char str4[32] = "a";
	char p3[32] = { 0 };
	char p4[32] = "sunshine";
	char arr5[32] = "you are my sunshine";
	char arr6[] = "what are you doing?";
	//cout << my_strcat(str1, str2) << endl;
	//cout << my_strncat(str1, str2, 6) << endl;
	//cout << my_strcmp(p1, p2) << endl;
	//cout << my_strncmp(str3, str4, 3) << endl;
	//cout << my_memcpy(p3, p4, 8) << endl;
	cout << my_memmove(arr5, arr6, 1) << endl;
	system("pause");
	return 0;
}