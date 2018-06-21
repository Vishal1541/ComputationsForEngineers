#include<stdio.h>
#include<string.h>
#include<assert.h>
void filter(char *s){
	int l=strlen(s);
	int i,q=0,c=0;
	for(i=0;i<l;i++){
		if(s[i]==34)
			q++;
	}
	assert(q%2==0&&q!=0);
	for(i=0;i<l;i++){
		if(s[i]==34)
			c++;
		if(c%2==1&&s[i]!=34){
			printf("%c",s[i]);
			if(s[i+1]==34)
				printf("\n");
		}
			
	}
}
int main(){
	char *str[100];
	fgets(str,100,stdin);
	filter(str);
	return 0;
}

