#include<stdio.h>
#define N 100001

int main()
{
	int arr1[N],arr2[N];
	int n,k,q,i,query,res;

	scanf("%d%d%d",&n,&k,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
		arr2[i]=arr1[i];
	}
	
	k=k%n;
	
	for(i=0;i<q;i++)
	{
		scanf("%d",&query);
		res=query-k;
		if(res<0)
			res=res+n;

		printf("%d\n",arr1[res]);
	}
	return 0;
}
