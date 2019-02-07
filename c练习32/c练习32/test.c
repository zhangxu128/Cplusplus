#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strstr(const char*str1, const char*str2)
{
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;
	assert(str1 != NULL);
	assert(str2 != NULL);

	if (*str2 == '\0')
		return (char*)str1;

	while (*cp)
	{
		s1 = cp;
		s2 = str2;

		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (char *)cp;
		cp++;
	}
	return NULL;
}

int main()
{
	char str1[] = "abcdbcd";
	char str2[] = "cdb";
	char *ret = my_strstr(str1,str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}