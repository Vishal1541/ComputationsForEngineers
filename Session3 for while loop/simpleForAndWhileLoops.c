    #include<stdio.h>
    #include<math.h>
     
    void main(){
      int   n, validEntry;
      float count, sum;

      printf("This program calculates the sum 1 + 1/2^2 + ... + 1/n^2\n"); 

      validEntry = 0;
      while (validEntry == 0)
      {
      printf("Enter a nonnegative integer value of n: "); 
      scanf("%d",&n);
        if(n >= 0)
        {
            validEntry = 1;
        }
      }
       
      sum = 0;
      for (count=1 ; count <= n ;  count = count + 1){
        sum = sum + 1/count/count ;
      }
      printf("The sum is is: %.5f\n",sum);
    }
