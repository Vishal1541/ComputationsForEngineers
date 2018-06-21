#include<stdio.h>
#include<math.h>

float Func(float t){
    float pi=3.14159;
    float f1,f2,f3,f4,f5,f6,f7,f8;
    float IAE;

    f1 = sqrt(1 - t*t);
    f2 = exp(-pi*t/f1);
    f3 = pow(1+f2,2);

    f4 = asin(f1);
    f5 = exp(f4*t/f1);

    f6 = exp(-2*pi*t/f1);
    f7 = 1 - f6;

    f8 = 2 - t*t;

    IAE = (f3*f5)/(f7*f8) - 1/f8;
    return IAE;

}

int main(){


    float a,b,n,i,j,x1,x2,Min;
    int l=0;
    scanf("%f%f%f",&a,&b,&n);
    Min=Func(a);

    for(i=1;i<=n+1;i++){
        j = Func(a+(i*(b-a)/(n+1)));
        //k = Func(a+((i-1)*(b-a)/(n+1)));
        if(j<Min){
            Min=j;
            x2 = a+((i+1)*(b-a)/(n+1));
            x1 = a+((i-1)*(b-a)/(n+1));
        }
        l++;
        if(j>Min){
            break;
        }

    }
    printf("\n%f\nx lies in interval [%f , %f]\n",Min,x1,x2);
    printf("No of function evaluations = %d",l);

    return 0;
}
