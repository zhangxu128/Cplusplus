//NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ��������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
//������Ľ�����
//��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
//������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
//�������� :
//��������������ݣ�ÿ������һ�У�Ϊ�յ������ġ�
//���Ľ��пո�ʹ�д��ĸ��ɡ�
//������� :
//��Ӧÿһ�����ݣ�������ܺ�����ġ�
//ʾ��1
//����
//HELLO WORLD
//SNHJ
//���
//CZGGJ RJMGY
//NICE

#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string s;
	while (getline(cin, s)) {
		string str = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				str += 'V';
				continue;
			}
			if (s[i] == 'B') {
				str += 'W';
				continue;
			}
			if (s[i] == 'C') {
				str += 'X';
				continue;
			}
			if (s[i] == 'D') {
				str += 'Y';
				continue;
			}
			if (s[i] == 'E') {
				str += 'Z';
				continue;
			}
			if (s[i] == ' ') {
				str += ' ';
				continue;
			}
			str += s[i] - 5;
		}
		cout << str << endl;
	}
	system("pause");
	return 0;
}