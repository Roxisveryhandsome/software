#include<iostream>
using namespace std;


void insert_diff(int**diff,int c,int x1,int y1,int x2,int y2){
    
    diff[x1][y1]+=c;
    diff[x2+1][y1]-=c;
    diff[x1][y2+1]-=c;
    diff[x2+1][y2+1]+=c;
}

int main(){
    int n,m,q;
    int x1,y1,x2,y2,c;
    cin>>n>>m>>q;
    int**a=new int*[n+1];
    int**diff=new int*[n+1];
    for(int i=0;i<n+1;i++){
        a[i]=new int[m+1]();
        diff[i]=new int[m+1]();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            insert_diff(diff,a[i][j],i,j,i,j);
        }
    }
    for(int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2>>c;
        insert_diff(diff,c,x1,y1,x2,y2);
    }
    
    int**outcome=new int*[n+1];
    for(int i=0;i<n+1;i++){
        outcome[i]=new int[m+1]();
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            outcome[i][j]=outcome[i][j-1]+outcome[i-1][j]+diff[i][j]-outcome[i-1][j-1];
            cout<<outcome[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}