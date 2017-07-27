#include<stdio.h>

int main()
{
	long long int number;
	int tc,T;
	scanf("%d",&T);
	for(tc=0;tc<T;tc++)
	{
		int hash[10]={0},digit[10]={0},count=0;
		scanf("%lld",&number);
		int i=1;
		for(i=1;i<10;i++)
		{
			if(number%i==0)
				hash[i]=1;
		}
		while(number>0)
		{
			digit[number%10]++;
			number/=10;
		}
		
		for(i=1;i<10;i++)
		{
			if(hash[i]==1)
				count+=digit[i];
		}
		printf("%d\n",count);
	}
	return 0;
}
