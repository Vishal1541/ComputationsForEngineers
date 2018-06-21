#include<stdio.h>
#include<math.h>
int Input();
/*void Add();
void Sub();
void Mul();
void Div();
void Sin();
void Cos();
void Tan();
float Tan2(float x);
void Cot();
void Power();
void Fact();
*/int Fact2(float a);

int Input(){

    int n;
    printf("Enter the serial no of the operation to be performed:\n");
    printf("0. Exit\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sin(x)\n");
    printf("6. Cos(x)\n");
    printf("7. Tan(x)\n");
    printf("8. Cot(x)\n");
    printf("9. x^y\n");
    printf("10. x!\n");
    printf("\n");
    scanf("%d",&n);
    return n;
}
/*void Add(){
    float a,b;
    printf("Enter the first number:\n");
    scanf("%f",&a);
    printf("Enter the second number:\n");
    scanf("%f",&b);
    float s=a+b;
    printf("The sum is %f",s);
}
void Sub(){
    float a,b;
    printf("Enter the first number:\n");
    scanf("%f",&a);
    printf("Enter the second number:\n");
    scanf("%f",&b);
    float s=a-b;
    printf("The difference is %f",s);
}
void Mul(){
    float a,b;
    printf("Enter the first number:\n");
    scanf("%f",&a);
    printf("Enter the second number:\n");
    scanf("%f",&b);
    float s=a*b;
    printf("The product is %f",s);
}
void Div(){
    float a,b;
    printf("Enter the first number:\n");
    scanf("%f",&a);
    printf("Enter the second number:\n");
    scanf("%f",&b);
    float s=a/b;
    printf("The division is %f",s);
}
void Sin(){
    float x,s=0;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    x = x*3.141592/180;

    for(i=1;i<=10;i++){
            s = s + pow(-1,(i+1))*pow(x,(2*i-1))/Fact2(2*i-1);
    }
    printf("The value of sine of x is %f",s);
}
void Cos(){
    float x,s=0;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
    x = x*3.141592/180;

    for(i=1;i<=10;i++){
            s = s + pow(-1,(i+1))*pow(x,((i-1)*2))/Fact2((i-1)*2);
    }
    printf("The value of cosine of x is %f",s);
}
void Tan(){
    float x,s=0;
    int i;
    printf("Enter the value of x in degrees: ");
    scanf("%f",&x);
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
    s = 1/Tan2(x);

    printf("The value of cot of x is %f",s);
}*/
int Fact2(float a){
    int f=1;
    int i;
    for(i=1;i<=a;i++){
        f=f*i;
    }
    return f;
}
/*
void Fact(){
    int a;
    printf("Enter the number:\n");
    scanf("%d",&a);
    int f=1;
    int i;
    for(i=1;i<=a;i++){
        f=f*i;
    }
    printf("The factorial is %d",f);
}
void Power(){
    float a,b;
    printf("Enter the first number(x):\n");
    scanf("%f",&a);
    printf("Enter the second number(y):\n");
    scanf("%f",&b);
    float p=1;
    int i;
    for(i=1;i<=b;i++){
        p=p*a;
    }
    printf("x^y is %f",p);
}
*/
int main(){
    int n=Input();
    float a=0,b=0,ans=0;
    if(n==1 || n==2 || n==3 || n==4 || n==9){
        printf("Enter the first number: ");
        scanf("%f",&a);
        printf("Enter the second number: ");
        scanf("%f",&b);
        switch(n){
            case 1: ans=a+b;break;
            case 2: ans=a-b;break;
            case 3: ans=a*b;break;
            case 4: ans=a/b;break;
            case 9: ans=pow(a,b);break;
        }
    }
    else {
        printf("Enter the number: ");
        scanf("%f",&a);
            a=a*3.141592/180;
        switch(n){
            case 5: ans=sin(a);break;
            case 6: ans=cos(a);break;
            case 7: ans=tan(a);break;
            case 8: ans=1/tan(a);break;
            case 10: a=a*180/3.141592;
                    ans=Fact2(a);break;

    }
    }
    printf("\nThe answer is %f",ans);
    return 0;
}
