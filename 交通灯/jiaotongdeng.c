#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char 
#define uint unsigned int 

//数码管定义
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};
uchar code weixuan[]={0x01,0x02,0x04,0x08};
uchar disbuf[4];


sbit yellowled_nb=P0^3;	//南北黄灯
sbit yellowled_dx=P0^0;	//东西黄灯
sbit greenled_nb=P0^4; //南北绿灯
sbit greenled_dx=P0^1;//东西绿灯
sbit K1=P3^0; //时间+1
sbit K2=P3^1;//时间-1
sbit K3=P3^6;//功能键选择

uchar  max_dx=10;//东西绿灯亮时间
uchar  max_nb=10;//南北绿灯亮时间
uchar  sec_nb;//南北数码管指示
uchar  sec_dx;//东西数码管指示

uchar flag_nb;
uchar flag_dx;//黄灯控制
uchar flag_all;//黄灯禁止
uchar t;//黄灯闪烁时间
int adjust_flag=-1;//功能选择


uchar flag1,flag2;//flag1为1秒定时,flag2黄灯闪烁
uchar data time,time1;//time为1秒定时,time1黄灯闪烁时间
bit  set=0;// 控制方向变量


void Delay_Ms(uchar ms)//延时函数
{
	uchar i;
  while(ms--)
  {
	 for(i=0;i<113;i++);
	}
}
//设置数码管
void adjust_smg()
{
  disbuf[1]=sec_nb/10; //十位
  if(disbuf[1]==0)
  { 
   disbuf[1]=10;
	}
  disbuf[0]=sec_nb%10; //个位
	//disbuf数组01是南北个十位
  disbuf[3]=sec_dx/10; //十位
  if(disbuf[3]==0)
  { 

    disbuf[3]=10;
	}
  disbuf[2]=sec_dx%10; //个位
}

void adjust_smg1()
{
    disbuf[1]=max_nb/10; 
		if(disbuf[1]==0)
		  {  
			  disbuf[1]=10;  
			}
    disbuf[0]=max_nb%10; 
		disbuf[3]=max_dx/10; 
		if(disbuf[3]==0)
		  {  
			disbuf[3]=10; 
			}
    disbuf[2]=max_dx%10;
}

void key1()//时间(+1)
{
  if(adjust_flag==0&&flag_all!=1)
   {	
		max_nb++; 
		if(max_nb==100)
		  max_nb=5;
	  }
	else if(adjust_flag==1&&flag_all!=1)
	{	
	max_dx++;
	if(	max_dx==100)
		max_dx=5;
	}
  if(adjust_flag!=-1&&flag_all!=1)
	{
	  adjust_smg1();
	}	
 }


void key2()//时间(-1)
{
  if(adjust_flag==0&&flag_all!=1)	
  {	
	 max_nb--;  
	 if(max_nb==4)
	 max_nb=99;
   }
	else if(adjust_flag==1&&flag_all!=1)
	{	
	 max_dx--;  
	 if(max_dx==4 )
		max_dx=99;
	}
	if(adjust_flag!=-1&&flag_all==0)
		{
		 adjust_smg1();
		}	
 }
 
void key3()//功能
{
  adjust_flag++;
  if(adjust_flag>=2)
  {
	adjust_flag=-1;
  }
  if(adjust_flag==-1)
  { 
	if(flag_all==1)
	  {	
	  flag_all=0;	
		}
	sec_nb=max_nb-5;	
	sec_dx=max_nb;
	TR0=1;
 	P0=0xeb;
	adjust_smg();
  }
  else
  {
  if(flag_all!=1)
  adjust_smg1();
  }
}

//按键选择


void key() 
{ 
 if(K1==0)
  {	
	Delay_Ms(10);
	if(K1==0)
	{ 
	 key1();
	 while(!K1);	
	 }  
	}
 if(K2==0)
  {  
	 Delay_Ms(10);
   if(K2==0)
    { 
		key2();
	  while(!K2);
	  } 
	}
 if(K3==0)
   { 
	 Delay_Ms(10);
   if(K3==0)
    { 
		TR0=0;
	  key3();
	  while(!K3);
	  }
  }
}


void adjust_Time()
{ 
  sec_dx--; sec_nb--;
	if(set==0)//南北通行
	{	
	  if(sec_nb==0)
	  {
		  if(flag_nb==0)
	    {	
 		   sec_nb=5;
	     flag_nb=1;//  南北黄灯控制
			 greenled_nb=1;  //  关绿灯
			 yellowled_nb=0;//黄灯亮
	    }
		  else
	    { 
		   flag_nb=0;//南北黄灯控清零
	     set=1;
	     sec_dx=max_dx-5;
	     sec_nb=max_dx;
	     P0=0xdd;
	    }	
	   } 	
   }
	else
	{ 
	  if(sec_dx==0)//东西通行
	  {
		  if(flag_dx==0)
	    { 
			  sec_dx=5;
	      flag_dx=1;//东西黄灯控制
	      greenled_dx=1;  // 东西关绿灯
				yellowled_dx=0;//  东西黄灯亮
	     }
	    else
	    {
		  flag_dx=0;//东西黄灯控制清零
	    set=0;
	    sec_dx=max_nb;
			sec_nb=max_nb-5;
	    P0=0xeb;
	    }
	  }
  }
	 adjust_smg();//刷新数码管指示
}


//数码管显示
void display()
{
  uchar i;
	for(i=0;i<4;i++)
	{
	 P1=0x00;
	 Delay_Ms(2);
	 P2=table[disbuf[i]];
	 P1=weixuan[i];
	 Delay_Ms(4);
	}
}

//黄灯闪烁
void yellowled()   
{
   if(flag_nb==1)   //南北黄灯标志
   {
   	yellowled_nb=~yellowled_nb;
	 }
	 else if(flag_dx==1)
	 {
	  yellowled_dx=~yellowled_dx;
	 }
	 if(flag_all==1)  //全部禁止
	 {
	   yellowled_nb=~yellowled_nb;
	   yellowled_dx=~yellowled_dx;
	   t++;  //黄灯闪烁时长
	   if(t>=12)
	   {
	    t=0;  TR0=0; P0=0xdb;
	   }	
	 }
}


void Init()//中断初始化
{	
  TMOD=0X61;
	TH0=0X3C;TL0=0XB0;
	TH1=0xff;TL1=0xff;
	ET0=1;	ET1=1;
	EX0=1;	IT0=1;
	EX1=1;	IT1=1;
	TR0=1;	TR1=1;
	EA=1;
	flag_nb=0;	flag_dx=0;
	set=0;//先设置南北方通行
	P0=0xeb;	      
	sec_nb=max_nb-5;	
	sec_dx=max_nb;
	adjust_smg();
}

void time0( ) interrupt 1 
{  
   TH0=0X3C; TL0=0XB0;
   time++;  time1++;
   //控制黄灯闪烁
   if(time1==10)
   { time1=0; flag2=1;  }
	   if(time==20)
	   {	
	    time=0;flag1=1;
	   }
}

void int0() interrupt 0 	//东西强行按键
{ 
   //外部中断0，定时器停止，数码管不显示，东西绿灯亮，南北红灯亮
   uchar i;   TR0=0;
   for(i=0;i<4;i++)
   {
	   disbuf[i]=10; 
	 }
   P0=0xdd;
}
//南北强行按键			  
void int1()interrupt 2 using 1
{ 
  //外部中断1，定时器停止，数码管不显示，南北绿灯亮，东西红灯亮
  uchar i;	TR0=0;
  for(i=0;i<4;i++)
   {   	
	   disbuf[i]=10;   
	 }
	P0=0xeb;
}

//全部禁止，紧急事件
void time2() interrupt 3
{  
   //全亮红灯
   uchar i;   TR0=1;
   flag_all=1;
   for(i=0;i<4;i++)
   {   	
	   disbuf[i]=10;
	 }
	 P0=0xf6;
}
 


void main()
{  
 Init();
 while(1)
 { 
   key();
   if(flag1==1&&flag_all!=1)	//正常情况
   {
	   adjust_Time();
		 flag1=0; 
	 }
   if(flag2==1)
   { 
	 yellowled();
   flag2=0;
	 }
   display(); 
 }
 
}



