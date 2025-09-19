#include<iostream>
using namespace std;
 return_type recursion(int n){    //recursion function with return type............
    if(n==1 like that){       
        return n;             //base condition..............
    }
    
    return recursion(n-1)       //recursion calls...........
 }
int main(){
    int n;
    cin>>n;
    cout<<recursion(n);          //main method calling............

}
