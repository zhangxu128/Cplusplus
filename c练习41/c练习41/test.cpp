#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	string re = "";
	if (strs.empty())
		return re;
	if (strs.size() == 1)
	{
		re += strs.at(0);
		return re;
	}
	int jishu = 0;
	int arrsize = strs.at(0).size();
	for (int p = 1; p < strs.size(); p++)
	{
		if (arrsize > strs.at(p).size())
			arrsize = strs.at(p).size();
	}
	for (int k = 0, zm = 0, jn = 0; k < strs.size() - 1; k++)
	{

		while (zm < arrsize&&strs[k][zm] == strs[k + 1][zm])
		{
			jn++;
			zm++;
			if (zm >= arrsize)
				break;
		}
		if (k == 0)
			jishu = jn;
		else if (jn < jishu)
			jishu = jn;
		zm = 0;
		jn = 0;
	}


	for (int ff = 0; ff < jishu; ff++)
		re += strs[0][ff];
	return re;
}


int main()
{
	/*��дһ�������������ַ��������е������ǰ׺��

		��������ڹ���ǰ׺�����ؿ��ַ��� ""��

		ʾ�� 1:

    ����: ["flower", "flow", "flight"]
	��� : "fl"
	ʾ�� 2 :

	���� : ["dog", "racecar", "car"]
	��� : ""
	���� : ���벻���ڹ���ǰ׺��*/

	//vector<string> str;
	//vector<string>::iterator it; 
	string a[3] = { "flower","flow","flight" };
	//string a[3]={"dog","racecar","car"};
	//string a="a";
	vector<string> str;
	//str.push_back(a);
	//cout<<str.at(0)<<endl;

	for (int nn = 0; nn < 3; nn++)
	{
		str.push_back(a[nn]);
		//cout<<str.at(nn)<<endl;
	}
	/*
	string putstr;
					//�û��Զ����յ�����vector�����е�string�����
	while(cin>>putstr)
	{
	str.push_back(putstr);
	}
	*/
	string bbbb = longestCommonPrefix(str);
	cout << bbbb << endl;
	system("pause");
	return 0;
}