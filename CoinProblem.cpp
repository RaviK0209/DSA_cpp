#include<iostream>
using namespace std;
static int count=0;

int numberOfPossibleWays(int arr[],int n,int sum){
         if(sum==0) return 1;
         if(sum<0 ) return 0;
         if(n<0) return 0;
         

         count++;
         int left = numberOfPossibleWays(arr,n,sum-arr[n]);
         int right = numberOfPossibleWays(arr,n-1,sum);
         return left+right;

}

int main(){
     int n=3;
     int arr[]={10,20,50};
     cout<<numberOfPossibleWays(arr,n-1,10);
     cout<<endl<<"no of iteration: "<<count;
}
