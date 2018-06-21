#include<stdio.h>
#include<math.h>

void goldenSection(float *x, float *y, float *min);
float evaluateObjectiveFunction();
float roundoff(float t);
float f(int t);

void goldenSection(float *a, float *b, float *min)
{
    float y1,y2;
    y2 = *a + ((*b-*a)*0.618034);
    y1 = ((y2-*a)*0.618034) + *a;

        if (f(y1)<f(y2))
        {
            *b=y2;
        }
        else
        {
            *a=y1;
        }

}

float f(int t)
{
    return (pow(t,2)+4*t+4);
}

float evaluateObjectiveFunction()
{
    float a = -50.00;
    float b = 50.00;
    float min=f(a+b/2);
    while(roundoff(b)>roundoff(a))
    {
        goldenSection(&a,&b,&min);
        min = f((a+b)/2);

    }
    printf("The minimum value is %f at %f\n",min,a);
}

int main()
{
    evaluateObjectiveFunction();
}


float roundoff(float t)
{
     return round(t * 1000000.0)/1000000.0;
}




