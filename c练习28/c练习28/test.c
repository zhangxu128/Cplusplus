#include<stdio.h>
#include<stdlib.h>

//Ä£ÄâÊµÏÖstrchr
char* my_strchr(char* src, char c)
{
	while (*src != '\0'&& *src != c)
	{
		*src++;
	}
	return *src == c ? src : NULL;
}

int main()
{
	char arr1[] = "abcdef";
	char c = 'f';
	printf("%s\n", my_strchr(arr1, c));
	system("pause");
	return 0;
}