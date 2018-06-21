#include<stdio.h>
#include<string.h>
#include<assert.h>
int main(){
    char check[1000],patt[20];
    int len,j,i=0,stind=0;
    FILE *fp = fopen("seqs.faa.txt","r");
    FILE *pp = fopen("pattern.txt","r");
    fgets(patt,20,pp);
    assert(fp!=NULL);
    assert(pp!=NULL);
    fgets(check,1000,fp);
    while(1){
        if(check[0]=='>'){
            printf("%s",check);
            fgets(check,1000,fp);
            len = strlen(check);
            while(i<len){
                if(check[i]==patt[j]){
                        stind=i;
                        i++;
                        j++;
                        while(check[i]==patt[j]){
                            i++;
                            j++;
                        }
                        //printf("%d-%d, ",j,i);
                if(j==14){
                    printf("\tStarting Index: %d\n",stind);
                    printf("\tEnding Index: %d\n",stind+13);
                }
                }
                j=0;
                i++;
            }
            i=0;
            fgets(check,1000,fp);
        }
        else
            break;
    }
    return 0;
}
