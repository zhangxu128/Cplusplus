#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char* my_strncat(char* dest, char* src, int n)
{
	assert(dest);
	assert(src);
	assert(n > 0);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (n&&*src)
	{
		*dest++ = *src++;
		n--;
	}
	return ret;
}

int main()
{
	char str1[20] = "abcd";
	char str2[] = "ef";
	int n = strlen(str2) + 1;
	printf("%s\n", my_strncat(str1, str2, n));
	system("pause");
	return 0;
}