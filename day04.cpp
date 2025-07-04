#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> add(vector<int>&A,vector<int>&B, vector<int>& C){

    if(B.size()>A.size()){
        return add(B,A,C);
    }
    int t=0;

    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size()){
            t+=B[i];
        }
        C.push_back(t%10);
        t/=10;
    }
    if(t){
        C.push_back(t);
    }

    return C;
}
bool cmp(vector<int>&A,vector<int>&B){
    if(A.size()>B.size()){
        return true;
    }
    if(A.size()<B.size()){
        return false;
    }
    int i=0;
    while(i<A.size()){
        i++;
        if(A[A.size()-i]>B[A.size()-i]){
            return true;
        }
        else if(A[A.size()-i]<B[A.size()-i]){
            return false;
        }
    }
    return true;
}
vector<int> sub(vector<int>&A,vector<int>&B,vector<int>&C){
      int t=0;
      for(int i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()){
            t-=B[i];
        }
        C.push_back((t+10)%10);
        if(t<0){
            t=1;
        }
        else{
            t=0;
        }
      }
      while(C.size() > 1 && C.back() == 0) C.pop_back();
      return C;
}

vector<int> mul(vector<int>&A,int b,vector<int>&C){
     int t=0;
     for(int i=0;i<A.size();i++){
        t+= A[i]*b;
        C.push_back(t%10);
        t/=10;
     }
     C.push_back(t);
     while(C.size()>1&&C.back()==0){
        C.pop_back();
     }
     return C;
}

vector<int> div(vector<int>&A,int& b,int&r,vector<int>&C){
    r=0;
    for(int i=A.size()-1;i>=0;i--){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0){
        C.pop_back();
     }
     return C;
    
}
int main(){
    string num1,num2;
    vector<int> num_1,num_2,outcome;
    cin>>num1>>num2;
    for(int i=num1.length()-1;i>=0;i--){
       num_1.push_back(num1[i]-'0');
    }
    for(int i=num2.length()-1;i>=0;i--){
        num_2.push_back(num2[i]-'0');
     }
    add(num_1,num_2,outcome);
    if(cmp(num_1,num_2)){
        sub(num_1,num_2,outcome);
        for(int i=outcome.size()-1;i>=0;i--){
            cout<<outcome[i];
           }
     
    }
    else{
        sub(num_2,num_1,outcome);
        cout<<'-';
        for(int i=outcome.size()-1;i>=0;i--){
            cout<<outcome[i];
           }
    }
  
   return 0;
}