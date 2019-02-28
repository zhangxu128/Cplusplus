//==================================================================
//文件名称:	LED显示函数
//功能说明: 发光二级管的闪烁
//硬件描述: P1口
//资源说明: 11.0592M晶体
//创建日期: 2018/10/9
//软件版本: v 1.1     
//==================================================================

#include<reg52.h>
#include<intrins.h>
unsigned char a=0xfe;

void Delay_Ms(int n);
void main(){
		 P1 = a;
		 while(1){
		   a=_crol_(a,1);
		   P1=a;
		   Delay_Ms(500);
		}
		
}
void Delay_Ms(int n)
{
	int data i,j;
	for(i=0;i<n;i++)
	for(j=0;j<113;j++);
}