#include<stdio.h>
#include<string.h>
#include<assert.h>
void Input(){
	printf("Enter the sr no of the operation to be performed:\n");
	printf("1. Delete all ch except alph ch,digits or from {+,-,*,/,=,(,)}\n");
	printf("2. = (if)appears only once neither at beginning not at end\n");
	printf("3. No consecutive occurence of +,-,*,/\n");
	printf("4. Checking matching of ( and )\n");
}
void partA(char *s){
	int i,l=strlen(s);
	for(i=0;i<l;i++){
		if( (s[i]>=48&&s[i]<=57) || (s[i]>=65&&s[i]<=90) || (s[i]>=97&&s[i]<=122) || (s[i]>=40&&s[i]<=43) || s[i]==45 || s[i]==47 || s[i]==61)
			printf("%c",s[i]);
	}
}
void partB(char *s){
	int c,i,l=strlen(s);
	if(s[0]==61)
		printf("'=' appears at the beginnig\n");
	if(s[l-2]==61)
		printf("'=' appears at the end\n");
	for(i=1;i<l-2;i++){
		if(s[i]==61)
			c++;
	}
	printf("'=' appears %d times in between.\n",c);
}
void partC(char *s){
	int i,l=strlen(s);
	int a=0,b=0,c=0,d=0;
	for(i=0;i<l-1;i++){
		if(s[i]=='+'&&s[i+1]=='+')	a++;
		if(s[i]=='-'&&s[i+1]=='-')	b++;
		if(s[i]=='*'&&s[i+1]=='*')	c++;
		if(s[i]=='/'&&s[i+1]=='/')	d++;		
	}
	if(a>0)	printf("+ appeared consecutively.\n");
	if(b>0)	printf("- appeared consecutively.\n");
	if(c>0)	printf("* appeared consecutively.\n");
	if(d>0)	printf("/ appeared consecutively.\n");
	if(a==0&&b==0&c==0&d==0)	
		printf("NONE appeared consecutively.\n");
}
int main(){
	int i;
	char *str[100];
	fgets(str,100,stdin);
	Input();
	scanf("%d",&i);
	assert(i>0&&i<5);
	switch(i){
		case 1: partA(str);break;
		case 2: partB(str);break;
		case 3: partC(str);break;
	}
	printf("\n");
	return 0;
}







