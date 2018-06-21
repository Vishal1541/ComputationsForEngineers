#include<stdio.h>
#include<string.h>
#include<assert.h>
static int z=0;
void Input(){
	printf("Enter the serial no of the operation to be performed:\n");
	printf("1. Substring of string\n");
	printf("2. Shorter string\n");
	printf("3. Lower case appearing in order of first occurence\n");	
}
void nl(){
	printf("\n");
}
/*void correction(char *s){
	int l=0;
	while(*s!='\0'){
		l++;
		s++;
	}
	s[l-1]='\0';
}*/
void subStr(char *s){
	int i,l=lenStr(s);
	int a,b;
	printf("Enter the starting position: ");
	scanf("%d",&a);
	assert(a>0&&a<=l);
	printf("Enter the ending position: ");
	scanf("%d",&b);
	assert(b>=a&&b<=l);
	a--;
	b--;
	printf("The substring is: ");
	for(i=a;i<=b;i++)
		printf("%c",s[i]);
}
void shortStr(char *s){
	if(s[z]!='\0'){
		if((s[z]>=48&&s[z]<=57) || (s[z]>=65&&s[z]<=90) || (s[z]>=97&&s[z]<=122) || s[z]=='+' || s[z]=='-' || s[z]=='*' || s[z]=='/')
			printf("%c",s[z]);
		shortStr(&s[z+1]);
	}
}
void lowerCase(char *s){
	int i,j=0,l=strlen(s);
	char a[l-1];	
	for(i=0;i<l-1;i++){
		if(s[i]>=97&&s[i]<=122){
			a[j]=s[i];
			j++;
		}
	}
	int k=j,m=j;
	for(k=1;k<m;k++){
		for(j=0;j<k;j++)
			if(a[k]!=a[j])
				printf("%c",a[k]);
	}
}
int lenStr(char *s){
	int l=0;
	while(*s!='\0'){
		l++;
		s++;
	}
	return (l-1);
}
void rev(char *s){
	int i,n=lenStr(s);
	printf("The original string is %s",s);
	printf("The reversed string is ");
	for(i=n-1;i>=0;i--)
		printf("%c",s[i]);
	nl();
	
}
int main(){
	int len,n=100;
	char *str[n];
	int i;
	printf("Enter the string: ");
	fgets(str,n,stdin);
	len=lenStr(str);
	printf("The length of string is %d\n",len);
	printf("Length of string from strlen fun is %d\n",(strlen(str)-1));
	rev(str);
	Input();
	scanf("%d",&i);
	assert(i>0&&i<4);
	switch(i){
		case 1:	subStr(str);break;
		case 2: printf("The shorted string is: ");
			shortStr(str);break;
		case 3:	lowerCase(str);
	}
	nl();
	return 0;
}









