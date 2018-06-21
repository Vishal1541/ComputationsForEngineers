#include<stdio.h>
int F(int x,int y);
int G(int x,int y);
int H(int x,int y);

int F(int x,int y)
{
    int a=1,b=1;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    G(x+a,y-b);
    printf("Function name: F\na = %d ; b= %d\n",a,b);
}

int G(int x, int y)
{
    int a=x*x,b=y;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    H(a,b);
    printf("Function name: G\na = %d ; b= %d\n",a,b);
}

int H(int x,int y)
{
    int a=x+2,b=y-4;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    printf("Function name: H\na = %d ; b= %d\n",a,b);
}
int main()
{
    int p,q;
    scanf("%d%d",&p,&q);
    F(p,q);
    return 0;
}
