#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<time.h>
void clrscr()
{
 system("cls");
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
    //delay(second);
}
void start()
{
    FILE *p;
    p=fopen("coffeepic.txt","r");
    char a[1000];
    clrscr();
    int j=0;
    printf("\n\n\t\t\t\t\t\t\t\t LOADING CONTENTS\n\t\t\t\t\t\t\t\t ");
    for(int i=0;i<16;i++)
        printf("-");
    printf("\n\n\n");
    while(!feof(p))
    {
        fgets(a,1000,p);
        printf("\t\t\t\t\t%s",a);
    }

    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tANALYZING DATA PLEASE WAIT");
    while(j<3)
    {int i;
           for(i=0;i<3;i++)
            {
                delay(600);
                printf(".");
            }
            delay(600);
           printf("\b\b\b");
            printf("   ");
           printf("\b\b\b");
    //printf(" ");
        j++;
    }

    clrscr();
}
