#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	while(1)
	{ 
		printf("����������Ҫת�����ַ�:");
		char str ;
		scanf("%c",&str);
		if (str >= 'a' && str <= 'z')
		{
			str -= 32;
			printf("%c\n",str);
		}
		else if (str >= 'A'&&str <= 'Z')
		{
			str += 32;
			printf("%c\n",str);
		}
		else
		{
			printf("");
		}
	}
	system("pause");
	return 0;
}