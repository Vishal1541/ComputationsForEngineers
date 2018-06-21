# include <stdio.h>
 # include <math.h>

void main ( ) {
float a,b,c;
float discriminant,root1,root2;

printf("enter a,b,c: ");
scanf("%f%f%f",&a,&b,&c);

discriminant = b*b-4*a*c;
root1 = (-b+sqrt(discriminant))/(2*a);
root2 = (-b-sqrt(discriminant))/(2*a);

printf("%.3f , %.3f\n",root1,root2);
 }
