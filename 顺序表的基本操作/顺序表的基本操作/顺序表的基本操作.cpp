#include<iostream>

using namespace std;

//˳���Ķ���
typedef struct SeqList
{
	int* array;  // ָ���ڶ��Ͽ��ٵĿռ�
	int capacity;  //˳��������
	int size;  //˳������ЧԪ�ظ���
}SeqList;

//˳���ĳ�ʼ��
void SeqListInit(SeqList* p,int capacity)
{
	if (p->array != NULL)
	{
		p->array = (int*)malloc(sizeof(int)*capacity);
		p->capacity = capacity;
		p->size = 0;
	}
}

//��ӡ˳��������
void printSeqList(SeqList* p)
{
	cout << "˳��������Ϊ" << p->capacity << "��" << endl;
	cout << "˳������ЧԪ��Ϊ" << p->size << "��" << endl;
	for (int i = 0; i < p->size; i++)
	{
		cout << p->array[i] << " ";
	}
	cout << endl;
}

//˳��������
void DestorySeqList(SeqList* p)
{
	if (p->array != NULL)
	{
		free(p->array);
		p->array = NULL;
		p->capacity = 0;
		p->size = 0;
	}
}

//ͷ����
void SeqListInsertFront(SeqList* p,int value)
{
	if (p->array == NULL)
	{
		return ;
	}
	for (int i = p->size - 1; i >= 0; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[0] = value;
	p->size++;
}

//β����
void SeqListInsertBack(SeqList* p, int value)
{
	if (p->array == NULL)
	{
		return;
	}
	p->array[p->size] = value;
	p->size++;
}
//�м��������
void SeqListInsertMid(SeqList* p, int value,int pos)
{
	if (p->array == NULL)
	{
		return;
	}
	for (int i = p->size - 1; i >= pos; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[pos] = value;
	p->size++;
}
//ͷɾ��
void SeqListDelFront(SeqList* p)
{
	if (p->array == NULL)
	{
		return;
	}
	for (int i = 1; i < p->size; i++)
	{
		p->array[i-1] = p->array[i];
	}
	p->size--;
}

//βɾ��
void SeqListDelBack(SeqList* p)
{
	if (p->array == NULL)
	{
		return;
	}
	p->size--;
}

//�м�ɾ��
void SeqListDelMid(SeqList* p,int pos)
{
	if (p->array == NULL)
	{
		return;
	}
	for (int i = pos; i < p->size; i++)
	{
		p->array[i] = p->array[i + 1];
	}
	p->size--;
}

//�޸�˳���Ԫ������
void SeqListModify(SeqList* p, int pos, int value)
{
	if (p->array == NULL)
	{
		return;
	}
	p->array[pos] = value;
}
//����
bool SeqListFind(SeqList* p, int value)
{
	if (p->array == NULL)
	{
		return false;
	}
	for (int i = 0; i < p->size; i++)
	{
		if (p->array[i] == value)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	SeqList ps;
	int capacity;
	cout << "--------------------------" << endl;
	cout << "������˳����������";
	cin >> capacity;
	SeqListInit(&ps,capacity);
	cout << "˳����ʼ�����������£�" << endl;
	printSeqList(&ps);
	cout << "--------------------------" << endl;

	cout << "������ͷ�������ݣ�";
	int value;
	cin >> value;
	SeqListInsertFront(&ps, value);
	cout << "������β�������ݣ�";
	int value1;
	cin >> value1;
	SeqListInsertBack(&ps, value1);
	cout << "�������м��������ݣ�";
	int value2;
	cin >> value2;
	cout << endl;
	cout << "���������λ�ã�";
	int pos;
	cin >> pos;
	SeqListInsertMid(&ps, value2, pos);
	printSeqList(&ps);

	cout << "�������޸�Ԫ�ص��±꣺";
	int pos2;
	cin >> pos2;
	cout << "������Ҫ�޸ĵ�ֵ��";
	int value3;
	cin >> value3;
	SeqListModify(&ps, pos2, value3);
	printSeqList(&ps);

	cout << "������Ҫ���ҵ�ֵ��";
	int value4;
	cin >> value4;
	SeqListFind(&ps,value4);
	printSeqList(&ps);

	cout << "�������м�ɾ����λ�ã�";
	int pos1;
	cin >> pos1;
	SeqListDelMid(&ps, pos1);
	printSeqList(&ps);

	cout << "ͷɾ��" << endl;
	SeqListDelFront(&ps);
	printSeqList(&ps);

	cout << "βɾ��" << endl;
	SeqListDelBack(&ps);
	printSeqList(&ps);

	system("pause");
	return 0;
}