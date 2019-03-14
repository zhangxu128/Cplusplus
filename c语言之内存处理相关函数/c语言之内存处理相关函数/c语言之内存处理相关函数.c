#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//模拟实现memcpy()函数
void* myMemcpy(void* dest, const void* src, size_t num)
{
	//参数的合法性检验
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//模拟实现memmove函数
//函数功能： memmove用于从src拷贝count个字符到dest，
//           如果目标区域和源区域有重叠的话，memmove能够保证源串
//           在被覆盖之前将重叠区域的字节拷贝到目标区域中。
//           但复制后src内容会被更改。但是当目标区域与源区域没有重叠
//           则和memcpy函数功能相同
void * myMemmove(void * dest, const void * src, size_t num)
{
	//参数的合法性检验
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	void* ret = dest;
	//不存在内存重叠，从低地址往高地址复制
	if (dest <= src || (char*)dest >= ((char*)src + num))
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//考虑内存重叠，从高地址往低地址复制
	else
	{
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;

		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}


//模拟实现memset()函数
void* myMemset(void *src, int c, size_t count)
{
	//参数的合法性检验
	if (src == NULL)
	{
		return NULL;
	}
	char *tmp = (char*)src;
	while (count--)
	{
		*tmp ++ = (char)c;
	}
	return src;
}


//测试memmove()函数
void test1()
{
	char s[] = "hello world!";
	char* ret = myMemcpy(s+5, s, 5);
	printf("%s\n", ret);
}

//测试memcpy()函数
void test2()
{
	char s[] = "hello world!";
	char* ret = myMemmove(s+5, s, 5);
	printf("%s\n", ret);
}

//测试memset()函数
void test3()
{
	char str[] = "almost every programmer should know memset!";
	myMemset(str, '-', 6);
	puts(str);
}


int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}