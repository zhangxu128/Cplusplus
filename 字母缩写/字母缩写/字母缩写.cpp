#include<iostream>
#include<string>

//�������һ���ַ���s, �ַ�������length(1 �� length �� 50), �ַ�����ֻ����Сд��ĸ('a'~'z')�Ϳո�
//������� :
//���һ���ַ���, ����д�Ľ����
//ʾ��1
//����
//looks good to me
//���
//lgtm


using namespace std;
int main()
{
	//string str;
	//while (cin >> str)
	//{
	//	cout << str[0];
	//}


	string str;
	while (cin >> str) {
		bool show = true;
		for (int i = 0; i < str.size(); ++i) {
			if (' ' == str[i]) {
				show = true;
			}
			else {
				if (show) {
					cout << str[i];
					show = false;
				}
			}
		}
		// cout << endl;
	}

	return 0;
}