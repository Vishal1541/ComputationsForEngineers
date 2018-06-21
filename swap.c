#include<stdio.h>
void Swap(int *p, int *q){
    int x = *p;
    *p = *q;
    *q = x;
}
int main(){
    int a=5,b=3;
    Swap(&a,&b);
    printf("%d %d",a,b);

    return 0;
}
