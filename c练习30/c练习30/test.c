#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void* my_memcpy(void* dest, void* src, int count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (count--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}

int main()
{
	int a[] = {1,2,3,4,5,6};
	int b[20] = {0};
	my_memcpy(b,a,24);
	for(int i = 0 ;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d ", b[i]);
	}
	system("pause");
	return 0;
}