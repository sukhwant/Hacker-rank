#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int tc,T,n,i,res=1;
    
    scanf("%d",&T);
    for(tc=0;tc<T;tc++)
    {
        res = 1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                        if(i%2 == 0)
                               res *= 2;
                        else
                            res += 1;
                        }
        printf("%d\n",res);
        }
    return 0;
}
