#include<iostream>
#include<ctime>

using namespace std;


//用new生成一个数组，数组里面的数随机生成，求该数组最大最小值
//要求时间复杂度为o(n)


//设计一个数组类
class Arr 
{
public:
	Arr(int len)
	{
		this->len = len;
		this->ptr = new int[len];
	}
	int getLen()
	{
		return this->len;
	}
	void setArr()
	{
		for (int i = 0; i < this->len; i++)
		{
			this->ptr[i] = rand() % len + 1;
		}
	}
	void printArr()
	{
		for (int i = 0; i < this->len; i++)
		{
			cout << this->ptr[i] << " ";
		}
		cout << endl;
	}
	~Arr()
	{
		if (this->ptr != NULL)
		{
			delete[] ptr;
			this->len = 0;
			ptr = NULL;
		}
	}
	//返回数组的最大的最小值,采用桶排序
	void getNum()
	{
		int lenth = this->len + 1;
		int * p_num = new int[lenth];
		for (int i = 0; i < lenth; i++)
		{
			p_num[i] = 0;
		}
		int temp;
		for (int i = 0; i < lenth; i++)
		{
			if (i < lenth - 1)
			{
				temp = this->ptr[i];
				p_num[temp]++;
			}
			else
			{
				break;
			}
			
		}
		for (int i = 0; i < lenth; i++)
		{
			if (p_num[i] != 0)
			{
				cout <<"该随机数组序列中最小的数是"<< i <<endl;
				break;
			}
			
		}
		for (int i = lenth-1; i >= 0; i--)
		{
			if (p_num[i] != 0)
			{
				cout << "该随机数组序列中最大的数是" << i << endl;
				break;
			}

		}
		if (p_num != NULL)
		{
			delete[] p_num;
			p_num = NULL;
		}
	}
private:
	int len;
	int* ptr;
};

void BubbleSort(int array[], int size);

int main()
{
	srand((unsigned int)time(0));
	cout << "请输入数组大小：";
	int n;
	cin >> n;
	Arr arr(n);
	arr.setArr();
	cout << "生成的数组随机数列为：" << endl;
	arr.printArr();
	arr.getNum();
	int arra[5] = { 1,4,21,5,2 };
	BubbleSort(arra, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arra[i]<<" ";
	}
	system("pause");
	return 0;
}




void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//假设数组有序
		int sorted = 1;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				sorted = 0;

			}
		}
		if (sorted == 1)
		{
			return;
		}
	}
}
