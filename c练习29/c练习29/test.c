#include<stdio.h>
#include<stdlib.h>

//Ä£ÄâÊµÏÖstrcmp
int my_strcmp(const char* src,const char* dest)
{
	if (src != NULL && dest != NULL)
	{
		while (*src == *dest)
		{
			if (*src == '\0')
			{
				return 0;
			}
			src++;
			dest++;
		}
	}
	return *src - *dest;
}

int main()
{
	char arr1[] = "abcda";
	char arr2[] = "abcda";
	printf("%d\n",my_strcmp(arr1,arr2));
	system("pause");
	return 0;
}