//快速排序
#include<iostream>
using namespace std;




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

