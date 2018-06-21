#include<stdio.h>
#include<math.h>
#include<assert.h>
int Input1();
void Sin();
void Cos();
void Tan();
float Tan2(float x);
void Cot();
void Exp();
void Log();
int Fact2();

void Sinc();
void Cosc();
void Expc();
void Logc();

void Sinc(){
    float s1=0,s2=0,c;
    int n,x=10;
    int i;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
            s1 = s1 + pow(-1,((i-1)+1))*pow(x,(2*(i-1)-1))/Fact2(2*(i-1)-1);
            s2 = s2 + pow(-1,(i+1))*pow(x,(2*i-1))/Fact2(2*i-1);
    }
    c=s2-s1;
    printf("The coefficient of x^%d is %f",n,c);
}
void Cosc(){
    float s1=0,s2=0,c;
    int i,n,x=10;
    //printf("Enter the value of x in degrees: ");
    //scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
            s1 = s1 + pow(-1,((i-1)+1))*pow(x,(((i-1)-1)*2))/Fact2(((i-1)-1)*2);
            s2 = s2 + pow(-1,(i+1))*pow(x,((i-1)*2))/Fact2((i-1)*2);
    }
    c=s2-s1;
    printf("The coefficient of x^%d is %f",n,c);
}
void Logc(){
    float t,s1=0,s2=0,c;
    int i,n,x=10;
    //printf("Enter the value of x: ");
    //scanf("%f",&x);
    //assert(x>0);
    printf("Enter the value of n: ");
    scanf("%d",&n);

        for(i=1;i<=n;i++){
            s1 = s1 + pow((x-1)/x,i)/i;
            s2 = s2 + pow((x-1)/x,i+1)/(i+1);
        }
    c=s2-s1;
    printf("The coefficient of x^%d is %f",n,c);
}
void Expc(){
    float x=10,s1=0,s2=0,c;
    int i,n;
    //printf("Enter the value of x: ");
    //scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
            s1 = s1 + pow(x,(i-1))/Fact2(i-1);
            s2 = s2 + pow(x,i)/Fact2(i);
    }
    c=s2-s1;
    printf("The coefficient of x^%d is %f",n,c);
}
int Input1(){

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
/*int Input2(){

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
}*/
void Sin(){
    float x,s=0;
    //int n;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    //printf("Enter the value of n: ");
    //scanf("%d",&n);
    x = x*3.141592/180;

    for(i=1;i<=5;i++){
            s = s + pow(-1,(i+1))*pow(x,(2*i-1))/Fact2(2*i-1);
    }
    printf("The value of sine of x is %f",s);
}
void Cos(){
    float x,s=0;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    //printf("Enter the value of n: ");
    //scanf("%d",&n);
    x = x*3.141592/180;

    for(i=1;i<=5;i++){
            s = s + pow(-1,(i+1))*pow(x,((i-1)*2))/Fact2((i-1)*2);
    }
    printf("The value of cosine of x is %f",s);
}
void Tan(){
    float x,s=0;
    int i,j;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    j=x;
    assert((j%90)!=0);
    x = x*3.141592/180;

    s = x + pow(x,3)/3 + 2*pow(x,5)/15 + 17*pow(x,7)/315 + 62*pow(x,9)/2835;

    printf("The value of tan of x is %f",s);
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
    int j;
    j=x;
    assert((j%180)!=0);
    s = 1/Tan2(x);

    printf("The value of cot of x is %f",s);
}
void Exp(){
    float x,s=1;
    int i;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    //printf("Enter the value of n: ");
    //scanf("%d",&n);

    for(i=1;i<=5;i++){
            s = s + pow(x,i)/Fact2(i);
    }
    printf("The value of exp(x) is %f",s);
}
void Log(){
    float x,t,s=0;
    int i;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    assert(x>0);
    //printf("Enter the value of n: ");
    //scanf("%d",&n);

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

    printf("The value of ln(x) is %f",s);
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
    int n;
    printf("Enter 1 for evaluating the functions or\n");
    printf("2 for finding the coefficient of x^n in the MacLaurin's series expansion.\n");
    scanf("%d",&n);
    assert(n==1 || n==2);

        int n1=Input1();

    if(n==1){

        switch(n1){
        case 1: Exp();break;
        case 2: Sin();break;
        case 3: Cos();break;
        case 4: Log();break;
        }
    }
    else{

        switch(n1){
        case 1: Expc();break;
        case 2: Sinc();break;
        case 3: Cosc();break;
        case 4: Logc();break;
        }
    }
    return 0;
}
