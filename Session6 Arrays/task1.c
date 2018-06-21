#include<stdio.h>
#include<assert.h>
void Swap(int *arr, int *n1, int *n2){
    *n1-=1;
    *n2-=1;
    int arr1;
    arr1=arr[*n1];
    arr[*n1]=arr[*n2];
    arr[*n2]=arr1;
}
int main(){
    int n,n1,n2,i=0;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    assert(n>2);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element nos to be interchanged: ");
    scanf("%d%d",&n1,&n2);
    assert(n1>0 && n1<=n);
    assert(n2>0 && n2<=n);

    Swap(arr,&n1,&n2);

    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
