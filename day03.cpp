#include<iostream>
#include<iomanip>
using namespace std;

double get_3_sqrt(double x){
   double left=-10000;
   double right=10000;
   while(right-left>1e-7){
    double mid=(left+right)/2;
    if(mid*mid*mid>x){
        right=mid;
    }
    else{
        left=mid;
    }
   }
   return 0;
}

