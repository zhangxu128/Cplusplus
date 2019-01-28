#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int string_move(char *msg, char *substring)
{
	int len = strlen(msg);
	char *tmp = (char*)malloc(2 * len + 1);  //申请2倍数组空间
	if (len == strlen(substring))  //保证要比较的两个字符串长度相同
	{
		strcpy(tmp, msg);  //原来的字符串拷贝到新空间里
		strcat(tmp, msg);  //字符串的拼接，实现复制
		if (strstr(tmp, substring) != NULL)
		{
			return 1;
		}
	}
	free(tmp);  //释放申请的新空间
	return 0;
}

int main()
{
	/*判断一个字符串是否为另外一个字符串旋转之后的字符串。
		例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.

		AABCD左旋一个字符得到ABCDA
		AABCD左旋两个字符得到BCDAA

		AABCD右旋一个字符得到DAABC*/
	char arr1[] = "abcdef";
	char arr2[6];
	scanf("%s",&arr2);
	if (string_move(arr1, arr2)==1)
	{
		printf("是旋转之后的字符串\n");
	}
	else
	{
		printf("不是旋转之后的字符串\n");
	}
	system("pause");
	return 0;
}