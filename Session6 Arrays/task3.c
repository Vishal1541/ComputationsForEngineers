#include<stdio.h>
#include<assert.h>
int n,m,n1,n2,m1,m2;
void addMat(float M1[n][m], float M2[n][m],float M3[n][m]){
    int i,j;
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                M3[i][j]= M1[i][j] + M2[i][j];
            }
        }
        printf("\n The addition of the matrices is : \n");
    for(i=0;i<n;i++){
            printf("| ");
            for(j=0;j<m;j++){
                printf("%8.2f",M3[i][j]);
            }
            printf("\t|\n");
    }
}

void mulMat(float M1[n1][m1], float M2[n2][m2],float M3[n1][m2]){
    int i,j,k=0;
    float p=0;
    for(i=0;i<n1;i++){
    while(k<m2){
        for(j=0;j<m1;j++){
                p+=M1[i][j] * M2[j][k];
        }
        M3[i][k]=p;
    k++;
    p=0;
    }
    k=0;
    p=0;
    }
}

int main(){
    printf("Enter the serial no of the operation to be performed on Matrix:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    int i;
    scanf("%d",&i);
    assert(i==1 || i==2);
    if(i==1){
        int i,j;
        printf("Enter the order of the matrices n , m :\n");
        scanf("%d %d",&n,&m);
        assert(n>0 && m>0);
        float M1[n][m];
        float M2[n][m];
        float M3[n][m];

        printf("Enter the elements in first matrix:\n");

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%f",&M1[i][j]);
            }
        }
        for(i=0;i<n;i++){
            printf("| ");
            for(j=0;j<m;j++){
                printf("%8.2f",M1[i][j]);
            }
            printf("\t|\n");
        }

        printf("Enter the elements in second matrix:\n");

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%f",&M2[i][j]);
            }
        }
        for(i=0;i<n;i++){
            printf("| ");
            for(j=0;j<m;j++){
                printf("%8.2f",M2[i][j]);
            }
            printf("\t|\n");
        }
        addMat(M1,M2,M3);
    }
    else{
        int i,j;
        printf("Enter the order of the matrix M1 n1 , m1 :\n");
        scanf("%d %d",&n1,&m1);
        assert(n1>0 && m1>0);
        printf("Enter the order of the matrix M2 %d , m2 :\n",m1);
        scanf("%d",&m2);
        assert(m2>0);
        n2=m1;
        float M1[n1][m1];
        float M2[n2][m2];
        float M3[n1][m2];

        printf("Enter the elements in first matrix M1:\n");
        for(i=0;i<n1;i++){
            for(j=0;j<m1;j++){
                scanf("%f",&M1[i][j]);
            }
        }
        for(i=0;i<n1;i++){
            printf("| ");
            for(j=0;j<m1;j++){
                printf("%8.2f",M1[i][j]);
            }
            printf("\t|\n");
        }
        printf("Enter the elements in second matrix M2:\n");
        for(i=0;i<n2;i++){
            for(j=0;j<m2;j++){
                scanf("%f",&M2[i][j]);
            }
        }
        for(i=0;i<n2;i++){
            printf("| ");
            for(j=0;j<m2;j++){
                printf("%8.2f",M2[i][j]);
            }
            printf("\t|\n");
        }
        mulMat(M1,M2,M3);
        printf("\n\nMatrix M3 :\n\n");
        for(i=0;i<n1;i++){
            printf("| ");
            for(j=0;j<m2;j++){
                printf("%8.2f",M3[i][j]);
            }
            printf("\t|\n");
        }
    }
    return 0;
}
