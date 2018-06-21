#include <stdio.h>
#include <math.h>
float fun(float i)
{
    float f1=sqrt(1-i*i);
    float f2=(1+exp((-3.14*i)/f1));
    float f3=asin(f1);
    float f4=(1-exp((-2*3.14*i)/f1));
    float f5=2-(i*i);
    float f6=1/(2-(i*i));
    float f7=exp((f3*i)/f1);
    float fi=((f2*f2*f7)/(f4*f5))-f6;
    return fi;

}
void main()
{
    float a,b;
    printf("Enter the value of lower limit a");
    scanf("%f", &a);
    printf("Enter the value of upper limit b");
    scanf("%f", &b);
    float n=10000;
    float dx=(b-a)/(n);
    float i=0.1;
    while(i<=b)
    {
        if((i==0.1)&&(fun(i)<fun(i+dx)))
        {
            printf("The minimum value is %f at x=%f", fun(i),i);
            break;
        }
        else if((fun(i-dx)>fun(i)) && (fun(i)<fun(i+dx)))
            {
                printf("The minimum value is %f at x=%f", fun(i),i);
                break;
            }
        else
        {
            i=i+dx;
        }
    }
    return 0;
}
