#include<iostream>
using namespace std;

const int M=10e4+10;
int head=-1,idx=0;
int value[M];
int link[M];

void insert2list(int x){
    value[idx]=x;
    link[idx]=head;
    head=idx;
    idx++;
}

void deleflist(int index){
    link[index]=link[link[index]];
}

void insert_after_k(int index,int x){
    value[idx]=x;
    link[idx]=link[index];
    link[index]=idx;
    idx++;
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        char s;
        cin >> s;
        if (s == 'H') {
            int x;
            cin >> x;
            insert2list(x);
        }
        if (s == 'D'){
            int k;
            cin >> k;
            if (k == 0) {
                head = link[head];
            }
            else deleflist(k-1);
        }
        if (s == 'I'){
            int k, x;
            cin >> k >> x;
            insert_after_k(k-1,x);
        }
    }

    for (int i = head; i != -1; i = link[i]) cout << value[i] << ' ' ;
    cout << endl;

    return 0;
}

