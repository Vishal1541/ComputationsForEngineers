    #include<stdio.h>

    void main(){
      unsigned int   l, m, n, validEntry=0;

      printf("Please enter a positive integer n, less than 15\n");
      if ( (scanf("%u", &n) == 1) && (n < 15) ){
        validEntry = 1;
      }
      while (validEntry == 0) {
        printf("\t You must enter a positive integer less than 15\n");
        if ( (scanf("%u", &n) == 1) && (n < 15) ){
             validEntry = 1;
        }
      }
      printf("Please now enter two positive integers l, m, greater than 15\n");
      n = scanf("%u %u", &l,&m);
      printf("\t My call of the scanf function to read your two numbers l, m returned the value: %u\n",n);
      if ( ( n == 2) && (l > 15) && (m > 15) ){
        printf("\t You entered l = %u,\t m = %u.\n",l,m);
        printf("\t You are a careful user. Goodbye ! \n\n");
      }
      else {
        printf("\t You did not follow instructions carefully. No more chances for you !\n\n");
      }
    }
