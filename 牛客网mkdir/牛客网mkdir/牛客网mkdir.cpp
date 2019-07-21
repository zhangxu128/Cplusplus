//���ӣ�https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
//��Դ��ţ����
//
//�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼�� / usr / local / bin��������Ҫ�˴δ����� / usr������ / usr / local���Լ��� / usr / local / bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ� - p��ѡ�ֻҪһ�����mkdir - p / usr / local / bin�������Զ�������Ҫ���ϼ�Ŀ¼��
//���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir - p�����
//
//�������� :
//
//��������������ݡ�
//
//ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)��
//
//������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ���
//
//
//������� :
//
//��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir - p�����
//
//ÿ������֮�����һ��������Ϊ�ָ���
//ʾ��1
//����
//
//3
/// a
/// a / b
/// a / b / c
//3
/// usr / local / bin
/// usr / bin
/// usr / local / share / bin
//���
//
//mkdir - p / a / b / c
//
//mkdir - p / usr / bin
//mkdir - p / usr / local / bin
//mkdir - p / usr / local / share / bin


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end());

		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1��������ͬ
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
				flag[i] = false;
		}

		for (int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}