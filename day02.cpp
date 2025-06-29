#include<iostream>
using namespace std;



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

