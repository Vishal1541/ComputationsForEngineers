#include<stdio.h>
#include<string.h>
#include<assert.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
    FILE *fp = fopen("seqs.faa.txt","r");
    char ch[1000];
    int lenarr[100],i=0;
    fgets(ch,1000,fp);
    assert(fp!=NULL);
    while(1){
        if(ch[0]=='>'){
            fgets(ch,1000,fp);
            lenarr[i]=strlen(ch);
            i++;
            printf("Length of protein %d is %d.\n",i,lenarr[i-1]);
            fgets(ch,1000,fp);
        }
        else
            break;
    }
    qsort(lenarr,i,4,cmpfunc);
    printf("The smallest protein is %d.\n",lenarr[0]);
    printf("The largest protein is %d.\n",lenarr[i-1]);
    return 0;
}
