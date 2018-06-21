    #include<stdio.h>
    #include<math.h>

    void main(){
      float a,b,c;
      float discriminant,root1,root2;

      printf("Enter a, b and c of quadratic equation:\n");
      printf("\t\t a * x^2 + b * x + c = 0\n");
      scanf("%f%f%f",&a,&b,&c);

      discriminant = b * b - 4 * a * c;

      if (a==0 && b==0 && c==0){
        printf("Any real or complex number is a root.\n");
      }
      else if (a==0 && b==0 && c!=0){
        printf("No root exists.\n");
      }
      else if(discriminant < 0){
        printf("Roots are complex number. Roots are");

        printf("%.3f%+.3fi",-b/(2*a),sqrt(-discriminant)/(2*a));
        printf(", %.3f%+.3fi\n",-b/(2*a),-sqrt(-discriminant)/(2*a));
      }
      else if(discriminant==0){
       printf("Both roots are equal. Root is: ");

       root1 = -b /(2* a);
       printf(" %.3f\n ",root1);
      }
      else{
       printf("Roots are real numbers. Roots are: ");

       root1 = ( -b + sqrt(discriminant)) / (2* a);
       root2 = ( -b - sqrt(discriminant)) / (2* a);
       printf("%.3f , %.3f\n",root1,root2);
      }
    }
