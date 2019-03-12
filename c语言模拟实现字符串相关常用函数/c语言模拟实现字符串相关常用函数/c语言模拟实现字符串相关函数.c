#define _CRT_SRCURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1��ģ��ʵ��strcpy()����
char*  myStrcpy(char* dest, const char* src)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* ret = (char*) dest;
	while ((*dest++ = *src++) != '\0');
	return ret;
}
//2��ģ��ʵ��strncpy()����
char* myStrncpy(char* dest, const char* src, size_t num)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* ret = dest;
	while ((num--) && (*dest++ = *src++) != '\0');
	return ret;
}
//3��ģ��ʵ��strcat()����
char* myStrcat(char* dest, const char* src)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest++ = *src++) != '\0');
	return ret;
}
//4��ģ��ʵ��strncat()
char* myStrncat(char* dest, const char* src, size_t num)
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((num--) && (*dest++ = *src++) != '\0');
	return ret;
}
//5��ģ��ʵ��strlen()����
size_t myStrlen(const char* str)
{
	////��ʽһ �� ������ʱ����


	//int count = 0;
	//while (*str++ != '\0')
	//{
	//	count++;
	//}
	//return count;


	//��ʽ���� ��������ʱ������ʹ�õݹ鷽ʽ
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}
//6��ģ��ʵ��strcmp()����
int myStrcmp(const char* dest, const char* src)
{
	if (dest == NULL || src == NULL)
	{
		return -1;
	}
	while (* dest == * src)
	{
		if ((*dest == '\0') && (*src == '\0'))
		{
			return 0;
		}
		dest++;
		src++;
	}
	return *dest - *src;
}
//7��ģ��ʵ��strncmp()����
int myStrncmp(const char* dest, const char* src, size_t num)
{
	if (dest == NULL || src == NULL)
	{
		return -1;
	}
	while (*dest == *src) 
	{
		if (num-- == 0)
		{
			return 0;
		}
		dest++;
		src++;
	}
	return *dest - *src;
}

//8��ģ��ʵ��strstr()����

char* myStrstr(const char *s1,const char *s2)
{
	int n;
	if (*s2)                      //�����������
	{
		while (*s1)
		{
			for (n = 0; *(s1 + n) == *(s2 + n); n++)
			{
				if (!*(s2 + n + 1))            //���ҵ���һ���ַ��Ƿ�Ϊ'\0'
				{
					return (char*)s1;
				}
			}
			s1++;
		}
		return NULL;
	}
	else
	{
		return (char*)s1;
	}
}
void test1()
{
	char string1[] = "abcdefg";
	char string2[20] = {0};
	char* ret=myStrcpy(string2, string1);
	printf("%s\n", ret);
}

void test2()
{
	char str1[] = "abcdefg";
	char str2[20] = "";
	int num = 4;
	char* str = myStrncpy(str2, str1, num);
	printf("%s\n", str);
}
void test3()
{
	char str1[20] = "abcd";
	char str2[] = "efg";
	char* str = myStrcat(str1, str2);
	printf("%s\n", str);

}

void test4()
{
	char str1[20] = "abcd";
	char str2[] = "efg";
	size_t num = 1;
	char* str = myStrncat(str1, str2,num);
	printf("%s\n", str);

}
void test5()
{
	char * str = "abcdefgwasd";
	int count = myStrlen(str);
	printf("%d\n", count);
}

void test6()
{
	char* str1 = "abcd";
	char* str2 = "abcda";
	int ret = myStrcmp(str1, str2);
	printf("%d\n", ret);
}

void test7()
{
	char* str1 = "abcdfg";
	char* str2 = "abcdeg";
	int ret = myStrncmp(str1, str2,5);
	printf("%d\n", ret);
}

void test8()
{
	char* str1 = "abcdfg";
	char* str2 = "cd";
	char* str = myStrstr(str1, str2);
	printf("%s\n", str);

}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	system("pause");
	return 0;
}