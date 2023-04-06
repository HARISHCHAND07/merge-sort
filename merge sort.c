#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int lb,int mid,int ub){
    int arr1[50];
    int i=lb;
    int k=lb;
    int j=mid+1;
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            arr1[k]=arr[i];
            i++;k++;
        }else{
            arr1[k]=arr[j];
            k++;j++;
        }
    }if(i>mid){while(j<=ub){
        arr1[k]=arr[j];
        k++;j++;
    }}else{
        while(i<=mid){
            arr1[k]=arr[i];
            i++;k++;
        }
    }
    
    for(k=lb;k<=ub;k++){
    arr[k]=arr1[k];}
}
int mergesort(int arr[],int lb,int ub){int mid;
    if(lb<ub){
           mid=(lb+ub)/2;
           mergesort(arr,lb,mid);
           mergesort(arr,mid+1,ub);
           merge(arr,lb,mid,ub);
    }
}
int main(){
    int arr[50],mid,n,i;
    printf("ente size=");
    scanf("%d",&n);
    printf("element=");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n);
    printf("array=\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}