//��Ŀ
//����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
//����
//1�� ��¼���8�������¼��ѭ����¼������ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
//2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
//3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����
//�������� :
//һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
//������� :
//�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺
//ʾ��1
//����
//E : \V1R2\product\fpgadrive.c   1325
//���
//	fpgadrive.c 1325 1

//����˼·�ܼ򵥣������Ͼ��ǰ������ݴ�����������¼��ͬ�������������������ظ��ľ����� + 1��
//�ؼ�����ʵ���ϣ����������ַ������������ǰ󶨵ģ�����Ҫ��һ���ṹ�����洢���ǣ�
//�Ա���ͬʱ�����ַ�����ʱ������޸���������������ֱ�Ӱ��ļ������к����ӳ�һ���ַ�����
//����Ҫ�ֳ������ַ������Աȡ���find���������Զ������ͱ���Ҫ���ء� == ����
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct ErrMsg {
	string fname;
	int num;

	ErrMsg(string fname) {
		this->fname = fname;
		this->num = 1;
	}

	bool operator==(const ErrMsg & a) {
		return fname == a.fname;
	}
};
int main()
{
	string dirName, lineNum;
	vector<ErrMsg> v;
	while (cin >> dirName >> lineNum)
	{
		string fileName = dirName.substr(dirName.find_last_of("\\") + 1);
		if (fileName.size() > 16) fileName.erase(fileName.begin(), fileName.end() - 16);
		fileName = fileName + " " + lineNum;//���ļ������к����ӳ�һ���ַ���
		ErrMsg er(fileName);
		auto it = find(v.begin(), v.end(), er);
		if (it == v.end())
			v.push_back(er);
		else (*it).num++;
	}
	if (v.size() <= 8 && v.size() >= 0)
		for (auto e : v) cout << e.fname << " " << e.num << endl;
	else if (v.size() > 8)
		for (auto ite = v.end() - 8; ite < v.end(); ite++) cout << (*ite).fname << " " << (*ite).num << endl;
	system("pause");
	return 0;
}