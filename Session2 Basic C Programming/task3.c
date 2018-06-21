#include<stdio.h>
#include<math.h>
int main(){
    int n1,n2;
    float l1,l2,angle1,angle2,c1,c2,i1,i2;
    printf("Enter no of sides of polygon A: ");
    scanf("%d",&n1);
    printf("Enter side length of polygon A: ");
    scanf("%f",&l1);
    printf("Enter no of sides of polygon B: ");
    scanf("%d",&n2);
    printf("Enter side length of polygon B: ");
    scanf("%f",&l2);

    angle1 = ((n1-2)*180)/n1;
    angle2 = ((n2-2)*180)/n2;

    c1 = l1/(2*cos(angle1*3.1428/360));
    c2 = l2/(2*cos(angle2*3.1428/360));

    i1 = (l1*tan(angle1*3.1428/360))/2;
    i2 = (l2*tan(angle2*3.1428/360))/2;

    if(c1<c2){
        if(c1<i2){
            printf("Polygon A fits into Polygon B");
        }
        else
            printf("Polygon will not fit into each other");
    }
    else if(c1>c2){
         if(c2<i1){
            printf("Polygon B fits into Polygon A");
        }
        else
            printf("Polygon will not fit into each other");
    }
    else
        printf("Polygon will not fit into each other");


    return 0;
}
