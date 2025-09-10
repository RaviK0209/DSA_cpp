#include<iostream>
#include<vector>
using namespace std;
void dfs(int start,vector<vector<int>>&graph,vector<bool>&visited){
    
    visited[start]=true;
    cout<<start<<" ";
    for(int neighbour: graph[start]){
        if(!visited[neighbour]){
            dfs(neighbour,graph,visited);
        }
    }
}
int main(){
    int n,e;
    cout<<"enter no. of vertices:"<<endl;
    cin>>n;
    cout<<"enter no. of edges:"<<endl;
    cin>>e;

    vector<vector<int>>graph(n);
    cout<<"enter edges in format u v one by one"<<endl;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool>visited(n,false);
    int start;
    cout<<"enter starting node for dfs: "<<endl;
    cin>>start;
    cout<<"DFS traversal: ";
    dfs(start,graph,visited);
    cout<<endl;
    return 0;
}
