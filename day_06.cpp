#include<iostream>
using namespace std;

void prefix_matrix_sum(int** matrix,int** sum_matrix,int n,int m){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum_matrix[i][j]=matrix[i][j]+sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1];
        }
     }
}

