#include<iostream>

using namespace std;

//顺序表的定义
typedef struct SeqList
{
	int* array;  // 指向在堆上开辟的空间
	int capacity;  //顺序表的容量
	int size;  //顺序表的有效元素个数
}SeqList;

//顺序表的初始化
void SeqListInit(SeqList* p,int capacity)
{
	if (p->array != NULL)
	{
		p->array = (int*)malloc(sizeof(int)*capacity);
		p->capacity = capacity;
		p->size = 0;
	}
}

//打印顺序表的内容
void printSeqList(SeqList* p)
{
	cout << "顺序表的容量为" << p->capacity << "个" << endl;
	cout << "顺序表的有效元素为" << p->size << "个" << endl;
	for (int i = 0; i < p->size; i++)
	{
		cout << p->array[i] << " ";
	}
	cout << endl;
}

//顺序表的销毁
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

//头插入
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

//尾插入
void SeqListInsertBack(SeqList* p, int value)
{
	if (p->array == NULL)
	{
		return;
	}
	p->array[p->size] = value;
	p->size++;
}
//中间插入数据
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
//头删除
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

//尾删除
void SeqListDelBack(SeqList* p)
{
	if (p->array == NULL)
	{
		return;
	}
	p->size--;
}

//中间删除
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

//修改顺序表元素内容
void SeqListModify(SeqList* p, int pos, int value)
{
	if (p->array == NULL)
	{
		return;
	}
	p->array[pos] = value;
}
//查找
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
	cout << "请输入顺序表的容量：";
	cin >> capacity;
	SeqListInit(&ps,capacity);
	cout << "顺序表初始化后内容如下：" << endl;
	printSeqList(&ps);
	cout << "--------------------------" << endl;

	cout << "请输入头插入数据：";
	int value;
	cin >> value;
	SeqListInsertFront(&ps, value);
	cout << "请输入尾插入数据：";
	int value1;
	cin >> value1;
	SeqListInsertBack(&ps, value1);
	cout << "请输入中间插入的数据：";
	int value2;
	cin >> value2;
	cout << endl;
	cout << "请输入插入位置：";
	int pos;
	cin >> pos;
	SeqListInsertMid(&ps, value2, pos);
	printSeqList(&ps);

	cout << "请输入修改元素的下标：";
	int pos2;
	cin >> pos2;
	cout << "请输入要修改的值：";
	int value3;
	cin >> value3;
	SeqListModify(&ps, pos2, value3);
	printSeqList(&ps);

	cout << "请输入要查找的值：";
	int value4;
	cin >> value4;
	SeqListFind(&ps,value4);
	printSeqList(&ps);

	cout << "请输入中间删除的位置：";
	int pos1;
	cin >> pos1;
	SeqListDelMid(&ps, pos1);
	printSeqList(&ps);

	cout << "头删除" << endl;
	SeqListDelFront(&ps);
	printSeqList(&ps);

	cout << "尾删除" << endl;
	SeqListDelBack(&ps);
	printSeqList(&ps);

	system("pause");
	return 0;
}