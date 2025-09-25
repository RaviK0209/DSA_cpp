#include<bits/stdc++.h>
using namespace std;

void permutation(string &s, int start,int end){
    if(start==end){
        for(char c:s){
            cout<<c;
        }
        cout<<endl;
        return;
    }
    for(int i=start;i<=end;i++){
        swap(s[start],s[i]);
        permutation(s,start+1,end);
        swap(s[start],s[i]);   //optional swap to get the original string for next swapping to get correct order.
    }
}
int main(){
    string s;
    cout<<"enter the string: "<<endl;
    getline(cin,s);
    int n=s.length();
    int start=0, end=n-1;
    cout<<"Given string permutations: "<<endl;
    permutation(s,start,end);

}
