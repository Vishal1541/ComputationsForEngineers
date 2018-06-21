#include <stdio.h>
#include <math.h>
#include "session4f.c"
//task 1 of session 4
void swapv(float *n1,float *n2)
{
	float t;
	t=*n1;
	*n1=*n2;
	*n2=t;
	return;
}
float evaluateObjectiveFunction(float t)
{
	float f;
	
	f=(t-1)*(t-1)-2;
	return f;
}
void goldenSection(float *a,float *b,float *m)
{
	static float y2,y1,x2,x1,i=0;
	if (i == 0)
	{
		x2=(sqrt(5)-1)*0.5*(*b-*a)+*a;
		y2=evaluateObjectiveFunction(x2);
	}
	x1=(sqrt(5)-1)*0.5*(x2-*a)+*a;
	y1=evaluateObjectiveFunction(x1);
	if (y1<y2)
	{
		*b=x2;
		x2=x1;
		y2=y1;
	}
	else
	{
		*a=x1;
		swapv(a,b);
	}
	*m=x1;
	i++;
}

int main()
{
	float a,b,minima,n;
	printf("\n\n\t\tGOLDEN SECTION METHOD\n");
	printf("\nf(x)=(x-1)(x-1)-2\n");
	printf("\nEnter Domain.[a,b]\n");
	printf("Input a : ");
	if (scanf("%f",&a) != 1) {winp;return 0;}
	printf("Input b : ");
	if (scanf("%f",&b) != 1) {winp;return 0;}
	printf("\nMore the number of evaluations, more the accuracy.");
	printf("\nEnter number of evaluations : ");
	if (scanf("%f",&n) != 1) {winp;return 0;}
	n=fabs(n);
	for (;n>=0;n--)
	{
		goldenSection(&a,&b,&minima);
	}
	printf("\nPoint of minima : (%.3f,%.3f)\n\n",minima,evaluateObjectiveFunction(minima));
	return 0;
}
