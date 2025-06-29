#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>add;
vector<pair<int,int>>query;
vector<int>alls; 
const int N = 300010; 
int a[N];
int s[N];

int bin_search(vector<int>arr,int l,int r,int target){
    int mid=0;
    while(l<r){
        mid=(l+r)/2;
        if(arr[mid]>=target){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r+1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int x,c,l,r;
    for(int i=0;i<n;i++){
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }

    for(int i=0;i<m;i++){
       cin>>l>>r;
       query.push_back({l,r});
       alls.push_back(l);
       alls.push_back(r);
    }
   sort(alls.begin(),alls.end());
   alls.erase(unique(alls.begin(),alls.end()),alls.end());
   //进行离散化
   for (auto item : add) {
    int x = bin_search(alls,0,alls.size()-1,item.first);
    
    a[x] += item.second;
   }

   for (int i = 1; i <= alls.size(); i++){
       s[i] = s[i-1] + a[i];
   } 

   for (auto item : query) {
    int l = bin_search(alls,0,alls.size()-1,item.first);
    int r = bin_search(alls,0,alls.size()-1,item.second);
    cout<<s[r]-s[l-1]<<endl;
}


    return 0;
}