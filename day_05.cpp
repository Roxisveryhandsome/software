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
