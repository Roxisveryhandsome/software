//快速排序
#include<iostream>
using namespace std;

void quick_sort(int *arr,int l,int r){
    if(l>=r){
        return;
        //注意这里是大于等于
    }
    int i=l-1,j=r+1,x=arr[(l+r)/2];
    //注意左右指针值得选取，以及比较量的选取
    while(i<j){
        do i++; while(arr[i]<x);
        do j--; while(arr[j]>x);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    //先操作后递归
    quick_sort(arr,l,j);
    quick_sort(arr,j+1,r);
}


void merge_sort(int*arr,int l,int r,int*temp){
    if(l>=r){
        return;
    }
    int k=0,mid=(l+r)/2;
    merge_sort(arr,l,mid,temp);
    merge_sort(arr,mid+1,r,temp);
    int i=l,j=mid+1;

    while(i<=mid&&j<=r){
       if(arr[i]<=arr[j]){
        //注意这里是<=注意全面性
        temp[k++]=arr[i++];
       }
       else{
        temp[k++]=arr[j++];
       }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    
    //必须要有这最后一步，否则结果是不对的
    for (i = l, j = 0; i <= r; i ++, j ++ ) {
        arr[i] = temp[j];
    }
}

