#include<stdio.h>

int main()
{
	int tc,T;
	scanf("%d",&T);
	for(tc=0;tc<T;tc++)
	{
		long long int B,W,X,Y,Z,whiteCost,blackCost,totalCost;
		scanf("%lld %lld",&B,&W);
		scanf("%lld %lld %lld",&X,&Y,&Z);
		
		long long int convertB2W = X+Z;
		long long int convertW2B = Y+Z;
		
		if(convertB2W<Y)
			whiteCost = W*convertB2W;
		else
			whiteCost = W*Y;
		
		if(convertW2B<X)
			blackCost = B*convertW2B;
		else
			blackCost = B*X;
		
		totalCost = whiteCost + blackCost;
		
		printf("%lld\n",totalCost);
	}
	return 0;
}
