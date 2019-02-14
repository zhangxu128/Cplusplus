#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char 
#define uint unsigned int 

//����ܶ���
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};
uchar code weixuan[]={0x01,0x02,0x04,0x08};
uchar disbuf[4];


sbit yellowled_nb=P0^3;	//�ϱ��Ƶ�
sbit yellowled_dx=P0^0;	//�����Ƶ�
sbit greenled_nb=P0^4; //�ϱ��̵�
sbit greenled_dx=P0^1;//�����̵�
sbit K1=P3^0; //ʱ��+1
sbit K2=P3^1;//ʱ��-1
sbit K3=P3^6;//���ܼ�ѡ��

uchar  max_dx=10;//�����̵���ʱ��
uchar  max_nb=10;//�ϱ��̵���ʱ��
uchar  sec_nb;//�ϱ������ָʾ
uchar  sec_dx;//���������ָʾ

uchar flag_nb;
uchar flag_dx;//�Ƶƿ���
uchar flag_all;//�Ƶƽ�ֹ
uchar t;//�Ƶ���˸ʱ��
int adjust_flag=-1;//����ѡ��


uchar flag1,flag2;//flag1Ϊ1�붨ʱ,flag2�Ƶ���˸
uchar data time,time1;//timeΪ1�붨ʱ,time1�Ƶ���˸ʱ��
bit  set=0;// ���Ʒ������


void Delay_Ms(uchar ms)//��ʱ����
{
	uchar i;
  while(ms--)
  {
	 for(i=0;i<113;i++);
	}
}
//���������
void adjust_smg()
{
  disbuf[1]=sec_nb/10; //ʮλ
  if(disbuf[1]==0)
  { 
   disbuf[1]=10;
	}
  disbuf[0]=sec_nb%10; //��λ
	//disbuf����01���ϱ���ʮλ
  disbuf[3]=sec_dx/10; //ʮλ
  if(disbuf[3]==0)
  { 

    disbuf[3]=10;
	}
  disbuf[2]=sec_dx%10; //��λ
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

void key1()//ʱ��(+1)
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


void key2()//ʱ��(-1)
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
 
void key3()//����
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

//����ѡ��


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
	if(set==0)//�ϱ�ͨ��
	{	
	  if(sec_nb==0)
	  {
		  if(flag_nb==0)
	    {	
 		   sec_nb=5;
	     flag_nb=1;//  �ϱ��Ƶƿ���
			 greenled_nb=1;  //  ���̵�
			 yellowled_nb=0;//�Ƶ���
	    }
		  else
	    { 
		   flag_nb=0;//�ϱ��Ƶƿ�����
	     set=1;
	     sec_dx=max_dx-5;
	     sec_nb=max_dx;
	     P0=0xdd;
	    }	
	   } 	
   }
	else
	{ 
	  if(sec_dx==0)//����ͨ��
	  {
		  if(flag_dx==0)
	    { 
			  sec_dx=5;
	      flag_dx=1;//�����Ƶƿ���
	      greenled_dx=1;  // �������̵�
				yellowled_dx=0;//  �����Ƶ���
	     }
	    else
	    {
		  flag_dx=0;//�����Ƶƿ�������
	    set=0;
	    sec_dx=max_nb;
			sec_nb=max_nb-5;
	    P0=0xeb;
	    }
	  }
  }
	 adjust_smg();//ˢ�������ָʾ
}


//�������ʾ
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

//�Ƶ���˸
void yellowled()   
{
   if(flag_nb==1)   //�ϱ��ƵƱ�־
   {
   	yellowled_nb=~yellowled_nb;
	 }
	 else if(flag_dx==1)
	 {
	  yellowled_dx=~yellowled_dx;
	 }
	 if(flag_all==1)  //ȫ����ֹ
	 {
	   yellowled_nb=~yellowled_nb;
	   yellowled_dx=~yellowled_dx;
	   t++;  //�Ƶ���˸ʱ��
	   if(t>=12)
	   {
	    t=0;  TR0=0; P0=0xdb;
	   }	
	 }
}


void Init()//�жϳ�ʼ��
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
	set=0;//�������ϱ���ͨ��
	P0=0xeb;	      
	sec_nb=max_nb-5;	
	sec_dx=max_nb;
	adjust_smg();
}

void time0( ) interrupt 1 
{  
   TH0=0X3C; TL0=0XB0;
   time++;  time1++;
   //���ƻƵ���˸
   if(time1==10)
   { time1=0; flag2=1;  }
	   if(time==20)
	   {	
	    time=0;flag1=1;
	   }
}

void int0() interrupt 0 	//����ǿ�а���
{ 
   //�ⲿ�ж�0����ʱ��ֹͣ������ܲ���ʾ�������̵������ϱ������
   uchar i;   TR0=0;
   for(i=0;i<4;i++)
   {
	   disbuf[i]=10; 
	 }
   P0=0xdd;
}
//�ϱ�ǿ�а���			  
void int1()interrupt 2 using 1
{ 
  //�ⲿ�ж�1����ʱ��ֹͣ������ܲ���ʾ���ϱ��̵��������������
  uchar i;	TR0=0;
  for(i=0;i<4;i++)
   {   	
	   disbuf[i]=10;   
	 }
	P0=0xeb;
}

//ȫ����ֹ�������¼�
void time2() interrupt 3
{  
   //ȫ�����
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
   if(flag1==1&&flag_all!=1)	//�������
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



