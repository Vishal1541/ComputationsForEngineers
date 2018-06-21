#include<stdio.h>

int Input();
int GCD(int p,int q);
int Output(int a,int b,int k);

int Input()
{
    int a,b,k;
    printf("Enter 2 numbers:\n");
    scanf("%d %d",&a,&b);
    k=GCD(a,b);
    Output(a,b,k);
}

int GCD(int p,int q)
{
    int i;
    if(p>q)
    {
        for(i=p;i>=1;i--)
        {
        if((p%i==0)&&(q%i==0))
        return i;
        }
    }
    else if(p==q)
    {
        return p;
    }

    else if(p<q)
    {
        for(i=q;i>=1;i--)
        {
        if((p%i==0)&&(q%i==0))
        return i;
        }
    }

}

int Output(int a,int b,int k)
{
    printf("The GCD of %d and %d is %d",a,b,k);
}

int main()
{
    Input();
    return 0;
}
