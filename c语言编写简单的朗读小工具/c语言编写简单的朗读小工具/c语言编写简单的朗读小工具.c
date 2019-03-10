#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//任务：利用c语言基础编写一个简单的朗读小工具
char buf[1024] = "";


//设置窗口样式
void showStyle()
{
	system("title 语音朗读");
	system("mode con cols=80 lines=30");
	system("color f0");

}




//接受用户输入
void inputInfo()
{
	memset(buf, 0, 1024);
	printf("输入要朗诵的语句：");
	scanf("%s", &buf);
}



int main()
{
	showStyle();
	while (1)
	{
		FILE* fp = fopen("voice.vbs", "w");
		inputInfo();
		if (fp != NULL)
		{
			fprintf(fp, "CreateObject(\"SAPI.Spvoice\").Speak\"%s\"", buf);
			fclose(fp);
			system("voice.vbs");
			system("del voice.vbs");
		}
		printf("朗诵内容为：%s\n", buf);
		fclose(fp);
	}
	system("pause");
	return 0;
}