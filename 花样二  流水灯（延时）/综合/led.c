//==================================================================
//�ļ�����:	LED��ʾ����
//����˵��: 
//Ӳ������:
//��Դ˵��: 11.0592M����
//��������: 2015/11/4
//����汾: v 1.1     
//==================================================================

//======================����ͷ�ļ�==================================

#include "led.h"
#include "delay.h"

//=============================����=================================		  
uchar LedState=0;				//��ʼ��״̬              
uchar LED_DisBuf=0xfe;			//��ʼ������	 
//==================================================================
//�� �� ��: Mn_Led_Player()
//��������: ���ֻ�����ˮ�Ƶ���ѭ
//�������: 
//�������:	
//�� �� �ߣ�
//�������ڣ�
//==================================================================
void Mn_Led_Player(void)
{  
	uint i;	                    
	switch(LedState)
	{
		case 0:					   
		{	
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf<<=1;
			LED_DisBuf=LED_DisBuf+1;
			if(LED_DisBuf==0x7f)
			{
				LedState=1;	
			}
		    break;
		}
		case 1:						
		{
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf>>=1;
			LED_DisBuf-=0x80;
			if(LED_DisBuf==0xfe)
			{
			 	LedState=2;
			}
			break;	
		}
		case 2:						
		{	
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf<<=1;
			if(LED_DisBuf==0)
			{
				LedState=3;	
			}		
			break;
		}
		case 3:						  
		{
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf<<=1;
	        LED_DisBuf++;
			if(LED_DisBuf==0xff)
			{
				LedState=4;	
			}
			break;
		}
	
		case 4:					      
		{	
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf>>=1;
			if(LED_DisBuf==0)
			{
				LedState=5;	
			}
			break;
		}
		case 5:					    
		{	
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf>>=1;
			LED_DisBuf+=0x80;
			if(LED_DisBuf==0xff)
			{
				LedState=6;
				LED_DisBuf=0xaa;	
			}
			break;
		}
		case 6:						   
		{							   
			i++;
			LED_port=LED_DisBuf;
			if(LED_DisBuf==0xaa)
			{
				LED_DisBuf=0x55;
			}
			else 
			{
				LED_DisBuf=0xaa;
			}
			if(i==7)
			{
				i=0;
				LedState=7;	
			}break;
		}
		case 7:
		{	
			LED_port=LED_DisBuf;
			delay(200);
			LED_DisBuf=0xfe;
			LedState=0;
			break;
		}
		default:break;		 
	}
}





