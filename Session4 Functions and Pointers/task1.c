#include<stdio.h>
#include<math.h>

float Func(float x);
void evaluateObjectiveFunctions();
void goldenSection(float *a,float *b, float *Min);

float Func(float x){
    float y=pow(x-2,2)+1;
    return y;
}
void goldenSection(float *a,float *b, float *Min){
    float r5=sqrt(5);
    float x1,x2;
        x2 = *a + (*b-*a)*(r5-1)/2;
        x1 = *a + (x2-*a)*(r5-1)/2;

        if(Func(x1)<Func(x2)){
            *b = x2;
        }
        else
            {*a = x1;}

        *Min=Func((*a+*b)/2);
}
void evaluateObjectiveFunctions(){
    float xi,xj,MinVal;
    scanf("%f %f",&xi,&xj);
    MinVal=Func(xi);
    while(xi!=xj){
        goldenSection(&xi,&xj,&MinVal);
    }
    printf("The minimum value is %f at %f\n",MinVal,xj);
}
int main(){
    evaluateObjectiveFunctions();
    return 0;
}
