#include<stdio.h>
#include<math.h>
#include<stdlib.h>
     
#define MAX_WIDTH  65 /* default terminal on ubuntu has a width of about 70 */

void main(){
      unsigned int  count,  numOfSamples, numBelowHalf, percent;
      float  dummy, fractionBelowHalf, scale;
     
      printf("%d\n",RAND_MAX);
      printf("This program generates independent samples of\n");
      printf("a uniform random variable bewteen 0, 1.\n\n"); 
      printf("Enter the number of independent samples:  "); 
      scanf("%u",&numOfSamples);

      numBelowHalf = 0;
      for (count=1 ; count <= numOfSamples ;  count++){
        dummy = ((float) rand())/(float) RAND_MAX;  /* RAND_MAX is defnied in stdlib.h */
        if (dummy <= 0.5) {
	      numBelowHalf = numBelowHalf + 1;
        }
      }
      fractionBelowHalf =  (float) numBelowHalf / (float) numOfSamples;
      percent = (unsigned int) ( (float) 100 * (float) fractionBelowHalf );
      
      scale = (float) MAX_WIDTH ;
      printf("scale=%f, fractionBelowHalf=%f \n",scale,fractionBelowHalf);

      printf("\n");
      for (count=1 ; count <= MAX_WIDTH ;  count = count + 1){
        if ( (fractionBelowHalf * scale) > ((float) count ) ) {
	      printf("*");
        }
        else {
	      printf(" ");
        }
      }
      printf("  %u \% \n", percent );
}
