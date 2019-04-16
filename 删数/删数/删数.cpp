#include<iostream>
using namespace std;

//��Ŀ����
//��һ������a[N]˳����0~N - 1��Ҫ��ÿ��������ɾ��һ������
//��ĩβʱѭ������ͷ�������У������һ����ɾ��������ԭʼ�±�λ�á�
//��8����(N = 7)Ϊ��:��0��1��2��3��4��5��6��7����0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),
//���ѭ��ֱ�����һ������ɾ����
//�������� :
//ÿ������Ϊһ��һ������n(С�ڵ���1000)��Ϊ�����Ա��, �������1000�����a[999]���м��㡣

#define null 0
struct node
{
	int data;
	node* next;
};

int delnum(int size) {
	node* head = new node;
	head->data = 0;
	head->next = null;
	node* p = head;
	for (int i = 1; i < size; i++)
	{
		node* tmp = new node;
		tmp->data = i;
		tmp->next = null;
		head->next = tmp;
		head = head->next;
	}
	head->next = p;
	while (p != p->next)
	{
		p->next->next = p->next->next->next;
		p = p->next->next;
	}
	return p->data;
}

int main(void) {

	int n = 0;
	cin >> n;
	if (n >= 1000) {
		n = 999;
	}
	int ret = delnum(n);
	cout << ret << endl;
	system("pause");
	return 0;
}