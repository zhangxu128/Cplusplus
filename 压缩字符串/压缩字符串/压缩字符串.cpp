//����һ���ַ���ʹ��ԭ���㷨����ѹ����
//ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�
//�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1 ���ַ������� int �������ͣ���
//�����ԭ���޸���������󣬷���������³���
//ʾ�� 1��
//���룺
//["a", "a", "b", "b", "c", "c", "c"]
//�����
//����6�����������ǰ6���ַ�Ӧ���ǣ�["a", "2", "b", "2", "c", "3"]
//˵����
//"aa"��"a2"�����"bb"��"b2"�����"ccc"��"c3"�����
//ʾ�� 2��
//���룺
//["a"]
//�����
//����1�����������ǰ1���ַ�Ӧ���ǣ�["a"]
//˵����
//û���κ��ַ����������
//ʾ�� 3��
//���룺
//["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
//�����
//����4�����������ǰ4���ַ�Ӧ���ǣ�["a", "b", "1", "2"]��
//˵����
//�����ַ�"a"���ظ������Բ��ᱻѹ����"bbbbbbbbbbbb"����b12�������
//ע��ÿ�������������ж������Լ���λ�á�
//ע�⣺
//�����ַ�����һ��ASCIIֵ��[35, 126]�����ڡ�
//1 <= len(chars) <= 1000��


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//ѹ���ַ���
int compress(vector<char>& chars) {
	int start = 0, end, count, len = 0;
	while (start < chars.size()) {
		end = start + 1;
		while (end < chars.size() && chars[end] == chars[start])end++;
		count = end - start;
		chars[len++] = chars[start];
		if (count != 1) {
			string data = to_string(count);
			for (auto ch : data) {
				chars[len++] = ch;
			}
		}
		start = end;
	}
	return len;
}

int main(void) {

	cout << "������һ���ַ���" << endl;
	string s;
	cin >> s;
	vector<char> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i]);
	}
	cout << "ѹ���ַ������СΪ" << compress(v) << endl;
	system("pause");
	return 0;
}



