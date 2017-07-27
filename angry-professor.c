#include<stdio.h>
int main()
{
	int tc,T;
	scanf("%d",&T);
	for(tc=0;tc<T;tc++)
	{
		int N,K,i,temp,count=0;
		scanf("%d %d",&N,&K);
		for(i=0;i<N;i++)
		{
			scanf("%d",&temp);
			if(temp<=0)
				count++;
		}
		if(count>=K)
			printf("NO\n");
		else
			printf("YES\n");
		
	}
}
