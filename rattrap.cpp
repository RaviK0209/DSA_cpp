#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>>&arr,int i,int j,int r,int c){
    return(i<r && j<c && arr[i][j]==1);
}

bool solve(vector<vector<int>>&arr,vector<vector<int>>&sol,int r,int c,int i,int j){
    if(i==r-1 && j==c-1){
        sol[i][j]=1;
        return true;
    }
    if(issafe(arr,i,j,r,c)){
        sol[i][j];
        if(solve(arr,sol,r,c,i,j+1)){
            return true;
        }
        if(solve(arr,sol,r,c,i+1,j)){
            return true;
        }
        sol[i][j]=0;
    }
    return false;
}

void solvemaze(vector<vector<int>>&arr,int r,int c){
        
    vector<vector<int>>sol(r,vector<int>(c,0));
    if(solve(arr,sol,r,c,0,0)){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<sol[i][j];
            }
            cout<<endl;
        }
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>maze(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
        }
    }
    solvemaze(maze,r,c);


    return 0;
}