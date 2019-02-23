#include<reg52.h>
#define uint unsigned int

sbit a=P2^3;

void Delay_Ms(uint n){
 uint i;
 while(n--){
   for(i=0;i<113;i++);
   }
}

void main(){
  while(1){
	 a=~a;
	 Delay_Ms(1000);
  } 
}
