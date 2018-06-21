#include<stdio.h>

int Input(){
    int i;
    scanf("%d",&i);
    while(i<0){
       printf("Please enter a non negative integer: ");
       scanf("%d",&i);
    }
    return i;
}
int Fact(int n){
    int f;
    if(n==0)
        f=1;
    else
        f = n*Fact(n-1);
    printf("The value of f is %d\n",f);
    printf("The address of f is %d\n",&f);
    return f;
}

void Output(int n, int f){
    printf("The factorial of %d is %d\n",n,f);
}
int main(){
    int n=Input();
    int fac=Fact(n);
    Output(n,fac);
    return 0;
}
