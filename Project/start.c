#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct dict{
	int sn;
	char name[20];
	char *des[1];
}Dictionary;
int main(){
	FILE *f=fopen("test","r");
	FILE *fw=fopen("test","a");
	Dictionary dictionary[100];
	char csn[4];
	fgets(csn,4,f);
	fgets(dictionary[0].name,20,f);
	fgets(dictionary[0].des,100,f);
	dictionary[0].sn=atoi(csn);
	printf("%d. %s%s\n",dictionary[0].sn,dictionary[0].name,dictionary[0].des);
	
	char in_sr[4];
	fprintf(fw,"%s",&in_sr);
	
	return 0;
}
