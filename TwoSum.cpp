#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
       vector<int> twoSum(vector<int>&nums,int target){
           unordered_map<int,int>mp;
           for(int i=0;i<nums.size();i++){
               int comp=target-nums[i];
               if(mp.find(comp)!=mp.end()){
                   return {mp[comp],i};
               }
               mp[nums[i]]=i;
           }
           return {};
       }
};

int main() {
   Solution sol;
   vector<int>nums={2,7,11,15};
   int target=9;
   vector<int>result=sol.twoSum(nums,target);
   for(int index:result){
       cout<<index<<" ";
   }
   cout<<endl;
    
	return 0;
}
