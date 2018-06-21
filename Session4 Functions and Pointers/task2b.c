#include<stdio.h>
int Input(){
    int i;
    scanf("%d",&i);
    while(i<0){
       printf("Please enter a non negative integer: ");
       scanf("%d",&i);
    }
    return i;
}
int GCD(int a,int b){
    int r,ans;
    if(a<b){
            ans=1;
        while(b%a!=0){
            r = b%a;
            b=a;
            a=r;
            ans=a;
        }
    }
    else if(a>b){
        ans=1;
        while(a%b!=0){
            r = a%b;
            a=b;
            b=r;
            ans=b;
        }
    }
    else ans=a;

    printf("The GCD is %d\n",ans);
}
int main(){
    int n1,n2,hcf;
    n1=Input();
    n2=Input();
    hcf = GCD(n1,n2);
    return 0;
}
