#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memmove(void* dest, void* src, int count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src)
	{
		while (count--)
		{
			*((char*)dest) = *((char*)src);
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	my_memmove(a, a+2, 16);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}