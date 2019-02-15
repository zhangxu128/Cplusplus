//==================================================================
//文件名称:	综合显示
//功能说明: 数码管显示
//硬件描述: P0口
//资源说明: 11.0592M晶体
//创建日期: 2018/10/9
//软件版本: v 1.1     
//==================================================================
#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char 
#define uint unsigned int

void Delay_Ms(uint n);



//录入数码管字形码
uchar code SegCode[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x73,0x80,0x00};
sbit dula = P2^6;   //锁存器
sbit wela = P2^7; 
uchar a=0xfe;
sbit b=P2^3;
uchar num;

void Delay_Ms(uint n)
{
	int data i,j;
	for(i=0;i<n;i++)
	for(j=0;j<113;j++);
}


void FengMingQi(){

	 b=~b;
   Delay_Ms(1000);
}



void led(){
		 P1 = a;
		 while(1){
		   a=_crol_(a,1);
		   P1=a;
		   Delay_Ms(500);
		}
		
}

void main()
{
  wela = 1;
	P0 = 0x00;
	wela = 0;
	while(1)
	{
		for(num = 0;num<19;num++)
		{
			dula = 1;
			P0 = SegCode[num];
		  Delay_Ms(500);
			dula = 0;
		}
		FengMingQi();
		led();
		
	}
}