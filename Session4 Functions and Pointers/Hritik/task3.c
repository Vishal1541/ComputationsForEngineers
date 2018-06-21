#include<stdio.h>
int F(int x,int y);
int G(int x,int y);
int H(int x,int y);

int F(int x,int y)
{
    int a=1,b=1;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    G(3,4);
    printf("Function name: F\na = %d ; b= %d\n",a,b);
}

int G(int x, int y)
{
    int a=7,b=6;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    H(5,9);
    printf("Function name: G\na = %d ; b= %d\n",a,b);
}

int H(int x,int y)
{
    int a=8,b=3;
    printf("Address of a = %u\n",&a);
    printf("Addresses of arguments are %u and %u\n",&x,&y);
    printf("Function name: G\na = %d ; b= %d\n",a,b);
}
int main()
{
    F(1,1);
    return 0;
}
