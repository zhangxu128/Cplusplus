#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��������c���Ի�����дһ���򵥵��ʶ�С����
char buf[1024] = "";


//���ô�����ʽ
void showStyle()
{
	system("title �����ʶ�");
	system("mode con cols=80 lines=30");
	system("color f0");

}




//�����û�����
void inputInfo()
{
	memset(buf, 0, 1024);
	printf("����Ҫ���е���䣺");
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
		printf("��������Ϊ��%s\n", buf);
		fclose(fp);
	}
	system("pause");
	return 0;
}