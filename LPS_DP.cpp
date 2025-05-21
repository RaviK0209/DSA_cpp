#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cout<<"enter first string "<<endl;;
    getline(cin,s1);
    s2=s1;
    reverse(s2.begin(),s2.end());
    
    
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    int max=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                if(max<dp[i][j]){
                    max=dp[i][j];
                }
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    cout<<"longest palindrome common subsequence length: "<<max;

  return 0;
}