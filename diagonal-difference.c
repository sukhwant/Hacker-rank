#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j;
    scanf("%d",&n);
    int arr[102][102];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    int sum1=0,sum2=0;
    int start=0;
    while(start<n){
        sum1+=arr[start][start];
        start++;
    }
    start=n-1;
    int end=0;
    while(start>=0){
        sum2+=arr[end][start];
        start--;
        end++;
    }
    printf("%d\n",abs(sum1-sum2));
    return 0;
}
