#include<stdio.h>
#include<assert.h>
void suppRxn(float load[][2],int n,float L,float *ra,float *rb){
    *ra=0;
    *rb=0;
    int i;
    float xi,Pi,PiTotal=0;
    float Ra[n],Rb[n];
    for(i=0;i<n;i++){
        xi=load[i][0];
        Pi=load[i][1];
        PiTotal+=Pi;
        Rb[i]=Pi*(xi/L);
        Ra[i]=Pi-Rb[i];
    }
    for(i=0;i<n;i++){
        *ra+=Ra[i];
        *rb+=Rb[i];
    }
    //assert(PiTotal==((*ra)+(*rb)));
}
float shearForce(float x,float ra,float load[][2],int n){
    float V,pi=0;
    int i;
    for(i=0;i<n;i++){
        if(load[i][0]<x){
            pi+=load[i][1];
        }
    }
    V = ra - pi;
    return V;
}
int main(){
    int n,i;
    float len;
    float xi,pi;
    printf("Enter the length: ");
    scanf("%f",&len);
    assert(len>0);
    printf("Enter the no of points: ");
    scanf("%d",&n);
    assert(n>0);
    float load_arr[n][2]; //n rows, 2 columns
    printf("Enter the dist and mag(-/+ = upward/downward) of each: ");

    for(i=0;i<n;i++){
        scanf("%f %f",&xi,&pi);
        assert(xi<=len);
        load_arr[i][0]=xi;
        load_arr[i][1]=pi;
    }

    float ra,rb;
    float x,v;
    suppRxn(load_arr,n,len,&ra,&rb);
    printf("Ra = %.2f and Rb = %.2f\n",ra,rb);
    printf("Enter the value of x for calculatig shear force: ");
    scanf("%f",&x);
    assert(x<=len);
    v=shearForce(x,ra,load_arr,n);
    printf("The shear force is %f",v);
    return 0;
}
