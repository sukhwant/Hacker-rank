#include<stdio.h>
#include<limits.h>

#define N 10000

int main()
{
	int n,arr[N],smallest=INT_MAX,i,cut;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	cut=n;
	
	while(cut>0)
	{
		
		
		cut=0;
		smallest = INT_MAX;
		for(i=0;i<n;i++)
			if(arr[i]<smallest && arr[i] > 0)
				smallest = arr[i];
				
		for(i=0;i<n;i++)
		{
			if(arr[i]>0)
			{
				arr[i]-=smallest;
				cut++;
			}
		}
		if(cut>0)
			printf("%d\n",cut);
	}	
	return 0;
}
