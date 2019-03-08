#include<stdio.h>
#include<stdlib.h>

void *memcpy(void *dst, const void *src, size_t len)
{
	if (NULL == dst || NULL == src) {
		return NULL;
	}  //参数容错性检查

	void *ret = dst;

	if (dst <= src || (char *)dst >= (char *)src + len) {
		//没有内存重叠，从低地址开始复制  ，考虑的很周全，太佩服这些人了
		while (len--) {
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else {
		//有内存重叠，从高地址开始复制   
		src = (char *)src + len - 1;
		dst = (char *)dst + len - 1;
		while (len--) {
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}

int main()
{

	char str[] = "abcedf";
	char* ret = (char*)memcpy(str + 2, str, 4);
	printf("%s\n", ret);
	system("pause");
	return 0;
}