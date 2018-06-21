#include<stdio.h>

int main(){
    float a,b,root=0;
    printf("Enter a and b of the linear equation:\n");
    printf("\tax + b = 0\n");
    scanf("%f%f",&a,&b);

    if(a==0 && b!=0){
        printf("No real root exist.\n");
    }
    else if(a==0 && b==0){
        printf("Equation has infinite roots.\n");
    }
    else{
        root = -b/a;
        printf("Root is %f\n",root);
    }

    return 0;
}
