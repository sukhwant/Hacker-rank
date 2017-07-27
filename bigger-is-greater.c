#include<stdio.h>
#include<string.h>
char str[105];

int main(){

	int tc,T;
	scanf("%d",&T);
	for(tc=0;tc<T;tc++){
		int iIndex=0,i,j,jIndex=0,flag=0;
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++){
			if(str[i]<str[i+1]){
				iIndex=i;
				flag=1;
			}
		}
		
		for(j=iIndex;str[j]!='\0';j++){
			if(str[j]>str[iIndex]){
				jIndex=j;
			}
		}
		
		//swap s[iIndex] with s[jIndex]
		char temp=str[iIndex];
		str[iIndex]=str[jIndex];
		str[jIndex]=temp;
		
		// Reverse all element form iIndex;
		int last=strlen(str)-1;
		int start=iIndex+1;
		
		//printf("%d %d\n",iIndex,jIndex);
		
		while(start<last){
			temp=str[start];
			str[start]=str[last];
			str[last]=temp;
			
			start++;
			last--;
		}
		if(flag==0){
			printf("no answer\n");
		}
		else
			printf("%s\n",str);
	}
	return 0;
}
