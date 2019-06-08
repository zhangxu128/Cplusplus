//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	/*stack<int>s;
	int j = 0;
	for (int i = 0; i < pushV.size(); i++) {
		s.push(pushV[i]);
		while (!s.empty() && s.top() == popV[j]) {
			s.pop();
			j++;
		}
	}
	return s.empty();*/


	//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
	if (pushV.size() != popV.size())
		return false;

	// ��s��ģ����ջ���ջ�Ĺ���
	int outIdx = 0;
	int inIdx = 0;
	stack<int> s;

	while (outIdx < popV.size())
	{
		// ���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
		while (s.empty() || s.top() != popV[outIdx])
		{
			if (inIdx < pushV.size())
				s.push(pushV[inIdx++]);
			else
				return false;
		}

		// ջ��Ԫ�����ջ��Ԫ����ȣ���ջ
		s.pop();
		outIdx++;
	}

	return true;
}

int main(void) {
	cout << "��������Ԫ�أ�" << endl;
	int n;
	cin >> n;
	vector<int>v1(n), v2(n);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
		cin >> v2[i];
	}
	cout << IsPopOrder(v1, v2) << endl;
	system("pause");
	return 0;
}