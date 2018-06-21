#include<stdio.h>
#include<math.h>
float error=0;
int Input();
void Sin();
void Cos();
void Tan();
float Tan2(float x);
void Cot();
void Exp();
void Log();
int Fact2();

int Input(){

    int n;
    printf("Enter the serial no of the operation to be performed:\n");
    printf("0. Exit\n");
    printf("1. Exp(x)\n");
    printf("2. Sin(x)\n");
    printf("3. Cos(x)\n");
    printf("4. ln(x)\n");
    printf("\n");
    scanf("%d",&n);
    return n;
}
void Sin(){
    float x,s=0;
    int n;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    x = x*3.141592/180;

    for(i=1;i<=n;i++){
            s = s + pow(-1,(i+1))*pow(x,(2*i-1))/Fact2(2*i-1);
    }
    error = sin(x)-s;
    printf("\nn\tMyFunc(x,n)\terror=sin(x)-Myfunc(x,n)\n");
    printf("%d.\t%f\t%f\n",n,s,error);
}
void Cos(){
    float x,s=0;
    int i,n;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    x = x*3.141592/180;

    for(i=1;i<=n;i++){
            s = s + pow(-1,(i+1))*pow(x,((i-1)*2))/Fact2((i-1)*2);
    }
    error = cos(x)-s;
    printf("\nn\tMyFunc(x,n)\terror=cos(x)-Myfunc(x,n)\n");
    printf("%d.\t%f\t%f\n",n,s,error);
}
void Tan(){
    float x,s=0;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    x = x*3.141592/180;

    s = x + pow(x,3)/3 + 2*pow(x,5)/15 + 17*pow(x,7)/315 + 62*pow(x,9)/2835;

printf("The value of the fun is %f\n",s);
}
float Tan2(float x){
    float s=0;
    x = x*3.141592/180;

    s = x + pow(x,3)/3 + 2*pow(x,5)/15 + 17*pow(x,7)/315 + 62*pow(x,9)/2835;
    return s;
}
void Cot(){
    float x,s=0;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    s = 1/Tan2(x);


printf("The value of the fun is %f\n",s);
}
void Exp(){
    float x,s=1;
    int i,n;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
            s = s + pow(x,i)/Fact2(i);
    }
    error = exp(x)-s;
    printf("\nn\tMyFunc(x,n)\terror=exp(x)-Myfunc(x,n)\n");
    printf("%d.\t%f\t%f\n",n,s,error);
}
void Log(){
    float x,t,s=0;
    int i,n;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    if(x<2){
             x=x-1;
    for(i=1;i<=10;i++){
            s = s + ( pow(-1,(i+1))*pow(x,i) )/i;
        }
    }
    else
        for(i=1;i<=10;i++){
            s = s + pow((x-1)/x,i)/i;
        }
    error = logf(x)-s;
    printf("\nn\tMyFunc(x,n)\terror=ln(x)-Myfunc(x,n)\n");
    printf("%d.\t%f\t%f\n",n,s,error);
}
int Fact2(int a){
    int f=1;
    int i;
    for(i=1;i<=a;i++){
        f=f*i;
    }
    return f;
}

int main(){
    int n=Input();

        switch(n){
        case 1: Exp();break;
        case 2: Sin();break;
        case 3: Cos();break;
        case 4: Log();break;
        }
    return 0;
}
