#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ģ��ʵ��memcpy()����
void* myMemcpy(void* dest, const void* src, size_t num)
{
	//�����ĺϷ��Լ���
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//ģ��ʵ��memmove����
//�������ܣ� memmove���ڴ�src����count���ַ���dest��
//           ���Ŀ�������Դ�������ص��Ļ���memmove�ܹ���֤Դ��
//           �ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ�������С�
//           �����ƺ�src���ݻᱻ���ġ����ǵ�Ŀ��������Դ����û���ص�
//           ���memcpy����������ͬ
void * myMemmove(void * dest, const void * src, size_t num)
{
	//�����ĺϷ��Լ���
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	void* ret = dest;
	//�������ڴ��ص����ӵ͵�ַ���ߵ�ַ����
	if (dest <= src || (char*)dest >= ((char*)src + num))
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//�����ڴ��ص����Ӹߵ�ַ���͵�ַ����
	else
	{
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;

		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}


//ģ��ʵ��memset()����
void* myMemset(void *src, int c, size_t count)
{
	//�����ĺϷ��Լ���
	if (src == NULL)
	{
		return NULL;
	}
	char *tmp = (char*)src;
	while (count--)
	{
		*tmp ++ = (char)c;
	}
	return src;
}


//����memmove()����
void test1()
{
	char s[] = "hello world!";
	char* ret = myMemcpy(s+5, s, 5);
	printf("%s\n", ret);
}

//����memcpy()����
void test2()
{
	char s[] = "hello world!";
	char* ret = myMemmove(s+5, s, 5);
	printf("%s\n", ret);
}

//����memset()����
void test3()
{
	char str[] = "almost every programmer should know memset!";
	myMemset(str, '-', 6);
	puts(str);
}


int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}