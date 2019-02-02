#include<stdio.h>
#include<stdlib.h>

//Ä£ÄâÊµÏÖstrcat
char* my_strcat(char* src, const char* dest)
{
	char* ret = src;
	if (src != NULL && dest != NULL)
	{
		while (*src != '\0')
		{
			*src++;
		}
		while (*src++ = *dest++)
		{
			
		}
	}
	return ret;
}

int main()
{
	char arr1[20] = "hello";
	char arr2[20] = " world";
	printf("%s\n", my_strcat(arr1, arr2));
	system("pause");
	return 0;
}