#include<stdio.h>
#include<stdlib.h>	
#include<string.h>
#include<assert.h>

char* my_strncpy(char* dest, char* src, int n)
{
	assert(dest);
	assert(src);
	assert(n > 0);
	char* ret = dest;
	while (n&&*src)
	{
		*dest++ = *src++;
		n--;
	}
	return ret;
}

int main()
{
	char str1[] = "abcde";
	char str2[] = "cdb";
	int n = strlen(str2)+1;
	printf("%s\n", my_strncpy(str1,str2,n));
	system("pause");
	return 0;
}