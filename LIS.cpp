#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of integers"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" integers with space:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
             if(arr[i]>arr[j]){
                dp[i]=max(dp[j]+1,dp[i]);
             }
        }
    }
    sort(dp.begin(),dp.end());
    cout<<"length of longest increasing subsequence is:"<<dp[n-1];

    return 0;
}