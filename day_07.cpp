#include<iostream>
using namespace std;
const int scale=10e5+10;

int max_length(int*arr,int len){
    int*if_apper=new int[scale]();
    int max_length=0;
  for(int i=0,j=0;i<len;i++){
    if_apper[arr[i]]++;
    while(if_apper[arr[i]]>1){
        if_apper[arr[j]]--;
        j++;
    }
    int temp=i-j+1;
    max_length=temp>max_length?temp:max_length;
  }
  return max_length;

}

pair<int,int> get_pos(int*arr1,int*arr2,int n,int m,int x){
   int i=0,j=m-1;
   int length=n>m?m:n;

   while(1){
    if((arr1[i]+arr2[j])<x){
        if(i==n-1){
            return {-1,-1};
        }
        i++;
    }
    else if((arr1[i]+arr2[j])==x){
        return {i,j};
    }
    else{
        if(j==0){
            return{-1,-1};
        }
        j--;
    }
   }
}

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    int*arr1=new int[n];
    int*arr2=new int[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    pair<int,int> res=get_pos(arr1,arr2,n,m,x);
    cout<<res.first<<' '<<res.second;
    return 0;
}