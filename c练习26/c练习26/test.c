#include<stdio.h>
#include<stdlib.h>

//Ä£ÄâÊµÏÖstrcpy
char* my_strcpy(const char* src, char* dest)
{
	char* ret = dest;
	if (src != NULL && dest != NULL)
	{
		while (*dest++ = *src++)
		{
			;
		}
	}
	return ret;
}

int main()
{
	char arr1[] = "abcde";
	char arr2[] = { 0 };
	printf("%s\n",my_strcpy(arr1,arr2));
	system("pause");
	return 0;
}
