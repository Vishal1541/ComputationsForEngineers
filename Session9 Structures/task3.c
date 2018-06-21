#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct randvar{
	int bin;
	float freq;
}RandVar;

int main(){
	int N,x,e;
	float r=0;
	printf("%d\n",RAND_MAX);
     	printf("This program generates independent samples of\n");
      	printf("a uniform random variable bewteen 0, 1.\n\n"); 
      	printf("Enter the number of independent samples:  ");
      	scanf("%d",&N);
      	assert(N>1);
      	printf("Enter an odd positive integer: ");
      	scanf("%d",&x);
      	assert(x>0 && x%2!=0);
      	printf("Enter no of evaluations: ");
      	scanf("%d",&e);
      	assert(x>0);
      	
      	RandVar randVar[x];
      	
      	for(int i=0;i<x;i++){
      		randVar[i].bin=i+1;
      		randVar[i].freq=0;
      	}
      	for(int i=0;i<N;i++){
      		for(int i=0;i<e;i++)
      			r+=(float)rand()/(float)RAND_MAX;
      		r/=e;
      		for(int j=0;j<x;j++){
      			if(r>=(float)j/x && r<(float)(j+1)/x)
      				randVar[j].freq++;
      		}
      		r=0;
      	}
      	for(int j=0;j<x;j++){
      		randVar[j].freq/=N;
      		printf("bin %d: freq = %.2f between %.2f and %.2f.\n",j+1,randVar[j].freq,(float)j/x,(float)(j+1)/x);
      		printf("\t%.2f%\t|\t",randVar[j].freq*100);
      		for(int i=0;i<randVar[j].freq*200;i++)
      			printf("*");
      		printf("\n");
      	}
	return 0;
}
