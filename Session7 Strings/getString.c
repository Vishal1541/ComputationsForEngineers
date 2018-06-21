#include<stdio.h>
#include<string.h>
 
#define maxStringSize 100

int main() {
   char str[maxStringSize], shorterStr[2], temp;
   unsigned int i;
 
   printf("\nEnter the string :");
   fgets(str,maxStringSize,stdin); /* Reads string and stores it in str */
   
   i = strlen(str) ;
   shorterStr[0] = str[0];
   shorterStr[1] = str[i-1];
 
   printf("\nOriginal string is                         : %s\n", str);
   printf("String made up first and last characters is: %s\n", shorterStr);
   return (0);
}
