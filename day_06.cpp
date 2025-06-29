#include<iostream>
using namespace std;

void prefix_matrix_sum(int** matrix,int** sum_matrix,int n,int m){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum_matrix[i][j]=matrix[i][j]+sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1];
        }
     }
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int**matrix=new int*[n+1];
    int**sum_matrix=new int*[n+1];
    for(int i=0;i<n+1;i++){
        matrix[i]=new int[m+1]();
        sum_matrix[i]=new int[m+1]();
        //这个括号必须是空的，只能初始化为0，其余值必须手动进行初始化
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    prefix_matrix_sum(matrix,sum_matrix,n,m);
    
    int x1,y1,x2,y2;
    int *q_val=new int[q];
    
    for(int i=0;i<q;i++){
        cin>>x1>>y1>>x2>>y2;
        q_val[i]=sum_matrix[x2][y2]-sum_matrix[x2][y1-1]-sum_matrix[x1-1][y2]+sum_matrix[x1-1][y1-1];
    }
    for(int i=0;i<q;i++){
        cout<<q_val[i]<<endl;
    }
    return 0;
}