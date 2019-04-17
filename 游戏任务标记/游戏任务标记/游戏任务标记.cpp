#include <iostream>
using namespace std;


//��Ŀ����
//��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ�
//��������һ����1024��������ID��Χ[1, 1024]������32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ�
//��ʼ״̬����δ��ɡ� ����������������������ID����Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ�
//�����ڶ���ID�������Ƿ��Ѿ���ɡ� ���һ��������
//����ڶ���ID�������Ѿ�������1�����δ������0�������һ��ڶ���ID����[1, 1024]��Χ������� - 1��

int main() {
	//λͼ   ���������
	unsigned int task_flag[32] = { 0 };

	int id1, id2;
	while (cin >> id1 >> id2) {  //����ĺϷ��Լ���
		if (id1 > 1024 || id1 < 1 || id2 > 1024 || id2 < 1) {
			cout << -1 << endl;
			break;
		}

		int index = (id1 - 1) / 32;
		int bit = (id1 - 1) % 32;
		task_flag[index] |= 1 << bit;         // ��������

		index = (id2 - 1) / 32;
		bit = (id2 - 1) % 32;
		//cout << (1 << bit & task_flag[index]) << endl;  ���д��
		if (1 << bit & task_flag[index]) {    // �������
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}