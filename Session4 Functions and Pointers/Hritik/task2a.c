#include<stdio.h>

int Input();
int Output(int a,int b);
int Fact(int p);

int Input(){


    int n;
    printf("Enter the number whose factorial is to be computed:\n");
    scanf("%d",&n);
    return n;
}

int Fact(int p)
{
    int f;
    if(p==0)
        return 1;
    else
    {
        f=p*Fact(p-1);
    }
    return f;
}

int Output(int a,int b)
{
    printf("The factorial of %d is %d",a,b);
}

int main()
{
    int k,j;
    k=Input();
    j=Fact(k);
    Output(k,j);
}



