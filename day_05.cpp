#include<iostream>
using namespace std;

void prefix_sum(int*sum,int*num,int len){
    sum[0]=0;
    for(int i=1;i<=len;i++){
        sum[i]+=sum[i-1]+num[i-1];
    }
}
//一维情况下进行前缀和计算

void prefix_matrix_sum(int**matrix,int**sum_matrix,int n,int m){
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum_matrix[i][j]=matrix[i][j]+sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1];
        }
     }
}
int main(){
    int n,m;
    cin>>n>>m;
    int*num=new int[n];
    int*sum=new int[n+1];
    for(int i=0;i<n;i++){
       cin>>num[i];
    }
    int*l=new int[m];
    int*r=new int[m];
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    prefix_sum(sum,num,n);
    for(int i=0;i<m;i++){
       cout<<sum[r[i]]-sum[l[i]-1]<<endl;
    }
    return 0;
}