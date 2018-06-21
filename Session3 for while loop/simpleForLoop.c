    #include<stdio.h>
    #include<math.h>
     
    void main(){
      int   n;
      float count, sum;
     
      printf("This program calculates the sum 1 + 1/2^2 + ... + 1/n^2\n"); 
      printf("Enter the positive integer value of n: "); 
      scanf("%d",&n);
       
      sum = 0;
      for (count=1 ; count <= n ;  count = count + 1){
        sum = sum + 1/count/count ;
      }
      printf("The sum is is: %.5f\n",sum);
    }
