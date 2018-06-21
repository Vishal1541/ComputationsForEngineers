#include<stdio.h>
#include<math.h>
int main(){
    int n;
    float l,angle,area;
    printf("Enter the no of sides: ");
    scanf("%d",&n);
    printf("Enter the side length: ");
    scanf("%f",&l);

    angle = ((n-2)*180)/n;
    area = (n*l*l*tan(angle*3.1428/360))/4;
    printf("The vertex angle of the polygon with %d sides and of side length %f = %f degree and the area = %f sq unit.",n,l,angle,area);

    return 0;
}
