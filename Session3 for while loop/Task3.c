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

    float a,b,x1=0,x2=1;
    float r5 = sqrt(5);
    int l=0;
    scanf("%f%f",&a,&b);

    while (x1!=x2){
        x2 = a + (b-a)*(r5-1)/2;
        x1 = a + (x2-a)*(r5-1)/2;

        if(Func(x1)<Func(x2)){
            b = x2;
        }
        else
            {a = x1;}
        l++;
    }
    //x = (a+b)/2;
    //y = Func(x);

    printf("\nMin value is %f \n",Func(a));
    printf("%d",l);

    return 0;
}
