#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i;
    long long int temp,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&temp);
        sum+=temp;
    }
    printf("%lld\n",sum);
    return 0;
}
