#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//���һ���ֿ���Ʒ��
class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "������һ����Ϊ" << 0 << "����Ʒ" << endl;
	}
	Goods(int w)
	{
		this->weight = w;
		next = NULL;
		cout << "������һ����Ϊ" << w << "�Ļ���" << endl;
		total_weight += w;
		
	}
	~Goods()
	{
		cout << "�۳���Ϊ" << weight << "�Ļ���" << endl;
		total_weight -= weight;
	}
	static int get_total_weight()
	{
		return total_weight;
	}
	Goods* next;
private:
	int weight;//��Ʒ����
	static int total_weight;//��Ʒ������
};

int Goods::total_weight = 0;

void add(Goods* &head, int w)
{
//����һ������
	Goods* new_goods = new Goods(w);
	if (head == NULL)
	{
		head = new_goods;
	}
	else 
	{
		new_goods->next = head;
		head = new_goods;
	}
}

void sale(Goods* &head)
{
	if (head == NULL)
	{
		cout << "�ֿ����Ѿ�û�л�����" << endl;
		return;
	}
	Goods* tem = head;
	head = head->next;
	delete tem;
	cout << "�����ɹ�" << endl;
}

int main()
{
	int choice = 0;
	Goods* head = NULL;
	do
	{
		cout << "1    ����" << endl;
		cout << "2    ����" << endl;
		cout << "0    �˳�" << endl;

		cin >> choice;
		if (choice == 1)
		{
		//����
			cout << "��������Ʒ��������" << endl;
			int w = 0;
			cin >> w;
			add(head, w);
		}
		if (choice == 2)
		{
		//����
			sale(head);
		}
		if (choice == 0)
		{
			break;
		}
		cout << "��ǰ��Ʒ��������Ϊ" << Goods::get_total_weight() << endl;
	} while (1);
	system("pause");
	return 0;
}