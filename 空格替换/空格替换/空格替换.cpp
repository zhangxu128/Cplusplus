#include<iostream>
using namespace std;

//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.
//�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++) {   //����ո���
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--) {
			if (str[i] != ' ') {
				str[i + 2 * count] = str[i];   //�ƶ�λ��
			}
			else {
				count--;
				str[i + 2 * count] = '%';		//�ַ��滻
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}
	}
};

int main()
{
	char str[] = "we are very  happy!";
	int len = strlen(str);
	Solution s;
	s.replaceSpace(str, len+1);
	cout << str << endl;
	system("pause");
	return 0;
}