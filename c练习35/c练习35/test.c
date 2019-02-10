#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int my_strncmp(const char* dest,const char* src, int n)
{
	assert(dest);
	assert(src);
	assert(n > 0);
	while (n--)
	{
		if (*dest == *src)
		{
			dest++;
			src++;
		}
		else if (dest > src)
		{
			return *dest - *src;
		}
		else
		{
			return *src - *dest;
		}
	}
	return 0;
}

int main()
{
	char str1[] = "abcde";
	char str2[] = "abcd";
	int n = strlen(str1) + 1;
	printf("%d\n", my_strncmp(str1, str2, n));
	system("pause");
	return 0;
}