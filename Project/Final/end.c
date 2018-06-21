#include<stdio.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>
//#include"printpic.c"
/*void clrscr()
{
 system("cls");
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}*/
int ending()
{
    int y,z,i=0;
    char x[10];
    char p[]="yes";
    char q[]="no";
    printf("\n\nDO YOU WANT TO USE THE DICTIONARY AGAIN\n ");
    printf("\nTPYE EITHER YES OR NO    ");
    here:
    scanf("%s",x);
    while(x[i]!='\0')
    {
        if(x[i]>='A'&&x[i]<='Z')
            x[i]=x[i]+32;
            i++;
    }
    y=strcmp(p,x);
    i=strcmp(q,x);

    if(y==0)
        {
           clrscr();
           z=1;
        }

    else if(i==0)
    {
        delay(500);
        clrscr();
        z=0;
        for(int x=0;x<143;x++)
        printf("=");
        for(int x=0;x<143;x++)
        printf("=");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t MADE BY :-");
        printf("\n\n\t\t\t\t\t  THANKS FOR USING OUR DICTIONARY\t\t\t\t\t\t\t YASH AGRAWAL");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t VISHAL ANAND");
        printf("\n\t\t\t\t\t\t   HAVE A NICE DAY\t\t\t\t\t\t\t\t TIRUPATI MISHRA");
        printf("\n\t\t  \t\t\t\t\t\t\t\t\t\t\t\t\t\t VEDANT AGGARWAL");
        printf("\n\t\t\t  \t\t\t\t\t\t\t\t\t\t\t\t\t PARIMAL KUMAR");
        printf("\n\n\n\n\t\t\t\t  \t\t\t\t EXITING ");
        int j=0;
        while(j<2)
        {
               for(int p=0;p<3;p++)
                {
                        delay(600);
                        printf(".");
                }
                delay(600);
               printf("\b\b\b");
                printf("   ");
               printf("\b\b\b");
            j++;
        }
        clrscr();
    }

    else if(y!=0&&i!=0)
    {
        printf("\n\n PLEASE ENTER \"YES\" OR \"NO\" ONLY  ");
        goto here;
    }

   return z;
}
