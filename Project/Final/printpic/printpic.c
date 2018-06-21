#include<stdio.h>
#include<string.h>
void printpic(int x)
{
    FILE *p;
    switch(x)
    {

        case 0: break;
        case 1: p=fopen("tigerpic.txt","r");
                break;
        case 2: p=fopen("dogpic.txt","r");
                break;
        case 3: p=fopen("rodentpic.txt","r");
                break;
        case 4: p=fopen("shrewspic.txt","r");
                break;
        case 5: p=fopen("civetspic.txt","r");
                break;
        case 6: p=fopen("mongoose.txt","r");
                break;
        case 7: p=fopen("boarpic.txt","r");
                break;
        case 8: p=fopen("primatespic.txt","r");
                break;
        case 9: p=fopen("harepic.txt","r");
                break;
        case 10: p=fopen("deerpic.txt","r");
                break;
        case 11: p=fopen("batpic.txt","r");
                break;
        case 12: p=fopen("snakepic.txt","r");
                break;
        case 13: p=fopen("lizardpic.txt","r");
                break;
        case 14: p=fopen("frogpic.txt","r");
                break;
        case 15: break;

        default:break;
    }
    char a[1000];
    while(!feof(p))
    {
        fgets(a,1000,p);
        printf("\t\t\t\t\t\t\t%s",a);
    }
}
