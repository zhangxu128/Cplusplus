#include<iostream>

using namespace std;
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20��.
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
void replaceSpace(char str[], int length) 
{
	int len = length * 2 + 1;
	char* ptr = (char*)malloc(sizeof(char)*len);
	memset(ptr, 0, len);
	int i = 0;  //ptr
	int j = 0;  //str
	while (j < length)
	{
		if (str[j] == ' ')
		{
			ptr[i] = '%';
			i++;
			ptr[i] = '2';
			i++;
			ptr[i] = '0';
			j++;
			i++;
		}
		else
		{
			while (str[j] != ' ')
			{
				ptr[i] = str[j];
				i++;
				j++;
				if (str[j] == '\0')
				{
					break;
				}
			}
		}

	}
	cout << ptr << endl;
	free(ptr);
}

void replaceSpace1(char* str, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ')
			count++;
	}
	for (int i = length - 1; i >= 0; i--) {
		if (str[i] != ' ') {
			str[i + 2 * count] = str[i];
		}
		else {
			count--;
			str[i + 2 * count] = '%';
			str[i + 2 * count + 1] = '2';
			str[i + 2 * count + 2] = '0';
		}
	}
	cout << str << endl;
}

int main()
{
	char str[] = "We Are Happy.";
	int len = strlen(str);
	replaceSpace(str, len);
	replaceSpace1(str, len);
	system("pause");
	return 0;
}