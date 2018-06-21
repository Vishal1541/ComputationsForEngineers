#include<stdio.h>
#include<string.h>
void main()
{
    FILE *p;
    p=fopen("animal.txt","r");
    char name[100],temp[10];
    char input[100],descr[1000];
    printf("enter name of animal   ");
    fgets(input,100,stdin);
    int j=0;
    while(input[j]!='\0')
    {
        if(input[j]<='z'&&input[j]>='a')
            input[j]=input[j]-32;
        j++;
    }
    int l;
    for(int i=0;i<30;i++)
    {
        if(i%3==1)
        {
           fgets(name,100,p);
           l=strcmp(name,input);
           if(l==0)
            goto here;
        }
        else if(i%3==0)
        {
          fgets(temp,10,p);

        }
        else
        {
            here :
            fgets(descr,1000,p);
            if(l==0)
                break;
        }
    }

    if(l==0)
    {
       printf("\n\n%s \t:\n",name);
        for(int i=0;i<80;i++)
            printf("-");
        printf("%s",descr);
        for(int i=0;i<80;i++)
        printf("-");
    }

    else
    {
        printf("\n \t NO SUCH ANIMAL IN OR NEAR IIT MANDI\n\n");
        main();
    }
}
