#include<stdio.h>
void clrscr()
{
 system("cls");
}
int main()
{
    FILE *p;
    int i=0;
    char a[1000];
    while(i<10000)
    {
        if(i%2==0)
        {
            p=fopen("coffeepic.txt","r");
            while(!feof(p))
            {
                fgets(a,1000,p);
                printf("%s",a);
            }
            clrscr();
        }
        if(i%2==1)
        {
            p=fopen("coffeepic2.txt","r");
            while(!feof(p))
            {
                fgets(a,1000,p);
                printf("%s",a);
            }
            clrscr();
        }
      i++;
    }
  return 0;
}
