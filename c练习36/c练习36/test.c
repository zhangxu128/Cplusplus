#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define NameMax 20
#define SexMax 3
#define TelMax 11
#define AddressMax 20
#define PeopleMax 1000

typedef char Persontype;

typedef struct PERSON
{
	Persontype Name[NameMax];//  ����
	Persontype Sex[SexMax];  // �Ա�
	int Age;          // ����
	Persontype Tel[TelMax]; //��ϵ��ʽ
	Persontype Address[AddressMax]; //��ַ

}Person;

typedef struct BOOK
{
	Person Data[PeopleMax];//Address_Book�ṹ�����洢����
	int count;    //��ǰ�Ѵ洢����
}Book;

void Initbook(Book* people); //��ʼ��

void show_person(Book* people);//��ӡ

void Add_person(Book *people);// ���ӳ�Ա

void Del_person(Book* people);//ɾ����Ա

int Find_person(Book* people);//���ҳ�Ա

void Change_person(Book* people);//�޸ĳ�Ա

void BubbleSort_person(Book* people);//ð������



//��ʼ��
void Initbook(Book* people)
{
	people->count = 0;
}

//��ӡ
void show_person(Book* people)
{
	if (people == NULL)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	if (people->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	int i = 0;
	for (; i <= people->count - 1; ++i)
	{
		printf("Name:%s\n", people->Data[i].Name);
		printf("Sex:%s\n", people->Data[i].Sex);
		printf("Age:%d\n", people->Data[i].Age);
		printf("Tel:%s\n", people->Data[i].Tel);
		printf("Addre:%s\n", people->Data[i].Address);
	}
	printf("\n");
}


//���ӳ�Ա
void Add_person(Book *people)
{
	assert(people);
	int i = 0;
	if (people->count > PeopleMax)
	{
		printf("ͨѶ¼������\n");
		return;
	}
	printf("������������\n");
	scanf("%s", (people->Data[people->count]).Name);
	printf("�������Ա�\n");
	scanf("%s", (people->Data[people->count]).Sex);
	printf("���������䣺\n");
	scanf("%d", &(people->Data[people->count]).Age);
	printf("��������ϵ��ʽ��\n");
	scanf("%s", (people->Data[people->count]).Tel);
	printf("������סַ��\n");
	scanf("%s", (people->Data[people->count]).Address);
	printf("���ӳɹ���\n");
	people->count++;
	printf("count = %d\n", people->count);

}
//ɾ����Ա
void Del_person(Book* people)
{
	if (people == NULL)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	int ret = Find_person(people);
	if (ret != -1)
	{
		int i = ret;
		for (; i < people->count - 1; ++i)
		{
			people->Data[i] = people->Data[i + 1];
		}
		people->count--;
		printf("count = %d\n", people->count);
	}
	else
	{
		printf("û�иó�Ա��\n");
	}
}

//���ҳ�Ա
int Find_person(Book* people)
{
	assert(people);
	char name[20];
	printf("������������\n");
	scanf("%s", name);
	int i = 0;
	for (; i < people->count; ++i)
	{
		if (strcmp(people->Data[i].Name, name) == 0)
		{
			printf("Name:%s\tSex:%s\tAge:%d\tTel:%s\tAddre:%s\n", people->Data[i].Name, people->Data[i].Sex, people->Data[i].Age, people->Data[i].Tel, people->Data[i].Address);
			return i;
			printf("�±�Ϊ %d\n", i);
		}
	}
	printf("û���ҵ�����ϵ�ˣ�\n");
	return -1;
}

//�޸ĳ�Ա
void Alter_person(Book* people)
{
	assert(people);
	int ret = Find_person(people);
	if (ret != -1)
	{
		printf("Name->:\n");
		scanf("%s", people->Data[ret].Name);
		printf("Sex->:\n");
		scanf("%s", people->Data[ret].Sex);
		printf("Age->:\n");
		scanf("%d", &(people->Data[ret]).Age);
		printf("Tel->:\n");
		scanf("%s", people->Data[ret].Tel);
		printf("Add->:\n");
		scanf("%s", people->Data[ret].Address);
	}
	else
	{
		printf("û�иó�Ա��\n");
		return;
	}
}

void BubbleSort_person(Book* people)
{
	if (people == NULL)
	{
		printf("��ͨѶ¼��\n");
		return;
	}
	int i = 0;
	for (; i < people->count - 1; ++i)
	{
		int j = 0;
		for (; j < people->count - 1 - i; ++j)
		{
			if (strcmp(people->Data[j].Name, people->Data[j + 1].Name) > 0)
			{
				char tmp[NameMax];
				strcpy(tmp, people->Data[j].Name);
				strcpy(people->Data[j].Name, people->Data[j + 1].Name);
				strcpy(people->Data[j + 1].Name, tmp);
			}
		}
	}
	show_person(people);
}

void menu()
{
	printf("***     ͨѶ¼      *********************\n");
	printf("* 1��  ���ӳ�Ա     *********************\n");
	printf("* 2��  ɾ����Ա     *********************\n");
	printf("* 3��  ���ҳ�Ա     *********************\n");
	printf("* 4��  �޸ĳ�Ա     *********************\n");
	printf("* 5��  ��ʾ��Ա     *********************\n");
	printf("* 6��  ��ճ�Ա     *********************\n");
	printf("* 7��    ����       *********************\n");
	printf("* 8��    �˳�       *********************\n");
}

int main()
{
	Book people;
	Initbook(&people);
	while (1)
	{
		menu();
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Add_person(&people);
			break;
		case 2:
			Del_person(&people);
			break;
		case 3:
			Find_person(&people);
			break;
		case 4:
			Alter_person(&people);
			break;
		case 5:
			show_person(&people);
			break;
		case 6:
			Initbook(&people);
			break;
		case 7:
			BubbleSort_person(&people);
			break;
		case 8:
			exit(0);
		default:
		{
			printf("�������!\n");
			break;
		}
		}
	}
	return 0;
}
