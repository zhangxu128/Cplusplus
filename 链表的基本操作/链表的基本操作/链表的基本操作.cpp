#include<iostream>

using namespace std;

//用Elemtype代替int  好处就是当int改变时，只需要改变一个int即可
typedef int Elemtype;
//链表节点的定义
typedef struct Node
{
	int value;
	struct Node* next;
}Node;

//初始化链表，没有一个节点的链表，即为空链表。
void LinkListInit(Node** p)
{
	*p = NULL;
}

//链表的销毁
void DestoryLinkList(Node** p)
{
	//销毁链表则要找一个临时变量保存当前的位置，这才能保证后面的节点位置信息不丢失
	Node* ptr;
	for (Node* cur = *p; cur != NULL; cur = ptr)
	{
		ptr = cur->next;
		free(cur);
	}
}
//打印节点值
void PrintLinkList(Node* p)
{
	if (p == NULL)
	{
		cout << "该链表为空链表。" << endl;
		return ;
	}
	while (p != NULL)
	{
		cout << p->value << " " << endl;
		p = p->next;
	}

}
//链表的头插法
void LinkListInsertFront(Node** p,int value)
{
	//构造节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = *p;
	*p = node;
}

//链表的尾插法
void LinkListInsertBack(Node** p, Elemtype value)
{
	//构造节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	if (*p == NULL) {
		// 链表中一个结点都没有
		*p = node;
		return;
	}


	//既然要尾插那么就要找到尾节点
	Node* cur = *p;
	for (; cur->next != NULL; cur = cur->next);
	//此时cur为尾节点
	cur->next = node;
	node->next = NULL;
}

//链表的中间插入，即插入到某个节点的后面
void LinkListInsertMid(Elemtype value,Node* pos)
{
	//构造节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	//先找到当前的节点位置
	node->next = pos->next;
	pos->next = node;
}

//链表的查找，返回当前节点的地址
Node* LinkListFind(Node* p, Elemtype value)
{
	//参数的合法性检验
	if (p == NULL)
	{
		return NULL;
	}
	Node* cur = p;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->value = value)
		{
			//此时cur为当前value的地址
			return cur;
		}
	}
	return NULL;

}

//头删
void LinkListDelFront(Node** p)
{
	if (*p == NULL)
	{
		return;
	}
	else
	{
		Node *next = (*p)->next;
		free(*p);
		*p = next;
	}
}

//尾删
void LinkListPopBack(Node** p)
{
	if (*p == NULL)
	{
		return;
	}
	if ((*p)->next == NULL) 
	{
		free(*p);
		*p = NULL;
		return;
	}

	// 找到倒数第二个结点
	// cur->next->next == NULL 停下来
	Node *cur = *p;
	while (cur->next->next != NULL) 
	{
		cur = cur->next;
	}

	// 释放最后一个结点
	free(cur->next);
	cur->next = NULL;
}

//中间删除(某个节点之后删除)
void LinkListDel(Node* p)
{
	Node *next = p->next;
	p->next = p->next->next;
	free(next);
}

int main()
{
	Node* node;
	cout << "链表已经初始化成功" << endl;;
	LinkListInit(&node);  //初始化
	PrintLinkList(node);

	cout << "请输入头插入的节点值：";
	Elemtype value;
	cin >> value;
	LinkListInsertFront(&node,value);//头插
	PrintLinkList(node);


	cout << "请输入尾插入的节点值：";
	Elemtype value1;
	cin >> value1;
	LinkListInsertBack(&node, value1);//尾插
	PrintLinkList(node);

	cout << "请输入您想要查找的节点值：";
	Elemtype value2;
	cin >> value2;
	Node* p = LinkListFind(node,value2);
	if (p == NULL)
	{
		cout << "没有找到该节点" << endl;
	}
	else
	{
		cout << "找到该节点" << endl;
	}

	cout << "请输入中间插入的节点值：";
	Elemtype value3;
	cin >> value3;
	cout << "请输入您想要插入的位置节点的值：";
	Elemtype value4;
	cin >> value4;
	Node* pp = LinkListFind(node, value4);
	LinkListInsertMid(value3,pp);//中间插入
	PrintLinkList(node);
	
	cout << "请输入您要删除节点的值：";
	int value5;
	cin >> value5;
	Node* ppp = LinkListFind(node, value5);
	cout << "删除" << value5 << "节点";
	LinkListDel(ppp);
	PrintLinkList(node);
	cout << "删除头节点" << endl;
	LinkListDelFront(&node);
	PrintLinkList(node);
	cout << "删除尾节点" << endl;
	LinkListPopBack(&node);
	PrintLinkList(node);
	
	system("pause");
	return 0;
}