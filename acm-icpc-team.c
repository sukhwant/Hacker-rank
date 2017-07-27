#include<stdio.h>
#include<string.h>

int main()
{
	char arr[505][505];
	int n,m,i,j,k,max=0,total=0,count;
	char str1[505],str2[505];
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",arr[i]);
		
	for(i=0;i<n;i++)
	{
		strcpy(str1,arr[i]);
		for(j=i;j<n;j++)
		{
			count=0;
			strcpy(str2,arr[j]);
			for(k=0;k<m;k++)
			{
				if(str2[k]=='1' || str1[k]=='1')
					count++;
			}
			
			if(count==max)
				total++;
			else if(count>max)
			{
				max=count;
				total=1;
			}
		}
	}
	
	printf("%d\n%d\n",max,total);
	return 0;
}
