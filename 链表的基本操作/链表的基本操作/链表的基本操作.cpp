#include<iostream>

using namespace std;

//��Elemtype����int  �ô����ǵ�int�ı�ʱ��ֻ��Ҫ�ı�һ��int����
typedef int Elemtype;
//����ڵ�Ķ���
typedef struct Node
{
	int value;
	struct Node* next;
}Node;

//��ʼ������û��һ���ڵ��������Ϊ������
void LinkListInit(Node** p)
{
	*p = NULL;
}

//���������
void DestoryLinkList(Node** p)
{
	//����������Ҫ��һ����ʱ�������浱ǰ��λ�ã�����ܱ�֤����Ľڵ�λ����Ϣ����ʧ
	Node* ptr;
	for (Node* cur = *p; cur != NULL; cur = ptr)
	{
		ptr = cur->next;
		free(cur);
	}
}
//��ӡ�ڵ�ֵ
void PrintLinkList(Node* p)
{
	if (p == NULL)
	{
		cout << "������Ϊ������" << endl;
		return ;
	}
	while (p != NULL)
	{
		cout << p->value << " " << endl;
		p = p->next;
	}

}
//�����ͷ�巨
void LinkListInsertFront(Node** p,int value)
{
	//����ڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = *p;
	*p = node;
}

//�����β�巨
void LinkListInsertBack(Node** p, Elemtype value)
{
	//����ڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	if (*p == NULL) {
		// ������һ����㶼û��
		*p = node;
		return;
	}


	//��ȻҪβ����ô��Ҫ�ҵ�β�ڵ�
	Node* cur = *p;
	for (; cur->next != NULL; cur = cur->next);
	//��ʱcurΪβ�ڵ�
	cur->next = node;
	node->next = NULL;
}

//������м���룬�����뵽ĳ���ڵ�ĺ���
void LinkListInsertMid(Elemtype value,Node* pos)
{
	//����ڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	//���ҵ���ǰ�Ľڵ�λ��
	node->next = pos->next;
	pos->next = node;
}

//����Ĳ��ң����ص�ǰ�ڵ�ĵ�ַ
Node* LinkListFind(Node* p, Elemtype value)
{
	//�����ĺϷ��Լ���
	if (p == NULL)
	{
		return NULL;
	}
	Node* cur = p;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->value = value)
		{
			//��ʱcurΪ��ǰvalue�ĵ�ַ
			return cur;
		}
	}
	return NULL;

}

//ͷɾ
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

//βɾ
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

	// �ҵ������ڶ������
	// cur->next->next == NULL ͣ����
	Node *cur = *p;
	while (cur->next->next != NULL) 
	{
		cur = cur->next;
	}

	// �ͷ����һ�����
	free(cur->next);
	cur->next = NULL;
}

//�м�ɾ��(ĳ���ڵ�֮��ɾ��)
void LinkListDel(Node* p)
{
	Node *next = p->next;
	p->next = p->next->next;
	free(next);
}

int main()
{
	Node* node;
	cout << "�����Ѿ���ʼ���ɹ�" << endl;;
	LinkListInit(&node);  //��ʼ��
	PrintLinkList(node);

	cout << "������ͷ����Ľڵ�ֵ��";
	Elemtype value;
	cin >> value;
	LinkListInsertFront(&node,value);//ͷ��
	PrintLinkList(node);


	cout << "������β����Ľڵ�ֵ��";
	Elemtype value1;
	cin >> value1;
	LinkListInsertBack(&node, value1);//β��
	PrintLinkList(node);

	cout << "����������Ҫ���ҵĽڵ�ֵ��";
	Elemtype value2;
	cin >> value2;
	Node* p = LinkListFind(node,value2);
	if (p == NULL)
	{
		cout << "û���ҵ��ýڵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ýڵ�" << endl;
	}

	cout << "�������м����Ľڵ�ֵ��";
	Elemtype value3;
	cin >> value3;
	cout << "����������Ҫ�����λ�ýڵ��ֵ��";
	Elemtype value4;
	cin >> value4;
	Node* pp = LinkListFind(node, value4);
	LinkListInsertMid(value3,pp);//�м����
	PrintLinkList(node);
	
	cout << "��������Ҫɾ���ڵ��ֵ��";
	int value5;
	cin >> value5;
	Node* ppp = LinkListFind(node, value5);
	cout << "ɾ��" << value5 << "�ڵ�";
	LinkListDel(ppp);
	PrintLinkList(node);
	cout << "ɾ��ͷ�ڵ�" << endl;
	LinkListDelFront(&node);
	PrintLinkList(node);
	cout << "ɾ��β�ڵ�" << endl;
	LinkListPopBack(&node);
	PrintLinkList(node);
	
	system("pause");
	return 0;
}