//��Ŀ����
//��������һ���϶̵��Ӵ�������һ���ϳ����ַ������ж϶̵��ַ����Ƿ��ܹ��ɳ��ַ����е��ַ������������ҳ����е�ÿ���ַ�ֻ����һ�Ρ�
//�������� :
//һ�����ݰ���һ���϶̵��ַ���S��һ���ϳ����ַ���T����һ���ո�ָ�����֤1<=|S|<=|T|<=100000��
//������� :
//����̵��ַ��������ɳ��ַ����е��ַ���������������ַ��� ��true������������ַ��� "false"��
//ʾ��1
//����
//a b
//���
//false
//ʾ��2
//����
//fj jfiejfiejfie
//���
//true

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		bool res = true;
		vector<int> va(256, 0);
		vector<int> vb(256, 0);
		for (int i = 0; i < a.size(); i++)
			va[a[i]] ++;
		for (int i = 0; i < b.size(); i++)
			vb[b[i]] ++;
		for (int i = 0; i < 256; i++)
			if (va[i] > vb[i])
				res = false;
		if (res)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}
