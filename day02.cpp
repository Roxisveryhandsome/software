#include<iostream>
using namespace std;

int left_border(int*arr,int l,int r,int target){
    int mid=0;
    while(l<r){
      mid=(l+r)/2;
      if(arr[mid]<target){
        l=mid+1;
      }
      else {
        r=mid;
      }
    }
    return l;
}

int right_border(int*arr,int l,int r,int target){
    int mid=0;
    while(l<r){
        mid=(l+r+1)/2;
        if(arr[mid]<=target){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    return l;
}

