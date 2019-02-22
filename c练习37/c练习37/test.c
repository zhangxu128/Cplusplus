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
#define Default_COUNT 3  //每次开辟内存大小
#define Default_INC 2    //默认大小

typedef char Persontype;

typedef struct PERSON
{
	Persontype Name[NameMax];//  姓名
	Persontype Sex[SexMax];  // 性别
	int Age;          // 年龄
	Persontype Tel[TelMax]; //联系方式
	Persontype Address[AddressMax]; //地址

}Person;

typedef struct BOOK
{
	Person* Data;//
	int count;    //当前已存储人数
	int cap;//存储容量
}Book;

void Initbook(Book* people); //初始化

void show_person(Book* people);//打印

void Add_person(Book *people);// 增加成员

void Del_person(Book* people);//删除成员

int Find_person(Book* people);//查找成员

void Change_person(Book* people);//修改成员

void BubbleSort_person(Book* people);//冒泡排序



//初始化
void Initbook(Book* people)
{
	people->count = 0;
	people->Data = (Person*)malloc(sizeof(Person));
	if (people->Data == NULL)
	{
		printf("开辟失败！\n");
		EXIT_FAILURE;
	}

	printf("申请成功！\n");
	memset(people->Data, 0, Default_COUNT * sizeof(people->Data));
	people->cap = Default_COUNT;
}

//打印
void show_person(Book* people)
{
	if (people == NULL)
	{
		printf("通讯录为空！\n");
		return;
	}
	if (people->count == 0)
	{
		printf("通讯录为空！\n");
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
int CheckCapacity(Book* people)          //查看容量
{
	if (people->count == people->cap)
	{
		Person* tmp = realloc(people->Data, (people->cap + Default_INC) * sizeof(Person));
		if (tmp != NULL)
		{
			people->Data = tmp;
			people->cap += Default_INC;
			printf("增容成功！\n");
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

//增加成员
void Add_person(Book *people)
{
	assert(people);
	if (CheckCapacity == 0)
	{
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", (people->Data[people->count]).Name);
	printf("请输入性别：\n");
	scanf("%s", (people->Data[people->count]).Sex);
	printf("请输入年龄：\n");
	scanf("%d", &(people->Data[people->count]).Age);
	printf("请输入联系方式：\n");
	scanf("%s", (people->Data[people->count]).Tel);
	printf("请输入住址：\n");
	scanf("%s", (people->Data[people->count]).Address);
	printf("增加成功！\n");
	people->count++;
	printf("count = %d\n", people->count);

}
//删除成员
void Del_person(Book* people)
{
	if (people == NULL)
	{
		printf("通讯录为空！\n");
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
		printf("没有该成员！\n");
	}
}

//查找成员
int Find_person(Book* people)
{
	assert(people);
	char name[20];
	printf("请输入姓名：\n");
	scanf("%s", name);
	int i = 0;
	for (; i < people->count; ++i)
	{
		if (strcmp(people->Data[i].Name, name) == 0)
		{
			printf("Name:%s\tSex:%s\tAge:%d\tTel:%s\tAddre:%s\n", people->Data[i].Name, people->Data[i].Sex, people->Data[i].Age, people->Data[i].Tel, people->Data[i].Address);
			return i;
			printf("下标为 %d\n", i);
		}
	}
	printf("没有找到该联系人！\n");
	return -1;
}

//修改成员
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
		printf("没有该成员！\n");
		return;
	}
}

void BubbleSort_person(Book* people)
{
	if (people == NULL)
	{
		printf("空通讯录！\n");
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
	printf("***     通讯录      *********************\n");
	printf("* 1、  增加成员     *********************\n");
	printf("* 2、  删除成员     *********************\n");
	printf("* 3、  查找成员     *********************\n");
	printf("* 4、  修改成员     *********************\n");
	printf("* 5、  显示成员     *********************\n");
	printf("* 6、  清空成员     *********************\n");
	printf("* 7、    排序       *********************\n");
	printf("* 8、    退出       *********************\n");
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
			printf("输入错误!\n");
			break;
		}
		}
	}
	return 0;
}
