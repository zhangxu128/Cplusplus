//��Ŀ
//��Դ��ţ����
//��C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
//���������ĳ���Ա���Զ�ת����������
//�������� :
//��������������ݡ�
//ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��
//������� :
//��Ӧÿһ�����ݣ������������Ӧ��������������
//ʾ��1
//����
//hello_world
//nice_to_meet_you
//���
//helloWorld
//niceToMeetYou

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	while (cin >> s) {
		string str = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '_') {
				str += s[i];
			}
			else {
				i++;
				s[i] = s[i] - ('a' - 'A');
				str += s[i];
			}
		}
		cout << str << endl;
	}

	return 0;
}

