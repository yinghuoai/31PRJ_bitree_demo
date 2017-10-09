#include <stdio.h>

#define MAXNUM 30

int falsecoin(int coin[],int low,int high)
{
	int i,sum1,sum2,sum3;
	int ret;
	
	sum1 = sum2 = sum3 = 0;
	
	if(low+1 == high)			/*** 如果只有两个硬币 ***/
	{

		if(coin[low] < coin[high]  )	/*** 如果低位硬币重量小，也就是低位硬币为假币，返回序号 ***/
		{
			ret = low+1;
			return ret;			
				
			
		}
		else							/***反之，如果高位硬币重量小，也就是高位硬币是假币，返回序号  ***/
		{
			ret =high+1;
			return ret;
			
		}
		
	}
	
	if((high-low+1)%2 == 0)        /*** 如果硬币的数目是大于2的偶数   ***/
	{
		for(i=low ; i<=low+(high-low)/2 ; i++)		  /*** 前半段和   ***/
		{
			sum1 = sum1+coin[i];
			
		}
		
		for(i=low+(high-low)/2+1 ; i<=high ; i++)		  /***  后半段和  ***/
		{
			sum2 = sum2+coin[i];
			
		}
		
		sum3 = coin[low+(high-low)/2];
		
		
		if(sum1 > sum2)		  /***  假币在后半段，所以下一次查找应该放弃前半段，转向后半段  ***/
		{
			ret = falsecoin(coin,low+(high-low)/2+1,high);
			return ret;
			
		}
		else if(sum1 < sum2)	  /***  假币在前半段，所以下一次查找应该放弃后半段，转向前半段  ***/
		{
			ret = falsecoin(coin,low,low+(high-low)/2);
			return ret;
			
		}
		else
		{
			
		}
		
		
		if(sum1+sum3 == sum2+sum3)
		{
			ret = low+(high-low)/2+1;
			return ret;
			
		}
		
		
		
		
		
	}
	

	
	
	
}


int main()
{
	int coin[MAXNUM];
	int i,n;
	int pos;
	
	printf("分治算法求解假银币问题！\n");
	printf("请输入银币总的个数：");
	scanf("%d",&n);
	printf("请输入银币的真假：");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&n);
		
		
	}
	
	pos = falsecoin(coin,0,n-1);
	printf("在上述%d个银币中，第%d个银币是假的\n",n,pos);
	
	
	
	
	return 0;
	
}




















