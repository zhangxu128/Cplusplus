//==================================================================
//文件名称:	LED循环右移
//功能说明: 发光二级管的闪烁
//硬件描述: P1口
//资源说明: 11.0592M晶体
//创建日期: 2018/10/9
//软件版本: v 1.1     
//==================================================================

#include<reg52.h>
#include<intrins.h>4

unsigned char a=0x7f;

void Delay_Ms(unsigned int n){
  unsigned int i;
	while(n--){
   for( i=0;i<113;i++);
  }
}

void main(){
  P1=a;
	while(1){
	  a=_cror_(a,1);
		P1=a;
		Delay_Ms(500);
	}
}