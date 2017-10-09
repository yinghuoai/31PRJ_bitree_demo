#include "13demo6.h"



int add2(int a,int b)
{
	return a+b;
}

int add3(int a,int b,int c)
{
	return a+b+c;
	
}

int mul2(int a,int b)
{
	return a*b;
}

int mul3(int a,int b,int c)
{
	return a*b*c;
	
}

int value(int a)
{
	
	return a;
	
}


void f1()
{
	putstr("hello world!");
	
}



void putstr(char* str)
{
	
	int far* scr =(int far*)(0xb8000000+160*10+33*2);
	int n;
	
	for(n = 0;str[n];n++)
	{
		
		scr[n] = str[n]+(n+1)*0x100;
		
	}
	
}