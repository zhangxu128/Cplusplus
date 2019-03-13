#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//设计一个仓库物品类
class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "创建了一个重为" << 0 << "的物品" << endl;
	}
	Goods(int w)
	{
		this->weight = w;
		next = NULL;
		cout << "创建了一个重为" << w << "的货物" << endl;
		total_weight += w;
		
	}
	~Goods()
	{
		cout << "售出重为" << weight << "的货物" << endl;
		total_weight -= weight;
	}
	static int get_total_weight()
	{
		return total_weight;
	}
	Goods* next;
private:
	int weight;//物品重量
	static int total_weight;//物品总重量
};

int Goods::total_weight = 0;

void add(Goods* &head, int w)
{
//创建一个货物
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
		cout << "仓库中已经没有货物了" << endl;
		return;
	}
	Goods* tem = head;
	head = head->next;
	delete tem;
	cout << "出货成功" << endl;
}

int main()
{
	int choice = 0;
	Goods* head = NULL;
	do
	{
		cout << "1    进货" << endl;
		cout << "2    出货" << endl;
		cout << "0    退出" << endl;

		cin >> choice;
		if (choice == 1)
		{
		//进货
			cout << "请输入物品的重量：" << endl;
			int w = 0;
			cin >> w;
			add(head, w);
		}
		if (choice == 2)
		{
		//出货
			sale(head);
		}
		if (choice == 0)
		{
			break;
		}
		cout << "当前物品的总重量为" << Goods::get_total_weight() << endl;
	} while (1);
	system("pause");
	return 0;
}